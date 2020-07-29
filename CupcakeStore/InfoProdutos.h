#ifndef INFOPRODUTOS_H
#define INFOPRODUTOS_H

#include <QDialog>
#include "Conexao.h"
#include <QMessageBox>
#include <QtSql>
#include <QTableWidget>

namespace Ui {
class InfoProdutos;
}

class InfoProdutos : public QDialog
{
    Q_OBJECT

public:
    explicit InfoProdutos(QWidget *parent = nullptr);
    ~InfoProdutos();
    Conexao conec;

private slots:
    void on_btn_novoProduto_clicked();

    void on_btn_gravarProduto_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_tab_GPprodutos_itemSelectionChanged();

    void on_btn_GPalterar_clicked();

    void on_btn_GPexcluir_clicked();

    void on_btn_GPfiltrar_clicked();

    void on_txt_GPfiltrar_returnPressed();

    void on_pushButton_clicked();

private:
    Ui::InfoProdutos *ui;
    void fazerConexao(); //método criado para fazer a conexão com o banco de dados quando necessário
    void removerLinhas(QTableWidget *tabela);
};

#endif // INFOPRODUTOS_H
