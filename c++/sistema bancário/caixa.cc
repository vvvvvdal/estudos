#include <iostream>
#include "caixa.hh"
using namespace std;

Caixa::Caixa(CPF cpf, string nome, float salario, Dia_semana dia_pagamento): Funcionario(cpf,nome,salario,dia_pagamento) {}

float Caixa::bonificacao() const {
    return salario * 0.10;
}