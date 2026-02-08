#ifndef MAPA_H
#define MAPA_H

#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define PILULA 'P'

typedef struct {
    char **m;
    int linhas;
    int colunas;
} Mapa;

typedef struct {
    int x,y;
} Posicao;

void fantasmas(Mapa *mapa);
int verificar_parede(int x, int y);
int verificar_limites(int x, int y, Mapa *mapa);
int encontrar_mapa(Mapa *mapa, Posicao *p, char c);
void alocar_mapa(Mapa *mapa);
void ler_mapa(Mapa *mapa);
void liberar_mapa(Mapa *mapa);

#endif