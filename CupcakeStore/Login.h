#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QString>
#include <QVector>
#include <QIcon>
#include "InfoMembros.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    bool logado;
    static QString nomeArq;

private slots:
    void on_btn_entrar_clicked();

    void on_btn_cancelar_clicked();

    void on_txt_senha_returnPressed();

    void on_txt_username_returnPressed();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
