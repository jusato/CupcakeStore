#ifndef INFOMEMBROS_H
#define INFOMEMBROS_H

#include <QString>

class InfoMembros { //Classe auxiliar com as informções de um membro para utilização do arquivo binário
public:
    QString nome, celular, username, senha;
    InfoMembros() {}
    InfoMembros(QString nome, QString celular, QString username, QString senha) : nome(nome),
        celular(celular), username(username), senha(senha) {}
    ~InfoMembros() {}

};

#endif // INFOMEMBROS_H
