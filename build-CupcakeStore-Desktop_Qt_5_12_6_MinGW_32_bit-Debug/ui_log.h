/********************************************************************************
** Form generated from reading UI file 'log.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Log
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *txt_username;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *txt_senha;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_entrar;
    QPushButton *btn_cancelar;

    void setupUi(QDialog *Log)
    {
        if (Log->objectName().isEmpty())
            Log->setObjectName(QString::fromUtf8("Log"));
        Log->resize(400, 300);
        widget = new QWidget(Log);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 50, 241, 191));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        txt_username = new QLineEdit(widget);
        txt_username->setObjectName(QString::fromUtf8("txt_username"));

        horizontalLayout_2->addWidget(txt_username);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        txt_senha = new QLineEdit(widget);
        txt_senha->setObjectName(QString::fromUtf8("txt_senha"));
        txt_senha->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(txt_senha);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_entrar = new QPushButton(widget);
        btn_entrar->setObjectName(QString::fromUtf8("btn_entrar"));

        horizontalLayout->addWidget(btn_entrar);

        btn_cancelar = new QPushButton(widget);
        btn_cancelar->setObjectName(QString::fromUtf8("btn_cancelar"));

        horizontalLayout->addWidget(btn_cancelar);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Log);

        QMetaObject::connectSlotsByName(Log);
    } // setupUi

    void retranslateUi(QDialog *Log)
    {
        Log->setWindowTitle(QApplication::translate("Log", "Dialog", nullptr));
        label->setText(QApplication::translate("Log", "Username", nullptr));
        label_2->setText(QApplication::translate("Log", "Senha      ", nullptr));
        btn_entrar->setText(QApplication::translate("Log", "Entrar", nullptr));
        btn_cancelar->setText(QApplication::translate("Log", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Log: public Ui_Log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
