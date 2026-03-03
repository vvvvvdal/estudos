#pragma once

#include <bits/stdc++.h>
using namespace std;

extern string PALAVRA;
extern map<char,bool>chutou;
extern vector<char>errados;

namespace fx_prints {
    void print_forca();
    void print_errados(int tent);

    inline void mensagem_inicial() { // inline: "compilador, se voce achar que é bom, copie essa função para onde ela está sendo usada no main" 
        cout<<"******************************"<<endl;
        cout<<"* bem vindo ao jogo da forca *"<<endl;
        cout<<"******************************"<<endl;
        print_forca();
    }

    void mensagem_final();
}