#include <iostream>
#include "conta_poupanca.hh"

Conta_poupanca::Conta_poupanca(std::string id, Titular titular): Conta(id,titular){
}

Conta_poupanca::~Conta_poupanca(){}

float Conta_poupanca::taxa_saque() const {
    return 0.03;
}


