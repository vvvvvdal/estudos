#pragma once

#include <iostream>
#include "cpf.hh"
#include "pessoa.hh"

class Funcionario: public Pessoa { // herança: funcionário é uma pessoa. funcionário recebe todos os atributos e métodos da classe pessoa.
private:
    float salario;
public:
    Funcionario(CPF cpf, std::string nome, float salario);
    std::string get_nome();
};