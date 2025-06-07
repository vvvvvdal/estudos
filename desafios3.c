#include <stdio.h>
#include <string.h>

// Escreva uma função potencia() que receba dois inteiros, c e d, calcule a potência c^d, ou seja, c elevado a d e imprima o resultado.
    void potencia(int c, int d) {
        int pot = 1;

        printf("digite o c: ");
        scanf("%d", &c);

        printf("\ndigite o d: ");
        scanf("%d", &d);

        for(int j = 0; j < d; j++) {
            pot *= c;
        }
        printf("\n%d elevado a %d = %d\n\n", c, d, pot);
    }



// Escreva uma função soma(int numeros[10]) que receba um array de inteiros e imprime a soma de todos os elementos dentro desse array.
    void soma(int numeros[10]) {
        int resultado = 0;

        for(int m = 0; m < 10; m++) {
            resultado += numeros[m];
        }
        printf("\nresultado da soma de 0 até 9: %d\n\n", resultado);
    }



// Escreva uma função somma que recebe um ponteiro de inteiro num e mais dois inteiros m e m. A função deve calcular a soma de m+n em num.
void somma(int* num2, int* m2, int* n2) {
    (*num2) = (*m2) + (*n2);
}



// Escreva a mesma função de potencia que você fez na aula anterior, só que dessa vez, o resultado deve ser salvo em um inteiro que vem na
// lista de parâmetros da função. Para isso, claro, você precisará receber um ponteiro de inteiro:
void potenciaaa(int* resultado2, int e, int f) {
    (*resultado2) = 1;

    for(int k = 0; k < f; k++) {
        (*resultado2) *= e;
    }
    printf("%d elevado a %d = %d\n\n", e, f, (*resultado2));
}


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
    printf("o resultado da multiplicacao entre %d e %d: %d\n\n", varX, varY, resposta);



// Escreva um programa que peça um inteiro ao usuário, e com esse inteiro, ele imprima, linha-a-linha, a tabuada daquele número até o 10.
// Por exemplo, se ele escolher o número 2, o programa imprimirá: 2x1=2, 2x2=4, 2x3=6, ..., 2x10=20.
    int a;
    int i;
    printf("digite seu numero escolhido para fazer a tabuada\n");
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
    printf("\ndigite seu numero escolhido para calcular fatorial\n");
    scanf("%d", &b);
    printf("seu numero escolhido foi %d\n\n", b);
    for(c = 1 ; c <= b ; c++) {
        fatorial *= c; // fatorial = fatorial * c
    }
    printf("fatorial de %d: %d\n\n", b, fatorial);
    


// Veja o array de inteiros abaixo. Como fazer para imprimir todos os elementos dele?
    int notas[5];
    notas[0] = 1;
    notas[1] = 4;
    notas[2] = 7;
    notas[3] = 5;
    notas[4] = 10;

    for(i = 0; i < 5; i++) {
        printf("no lugar %d tem a nota %d\n",i , notas[i]);

    }
    printf("\n");


    

// Escreva uma função potencia() que receba dois inteiros, c e d, calcule a potência c^d, ou seja, c elevado a d e imprima o resultado.
    potencia(0, 0);



// Escreva uma função soma(int numeros[10]) que receba um array de inteiros e imprime a soma de todos os elementos dentro desse array.
    int numerosDaSoma[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    soma(numerosDaSoma);



// Escreva uma função somma que recebe um ponteiro de inteiro num e mais dois inteiros m e n. A função deve calcular a soma de m+n em num.
    int m;
    int n;

    printf("digite o m: ");
    scanf("%d", &m );

    printf("\ndigite o n: ");
    scanf("%d", &n);

    int num;
    
    somma(&num, &m, &n);
    printf("%d + %d = %d\n\n", m, n, num);



// Escreva a mesma função de potencia que você fez na aula anterior, só que dessa vez, o resultado deve ser salvo em um inteiro que vem na
// lista de parâmetros da função. Para isso, claro, você precisará receber um ponteiro de inteiro:
    int resultado;
    potenciaaa(&resultado, 2, 3);

return 0;
}
