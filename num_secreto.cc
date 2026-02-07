#include <bits/stdc++.h>
using namespace std;

void mensagem_introducao(){
    cout <<"************************************" << endl;
    cout <<"* bem-vindo ao jogo da adivinhacao *" << endl;
    cout <<"************************************" << endl;
}

void menu_dificuldade(int *max_tentativas){
    char dificuldade;

    cout<<"digite sua dificuldade:"<<endl;
    cout<<"digite f para facil(15 tentativas)"<<endl;
    cout<<"digite m para medio(10 tentativas)"<<endl;
    cout<<"digite d para dificil(5 tentativas)"<<endl;
    cout<<"dificuldade: ";
    cin>>dificuldade;
    cout<<endl;

    dificuldade = tolower(dificuldade); // se digitar maiusculo tambem funciona

    if(dificuldade == 'f') *max_tentativas = 15;
    else if (dificuldade == 'm') *max_tentativas = 10;
    else if (dificuldade == 'd') *max_tentativas = 5;
    else {
        cout<<"dificuldade/caracter incorreto"<<endl;
        cout<<"digite a dificuldade novamente"<<endl<<endl;
        menu_dificuldade(max_tentativas);
    }
}

void mensagem_final(bool acabou, double pontos, int tentativas){
    if(!acabou) {
        cout<<"qtd tentativas: "<<tentativas<<endl;
        cout.precision(2); // imprimir com 2 casas de precisão
        cout<<fixed; // virgula fixa, se nao fica em notação científica.
        cout<<"pontos: "<<pontos<<endl;
    }

    cout<<"fim de jogo!"<<endl;
}

int main() {
    srand(time(NULL));
    const int NUM = rand()%100;
    int chute, tentativas = 1, max_tentativas;
    bool acertou = false, acabou = false;
    double pontos = 1000.0;

    mensagem_introducao();
    menu_dificuldade(&max_tentativas);

    while(!acertou) {
        if(tentativas > max_tentativas) {
            acabou = true;
            cout<<"suas tentativas acabaram!"<<endl;
            cout<<"o num era "<<NUM<<endl;
            break;
        }

        cout<<"tentativa "<<tentativas<<":"<<endl;
        cout << "qual seu chute? ";
        cin >> chute;
        cout<<endl;

        double pontos_perdidos = abs(chute-NUM)/2.0;
        pontos -= pontos_perdidos;
        
        acertou = chute == NUM;
        bool maior = chute > NUM;
        bool menor = chute < NUM;

        if(acertou) {
            cout <<"acertou!"<< endl;
            break;
        }
        else if(maior) cout <<"o chute foi maior"<< endl;
        else if (menor) cout <<"o chute foi menor"<< endl;

        tentativas++;
        cout << endl;
    }

    mensagem_final(acabou, pontos, tentativas);
    
    return 0;
}