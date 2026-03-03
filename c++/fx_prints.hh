#pragma once

#include <bits/stdc++.h>
using namespace std;

void print_forca();
void print_errados(int tent);

inline void mensagem_inicial() { // inline: "compilador, se voce achar que é bom, copie essa função para onde ela está sendo usada no main" 
    cout<<"******************************"<<endl;
    cout<<"* bem vindo ao jogo da forca *"<<endl;
    cout<<"******************************"<<endl;
    print_forca();
}

void mensagem_final();
