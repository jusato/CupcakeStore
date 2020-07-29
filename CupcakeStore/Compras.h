#ifndef COMPRAS_H
#define COMPRAS_H

#include "Conexao.h"
#include "produtos_editarqtde.h"
#include "mainwindow.h"

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QTableWidget>

namespace Ui {
class Compras;
}

class Compras : public QDialog
{
    Q_OBJECT

public:
    explicit Compras(QWidget *parent = nullptr);
    ~Compras();
    Conexao conec;

    //Criando variáveis globais para serem usadas na classe produtos_editarQtde
    static QString idprod, prod, qtde, valUni, valTot;
    static bool alterou;

private slots:
    void on_txt_codigo_returnPressed();

    void on_btn_removerProduto_clicked();

    void on_txt_qtde_returnPressed();

    void on_btn_editarProduto_clicked();

    void on_btn_finalizarCompra_clicked();

    void on_btn_pesquisarProduto_clicked();

    void on_pushButton_clicked();

private:
    Ui::Compras *ui;
    int countLinhas; //variável criada para saber em qual linha eu vou estar editando
    void fazerConexao();
    void resetaCampos();
    double calculaTotal(QTableWidget *tabela, int coluna);
    void removeLinhas(QTableWidget *tabela);
    void listarProdutos();
};

#endif // COMPRAS_H
