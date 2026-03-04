#include <bits/stdc++.h>
#include "titular.hh"

using namespace std;

Titular::Titular(string cpf,string nome): cpf(cpf), nome(nome){
    check_nome();
}

void Titular::check_nome() {
    if(nome.size() < 5) {
        cout<<"nome muito pequeno"<<endl;
        exit(1);
    }
}

void Titular::get_cpf() {
    cout<<cpf<<endl;
}

void Titular::get_nome() {
    cout<<nome<<endl;
}
