#pragma once

#include <iostream>
#include <utility>
#include "titular.hh"

class Conta {
private: // atributos
    std::string id;
    Titular titular;
    float saldo;
    static int num_contas; // em classes, static significa algo que é referente a toda a classe, e não só a um objeto específico
public: // métodos
    enum resultado_saque: short int{
        sucesso, valor_negativo, saldo_insuficiente
    };

    Conta() = delete; // o construtor padrão dessa classe é removido, para poder utilizar o meu próprio (linha não obrigatória)
    Conta(std::string id, Titular titular);
    ~Conta();
    static int get_num_contas();
    // virtual: esse método PODE ser sobrescrito por um método de mesmo nome em classes herdeiras (override).
    virtual float taxa_saque() const = 0; // 0 diz que é um método puramente virtual nessa classe e que ele so sera implementado na herdeira.

    std::variant<resultado_saque,float> sacar(float valor);
    void depositar(float valor);
    void operator+=(float valor); // mesma coisa que depositar
    void get_id() const;
    float get_saldo() const;

    friend std::ostream& operator<<(std::ostream& cout, const Conta& conta); // friend: função que existe fora da classe que tem acesso aos atributos privados
    // útil quando vc quer usar uma função já existente que precisa de acesso de privados/protegidos
    
    bool operator<(const Conta &outra);
};