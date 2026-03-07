#pragma once

#include <iostream>
#include "funcionario.hh"
#include "autenticavel.hh"

class Gerente final: public Funcionario, public Autenticavel { // final: nenhuma classe pode herdar as características dessa classe
public:
    Gerente(CPF cpf, std::string nome, float salario, std::string senha);
    float bonificacao() const override;
};