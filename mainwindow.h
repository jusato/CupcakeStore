#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //criando dois objetos do tipo Icon para trocar as imagens do botão quando tiver alguém logado
    QIcon cadFechado;
    QIcon cadAberto;
    static bool logado;
    static QString nome_membro, username_membro;

private slots:
    void on_btn_cadeado_clicked();

    void on_actionMembros_triggered();

    void on_btn_produtos_clicked();

    void on_actionProdutos_triggered();

    void on_btn_Entrar_clicked();

    void on_actionSair_triggered();

    void on_actionSobre_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
