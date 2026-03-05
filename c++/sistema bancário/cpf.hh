#pragma once

#include <bits/stdc++.h>

class CPF {
private:
    std::string s_cpf;
    bool check_cpf();

public:
    explicit CPF(std::string s_cpf); // explicit antes do construtor obriga que, no uso do objeto, seja passado o objeto CPF() com uma string dentro.
    void get_cpf();                  // sem o explicit, poderia passar uma string no lugar de CPF(), já que o compilador faz a conversão implícita
};