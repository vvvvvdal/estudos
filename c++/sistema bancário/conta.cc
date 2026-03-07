#include <iostream>
#include "conta.hh"
#include "titular.hh"

int Conta::num_contas = 0;

int Conta::get_num_contas() {return num_contas;}

Conta::Conta(std::string id, Titular titular): id(id), titular(titular), saldo(0) { // método construtor
    num_contas++;
}

Conta::~Conta(){num_contas--;} // método destrutor

// Conta::função -> implementa a função como método da classe Conta
void Conta::sacar(float valor) {
    if(saldo<0){
        std::cout<<"conta vazia\n\n";
        return;
    }

    float saque = valor + (valor * taxa_saque()); // saque = valor + tarifa; tarifa = valor*porcentagem
    
    if(saldo<saque){
        std::cout<<"valor maior que o saldo\n\n";
        return;
    }
    
    if(saque<0){
        std::cout<<"valor de saque invalido\n\n";
        return;
    }

    saldo -= saque;
}

void Conta::depositar(float valor) {
    if(valor<0){
        std::cout<<"valor de deposito invalido\n\n";
        return;
    }

    saldo += valor;
}

void Conta::get_id() const{std::cout<<id<<std::endl;} // método const: é um método que não altera nada na classe.

float Conta::get_saldo() const {return saldo;}