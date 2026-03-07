#include <iostream>
#include "caixa.hh"
using namespace std;

Caixa::Caixa(CPF cpf, string nome, float salario): Funcionario(cpf,nome,salario) {}

float Caixa::bonificacao() const {
    return salario * 0.10;
}