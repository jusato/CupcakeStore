#ifndef PRODUTOS_EDITARQTDE_H
#define PRODUTOS_EDITARQTDE_H

#include <QDialog>

#include "Compras.h"

namespace Ui {
class produtos_editarQtde;
}

class produtos_editarQtde : public QDialog
{
    Q_OBJECT

public:
    explicit produtos_editarQtde(QWidget *parent = nullptr);
    ~produtos_editarQtde();

private slots:
    void on_btn_editaConfirmar_clicked();

    void on_btn_editaCancelar_clicked();

private:
    Ui::produtos_editarQtde *ui;
};

#endif // PRODUTOS_EDITARQTDE_H
