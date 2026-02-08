#ifndef FOGE_H
#define FOGE_H

#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define BOMBA 'b'

int acabou();
void mover(char direcao);
void explodir_pilula();
void explodir_pilula2(int x, int y, int soma_x, int soma_y, int qtd);

#endif