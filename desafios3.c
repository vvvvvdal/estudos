// Escreva um programa que peça para o usuário digitar duas variáveis inteiras (x e y) e
// imprima o resultado da multiplicação entre essas duas variáveis.

#include <stdio.h>

int main() {
    int varX;
    int varY;

    printf("digite a variavel x\n");
    scanf("%d", &varX);
    printf("digite a variavel y\n");
    scanf("%d", &varY);

    int resposta = varX * varY;
    printf("o resultado da multiplicacao entre %d e %d: %d", varX, varY, resposta);

    return 0;
}

