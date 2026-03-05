#include <iostream>
#include "funcionario.hh"

Funcionario::Funcionario(CPF cpf, std::string nome, float salario): Pessoa(cpf, nome), salario(salario){}

std::string Funcionario::get_nome(){
    return nome;
}   