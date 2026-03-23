#pragma once

#include <iostream>
#include "cpf.hh"
#include "pessoa.hh"
#include "dia_semana.hh"

class Funcionario: public Pessoa { // herança: funcionário é uma pessoa. funcionário recebe todos os atributos e métodos da classe pessoa.
protected:
    float salario;
    Dia_semana dia_pagamento;
public:
    Funcionario(CPF cpf, std::string nome, float salario, Dia_semana dia_pagamento);
    std::string get_nome();
    virtual float bonificacao() const = 0;
};