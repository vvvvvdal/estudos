#pragma once

#include <iostream>
#include "titular.hh"

class Conta {
private:
    static int num_contas; // em classes, static significa algo que é referente a toda a classe, e não só a um objeto específico

public:
    static int get_num_contas();

private: // atributos
    std::string id;
    Titular titular;
    float saldo;

public: // métodos
    Conta() = delete; // o construtor padrão dessa classe é removido, para poder utilizar o meu próprio (linha não obrigatória)
    Conta(std::string id, Titular titular);
    ~Conta();

    void sacar(float valor);
    void depositar(float valor);
    void get_id() const;
    float get_saldo() const;
};