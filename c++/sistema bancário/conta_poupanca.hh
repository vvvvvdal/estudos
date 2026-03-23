#pragma once

#include <iostream>
#include "conta.hh"

class Conta_poupanca: public Conta {
private:
public:
    Conta_poupanca(std::string id, Titular titular);
    float taxa_saque() const override;
};
