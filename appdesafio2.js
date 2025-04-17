//Altere o conteúdo da tag h1 com document.querySelector e atribua o seguinte texto: Hora do Desafio.
let header = document.querySelector('h1');
header.innerHTML = 'Hora do desafio';

//Crie uma função que exiba no console a mensagem O botão foi clicado sempre que o botão Console for pressionado.
function botaoConsole(){
    console.log('o botão "Console" foi clicado');
}

//Crie uma função que exiba um alerta com a mensagem: Eu amo JS, sempre que o botão Alerta for pressionado.
function botaoAlerta(){
    alert('eu amo JS');
}

//Crie uma função que é executada quando o botão prompt é clicado, perguntando o nome de uma cidade do Brasil.
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