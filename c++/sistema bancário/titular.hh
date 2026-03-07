#pragma once

#include <iostream>
#include "cpf.hh"
#include "pessoa.hh"
#include "autenticavel.hh"

class Titular: public Pessoa, public Autenticavel {
public:
    Titular(CPF cpf, std::string nome, std::string senha);
};
