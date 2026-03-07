#pragma once

#include <iostream>
#include "conta.hh"

class Conta_corrente: public Conta {
private:
public:
    Conta_corrente(std::string id, Titular titular);
    float taxa_saque() const override;
    void transferencia(Conta &conta, float valor);
};
