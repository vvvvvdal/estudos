#include <bits/stdc++.h>
using namespace std;

string PALAVRA;
map<char,bool>chutou; // dicionario com chave (indice) de char (letra) e valor de booleano
vector<char>errados; // vetor dinamico de char (letras)

vector<string> ler_arquivo(){
    ifstream arquivo; // variavel do tipo input file stream (arquivo de fluxo de entrada de dados)
    arquivo.open("palavras.txt");

    if(!arquivo.is_open()) {
        cout<<"erro na abertura do banco de palavras. encerrando programa..."<<endl;
        exit(0);
    }

    vector<string> palavras_arquivo;

    int qtd_palavras;
    arquivo>>qtd_palavras;

    for(int i=0;i<qtd_palavras;i++){
        string p;
        arquivo>>p;
        palavras_arquivo.push_back(p);
    }

    arquivo.close();

    return palavras_arquivo;
}

void sortear_palavra(vector<string> palavras_arquivo){
    int sorteado = rand()%palavras_arquivo.size();
    PALAVRA = palavras_arquivo[sorteado];
}

void print_forca(){
    for(char letra:PALAVRA) {
        if(chutou[letra]) cout<<letra<<" "; // se a letra existir na palavra, imprime ela
        else cout<<"_ ";
    }
    cout<<endl;
}

void print_errados(int tent){
    string palavra_tent = tent == 1 ? "tentativa":"tentativas";
    cout<<"("<<tent<<" "<<palavra_tent<<")"<<" chutes errados: ";
    for(char letra:errados) cout<<letra<<" ";
    cout<<endl<<endl;
}

void mensagem_inicial(){
    cout<<"******************************"<<endl;
    cout<<"* bem vindo ao jogo da forca *"<<endl;
    cout<<"******************************"<<endl;
    print_forca();
}

void ler_chute(char *chute){

    cout<<"digite seu chute: ";
    cin>>*chute;
    cout<<endl;

    if(isalpha(*chute)) { // se for letra
        *chute = toupper(*chute);
        return;
    }

    // se nao for letra
    cout<<"o caracter digitado nao foi uma letra. tente novamente"<<endl;
    print_forca();
    
    ler_chute(chute);
}

bool existe_palavra(char chute) {
    for(char letra:PALAVRA) if(chute == letra) return true;
    return false;
}

bool existe_errados(char chute) {
    for(char letra:errados) if(chute == letra) return true;

    return false;
}

bool nao_acertou() {
    for(char letra:PALAVRA) if(chutou[letra] == false) return true;

    return false;
}

bool nao_enforcou() {
    return errados.size() < 5; // 5 tentativas
}

bool palavra_repetida(string pal) {
    vector<string> palavras_arquivo = ler_arquivo(); 
    for(string p:palavras_arquivo) if(pal == p) return true;

    return false;
}

void salvar_arquivo(vector<string> palavras_arquivo) {
    ofstream arquivo; // variavel do tipo outpot file stream (arquivo de fluxo de saida de dados)
    arquivo.open("palavras.txt");

    if(!arquivo.is_open()) {
        cout<<"erro na abertura do banco de palavras. encerrando programa..."<<endl;
        exit(0);
    }

    arquivo<<palavras_arquivo.size()<<endl;

    for(string palav:palavras_arquivo) arquivo<<palav<<endl;

    arquivo.close();
}

void nova_palavra(){
    vector<string> palavras_arquivo = ler_arquivo();
    string palav;

    cout<<"certo. digite a palavra que voce quer adicionar"<<endl;
    cout<<"palavra: "<<endl;
    cin>>palav;
    cout<<endl;

    for(int i=0;i<palav.size();i++) palav[i] = toupper(palav[i]);

    if(palavra_repetida(palav)) {
        cout<<"palavra ja existente no banco de dados. digite uma palavra diferente"<<endl;
        nova_palavra();
    }

    palavras_arquivo.push_back(palav);

    salvar_arquivo(palavras_arquivo);

    cout<<"palavra "<<palav<<" adicionada com sucesso ao banco de dados!";
    cout<<"encerrando programa..."<<endl;
    exit(0);
}

void adicionar_palavra(){
    char op;
    cout<<"voce deseja adicionar uma nova palavra ao banco de dados?"<<endl;
    cout<<"digite s para sim ou n para nao"<<endl;
    cout<<"sua opcao: ";
    cin>>op;
    op = tolower(op);
    cout<<endl;

    if(op == 's') {
        nova_palavra();
    } else if(op == 'n') {
        cout<<"certo. voce nao quer adicionar uma nova palavra"<<endl;
        cout<<"encerrando programa..."<<endl;
        exit(0);
    }

    cout<<"opcao incorreta. digite sua opcao novamente"<<endl;
    adicionar_palavra();
}

void mensagem_final(){
    string palavra_erros = errados.size() == 1 ? "erro":"erros";

    if(nao_acertou()) cout<<"suas tentativas acabaram e voce perdeu :("<<endl;
    else cout<<"voce acertou com "<<errados.size()<<" "<<palavra_erros<<"!!"<<endl;
    cout<<"a palavra secreta era "<<PALAVRA<<endl;
    cout<<"fim de jogo!"<<endl<<endl;
    adicionar_palavra();
}

int main() {
    srand(time(NULL));
    char chute;
    int tent = 5;
    vector<string> palavras_arquivo = ler_arquivo();

    sortear_palavra(palavras_arquivo);
    mensagem_inicial();

    while(nao_acertou() && nao_enforcou()){
        ler_chute(&chute);

        if(existe_palavra(chute)) chutou[chute] = true;
        else {
            if(!existe_errados(chute)) {
                errados.push_back(chute); // coloca o chute errado no final do vector
                tent--;
            }
        }

        print_errados(tent);
        print_forca();
    }

    mensagem_final();

    return 0;
}
