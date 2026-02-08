#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "foge.h"
#include "mapa.h"
#include "ui.h"

Mapa mapa;
Posicao heroi;
int tem_pilula = 0;

int direcao_fantasma(int x_atual, int y_atual, int *x, int *y) {
    int opcoes[4][2] = {
        {x_atual, y_atual+1},
        {x_atual+1, y_atual},
        {x_atual, y_atual-1},
        {x_atual-1, y_atual}
    };

    for(int i = 0; i < 10; i++){
        int pos = rand() % 4;
        
        if(verificar_limites(opcoes[pos][0], opcoes[pos][1], &mapa) && 
           !verificar_parede(opcoes[pos][0], opcoes[pos][1])) {
            *x = opcoes[pos][0];
            *y = opcoes[pos][1];
            return 1;
        }
    }

    return 0;
}

void fantasmas(Mapa *mapa){
    int x, y;
    
    for(int i = 0; i < mapa->linhas; i++){
        for(int j = mapa->colunas-1; j >= 0; j--){
            if(mapa->m[i][j] == FANTASMA) {
                if(direcao_fantasma(i, j, &x, &y)) {
                    if(mapa->m[x][y] != FANTASMA) {
                        mapa->m[x][y] = FANTASMA; 
                        mapa->m[i][j] = VAZIO;
                    }
                }
            }
        }
    }
}

void explodir_pilula2(int x, int y, int soma_x, int soma_y, int qtd) {
    if(qtd == 0) return;

    int novo_x = x + soma_x;
    int novo_y = y + soma_y;

    if(!verificar_limites(novo_x, novo_y, &mapa)) return;
    if(verificar_parede(novo_x, novo_y)) return;

    mapa.m[novo_x][novo_y] = VAZIO;
    explodir_pilula2(novo_x, novo_y, soma_x, soma_y, qtd-1);
}

void explodir_pilula() {
    if(!tem_pilula) return;

    explodir_pilula2(heroi.x, heroi.y, 0, 1, 3);
    explodir_pilula2(heroi.x, heroi.y, 0, -1, 3);
    explodir_pilula2(heroi.x, heroi.y, 1, 0, 3);
    explodir_pilula2(heroi.x, heroi.y, -1, 0, 3);

    tem_pilula = 0;
}

int acabou(){
    Posicao pos;

    int perdeu = !encontrar_mapa(&mapa, &pos, HEROI);
    int ganhou = !encontrar_mapa(&mapa, &pos, FANTASMA);
    
    return ganhou || perdeu;
}

int verificar_parede(int x, int y) {
    return (mapa.m[x][y] == PAREDE_VERTICAL || mapa.m[x][y] == PAREDE_HORIZONTAL);
}

void mover(char direcao) {
    int x = heroi.x, y = heroi.y;

    switch(tolower(direcao)) {
        case ESQUERDA: y--; break;
        case CIMA: x--; break;
        case BAIXO: x++; break;
        case DIREITA: y++; break;
        default: return;
    }

    if(!verificar_limites(x, y, &mapa)) return;
    if(verificar_parede(x, y)) return;

    if(mapa.m[x][y] == PILULA) {
        tem_pilula = 1;
    }

    mapa.m[heroi.x][heroi.y] = VAZIO;
    heroi.x = x;
    heroi.y = y;
    mapa.m[heroi.x][heroi.y] = HEROI;
}

int main() {
    srand(time(NULL));

    ler_mapa(&mapa);
    encontrar_mapa(&mapa, &heroi, HEROI);

    do {
        printf("Tem pilula: %s\n", (tem_pilula ? "SIM" : "NAO"));
        imprimir_mapa(&mapa);

        char comando;
        scanf(" %c", &comando);

        if(comando == BOMBA) {
            explodir_pilula();
        } else {
            mover(comando);
        }
        
        fantasmas(&mapa);

    } while(!acabou());

    liberar_mapa(&mapa);
}