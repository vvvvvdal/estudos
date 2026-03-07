#include <iostream>
#include "gerente.hh"
using namespace std;

Gerente::Gerente(CPF cpf, string nome, float salario, string senha): Funcionario(cpf,nome,salario), Autenticavel(senha) {}

float Gerente::bonificacao() const {
    return salario * 0.50;
}