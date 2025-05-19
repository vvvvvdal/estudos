#include <stdio.h>

int main() {

// Escreva um programa que peça para o usuário digitar duas variáveis inteiras (x e y) e
// imprima o resultado da multiplicação entre essas duas variáveis.
    int varX;
    int varY;

    printf("digite a variavel x\n");
    scanf("%d", &varX);
    printf("digite a variavel y\n");
    scanf("%d", &varY);

    int resposta = varX * varY;
    printf("o resultado da multiplicacao entre %d e %d: %d", varX, varY, resposta);








// Escreva um programa que peça um inteiro ao usuário, e com esse inteiro, ele imprima, linha-a-linha, a tabuada daquele número até o 10.
// Por exemplo, se ele escolher o número 2, o programa imprimirá: 2x1=2, 2x2=4, 2x3=6, ..., 2x10=20.
    int a;
    int i;
    printf("digite seu numero escolhido\n");
    scanf("%d", &a);
    printf("seu numero escolhido foi %d\n\n", a);
    for(i = 1 ; i <= 20 ; i++) {
    int resultado = a * i;
    printf("%d * %d = %d\n", a, i, resultado);
    }


// Faça uma calculadora do fatorial de um número
    int b;
    int c;
    int fatorial = 1;
    printf("digite seu numero escolhido para calcular fatorial\n");
    scanf("%d", &b);
    printf("seu numero escolhido foi %d\n\n", b);
    for(c = 1 ; c <= b ; c++) {
        fatorial *= c; // fatorial = fatorial * c
    }
    printf("fatorial de %d: %d", b, fatorial);
    
    return 0;
}






