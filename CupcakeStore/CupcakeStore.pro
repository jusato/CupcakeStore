QT       += core gui sql #colocando sql so p salvar as funcionalidades do banco de dados

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Compras.cpp \
    InfoProdutos.cpp \
    Login.cpp \
    Membros.cpp \
    main.cpp \
    mainwindow.cpp \
    produtos_editarqtde.cpp \
    sobreapp.cpp

HEADERS += \
    Compras.h \
    Conexao.h \
    InfoMembros.h \
    InfoProdutos.h \
    Login.h \
    Membros.h \
    mainwindow.h \
    produtos_editarqtde.h \
    sobreapp.h

FORMS += \
    Compras.ui \
    InfoProdutos.ui \
    Login.ui \
    Membros.ui \
    mainwindow.ui \
    produtos_editarqtde.ui \
    sobreapp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursoss.qrc
