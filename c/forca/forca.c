#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

// variáveis globais
char palavraSecreta[TAMANHO_PALAVRA];
char letras[27]; // 26 letras do alfabeto + '\0' -> 27 espaços
int chutesDados = 0;
int erros = 0;
int errosMaximos = 6;
int escolhaMenu;

// imprime o título
void titulo() {
    printf("\n\n");
    printf("*******************************************\n");
    printf("*****          JOGO DA FORCA          *****\n");
    printf("*******************************************\n\n");
}

void menu() {
    titulo();
    printf("*****              MENU                *****\n");
    printf("escolha uma opcao do menu: \n\n");
    printf("digite 1 para jogar\ndigite 2 para adicionar uma nova palavra ao banco de palavras\ndigite 3 para ver o banco de palavras\n");
    printf("digite 4 para encerrar o jogo\nsua opcao -> ");

    scanf("%d", &escolhaMenu);
    while(getchar() != '\n');

    switch(escolhaMenu) {
        case 1:
            escolhaMenu = 1;
            printf("certo! sua escolha foi (1): iniciar o jogo!\n\n");
            iniciarJogo();
            break;

        case 2:
            escolhaMenu = 2;
            printf("certo! sua escolha foi (2): adicionar uma nova palavra no banco de palavras!\n\n");
            adicionarPalavra();
            break;

        case 3:
            escolhaMenu = 3;
            printf("certo! sua escolha foi (3): ver o banco de palavras!\n\n");
            imprimirBancoPalavras();
            break;
        case 4:
            escolhaMenu = 4;
            printf("certo! sua escolha foi (4): encerrar o jogo!\n\n");
            exit(1);

        default:
            printf("opcao invalida! pressione ENTER para voltar ao menu.\n");
            getchar();
            break;
    }
        
}

void imprimirBancoPalavras() {
    FILE* f = fopen("palavras.txt", "r");
    char linha[256];

    if(f == 0) {
        printf("desculpe :( banco de dados indisponivel, encerrando jogo!\n\n");   // aviso caso ocorra algum erro no arquivo
        exit(1);
    }

    printf("imprimindo a seguir: o banco de palavras\n\n");
    fgets(linha, sizeof(linha), f);  // lê e descarta: armazena a quantidade de palavras na variável 'linha', para depois não imprimir ela junto com as palavras
    while (fgets(linha, sizeof(linha), f) != 0) { // imprime cada linha do arquivo -> o banco de palavras
        printf("- %s", linha); 
    }

    fclose(f);
}

void chutar() {                         // um array é um ponteiro por natureza.
    char chute;
    printf("digite seu chute: ");
    scanf(" %c", &chute);                   // o ' ' (espaço) antes do '%c' diz pro scanf() ignorar o espaço como resposta no buffer de entrada

    while(getchar() != '\n'); 

    letras[chutesDados] = toupper(chute);         // armazena o chute do usuário no array de letras em uma posição de acordo com a sua tentativa
    chutesDados++;
}

// detecta se a letra ja foi chutada
int jaChutou(char resposta) {
    int achou = 0;

    for(int j = 0; j < chutesDados; j++) {
        if(letras[j] == resposta) {
            achou = 1;
            break;
        }
    }
    return achou;
}

// imprime a palavra secreta
void desenhaForca() {

    printf("  ________     \n");
    printf(" |/      |     \n");
    printf(" |      %c%c%c \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 4 ? '/' : ' '));
    printf(" |       %c    \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c  \n", (erros >= 5 ? '/' : ' '), (erros >= 6 ? '\\' : ' '));
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

    for(int i = 0; i < strlen(palavraSecreta); i++) {                 // strlen(palavra) pega o tamanho de uma string do tipo char; nesse caso: strlen(palavra) = 8
            
        // detecta se a letra ja foi chutada
        int achou = jaChutou(palavraSecreta[i]);

        // imprime o chute
        if(achou) {
            printf("%c ", palavraSecreta[i]);
        } else {
            printf("_ ");
        }
            
    }

    printf("\n");
}


void palavraMaiuscula(char* string) {  // transforma a palavra em maíscula, se ela for minúscula
    for (int i = 0; string[i] != '\0'; i++) {
        string[i] = toupper(string[i]);
    }
}

void adicionarPalavra() {
    int escolhaAdicionar;
    printf("voce quer adicionar uma nova palavra ao banco de palavras?\n");
    printf("digite 1 para sim e 2 para nao\n");
    scanf("%d", &escolhaAdicionar);
    while (getchar() != '\n');

    verificarBancoPalavra();

    while(escolhaAdicionar != 1 && escolhaAdicionar != 2) {
        printf("digite uma opcao valida\n");
        printf("digite 1 para sim e 2 para nao\n");
        scanf("%d", &escolhaAdicionar);
        while (getchar() != '\n'); // loop que evita respostas incorretas no buffer de entrada da variável 'escolhaAdicionar'
    }

    if(escolhaAdicionar == 1) {
        char novaPalavra[TAMANHO_PALAVRA];
        printf("qual a nova palavra?\n");
        scanf("%s", novaPalavra);
        palavraMaiuscula(novaPalavra);

        while (verificarBancoPalavra(novaPalavra) == 1) { // verifica se a palavra digitada já existe no banco
        printf("\na palavra '%s' ja existe no banco de palavras\n", novaPalavra);
        printf("por favor, digite uma palavra diferente:\n-> ");
        scanf("%s", novaPalavra);
        while (getchar() != '\n');
        palavraMaiuscula(novaPalavra);
    }


        FILE* f = fopen("palavras.txt", "r+");  // 'r+' é uma opção de leitura e escrita de arquivos

        if(f == 0) {
            printf("desculpe :( banco de dados indisponivel, encerrando jogo!\n\n");   // aviso caso ocorra algum erro no arquivo
            exit(1);
        }

        int quantidade;
        fscanf(f, "%d", &quantidade);
        quantidade++;

        fseek(f, 0, SEEK_SET);   // explicação*
        fprintf(f, "%d", quantidade);   // vê a quantidade de palavras, acrescenta 1, reinicia a leitura para o começo do arquivo e imprime a nova quantidade no começo do arquivo.


        fseek(f, 0, SEEK_END); // posiciona o ponteiro para o final do arquivo
        fprintf(f, "\n%s", novaPalavra);   // escreve a nova palavra no final do arquivo

        fclose(f);

        printf("sua palavra %s foi adicionada ao banco de palavras!\n\n", novaPalavra);
        return;
    } else if(escolhaAdicionar == 2) {
            printf("certo! entao voce nao quer adicionar uma nova palavra! entendido!\n");
            return;
    }

}


//verifica se a palavra que o usuário quer adicionar já existe no banco de palavras
int verificarBancoPalavra(char* palavraVerificar) {
    FILE* f = fopen("palavras.txt", "r");
    char linha[TAMANHO_PALAVRA];

    if(f == 0) {
        printf("desculpe :( banco de dados indisponivel, encerrando jogo!\n\n");   // aviso caso ocorra algum erro no arquivo
        exit(1);
    }

    fgets(linha, sizeof(linha), f);  // lê e descarta: armazena a quantidade de palavras na variável 'linha', para depois não imprimir ela junto com as palavras
    
    while (fgets(linha, sizeof(linha), f) != 0) { // percorre cada linha do banco de palavras
        linha[strcspn(linha, "\n")] = 0; // no loop, passa por cada linha, parando quando acabar de passar por todas as palavras encontrando o '\n' e trocando por '\0' que indica o fim

        if (strcmp(linha, palavraVerificar) == 0) {  // função 'string compare', compara cada linha com a palavra para ver se são iguais
            fclose(f); // fecha o arquivo antes de sair
            return 1; // se a palavra existe no banco
        }
    }
    
    fclose(f);
    return 0; // se a palavra NÃO existe no banco
}

void resetarVariaveis() {
    letras[0] = '\0';
    chutesDados = 0;
    erros = 0;
    palavraSecreta[0] = '\0';
}

// escolhe a palavra secreta
void escolhePalavra() {
    // sprintf(palavraSecreta, "MELANCIA");    // função sprintf() armazena a string numa array
    // printf("%s", palavraSecreta);           // '%s' imprime a array, parando a leitura no caractere nulo '\0' que aparece após o final da palavra

    FILE* f = fopen("palavras.txt", "r");           // fopen() abre um arquivo e devolve um ponteiro para esse arquivo. o parâmetro "r" é de "read" -> lê o arquivo

    if(f == 0) {
        printf("desculpe :( banco de dados indisponível\n\n");   // aviso caso ocorra algum erro no arquivo
        exit(1);
    }

    int quantidadeDePalavras;
    fscanf(f, "%d", &quantidadeDePalavras);     // vê a quantidade de palavras no arquivo -> 12

    srand(time(0));
    int randomico = rand() % quantidadeDePalavras;   // gera um número pseudoaleatório entre 0 e 11

    for(int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f);      // fclose() interrompe o uso do arquivo no programa. é uma boa prática de programação.
}

int acertou() {
    for(int i = 0; i < strlen(palavraSecreta); i++) {
        if(!jaChutou(palavraSecreta[i])) {
            return 0;
        }
    }
    printf("\nvoce acertou! a palavra secreta era %s !\n\n", palavraSecreta);
    printf("             ___________             \n");
    printf("            '._==_==_=_.'            \n");
    printf("            .-\\:      /-.            \n");
    printf("           | (|:.     |) |           \n");
    printf("            '-|:.     |-'            \n");
    printf("              \\::.    /              \n");
    printf("               '::. .'               \n");
    printf("                 ) (                 \n");
    printf("               _.' '._               \n");

    return 1;
}

int chutesErrados() {
    int errosLocais = 0;

    for(int i = 0; i < chutesDados; i++) {
        int existe = 0;

        for(int j = 0; j < strlen(palavraSecreta); j++) {
            if(toupper(letras[i]) == palavraSecreta[j]) {  // toupper(letras[i]) pega respostas minúsculas e converte para maíusculas. 'e' vira 'E'
                existe = 1;
                break;
            }
        }
        if(!existe) {
            errosLocais++;
        }
    }
    return errosLocais;
}

int enforcou() {

    if(erros >= errosMaximos) {

        printf("  ________     \n");
        printf(" |/      |     \n");
        printf(" |      (_) \n");
        printf(" |      \\|/ \n");
        printf(" |       |    \n");
        printf(" |      / \\  \n");
        printf(" |             \n");
        printf("_|___          \n");
        printf("\n\n");
        printf("\nvoce atingiu o limite de erros (%d) e foi enforcado :( a palavra secreta era %s !\n\n", errosMaximos, palavraSecreta);
        printf("     .----------.\n");
        printf("   .'           '.\n");
        printf("  /   O      O    | \n");
        printf(" :           `    :\n");
        printf(" |                |   \n");
        printf(" :    .------.    :\n");
        printf("  \\  '        '  /\n");
        printf("   '.          .'\n");
        printf("    '-......-'\n");
    }

    return erros >= errosMaximos; // se errar 6 ou mais vezes, a função retorna verdadeiro (1). caso contrário, retorna falso (0)
}

void iniciarJogo() {

    // reseta as variaveis
    resetarVariaveis();

    // imprime o título
    titulo();

    // escolhe a palavra secreta
    escolhePalavra();


    do {
        
        // imprime a palavra secreta
        desenhaForca();

        // detecta um novo chute
        chutar();

        erros = chutesErrados(); // atualiza a contagem de erros a cada rodada.


    } while(!acertou() && !enforcou());        // o '!' inverte o valor da variável booleana. '!acertou = 1' e '!enforcou() = 1';

}


int main() {

    while(1) {
        menu();  // roda o programa em um loop infinito. somente para quando o usuário escolhe a opção de fechar o jogo (5)
    }

    return 0;
}

// * a função fseek() reposiciona o ponteiro do arquivo f para o começo do arquivo, fazendo com que o ponteiro leia sempre a quantidade de palavras.
// deslocamento é um valor inteiro que indica quantos bytes você deseja mover o ponteiro de leitura, sendo '0' uma movimentação nula em relação a origem 'SEEK'.
// 'SEEK_SET' é um valor que indica de onde o deslocamento deve ser iniciado, sendo, nesse caso, do começo do arquivo.