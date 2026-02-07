#include <stdio.h>             // biblioteca padrão de escrita e leitura, entrada e saída (io = input, output = entrada, saída)
                               // standard input output header = cabeçalho padrão de entrada e saída
#include <stdlib.h>            // biblioteca padrão que contém a função abs()

#include <time.h>              // biblioteca para utilizar a função time()

// int retorna um valor inteiro, para verificar se o código está sendo executado de maneira correta ou se existe algum erro
int main() {                                  // main é a função principal de um programa em C. o código deve estar dentro dessa função para ser executado.
                                              // '\n' = tecla ENTER (separa as linhas: oq estiver depois do '\n aparece na linha de baixo) 
    printf(".-----------------------------.\n"); // imprime o cabeçalho do jogo
    printf("|                             |\n");
    printf("| .-------------------------. |\n");
    printf("| | Bem Vindo ao            | |\n");
    printf("| |         Jogo do         | |\n");
    printf("| |. . . . . . . . . . . . .| |\n");
    printf("| |      Numero Secreto     | |\n");
    printf("| |                         | |\n");
    printf("| '-------------------------' |\n");
    printf("| [Y=][WIN][ZOOM][TRACE][GRH] |\n");
    printf("|                  _ [ ^ ] _  |\n");
    printf("| [2nd][MODE][DEL]|_|     |_| |\n");
    printf("| [ALP][XTO][STAT]   [ V ]    |\n");
    printf("| [MATH][MAT][PGM][VARS][CLR] |\n");
    printf("| [x-1] [SIN] [COS] [TAN] [^] |\n");
    printf("|  [x2][ , ][ ( ][ ) ][ / ]   |\n");
    printf("| [LOG][ 7 ][ 8 ][ 9 ] [ X ]  |\n");
    printf("| [LN ][ 4 ][ 5 ][ 6 ] [ - ]  |\n");
    printf("| [STO>][ 1 ][ 2 ][ 3 ][ + ]  |\n");
    printf("| [ON][ 0 ][ . ][ (-) ][ENTR] |\n");
    printf("| ----                        |\n");
    printf("'-----------------------------'\n\n");

    int segundos = time(0); // função time(0) retorna o número de segundos passados de 01/01/1970 até agora
    srand(segundos);        // função srand() usa o valor retornado por time(0) como 'semente' para gerar um número pseudoaleatório
                            // diferente toda vez que o programa é inicializado ('s' antes do 'rand' -> seed = semente)

    int numeroGerado = rand();             // int declara uma variável que armazena um número inteiro
    int numeroSecreto = numeroGerado % 16; // o operador '%' retorna o resto da divisão entre dois números inteiros
                                           // o resto da divisão por '16' resultará em valores entre 1 e 15
                            // o '%' serve para imprimir variáveis que são números inteiros, ele será substituido
                            // pelo valor do número inteiro da variável numeroSecreto, que é 21
    
    int chute;
    double pontosIniciais = 100;

    int dificuldade;


    int tentativas = 1;
    int tentativasMax;
    const char* palavraTentativa; // tentativas > 1 -> aparece 'tentativas', caso contrário, aparece 'tentativa'


    while(1) { // enquanto for verdadeiro (1)
        printf("qual o nivel de dificuldade?\n");
        printf("digite 1 para facil (com 7 tentativas)\ndigite 2 para medio (com 5 tentativas)\ndigite 3 para dificil (com 3 tentativas)\ndigite 4 para impossivel (com 1 tentativa)\n\n");
        printf("escolha sua dificuldade: ");

        if(scanf("%d", &dificuldade) != 1 || dificuldade <= 0 || dificuldade > 4) {
             printf("a dificuldade deve ser um numero inteiro de 1 a 4\n\n");
             while (getchar() != '\n');
             continue;
        }
    
        switch(dificuldade) { // o break é necessário em cada caso pq se ele não existir o switch continua executando todos os casos até chegar no último
            case 1: 
                tentativasMax = 6;
                break;

            case 2: 
                tentativasMax = 4;
                break;

            case 3: 
                tentativasMax = 2;
                break;

            case 4: 
                tentativasMax = 0;
                break;
        }

        int totalTentativas = tentativas + tentativasMax;
        palavraTentativa = (totalTentativas > 1) ? "tentativas" : "tentativa";
        printf("sua dificuldade escolhida foi %d e voce vai ter %d %s\n\n", dificuldade, totalTentativas, palavraTentativa);
        break;
    }


    //printf("qual o seu chute?");
    //scanf("%d", &chute);        // função scanf() exibe a resposta do usuário; é necessário colocar o '&' antes da variável.
    //printf("o seu chute foi %d", chute);

    while(chute != numeroSecreto) {
        printf("numero secreto: um numero inteiro entre 1 e 15\nqual seu chute? ");

        if (scanf("%d", &chute) != 1 || chute <= 0 || chute > 15) { // se o user digitar um número não inteiro, retornará um valor diferente de 1, o 0
            printf("a chute deve ser um numero inteiro maior que 0 e menor que o numero maximo (15)\n\n");
            while (getchar() != '\n'); // lê e descarta chutes inválidos (como '0,5' ou 'abcde') para evitar um erro de código*
            continue; // volta para o início do loop (reinicia o loop), não contando as tentativas
        } else {
            printf("Seu chute foi %d\n\n", chute);
        }
        
        int acertou = chute == numeroSecreto;

        int totalTentativas = tentativas + tentativasMax;
        palavraTentativa = (totalTentativas > 1) ? "tentativas" : "tentativa";
        
        if(acertou) { // verifica se acertou é verdadeiro ou falso (1 ou 0, executando o bloco de codigo dentro de {} se for verdadeiro (1)

            printf("       ,O,\n");
            printf("      ,OOO,\n");
            printf("'oooooOOOOOooooo'      parabens! voce encontrou o numero secreto %d com %d %s!\n", numeroSecreto, tentativas, palavraTentativa);
            printf("  `OOOOOOOOOOO`        voce fez %f pontos\n", pontosIniciais);
            printf("    `OOOOOOO`          fim de jogo!\n");
            printf("    OOOO'OOOO\n");
            printf("   OOO'   'OOO\n");
            printf("  O'         'O\n");
            break; // interrompe o loop e encerra o jogo quando o jogador acerta
        } else if(numeroSecreto < chute) {
            printf("voce errou :( tente novamente.\ndica -> numero secreto: menor que seu chute %d\nvoce ainda tem %d tentativas\n\n", chute, tentativasMax);
        } else if(numeroSecreto > chute) {
            printf("voce errou :( tente novamente.\ndica -> numero secreto: maior que seu chute %d\nvoce ainda tem %d tentativas\n\n", chute, tentativasMax);
        }

        double pontosDescontados = (double)abs(chute - numeroSecreto) / (double)2; // abs() pega o módulo, evitando resultados negativos
        pontosIniciais -= pontosDescontados; // pontosIniciais = pontosIniciais - pontosDescontados

        tentativas++; // acrescenta uma unidade (1) da quantidade de tentativas a cada vez que o loop while é executado
        tentativasMax--; // decrescenta uma unidade (1) do máximo de tentativas a cada vez que o loop while é executado

        if(tentativas > totalTentativas) {

            printf("              ____\n");
            printf("          />    >\n");
            printf("          |   _   _ l       voce atingiu o maximo de tentativas %d :( infelizmente voce perdeu o jogo\n", totalTentativas);
            printf("         |` =  x ?>         o numero secreto era %d\n", numeroSecreto);
            printf("        /          |\n");
            printf("       /   /     /\n");
            printf("      |    |  |  |\n");
            printf("   /=|     |  |  |\n");
            printf("  | (=/_//__/ __)\n");
            printf("  /_>\n");
            break; // interrompe o loop e encerra o jogo quando acabam todas as tentativas
        }
    }
    return 0; // se não existir problemas na execução do código, a função main() retornará 'true' (0 significa true) no console, com o comando 'echo $?'
}


// * acho válido destacar um comentário mais explicativo sobre a linha 'while (getchar() != '\n');'. nessa linha, um loop while executa
// a função 'getchar()', que lê todos os caracteres, um por um. exemplo: digitando '0.5' essa função lê '0', '.' e '5'. digitando 'abcde'
// essa função lê 'a', 'b', 'c', 'd' e 'e'. essa função fica em loop até que ela encontre caracteres que são diferentes de uma nova linha
// (\n), que aparece quando o usuário pressiona 'ENTER'. como essa função fica em loop até encontrar uma nova linha ('\n'), ela simplesmente
// lê e descarta todos os caractéres que foram escritos antes, evitando que caracteres inválidos permaneçam no valor de entrada, que poderiam
// causar um erro na próxima chamada da função scanf();
