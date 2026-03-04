#pragma once

#include <bits/stdc++.h>

class Conta {
private:
    static int num_contas; // em classes, static significa algo que é referente a toda a classe, e não só a um objeto específico

public:
    static int get_num_contas();

private: // atributos
    std::string id, cpf, nome;
    float saldo;

public: // métodos
    Conta() = delete; // o construtor padrão dessa classe é removido, para poder utilizar o meu próprio (linha não obrigatória)
    Conta(std::string id, std::string cpf, std::string nome);
    ~Conta();

    void sacar(float valor);
    void depositar(float valor);
    void get_id() const;
    void get_cpf() const;
    void get_nome() const ;
    float get_saldo() const;
};