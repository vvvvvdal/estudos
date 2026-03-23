#include <iostream>
#include "funcionario.hh"

Funcionario::Funcionario(CPF cpf, std::string nome, float salario, Dia_semana dia_pagamento): Pessoa(cpf, nome), salario(salario), dia_pagamento(dia_pagamento){
    std::cout<<"construtor de funcionario"<<std::endl;
}

std::string Funcionario::get_nome(){
    return nome;
}