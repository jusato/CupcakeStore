#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include "Login.h"
#include "Membros.h"
#include "Compras.h"
#include "InfoProdutos.h"
#include "sobreapp.h"

QString MainWindow::nome_membro;
bool MainWindow::logado;
QString MainWindow::username_membro;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //começando o programa bloqueado:
    logado = false;

    //Adicionando imagens:
    cadFechado.addFile(":/Imagens/imgs/Nolog.png");
    cadAberto.addFile(":/Imagens/imgs/Yeslog1.png");

    //Adicionando imagem no botão:
    ui->btn_cadeado->setIcon(cadFechado);
    ui->statusbar->addWidget(ui->btn_cadeado); //fazendo com que o botão seja inserido na barra de status
    ui->statusbar->addWidget(ui->label_nome);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_cadeado_clicked()
{

}

void MainWindow::on_actionMembros_triggered()
{
    if (logado) {
        Membros membros;
        membros.exec();
    } else {
        QMessageBox::information(this, "LOGIN", "Não existe membro logado");
    }
}

void MainWindow::on_btn_produtos_clicked()
{
    Compras compras;
    compras.exec();
}

void MainWindow::on_actionProdutos_triggered()
{
    if (logado) {
        InfoProdutos infoProdutos;
        infoProdutos.exec();
    } else {
        QMessageBox::information(this, "LOGIN", "Não existe membro logado");
    }
}

void MainWindow::on_btn_Entrar_clicked()
{
    if(!logado) {
        Login logar;
        logar.exec(); //chamar a janela de login

        if(logado) {
            ui->btn_cadeado->setIcon(cadAberto);
            ui->label_nome->setText(nome_membro);
        }

    } else {
        logado = false;
        ui->btn_cadeado->setIcon(cadFechado);
        ui->label_nome->setText("Membro não conectado");
    }
}

void MainWindow::on_actionSair_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionSobre_triggered()
{
    SobreApp sobre;
    sobre.exec();
}
