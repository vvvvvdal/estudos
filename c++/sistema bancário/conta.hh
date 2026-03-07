#pragma once

#include <iostream>
#include "titular.hh"

class Conta {
private: // atributos
    std::string id;
    Titular titular;
    float saldo;
    static int num_contas; // em classes, static significa algo que é referente a toda a classe, e não só a um objeto específico
public: // métodos
    Conta() = delete; // o construtor padrão dessa classe é removido, para poder utilizar o meu próprio (linha não obrigatória)
    Conta(std::string id, Titular titular);
    ~Conta();
    static int get_num_contas();
    // virtual: esse método PODE ser sobrescrito por um método de mesmo nome em classes herdeiras (override).
    virtual float taxa_saque() const = 0; // 0 diz que é um método puramente virtual nessa classe e que ele so sera implementado na herdeira.

    void sacar(float valor);
    void depositar(float valor);
    void get_id() const;
    float get_saldo() const;
};