#ifndef CONEXAO_H
#define CONEXAO_H

#include <QtSql>

//Essa classe vai fazer a conexão com o banco de dados
class Conexao {
public:
    QSqlDatabase bancoDeDados;
    QString local;
    QString banco;

    Conexao() {
        local = qApp->applicationDirPath(); //string que vai conter o caminho da aplicação
        banco = local + "/db/CupcakeStore.db";
        bancoDeDados = QSqlDatabase::addDatabase("QSQLITE"); //Adicionando o tipo que usei
    }
    void fechar() {
        bancoDeDados.close();
    }
    bool abrir() {

        //bancoDeDados.setDatabaseName("C:/Users/satoj/Documents/T3_Cupcake_Store/CupcakeStore/db/Cupcake_Store.db");
        bancoDeDados.setDatabaseName(banco);

        if(!bancoDeDados.open()) {
            return false;
        } else {
            return true;
        }
    }
    bool aberto() {
        if(!bancoDeDados.isOpen()) {
            return true;
        } else {
            return false;
        }
    }
};

#endif // CONEXAO_H
