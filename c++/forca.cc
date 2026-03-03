#include <bits/stdc++.h>
#include "forca.hh"
using namespace std;

string PALAVRA;
map<char,bool>chutou; // dicionario com chave (indice) de char (letra) e valor de booleano
vector<char>errados; // vetor dinamico de char (letras)

int main() {
    srand(time(NULL));
    char chute;
    int tent = 5;
    vector<string> palavras_arquivo = ler_arquivo();

    sortear_palavra(palavras_arquivo);
    mensagem_inicial();

    while(nao_acertou() && nao_enforcou()){
        ler_chute(&chute);

        if(existe_palavra(chute)) chutou[chute] = true;
        else {
            if(!existe_errados(chute)) {
                errados.push_back(chute); // coloca o chute errado no final do vector
                tent--;
            }
        }

        print_errados(tent);
        print_forca();
    }

    mensagem_final();

    return 0;
}