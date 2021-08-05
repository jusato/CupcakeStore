#include "Membros.h"
#include "ui_Membros.h"

QString Membros::nomeArq = "Membross.dat";

Membros::Membros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Membros)
{
    ui->setupUi(this);

    ui->tabWidget->setCurrentIndex(0);
    ui->txt_nome->clear();
    ui->txt_user->clear();
    ui->txt_senha->clear();
    ui->txt_celular->clear();
    ui->txt_nome->setFocus();
    ui->txt_userMembro->setReadOnly(true);
}

Membros::~Membros()
{
    delete ui;
}
//Sobrecarregando os operadores para ser possível realizar as operações de leitura e escrita de um objeto nas formas >> e <<
QDataStream &operator<<(QDataStream &out, InfoMembros const &membro) {
    out << membro.nome << membro.celular << membro.username << membro.senha;
    return out;
}

QDataStream &operator>>(QDataStream &in, InfoMembros &membro) {
    in >> membro.nome >> membro.celular >> membro.username >> membro.senha;
    return in;
}

void Membros::removerLinhas(QTableWidget *tabela) {
    while (tabela->rowCount() > 0) {
        tabela->removeRow(0);
    }
}

int Membros::encontraUsername(QString user) {
    QFile arquivo(qApp->applicationDirPath() + nomeArq);
    int pos = 0;
    bool achou = false;
    if(!arquivo.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "ERROR", "Erro ao abrir arquivo");
    } else {
        QDataStream in (&arquivo);
        InfoMembros membro;
        arquivo.QIODevice::seek(0);
        while(!in.atEnd()) {
            in >> membro;
            pos++;
            if(membro.username == user) {
                achou = true;
                break;
            }
        }
    }
    arquivo.close();
    if(achou)
        return pos;
    return -1;
}

void Membros::leitura(QVector<InfoMembros> & membros) {
    QFile arquivo(qApp->applicationDirPath() + nomeArq);
    if(!arquivo.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "ERROR", "Erro ao abrir arquivo");
    } else {
        QDataStream in (&arquivo);
        InfoMembros membro;
        membros.clear();
        arquivo.QIODevice::seek(0);
        while(!in.atEnd()) {
            in >> membro;
            membros.push_back(membro);
        }
    }
    arquivo.close();
}

void Membros::on_btn_addMembro_clicked()
{
        QString nome = ui->txt_nome->text();
        QString user = ui->txt_user->text();
        QString senha = ui->txt_senha->text();
        QString celular = ui->txt_celular->text();
        if(nome != "" && user != "" && senha != "") {
            int ok = encontraUsername(user);
            if(ok != -1) {
                QMessageBox::warning(this, "Username já existente", "Esse username já foi utilizado. Escolha outro username");
                ui->txt_user->clear();
                ui->txt_user->setFocus();
            } else {
                InfoMembros membro(nome, celular, user, senha);

                QFile arquivo(qApp->applicationDirPath() + nomeArq);
                if(!arquivo.open(QFile::Append | QFile::Text)) {
                    QMessageBox::warning(this, "ERROR", "Erro ao abrir o arquivo");
                }
                QDataStream out (&arquivo);
                out.setVersion(QDataStream::Qt_4_7);
                out << membro;
                arquivo.flush();
                arquivo.close();
                QMessageBox::information(this, "SUCCESSFUL", "Membro adicionado com sucesso");
                ui->txt_nome->clear();
                ui->txt_user->clear();
                ui->txt_senha->clear();
                ui->txt_celular->clear();
                ui->txt_nome->setFocus();
            }
        } else {
            QMessageBox::information(this, "ERROR", "Preencha todos os campos.");
        }

}

void Membros::on_btn_alterarMembro_clicked()
{
     if(ui->txt_nomeMembro->text() == "") {
        QMessageBox::warning(this, "ERROR", "Selecione um item");
    } else {
         QString nome = ui->txt_nomeMembro->text();
         QString user = ui->txt_userMembro->text();
         QString senha = ui->txt_senhaMembro->text();
         QString celular = ui->txt_celularMembro->text();

         int linha = ui->tab_listaMembros->currentRow();
         QString username = ui->tab_listaMembros->item(linha, 1)->text();

         InfoMembros membro(nome, celular, user, senha);
         int pos = encontraUsername(username);
         QVector<InfoMembros> membros;
         leitura(membros);
         membros[pos - 1] = membro;

         QFile arquivo(qApp->applicationDirPath() + nomeArq);
         if(!arquivo.open(QFile::WriteOnly| QFile::Text)) {
             QMessageBox::warning(this, "ERROR", "Erro ao abrir o arquivo");
         }
         QDataStream out (&arquivo);
         out.setVersion(QDataStream::Qt_4_7);
         int count = 0;
         while(count < membros.size()) {
             out << membros[count];
             count++;
         }
         arquivo.flush();
         arquivo.close();

         ui->tab_listaMembros->item(linha, 0)->setText(ui->txt_nomeMembro->text());
         ui->tab_listaMembros->item(linha, 1)->setText(ui->txt_userMembro->text());
         QMessageBox::information(this, "SUCCESSFUL", "Informações alteradas com sucesso");
    }
}

void Membros::on_btn_excluirMembro_clicked()
{
    if(ui->txt_nomeMembro->text() == "") {
        QMessageBox::warning(this, "ERROR", "Selecione um item");
    } else {
        QMessageBox::StandardButton opcao;
        opcao = QMessageBox::question(this, "Deletar", "Tem certeza que deseja remover este membro?", QMessageBox::Yes | QMessageBox::No);
        if(opcao == QMessageBox::Yes) {
            QVector<InfoMembros> membros;
            leitura(membros);
            int linha = ui->tab_listaMembros->currentRow();
            QString user = ui->tab_listaMembros->item(linha, 1)->text();

            QFile arquivo(qApp->applicationDirPath() + nomeArq);
            if(!arquivo.open(QFile::WriteOnly | QFile::Text)) {
                QMessageBox::warning(this, "ERROR", "Erro ao abrir o arquivo");
            } else {
                QDataStream out (&arquivo);
                out.setVersion(QDataStream::Qt_4_7);
                int count = 0;
                while(count < membros.size()) {
                    if(membros[count].username != user)
                        out << membros[count];
                    count++;
                }
                ui->tab_listaMembros->removeRow(linha);
                QMessageBox::information(this, "SUCCESSFUL", "Membro removido com sucesso");
            }
            arquivo.flush();
            arquivo.close();
        }
    }
}

void Membros::on_tab_listaMembros_itemSelectionChanged()
{
        QString user = ui->tab_listaMembros->item(ui->tab_listaMembros->currentRow(),1)->text();
        int pos = encontraUsername(user);
        QVector<InfoMembros> membros;
        leitura(membros);
        if (pos > 0 && pos <= membros.size()) {
            ui->txt_nomeMembro->setText(membros[pos - 1].nome);
            ui->txt_userMembro->setText(membros[pos - 1].username);
            ui->txt_senhaMembro->setText(membros[pos - 1].senha);
            ui->txt_celularMembro->setText(membros[pos - 1].celular);
        }
}

void Membros::on_tabWidget_currentChanged(int index)
{
    if(index == 0) {
        ui->txt_nomeMembro->clear();
        ui->txt_userMembro->clear();
        ui->txt_senhaMembro->clear();
        ui->txt_celularMembro->clear();
    }
    if(index == 1) {
        QVector<InfoMembros> membros;
        leitura(membros);
        ui->txt_nomeMembro->clear();
        ui->txt_userMembro->clear();
        ui->txt_senhaMembro->clear();
        ui->txt_celularMembro->clear();
        if(membros.size() > 0) {
            removerLinhas(ui->tab_listaMembros);
            ui->tab_listaMembros->setRowCount(membros.size());
            ui->tab_listaMembros->setColumnCount(2);
            int count = 0;
            while(count < membros.size()) {
                ui->tab_listaMembros->setItem(count, 0, new QTableWidgetItem(membros[count].nome));
                ui->tab_listaMembros->setItem(count, 1, new QTableWidgetItem(membros[count].username));

                ui->tab_listaMembros->setRowHeight(count, 20);
                count++;
            }
            ui->tab_listaMembros->setColumnWidth(0, 130);
            ui->tab_listaMembros->setColumnWidth(1, 98);
            QStringList cabecalhos = {"Membro", "username"};
            ui->tab_listaMembros->setHorizontalHeaderLabels(cabecalhos);
            ui->tab_listaMembros->setStyleSheet("QTableView {selection-background-color: green}");
            ui->tab_listaMembros->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tab_listaMembros->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tab_listaMembros->verticalHeader()->setVisible(false);
        }
    }
}

void Membros::on_pushButton_clicked()
{
    close();
}
