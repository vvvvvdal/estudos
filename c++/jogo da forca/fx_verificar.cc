#include <bits/stdc++.h>
#include "forca.hh"

using namespace fx_prints;
using namespace fx_arquivos;

namespace fx_verificar {
    void ler_chute(char *chute){

        cout<<"digite seu chute: ";
        cin>>chute;
        cout<<endl;

        if(isalpha(*chute)) { // se for letra
            *chute = toupper(*chute);
            return;
        }

        // se nao for letra
        cout<<"o caracter digitado nao foi uma letra. tente novamente"<<endl;
        print_forca();
        
        ler_chute(chute);
    }

    bool existe_palavra(char chute) {
        for(char letra:PALAVRA) if(chute == letra) return true;
        return false;
    }

    bool existe_errados(char chute) {
        for(char letra:errados) if(chute == letra) return true;

        return false;
    }

    bool nao_acertou() {
        for(char letra:PALAVRA) if(chutou[letra] == false) return true;

        return false;
    }

    bool nao_enforcou() {
        return errados.size() < 5; // 5 tentativas
    }

    bool palavra_repetida(string pal) {
        vector<string> palavras_arquivo = ler_arquivo(); 
        for(string p:palavras_arquivo) if(pal == p) return true;

        return false;
    }
}