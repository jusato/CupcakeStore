#ifndef MEMBROS_H
#define MEMBROS_H

#include <QDialog>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QString>
#include <QTableWidget>
#include "InfoMembros.h"
#include <QVector>

namespace Ui {
class Membros;
}

class Membros : public QDialog
{
    Q_OBJECT

public:
    explicit Membros(QWidget *parent = nullptr);
    ~Membros();
    static QString nomeArq;

private slots:
    void on_btn_addMembro_clicked();

    void on_btn_alterarMembro_clicked();

    void on_btn_excluirMembro_clicked();

    void on_tab_listaMembros_itemSelectionChanged();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::Membros *ui;
    int encontraUsername(QString);
    void removerLinhas(QTableWidget *tabela);
    void leitura(QVector<InfoMembros> & membros);
};

#endif // MEMBROS_H
