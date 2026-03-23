#include <iostream>
#include "gerente.hh"
using namespace std;

Gerente::Gerente(CPF cpf, string nome, float salario, Dia_semana dia_pagamento, string senha): Funcionario(cpf,nome,salario,dia_pagamento), Autenticavel(senha) {}

float Gerente::bonificacao() const {
    return salario * 0.50;
}