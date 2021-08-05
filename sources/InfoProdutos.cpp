#include "InfoProdutos.h"
#include "ui_InfoProdutos.h"

InfoProdutos::InfoProdutos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoProdutos)
{
    ui->setupUi(this);

    ui->tab_GPprodutos->setColumnCount(2); //para ja definir que a tabela tem 2 colunas
    ui->tabWidget->setCurrentIndex(0); //so para sempre começar na aba "Novo Produto"
    ui->txt_codigoProduto->setFocus();
    ui->txt_GPcodigo->setReadOnly(true);
}

InfoProdutos::~InfoProdutos()
{
    delete ui;
}

void InfoProdutos::fazerConexao() {
    //Abertura da conexão
    if (!conec.abrir()) {
        QMessageBox::warning(this, "ERROR", "Erro ao abrir banco de dados");
    } else {
        return;
    }
}

void InfoProdutos::removerLinhas(QTableWidget *tabela) {
    //se tiver alguma linha vai remover ate não ter mais
    while (tabela->rowCount() > 0) {
        tabela->removeRow(0);
    }
}

void InfoProdutos::on_btn_novoProduto_clicked()
{
    //limpar todos os campos
    ui->txt_codigoProduto->clear();
    ui->txt_qtdeEstoque->clear();
    ui->txt_descricaoProduto->clear();
    ui->txt_valorVenda->clear();
    ui->txt_valorCompra->clear();

    //posicionar o cursor no 1o campo
    ui->txt_codigoProduto->setFocus();
}

void InfoProdutos::on_btn_gravarProduto_clicked()
{
        //Armazenar as informações em variáveis:   
        QString codigo = ui->txt_codigoProduto->text();
        QString produto = ui->txt_descricaoProduto->text();
        QString qtde = ui->txt_qtdeEstoque->text();

        QString aux; //variável criada para trocar vírgula por ponto em double

        aux = ui->txt_valorVenda->text();
        std::replace(aux.begin(), aux.end(), ',', '.');
        QString valorVenda = aux;

        aux = ui->txt_valorCompra->text();
        std::replace(aux.begin(), aux.end(), ',', '.');
        QString valorCompra = aux;
        if(codigo != "" && produto != "" && qtde != "" && valorVenda != "" && valorCompra != "") {
            fazerConexao();
            //Criar a query e fazer sua execuçao para a inserção dos produtos:
            QSqlQuery query;
            query.prepare("select id_produto from tabela_produtos where id_produto ="+codigo);
            if(query.exec()) {
                query.first();
                if(query.value(0).toString() == "") { //Não pode registrar um produto com o mesmo código
                    query.prepare("insert into tabela_produtos (id_produto, produto, qtde_produto, valor_compra, valor_venda)"
                                  "values ("+QString::number(codigo.toInt())+", '"+produto+"', "+QString::number(qtde.toInt())+", "
                                           ""+QString::number(valorCompra.toDouble())+", "+QString::number(valorVenda.toDouble())+")");
                        query.exec();
                        QMessageBox::information(this, "SUCCESSFUL", "Produto gravado com sucesso");
                        ui->txt_codigoProduto->clear();
                        ui->txt_qtdeEstoque->clear();
                        ui->txt_descricaoProduto->clear();
                        ui->txt_valorVenda->clear();
                        ui->txt_valorCompra->clear();
                        ui->txt_codigoProduto->setFocus();
                } else {
                    QMessageBox::information(this, "ERROR", "Esse código já foi utilizado. Digite outro.");
                    ui->txt_codigoProduto->clear();
                }
            conec.fechar();
            } else {
                QMessageBox::information(this, "ERROR", "Erro ao listar produtos.");
            }
    } else {
            QMessageBox::information(this, "ERROR", "Preencha todos os campos.");
    }
}

void InfoProdutos::on_tabWidget_currentChanged(int index)
{
    fazerConexao();
    if (index == 1) { //se for a 2a tab (Gestão Produtos)

        removerLinhas(ui->tab_GPprodutos);

        //Listar todos os produtos e fazer inserção deles na tabela:
        int count = 0;
        QSqlQuery query;
        query.prepare("select id_produto,produto from tabela_produtos");
        if(query.exec()) {
            while(query.next()) {
                ui->tab_GPprodutos->insertRow(count);
                ui->tab_GPprodutos->setItem(count, 0, new QTableWidgetItem(query.value(0).toString())); //definir o item para a 1a coluna
                ui->tab_GPprodutos->setItem(count, 1, new QTableWidgetItem(query.value(1).toString())); //para a 2a coluna
                                                                          //value(0): id_produto | value(1): produto
                ui->tab_GPprodutos->setRowHeight(count, 20);
                count++;
            }
            //Parte de "design" da tabela:
            ui->tab_GPprodutos->setColumnWidth(0, 70);
            ui->tab_GPprodutos->setColumnWidth(1, 218);
            QStringList cabecalhos = {"Código", "Produto"};
            ui->tab_GPprodutos->setHorizontalHeaderLabels(cabecalhos);
            ui->tab_GPprodutos->setStyleSheet("QTableView {selection-background-color: orange}");
            ui->tab_GPprodutos->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tab_GPprodutos->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tab_GPprodutos->verticalHeader()->setVisible(false);

        }

    }
    conec.fechar();
}

void InfoProdutos::on_tab_GPprodutos_itemSelectionChanged()
{
    fazerConexao();
    //A partir do id do produto, acharemos as informações dele e preencheremos nas linhas à esquerda
     int id = ui->tab_GPprodutos->item(ui->tab_GPprodutos->currentRow(), 0)->text().toInt();

    QSqlQuery query;
    query.prepare("select * from tabela_produtos where id_produto = "+QString::number(id));
    if(query.exec()) {
        //Preencher elementos do formulário com o retorno da query:
        query.first();
        ui->txt_GPcodigo->setText(query.value(0).toString());
        ui->txt_GPproduto->setText(query.value(1).toString());
        ui->txt_GPqtde->setText(query.value(2).toString());
        ui->txt_GPvalorCompra->setText(query.value(3).toString());
        ui->txt_GPvalorVenda->setText(query.value(4).toString());
    } else {
       QMessageBox::warning(this, "ERROR", "Erro ao listar produtos");
    }
    conec.fechar();
}

void InfoProdutos::on_btn_GPalterar_clicked()
{
    if(ui->txt_GPcodigo->text() == "") { //se não tiver nada selecionado
        QMessageBox::warning(this, "ERROR", "Selecione um item");
    } else {
        fazerConexao();
        int id = ui->tab_GPprodutos->item(ui->tab_GPprodutos->currentRow(), 0)->text().toInt();

        QString produto = ui->txt_GPproduto->text();
        QString qtde = ui->txt_GPqtde->text();

        QString aux;
        aux = ui->txt_GPvalorVenda->text();
        std::replace(aux.begin(), aux.end(), ',', '.');
        QString valorVenda = aux;

        aux = ui->txt_GPvalorCompra->text();
        std::replace(aux.begin(), aux.end(), ',', '.');
        QString valorCompra = aux;

        QSqlQuery query;
        query.prepare("update tabela_produtos set id_produto = "+QString::number(id)+", produto = '"+produto+"', "
                      "qtde_produto = "+QString::number(qtde.toInt())+", valor_compra = "+QString::number(valorCompra.toDouble())+", "
                      "valor_venda = "+QString::number(valorVenda.toDouble())+" where id_produto = "+QString::number(id)+"");
        if(query.exec()) {
           //pegar linha que esta selecionada e atualizar
            int linha = ui->tab_GPprodutos->currentRow();
            ui->tab_GPprodutos->item(linha, 0)->setText(ui->txt_GPcodigo->text());
            ui->tab_GPprodutos->item(linha, 1)->setText(produto);
            QMessageBox::information(this, "SUCCESSFUL", "Produto atualizado com sucesso");

        } else {
           QMessageBox::warning(this, "ERROR", "Erro ao atualizar o produto");
        }
        conec.fechar();
    }

}

void InfoProdutos::on_btn_GPexcluir_clicked()
{
    if(ui->txt_GPcodigo->text() == "") {
        QMessageBox::warning(this, "ERROR", "Selecione um item");
    } else {
        fazerConexao();
        QMessageBox::StandardButton opcao;
        opcao = QMessageBox::question(this, "Deletar", "Tem certeza que deseja excluir o produto?", QMessageBox::Yes | QMessageBox::No);
        if(opcao == QMessageBox::Yes) {
            int linha = ui->tab_GPprodutos->currentRow();
            int id = ui->tab_GPprodutos->item(linha, 0)->text().toInt();
            QSqlQuery query;
            query.prepare("delete from tabela_produtos where id_produto =" +QString::number(id));
            if(query.exec()) {
                ui->tab_GPprodutos->removeRow(linha);
                QMessageBox::information(this, "SUCCESSFUL", "Produto removido com sucesso");

            } else {
               QMessageBox::warning(this, "ERROR", "Erro ao remover o produto");
            }
        }
        conec.fechar();
    }
}

void InfoProdutos::on_btn_GPfiltrar_clicked()
{
    if(ui->txt_GPcodigo->text() == "") {
        fazerConexao();
        removerLinhas(ui->tab_GPprodutos); //removendo todas as linhas da tabela
        QString busca;
        if(ui->txt_GPfiltrar->text() == "") {            //se não digitou nada, todos os produtos vão ser mostrados novamente
            if(ui->radbtn_GPcodigo->isChecked()) {
                busca = "select id_produto,produto from tabela_produtos order by id_produto";
            } else {
                busca = "select id_produto,produto from tabela_produtos order by produto";
            }
        } else {
            busca = "select id_produto,produto from tabela_produtos where produto like '%"+ui->txt_GPfiltrar->text()+"%' order by produto";
            /*if(ui->radbtn_GPcodigo->isChecked()) {
                busca = "select id_produto,produto from tabela_produtos where id_produto = "+ui->txt_GPfiltrar->text()+" order by id_produto";
            } else {
                busca = "select id_produto,produto from tabela_produtos where produto like '%"+ui->txt_GPfiltrar->text()+"%' order by produto";

            }*/
        }
        //Listar produtos e fazer inserção na tabela:
        int count = 0;
        QSqlQuery query;
        query.prepare(busca);
        if(query.exec()) {
            while(query.next()) {
                ui->tab_GPprodutos->insertRow(count);
                ui->tab_GPprodutos->setItem(count, 0, new QTableWidgetItem(query.value(0).toString()));
                ui->tab_GPprodutos->setItem(count, 1, new QTableWidgetItem(query.value(1).toString()));
                ui->tab_GPprodutos->setRowHeight(count, 20);
                count++;
            }
        } else {
           QMessageBox::warning(this, "ERROR", "Erro ao listar produtos");
        }
        ui->txt_GPfiltrar->clear();
        conec.fechar();
    }

}

void InfoProdutos::on_txt_GPfiltrar_returnPressed()
{
    on_btn_GPfiltrar_clicked();
}

void InfoProdutos::on_pushButton_clicked()
{
    close();
}
