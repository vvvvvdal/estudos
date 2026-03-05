#pragma once

#include <bits/stdc++.h>
#include "cpf.hh"

class Titular {
private:
    CPF cpf;
    std::string nome;
    float saldo;

public:
    Titular(CPF cpf, std::string nome);
    void get_nome();
    
private:
    void check_nome();
};
