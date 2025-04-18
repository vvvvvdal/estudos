// Altere o conteúdo da tag h1 com document.querySelector e atribua o seguinte texto: Hora do Desafio.
let header = document.querySelector('h1');
header.innerHTML = 'Hora do desafio';

// Crie uma função que exiba no console a mensagem O botão foi clicado sempre que o botão Console for pressionado.
function botaoConsole(){
    console.log('o botão "Console" foi clicado');
}


// Crie uma função que exiba um alerta com a mensagem: Eu amo JS, sempre que o botão Alerta for pressionado.
function botaoAlerta(){
    alert('eu amo JS');
}


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


// Criar uma função que exibe "Olá, mundo!" no console.
function exibirTexto() {
    console.log('olá mundo');
}





// ATENÇÃO: Resolvi deixar uma pergunta no prompt ao invés de passar o valor da variável no parâmetro nos desafios a baixo.





// Criar uma função que recebe um nome como parâmetro e exibe "Olá, [nome]!" no console.
function receberNome() {
    let nome = prompt('qual o seu nome?');
    console.log(`olá, ${nome}!`);
}


// Criar uma função que recebe um número como parâmetro e retorna o dobro desse número.
function dobroDoNumero() {
    let numero = Number(prompt('digite um número'));
    let dobroDoNumero = numero * 2;
    return console.log(`o dobro de ${numero} é ${dobroDoNumero}`);
}


// Criar uma função que recebe três números como parâmetros e retorna a média deles.
function mediaDosTresNumeros() {
    let numeroPrimeiro = Number(prompt('digite o primeiro número'));
    let numeroSegundo = Number(prompt('digite o segundo número'));
    let numeroTerceiro = Number(prompt('digite o terceiro número'));
    let mediaDosTresNumeros = (numeroPrimeiro + numeroSegundo + numeroTerceiro) / 3;
    return console.log(`a média de ${numeroPrimeiro}, ${numeroSegundo} e ${numeroTerceiro} é ${mediaDosTresNumeros}`);
}


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


// Criar uma função que recebe um número como parâmetro e retorna o resultado da multiplicação desse número por ele mesmo
function numeroElevadoAoquadrado() {
    let numeroParaSerElevadoAoQuadrado = Number(prompt('digite um número para ser elevado ao quadrado'));
    let numeroResultadoAoQuadrado = numeroParaSerElevadoAoQuadrado * numeroParaSerElevadoAoQuadrado;
    return console.log(`o número ${numeroParaSerElevadoAoQuadrado} ao quadrado é ${numeroResultadoAoQuadrado} `);
}



// Crie uma função que calcule o índice de massa corporal (IMC) de uma pessoa, a partir de sua altura, em metros, e peso, em quilogramas,
// que serão recebidos como parâmetro.
function calculadoraDeIMC(peso, altura) {
    peso = prompt('digite seu peso em kg');
    altura = prompt('digite sua altura em em metros');
    let IMC = parseInt(peso / (altura * altura));
    return alert(`com base no seu peso ${peso} kg e sua altura ${altura} m o seu IMC é ${IMC} kg/m²`);
}


// Crie uma função que calcule o valor do fatorial de um número passado como parâmetro.
function calculoDoFatorial(numeroFatorial){
    numeroFatorial = Number(4);
    let respostaDofatorial = Number(numeroFatorial * (numeroFatorial - 1) * (numeroFatorial - 2) * (numeroFatorial - 3));
    return console.log(`o número ${numeroFatorial} em seu valor fatorial é ${respostaDofatorial}`);
}


// Crie uma função que converte um valor em dólar, passado como parâmetro, e retorna o valor equivalente em reais.
// Para isso, considere a cotação do dólar igual a R$4,80.
function conversorDeMoedas(valorDolar){
    valorDolar = Number(prompt('digite um valor em dolar para ser convertido em real'));
    let valorReal = Number(valorDolar * 4.80);
    return alert(`o valor U$${valorDolar} em real é R$${valorReal}`);
}

// Crie uma função que mostre na tela a área e o perímetro de uma sala retangular,
// utilizando altura e largura que serão dadas como parâmetro.
function calculadoraDeAreaEPerimetroRetangular(altura, largura) {
    altura = Number(prompt('digite uma altura em metros'));
    largura = Number(prompt('digite uma largura em metros'));
    let area = altura * largura;
    let perimetro = (2 * altura) + (2 * largura);
    return alert(`com a altura de ${altura} metros e largura de ${largura} metros, a área é de ${area} m² e o perímetro é de ${perimetro} metros`);
}

// Crie uma função que mostre na tela a área e o perímetro de uma sala circular, utilizando seu raio que será fornecido como parâmetro.
// Considere Pi = 3,14.
function calculadoraDeAreaEPerimetroCircular(raio) {
    raio = Number(prompt('digite um raio em metros'));
    let area = 3.14 * raio * raio;
    let perimetro = 2 * 3.14 * raio;
    return alert(`com raio de ${raio} metros, a área é de ${area} m² e o perímetro é de ${perimetro} metros`);
}

// Crie uma função que mostre na tela a tabuada de um número dado como parâmetro.
function tabuada(numero){
    numero = Number(prompt('escolha um número para fazer sua tabuada'));
    let numerox1 = numero * 1;
    let numerox2 = numero * 2;
    let numerox3 = numero * 3;
    let numerox4 = numero * 4;
    let numerox5 = numero * 5;
    let numerox6 = numero * 6;
    let numerox7 = numero * 7;
    let numerox8 = numero * 8;
    let numerox9 = numero * 9; 
    let numerox10 =numero * 10;
    return alert(`a tabuada de ${numero} é: ${numerox1}, ${numerox2}, ${numerox3}, ${numerox4}, ${numerox5}, ${numerox6}
        ${numerox7}, ${numerox8}, ${numerox9}, ${numerox10}`);
}
