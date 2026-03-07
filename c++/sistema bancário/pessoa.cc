#include <iostream>
#include "pessoa.hh"
using namespace std;

Pessoa::Pessoa(CPF cpf, string nome): cpf(cpf), nome(nome){
    std::cout<<"construtor de pessoa"<<std::endl;
}

void Pessoa::check_nome() {
    if(nome.size() < 5) {
        cout<<"nome muito pequeno"<<endl;
        exit(1);
    }
}