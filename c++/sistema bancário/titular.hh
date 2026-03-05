#pragma once

#include <iostream>
#include "cpf.hh"
#include "pessoa.hh"

class Titular: public Pessoa {
public:
    Titular(CPF cpf, std::string nome);
};
