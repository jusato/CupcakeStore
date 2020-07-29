#include "sobreapp.h"
#include "ui_sobreapp.h"

SobreApp::SobreApp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SobreApp)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

SobreApp::~SobreApp()
{
    delete ui;
}

void SobreApp::on_pushButton_clicked()
{
    close();
}
