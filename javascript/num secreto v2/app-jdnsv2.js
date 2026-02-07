let listaDeNumerosSecretos = [];
let numeroMaximo = 10;
let numeroSecreto = gerarNumeroSecreto();
let tentativas = 1;

console.log(numeroSecreto);

//function gerarNumeroMaximo() {
//    return parseInt(Math.random() * 10 + 1);
//}

function escritaDeTexto(tag, texto) {
    let escrita = document.querySelector(tag);
    escrita.innerHTML = texto;
    if ('speechSynthesis' in window) {
        let utterance = new SpeechSynthesisUtterance(texto);
        utterance.lang = 'pt-BR'; 
        utterance.rate = 1.2; 
        window.speechSynthesis.speak(utterance); 
    } else {
        console.log("Web Speech API não suportada neste navegador.");
    }
}

function exibirMensagemInicial() {
    escritaDeTexto('h1', 'Jogo do número secreto');
    escritaDeTexto('p', `Escolha um número entre 1 e ${numeroMaximo}`);
}
exibirMensagemInicial();


// Para não repetir um mesmo número secreto, é usado a lista de números secretos. No if, é verificado se o numero escolhido
// está incluso na lista de números secretos. Se ele estiver, será gerado outro número secreto que será armazenado na variável numero secreto
// através do return. Se ele não estiver, o numero escolhido será adicionado na lista através do push e será retornado o número escolhido, que
// será armazenado na variável número secreto.
function gerarNumeroSecreto() {
    let numeroEscolhido = parseInt(Math.random() * numeroMaximo + 1);
    if (listaDeNumerosSecretos.includes(numeroEscolhido)) {
        return gerarNumeroSecreto();
    } else {
        listaDeNumerosSecretos.push(numeroEscolhido);
        console.log(listaDeNumerosSecretos);
        return numeroEscolhido;
    }
}

function botaoVerificarChute() {
    let chute = document.querySelector('input').value;
    let quantidadeDeNumerosSecretos = listaDeNumerosSecretos.length;
    console.log(chute == numeroSecreto);
    
    if (quantidadeDeNumerosSecretos == numeroMaximo) {
        listaDeNumerosSecretos = [];
    }
    if (chute == numeroSecreto) {
        escritaDeTexto('h1', 'Parabéns!');
        let palavraTentativas = tentativas > 1 ? 'tentativas' : 'tentativa';
        let mensagemTentativas = `Você descobriu o número secreto (${numeroSecreto}) com ${tentativas} ${palavraTentativas}`;
        escritaDeTexto('p', mensagemTentativas);
        document.getElementById('reiniciar').removeAttribute('disabled');
    } else if  (chute > numeroSecreto) {
            escritaDeTexto('h1', 'Errado :( Tente novamente!');
            escritaDeTexto('p', `o número secreto é menor que ${chute}`);
        } else {
            escritaDeTexto('h1', 'Errado :( Tente novamente!');
            escritaDeTexto('p', `o número secreto é maior que ${chute}`);
        }
        tentativas++;
        limparInput();
        
    }
            
// JS não é uma linguagem tipada, ou seja, não é necessário escolher o que uma variável irá armazenar quando ela é criada.
// podendo fazer uma variável armazenar uma string (texto) ou um número, sem precisar especificar com algum comando que a variável
// é uma string ou um número.


// função para limpar o campo onde o número secreto é escrito: primeiramente, é selecionado o campo (input), com o comando chute = document
// .querySelector('input'); e, segundamente, é selecionado o valor escrito no campo para transformá-lo numa string vazia, com o
// chute.value = '';
function limparInput() {
    chute = document.querySelector('input');
    chute.value = '';
}

// gerar outro número máximo, outro número secreto, limpar a caixa onde é escrito o chute, resetar as tentativas para "1", exibir a mensagem
// inicial de começo do jogo e desabilitar o botão "novo jogo".
function botaoNovoJogo() {
    //numeroMaximo = gerarNumeroMaximo();
    limparInput();
    tentativas = 1;
    numeroSecreto = gerarNumeroSecreto();
    console.log(numeroSecreto);
    exibirMensagemInicial();
    document.getElementById('reiniciar').setAttribute('disabled', true);
}
