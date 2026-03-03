#include <bits/stdc++.h>
#include "forca.hh"

using namespace fx_arquivos;
using namespace fx_verificar;

namespace fx_palavras {
    void sortear_palavra(vector<string> palavras_arquivo){
        int sorteado = rand()%palavras_arquivo.size();
        PALAVRA = palavras_arquivo[sorteado];
    }

    void nova_palavra(){
        vector<string> palavras_arquivo = ler_arquivo();
        string palav;

        cout<<"certo. digite a palavra que voce quer adicionar"<<endl;
        cout<<"palavra: "<<endl;
        cin>>palav;
        cout<<endl;

        for(int i=0;i<palav.size();i++) palav[i] = toupper(palav[i]);

        if(palavra_repetida(palav)) {
            cout<<"palavra ja existente no banco de dados. digite uma palavra diferente"<<endl;
            nova_palavra();
        }

        palavras_arquivo.push_back(palav);

        salvar_arquivo(palavras_arquivo);

        cout<<"palavra "<<palav<<" adicionada com sucesso ao banco de dados!";
        cout<<"encerrando programa..."<<endl;
        exit(0);
    }

    void adicionar_palavra(){
        char op;
        cout<<"voce deseja adicionar uma nova palavra ao banco de dados?"<<endl;
        cout<<"digite s para sim ou n para nao"<<endl;
        cout<<"sua opcao: ";
        cin>>op;
        op = tolower(op);
        cout<<endl;

        if(op == 's') {
            nova_palavra();
        } else if(op == 'n') {
            cout<<"certo. voce nao quer adicionar uma nova palavra"<<endl;
            cout<<"encerrando programa..."<<endl;
            exit(0);
        }

        cout<<"opcao incorreta. digite sua opcao novamente"<<endl;
        adicionar_palavra();
    }
}