#include "Login.h"
#include "ui_Login.h"
#include "mainwindow.h"

QString Login::nomeArq = "Membross.dat";

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    logado = false; //ao abrir a janela de login, não vai estar logado
    ui->txt_username->setFocus();
}

Login::~Login()
{
    delete ui;
}

QDataStream &operator>>(QDataStream &in, InfoMembros &membro);

void Login::on_btn_entrar_clicked()
{
    QFile arquivo(qApp->applicationDirPath() + nomeArq);
    if(!arquivo.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "ERROR", "Erro no login");
    } else {
        QDataStream in (&arquivo);
        InfoMembros membro;
        QString username = ui->txt_username->text();
        QString senha = ui->txt_senha->text();
        bool achou = false;
        while(!in.atEnd()) {
            in >> membro;
            if(membro.username == username && membro.senha == senha) {
                MainWindow::logado = true;
                MainWindow::nome_membro = membro.nome;
                achou = true;
            }
        }
        if(!achou)
            QMessageBox::warning(this, "ERROR", "Membro não encontrado");
        else
            close();
    }
    arquivo.close();

}

void Login::on_btn_cancelar_clicked()
{
    logado = false;
    close();
}


void Login::on_txt_senha_returnPressed()
{
    on_btn_entrar_clicked();
}

void Login::on_txt_username_returnPressed()
{
    on_btn_entrar_clicked();
}
