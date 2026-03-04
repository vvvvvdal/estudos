#include <bits/stdc++.h>
#include "conta.hh"

using namespace std;

int Conta::num_contas = 0;

int Conta::get_num_contas() {return num_contas;}

Conta::Conta(string id, string cpf, string nome): id(id), cpf(cpf), nome(nome), saldo(0){num_contas++;} // método construtor

Conta::~Conta(){num_contas--;} // método destrutor

// Conta::função -> implementa a função como método da classe Conta
void Conta::sacar(float valor) {
    if(saldo<0){
        cout<<"conta vazia\n\n";
        return;
    } else if(saldo<valor){
        cout<<"valor maior que o saldo\n\n";
        return;
    } else if(valor<0){
        cout<<"valor de saque invalido\n\n";
        return;
    }

    saldo -= valor;
}

void Conta::depositar(float valor) {
    if(valor<0){
        cout<<"valor de deposito invalido\n\n";
        return;
    }

    saldo += valor;
}

void Conta::get_id() const{cout<<id<<endl;} // método const: é um método que não altera nada na classe.

void Conta::get_cpf() const{cout<<cpf<<endl;}

void Conta::get_nome() const{cout<<nome<<endl;}

float Conta::get_saldo() const {return saldo;}