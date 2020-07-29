/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPets;
    QAction *actionPets_adotados;
    QAction *actionMembros;
    QAction *actionSobre;
    QAction *actionSair;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *btn_cadeado;
    QLabel *label_nome;
    QMenuBar *menubar;
    QMenu *menuGest_o;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(454, 281);
        actionPets = new QAction(MainWindow);
        actionPets->setObjectName(QString::fromUtf8("actionPets"));
        actionPets_adotados = new QAction(MainWindow);
        actionPets_adotados->setObjectName(QString::fromUtf8("actionPets_adotados"));
        actionMembros = new QAction(MainWindow);
        actionMembros->setObjectName(QString::fromUtf8("actionMembros"));
        actionSobre = new QAction(MainWindow);
        actionSobre->setObjectName(QString::fromUtf8("actionSobre"));
        actionSair = new QAction(MainWindow);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 10, 91, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("MV Boli"));
        font.setPointSize(16);
        pushButton->setFont(font);
        btn_cadeado = new QPushButton(centralwidget);
        btn_cadeado->setObjectName(QString::fromUtf8("btn_cadeado"));
        btn_cadeado->setGeometry(QRect(10, 180, 18, 32));
        btn_cadeado->setIconSize(QSize(18, 32));
        btn_cadeado->setFlat(true);
        label_nome = new QLabel(centralwidget);
        label_nome->setObjectName(QString::fromUtf8("label_nome"));
        label_nome->setGeometry(QRect(50, 210, 151, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 454, 21));
        menuGest_o = new QMenu(menubar);
        menuGest_o->setObjectName(QString::fromUtf8("menuGest_o"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuGest_o->menuAction());
        menubar->addAction(menu->menuAction());
        menuGest_o->addAction(actionPets);
        menuGest_o->addAction(actionPets_adotados);
        menuGest_o->addAction(actionMembros);
        menu->addAction(actionSobre);
        menu->addSeparator();
        menu->addAction(actionSair);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionPets->setText(QApplication::translate("MainWindow", "Pets", nullptr));
        actionPets_adotados->setText(QApplication::translate("MainWindow", "Pets adotados", nullptr));
        actionMembros->setText(QApplication::translate("MainWindow", "Membros", nullptr));
        actionSobre->setText(QApplication::translate("MainWindow", "Sobre", nullptr));
        actionSair->setText(QApplication::translate("MainWindow", "Sair", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Ado\303\247\303\243o", nullptr));
        btn_cadeado->setText(QString());
        label_nome->setText(QApplication::translate("MainWindow", "Membro n\303\243o conectado", nullptr));
        menuGest_o->setTitle(QApplication::translate("MainWindow", "Gest\303\243o", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
