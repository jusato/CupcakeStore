/********************************************************************************
** Form generated from reading UI file 'gestaomembros.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTAOMEMBROS_H
#define UI_GESTAOMEMBROS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_gestaoMembros
{
public:

    void setupUi(QDialog *gestaoMembros)
    {
        if (gestaoMembros->objectName().isEmpty())
            gestaoMembros->setObjectName(QString::fromUtf8("gestaoMembros"));
        gestaoMembros->resize(400, 300);

        retranslateUi(gestaoMembros);

        QMetaObject::connectSlotsByName(gestaoMembros);
    } // setupUi

    void retranslateUi(QDialog *gestaoMembros)
    {
        gestaoMembros->setWindowTitle(QApplication::translate("gestaoMembros", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gestaoMembros: public Ui_gestaoMembros {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTAOMEMBROS_H
