#include <iostream>
#include "cpf.hh"

CPF::CPF(std::string s_cpf): s_cpf(s_cpf) {
    if(!check_cpf()){
        std::cout<<"cpf invalido"<<std::endl;
        exit(1);
    }
}

bool CPF::check_cpf() {

    if (s_cpf.size() != 11) {
        return false;
    }

    bool iguais = true;
    for (int i = 1; i < 11; i++) {
        if (s_cpf[i] != s_cpf[0]) {
            iguais = false;
            break;
        }
    }
    if (iguais) return false;

    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (s_cpf[i] - '0') * (10 - i);
    }
    int resto = soma % 11;
    int digito1 = (resto < 2) ? 0 : 11 - resto;

    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (s_cpf[i] - '0') * (11 - i);
    }
    resto = soma % 11;
    int digito2 = (resto < 2) ? 0 : 11 - resto;

    return (digito1 == (s_cpf[9] - '0') && digito2 == (s_cpf[10] - '0'));
}


void CPF::get_cpf() {
    std::cout<<s_cpf<<std::endl;
}
