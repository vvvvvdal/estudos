#include <bits/stdc++.h>
#include "forca.hh"

namespace fx_arquivos {
    vector<string> ler_arquivo(){
        ifstream arquivo; // variavel do tipo input file stream (arquivo de fluxo de entrada de dados)
        arquivo.open("palavras.txt");

        if(!arquivo.is_open()) {
            cout<<"erro na abertura do banco de palavras. encerrando programa..."<<endl;
            exit(0);
        }

        vector<string> palavras_arquivo;

        int qtd_palavras;
        arquivo>>qtd_palavras;

        for(int i=0;i<qtd_palavras;i++){
            string p;
            arquivo>>p;
            palavras_arquivo.push_back(p);
        }

        arquivo.close();

        return palavras_arquivo;
    }

    void salvar_arquivo(vector<string> palavras_arquivo) {
        ofstream arquivo; // variavel do tipo outpot file stream (arquivo de fluxo de saida de dados)
        arquivo.open("palavras.txt");

        if(!arquivo.is_open()) {
            cout<<"erro na abertura do banco de palavras. encerrando programa..."<<endl;
            exit(0);
        }

        arquivo<<palavras_arquivo.size()<<endl;

        for(string palav:palavras_arquivo) arquivo<<palav<<endl;

        arquivo.close();
    }
}
