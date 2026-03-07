#pragma once

#include <iostream>
#include "conta.hh"

class Conta_poupanca: public Conta {
private:
public:
    Conta_poupanca(std::string id, Titular titular);
    ~Conta_poupanca();
    float taxa_saque() const override;
};
