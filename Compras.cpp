#include "Compras.h"
#include "ui_Compras.h"

//Inicializar variáveis
QString Compras::idprod;
QString Compras::prod;
QString Compras::qtde;
QString Compras::valUni;
QString Compras::valTot;
bool Compras::alterou;


Compras::Compras(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Compras)
{
    ui->setupUi(this);

    if(!conec.abrir()) {
        QMessageBox::warning(this, "ERROR", "Erro ao abrir banco de dados");
    }
    listarProdutos();
    //"Design" da tabela:
    ui->tab_listaProdutos->setColumnCount(5);
    ui->tab_listaProdutos->setColumnWidth(0, 70);
    ui->tab_listaProdutos->setColumnWidth(1, 218);
    ui->tab_listaProdutos->setColumnWidth(2, 88);
    ui->tab_listaProdutos->setColumnWidth(3, 110);
    ui->tab_listaProdutos->setColumnWidth(4, 71);
    QStringList cabecalhos = {"Código", "Produto", "Valor un.", "Quantidade", "Total"};
    ui->tab_listaProdutos->setHorizontalHeaderLabels(cabecalhos);
    ui->tab_listaProdutos->setStyleSheet("QTableView {selection-background-color: pink}");
    ui->tab_listaProdutos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tab_listaProdutos->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tab_listaProdutos->verticalHeader()->setVisible(false);

    ui->txt_codigo->setFocus(); //só deixando o cursor no lugar do codigo do produto
    countLinhas = 0;

}

Compras::~Compras()
{
    delete ui;
}

void Compras::listarProdutos() {
     ui->tab_Produtos->setColumnCount(3);
        //Remover os produtos da tabela:
        while (ui->tab_Produtos->rowCount() > 0) {
            ui->tab_Produtos->removeRow(0);
        }
        int count = 0;
        QSqlQuery query;
        query.prepare("select id_produto,produto,valor_venda from tabela_produtos");
        if(query.exec()) {
            while(query.next()) {
                ui->tab_Produtos->insertRow(count);
                ui->tab_Produtos->setItem(count, 0, new QTableWidgetItem(query.value(0).toString()));
                ui->tab_Produtos->setItem(count, 1, new QTableWidgetItem(query.value(1).toString()));
                ui->tab_Produtos->setItem(count, 2, new QTableWidgetItem("R$"+query.value(2).toString()));
                ui->tab_Produtos->setRowHeight(count, 30);
                count++;
            }
            ui->tab_Produtos->setColumnWidth(0, 70);
            ui->tab_Produtos->setColumnWidth(1, 218);
            ui->tab_Produtos->setColumnWidth(2, 79);
            QStringList cabecalhos = {"Código", "Produto", "Preço"};
            ui->tab_Produtos->setHorizontalHeaderLabels(cabecalhos);
            ui->tab_Produtos->setStyleSheet("QTableView {selection-background-color: pink}");
            ui->tab_Produtos->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tab_Produtos->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tab_Produtos->verticalHeader()->setVisible(false);
        } else {
           QMessageBox::warning(this, "ERROR", "Erro ao listar produtos");
        }
}


void Compras::fazerConexao() {
    //Abertura da conexão
    if (!conec.abrir()) {
        QMessageBox::warning(this, "ERROR", "Erro ao abrir banco de dados");
    } else {
        return;
    }
}

void Compras::removeLinhas(QTableWidget *tabela) {
    while (tabela->rowCount() > 0) {
        tabela->removeRow(0);
    }
}

void Compras::on_txt_codigo_returnPressed()
{
    fazerConexao();
    double valTotal;
    QString id = ui->txt_codigo->text();
    QSqlQuery query;
    query.prepare("select id_produto,produto,valor_venda from tabela_produtos where id_produto ="+id);
    if(query.exec()) {
        query.first();
        if(query.value(0).toString() != "") { //Se existir produto com esse id
            ui->tab_listaProdutos->insertRow(countLinhas);
            ui->tab_listaProdutos->setItem(countLinhas, 0, new QTableWidgetItem(query.value(0).toString())); //id_produto
            ui->tab_listaProdutos->setItem(countLinhas, 1, new QTableWidgetItem(query.value(1).toString())); //produto
            ui->tab_listaProdutos->setItem(countLinhas, 2, new QTableWidgetItem(query.value(2).toString())); //valor_venda
            ui->tab_listaProdutos->setItem(countLinhas, 3, new QTableWidgetItem(ui->txt_qtde->text())); //pegando o valor do campo "Quantidade"

            valTotal = ui->txt_qtde->text().toDouble() * query.value(2).toDouble(); //valor total = qtde x valor un.
            ui->tab_listaProdutos->setItem(countLinhas, 4, new QTableWidgetItem(QString::number(valTotal)));

            ui->tab_listaProdutos->setRowHeight(countLinhas, 20);
            countLinhas++;

            //Atualizando o valor total da venda:
            ui->label_valorTotal->setText("R$ " + QString::number(calculaTotal(ui->tab_listaProdutos, 4))); //coluna 4, que é aonde está o valor total de cada produto
        } else {
            QMessageBox::warning(this, "ERROR", "Produto não econtrado");
        }
        resetaCampos();
    } else {
        QMessageBox::warning(this, "ERROR", "Erro ao inserir novo produto");
    }
    conec.fechar();
}

void Compras::on_txt_qtde_returnPressed()
{
    on_txt_codigo_returnPressed(); //se estiver no campo quantidade e apertar Enter, faz a mesma coisa
}

void Compras::resetaCampos() {
    ui->txt_codigo->clear();
    ui->txt_qtde->setText("1");
    ui->txt_codigo->setFocus();
}

double Compras::calculaTotal(QTableWidget *tabela, int coluna) {
    //Função que faz a soma dos valores da coluna (para informar o valor total da compra)

    int totLinhas = tabela->rowCount();
    double total = 0;
    for(int i = 0; i < totLinhas; i++) {
        total = total + tabela->item(i, coluna)->text().toDouble();
    }
    return total;
}

void Compras::on_btn_removerProduto_clicked()
{
    if(ui->tab_listaProdutos->currentColumn() != -1) { //(o método currentColumn retorna -1 se não tiver coluna selecionada)
        fazerConexao();
        QMessageBox::StandardButton opcao;
        opcao = QMessageBox::question(this, "Exclusão", "Confirma a remoção deste produto do seu carrinho?", QMessageBox::Yes | QMessageBox::No);
        if(opcao == QMessageBox::Yes) {
            ui->tab_listaProdutos->removeRow(ui->tab_listaProdutos->currentRow());
            ui->label_valorTotal->setText("R$ " + QString::number(calculaTotal(ui->tab_listaProdutos, 4)));
            countLinhas--;
        }
        conec.fechar();
    } else {
        QMessageBox::warning(this, "ERROR", "Selecione um item");
    }
}


void Compras::on_btn_editarProduto_clicked()
{
    if(ui->tab_listaProdutos->currentColumn() != -1) { //se existir um produto selecionado
        fazerConexao();
        int linha = ui->tab_listaProdutos->currentRow();

        idprod = ui->tab_listaProdutos->item(linha, 0)->text();
        prod = ui->tab_listaProdutos->item(linha, 1)->text();
        valUni = ui->tab_listaProdutos->item(linha, 2)->text();
        qtde = ui->tab_listaProdutos->item(linha, 3)->text();

        produtos_editarQtde editarQtde;
        editarQtde.exec();

        if(alterou) { //Mudaremos na tabela se mudar algo na edição
            ui->tab_listaProdutos->item(linha, 3)->setText(qtde);
            ui->tab_listaProdutos->item(linha, 4)->setText(valTot);
            ui->label_valorTotal->setText("R$ " + QString::number(calculaTotal(ui->tab_listaProdutos, 4)));

        }
    } else {
        QMessageBox::warning(this, "ERROR", "Selecione um item");
    }
}

void Compras::on_btn_finalizarCompra_clicked()
{
    if(ui->tab_listaProdutos->rowCount() > 0) { //se existir um produto selecionado
        fazerConexao();
        int idVenda; //precisamos do id do produto para modificar a tabela sql de vendas
        QString msgFimVenda;
        double valTotal = calculaTotal(ui->tab_listaProdutos, 4);
        QString data = QDate::currentDate().toString("yyyy-MM-dd");
        QString hora = QTime::currentTime().toString("hh:mm:ss");

        QSqlQuery query;
        query.prepare("insert into tabela_vendas (data_venda,hora_venda,valor_total,id_tipo_pagamento) values('"+data+"', '"+hora+"', "+QString::number(valTotal)+", 1)");
        if(query.exec()) {
            //criar nova query para obter o ultimo registro
            query.prepare("select id_venda from tabela_vendas order by id_venda desc limit 1"); //ordena de forma decrescente e limita para um registro
            query.exec();
            query.first();
            idVenda = query.value(0).toInt(); //value 0 porque sabemos que o id sempre esta nessa posição
            //Inserir produto na tabela dos produtos vendidos:
            int totalLinhas = ui->tab_listaProdutos->rowCount();
            int linha = 0;
            while(linha < totalLinhas) {
                QString prod = ui->tab_listaProdutos->item(linha, 1)->text(); //coluna 1
                QString qtde = ui->tab_listaProdutos->item(linha, 3)->text();
                QString valUn = ui->tab_listaProdutos->item(linha, 2)->text();
                QString valTot = ui->tab_listaProdutos->item(linha, 4)->text();
                query.prepare("insert into tabela_produtosVendas (id_venda, produto, qtde, valor_un, valor_total)values ("+QString::number(idVenda)+", '"+prod+"',"+qtde+", "+valUn+", "+valTot+")");
                query.exec();
                linha++;
            }

            QMessageBox::information(this, "SUCCESSFUL", "Compra realizada com sucesso! \nValor Total: R$"+QString::number(valTotal));
            resetaCampos();
            removeLinhas(ui->tab_listaProdutos);
            ui->label_valorTotal->setText("R$ 0.00");
        } else {
            QMessageBox::warning(this, "ERROR", "Erro ao registrar nova venda");
        }
        conec.fechar();
    } else {
        QMessageBox::warning(this, "ERROR", "Não existem produtos nesta compra");
    }
}

void Compras::on_btn_pesquisarProduto_clicked()
{
    on_txt_codigo_returnPressed();
}

void Compras::on_pushButton_clicked()
{
    close();
}
