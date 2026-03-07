#pragma once

#include <iostream>
#include "funcionario.hh"

class Caixa final: public Funcionario {
public:
    Caixa(CPF cpf, std::string nome, float salario);
    float bonificacao() const override;
};