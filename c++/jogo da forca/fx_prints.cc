#include <bits/stdc++.h>
#include "forca.hh"

using namespace fx_palavras;
using namespace fx_verificar;

namespace fx_prints { //namespace serve para delimitar o "grupo" que a função/variável/classe existe
    void print_forca(){
        for(char letra:PALAVRA) {
            if(chutou[letra]) cout<<letra<<" "; // se a letra existir na palavra, imprime ela
            else cout<<"_ ";
        }
        cout<<endl;
    }

    void print_errados(int tent){
        string palavra_tent = tent == 1 ? "tentativa":"tentativas";
        cout<<"("<<tent<<" "<<palavra_tent<<")"<<" chutes errados: ";
        for(char letra:errados) cout<<letra<<" ";
        cout<<endl<<endl;
    }

    void mensagem_final(){
        string palavra_erros = errados.size() == 1 ? "erro":"erros";

        if(nao_acertou()) cout<<"suas tentativas acabaram e voce perdeu :("<<endl;
        else cout<<"voce acertou com "<<errados.size()<<" "<<palavra_erros<<"!!"<<endl;
        cout<<"a palavra secreta era "<<PALAVRA<<endl;
        cout<<"fim de jogo!"<<endl<<endl;
        adicionar_palavra();
    }
}