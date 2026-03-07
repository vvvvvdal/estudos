#include <iostream>
#include "autenticavel.hh"

using namespace std;

Autenticavel::Autenticavel(string senha): senha(senha) {}

bool Autenticavel::autentica(string teste) const {
    return teste == senha;
}

void Autenticavel::login(string teste) const{
    if(autentica(teste)) cout<<"login realizado com sucesso"<<endl;
    else cout<<"senha invalida"<<endl;
}
