#include "produtos_editarqtde.h"
#include "ui_produtos_editarqtde.h"

produtos_editarQtde::produtos_editarQtde(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::produtos_editarQtde)
{
    ui->setupUi(this);
    ui->txt_editaProduto->setText(Compras::prod);
    ui->txt_editaQtde->setText(Compras::qtde);
    ui->txt_editaProduto->setReadOnly(true);
    ui->txt_editaQtde->setFocus();
}

produtos_editarQtde::~produtos_editarQtde()
{
    delete ui;
}

void produtos_editarQtde::on_btn_editaConfirmar_clicked()
{
    Compras::alterou = true;
    Compras::qtde = ui->txt_editaQtde->text();
    Compras::valTot = QString::number(ui->txt_editaQtde->text().toDouble() * Compras::valUni.toDouble());
    close();
}

void produtos_editarQtde::on_btn_editaCancelar_clicked()
{
    Compras::alterou = false;
    close();
}
