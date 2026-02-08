#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

int encontrar_mapa(Mapa *mapa, Posicao *p, char c) {
    for(int i=0;i<mapa->linhas;i++){
        for(int j=0;j<mapa->colunas;j++){
            if(mapa->m[i][j] == c) {
                p->x=i;
                p->y=j;
                return 1;
            }
        }
    }
    return 0;
}

int verificar_limites(int x, int y, Mapa *mapa) {
    if(x >= mapa->linhas || y >= mapa->colunas || x < 0 || y < 0) 
        return 0;
    return 1;   
}

void ler_mapa(Mapa *mapa) {
    FILE* f;
    f = fopen("mapa.txt", "r");
    if(f == 0) {
        printf("Erro na leitura do mapa");
        exit(1);
    }

    fscanf(f, "%d %d", &(mapa->linhas), &(mapa->colunas));
    alocar_mapa(mapa);
    
    for(int i = 0; i < mapa->linhas; i++) {
        fscanf(f, "%s", mapa->m[i]);
    }

    fclose(f);
}

void alocar_mapa(Mapa *mapa) {
    mapa->m = (char**) malloc(sizeof(char*) * mapa->linhas);

    for(int i = 0; i < mapa->linhas; i++) {
        mapa->m[i] = (char*) malloc(sizeof(char) * (mapa->colunas + 1));
    }
}

void liberar_mapa(Mapa *mapa) {
    for(int i = 0; i < mapa->linhas; i++) {
        free(mapa->m[i]);
    }
    free(mapa->m);
}