// Altere o conteúdo da tag h1 com document.querySelector e atribua o seguinte texto: Hora do Desafio.
let header = document.querySelector('h1');
header.innerHTML = 'Hora do desafio';

// Crie uma função que exiba no console a mensagem O botão foi clicado sempre que o botão Console for pressionado.
function botaoConsole(){
    console.log('o botão "Console" foi clicado');
}
botaoConsole();

// Crie uma função que exiba um alerta com a mensagem: Eu amo JS, sempre que o botão Alerta for pressionado.
function botaoAlerta(){
    alert('eu amo JS');
}
botaoAlerta();

// Crie uma função que é executada quando o botão prompt é clicado, perguntando o nome de uma cidade do Brasil.
// Em seguida, exiba um alerta com a mensagem concatenando a resposta com o texto: Estive em {cidade} e lembrei de você.
function botaoPrompt(){
    let nomeDaCidade = prompt('escreva o nome de uma cidade do Brasil');
    alert(`estive em ${nomeDaCidade} e lembrei de você!`);
}

//Ao clicar no botão soma, peça 2 números INTEIROS e exiba o resultado da soma em um alerta.
function botaoSoma(){
    let numero1 = parseInt(prompt('digite um número para soma'));
    let numero2 = parseInt(prompt('digite outro número para soma'));
    let soma = numero1 + numero2;
    alert(`o resultado da soma de ${numero1} com ${numero2} foi ${soma}`);
}
botaoSoma();

// Criar uma função que exibe "Olá, mundo!" no console.
function exibirTexto() {
    console.log('olá mundo');
}
exibirTexto();

// Criar uma função que recebe um nome como parâmetro e exibe "Olá, [nome]!" no console.
function receberNome() {
    let nome = prompt('qual o seu nome?');
    console.log(`olá, ${nome}!`);
}
receberNome();

// Criar uma função que recebe um número como parâmetro e retorna o dobro desse número.
function dobroDoNumero() {
    let numero = Number(prompt('digite um número'));
    let dobroDoNumero = numero * 2;
    return console.log(`o dobro de ${numero} é ${dobroDoNumero}`);
}
dobroDoNumero();

// Criar uma função que recebe três números como parâmetros e retorna a média deles.
function mediaDosTresNumeros() {
    let numeroPrimeiro = Number(prompt('digite o primeiro número'));
    let numeroSegundo = Number(prompt('digite o segundo número'));
    let numeroTerceiro = Number(prompt('digite o terceiro número'));
    let mediaDosTresNumeros = (numeroPrimeiro + numeroSegundo + numeroTerceiro) / 3;
    return console.log(`a média de ${numeroPrimeiro}, ${numeroSegundo} e ${numeroTerceiro} é ${mediaDosTresNumeros}`);
}
mediaDosTresNumeros();

// Criar uma função que recebe dois números como parâmetros e retorna o maior deles.

function comparacaoNumeros() {
    let numeroPri = Number(prompt('digite o primeiro número para comparação'));
    let numeroSeg = Number(prompt('digite o segundo número para comparação'));
    if (numeroPri > numeroSeg) {
        return console.log(`entre os números ${numeroPri} e ${numeroSeg} o maior é ${numeroPri}`);
    } else if (numeroPri < numeroSeg) {
        return console.log(`entre os números ${numeroPri} e ${numeroSeg} o maior é ${numeroSeg}`)
    } else {
        return console.log(`os números ${numeroPri} e ${numeroSeg} são iguais`);
    }
}
comparacaoNumeros();

// Criar uma função que recebe um número como parâmetro e retorna o resultado da multiplicação desse número por ele mesmo
function numeroElevadoAoquadrado() {
    let numeroParaSerElevadoAoQuadrado = Number(prompt('digite um número para ser elevado ao quadrado'));
    let numeroResultadoAoQuadrado = numeroParaSerElevadoAoQuadrado * numeroParaSerElevadoAoQuadrado;
    return console.log(`o número ${numeroParaSerElevadoAoQuadrado} ao quadrado é ${numeroResultadoAoQuadrado} `);
}
numeroElevadoAoquadrado();
