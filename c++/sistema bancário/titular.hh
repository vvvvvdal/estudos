#pragma once

#include <bits/stdc++.h>

class Titular {
private:
    std::string cpf, nome;
    float saldo;

public:
    Titular(std::string cpf, std::string nome);
    void get_cpf();
    void get_nome();
    
private:
    void check_nome();
};