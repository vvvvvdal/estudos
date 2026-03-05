#pragma once

#include <iostream>
#include "cpf.hh"

class Pessoa{
protected: // as classes herdeiras podem acessar os atributos privados com protected
    CPF cpf;
    std::string nome;
    void check_nome();
public:
    Pessoa(CPF cpf, std::string nome);
};