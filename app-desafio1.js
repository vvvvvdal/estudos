//Crie um programa que utilize o console.log para exibir uma mensagem de boas-vindas.
console.log("boas vindas");

//Crie uma variável chamada "nome" e atribua a ela o seu nome. Em seguida, utilize o console.log para exibir a mensagem "Olá, [seu nome]!" no console do navegador.
let nome = "felipe";
console.log(`boas vindas ${nome}`);

//Crie uma variável chamada "nome" e atribua a ela o seu nome. Em seguida, utilize o alert para exibir a mensagem "Olá, [seu nome]!" .
alert(`olá ${nome}`);

//Utilize o prompt e faça a seguinte pergunta: Qual a linguagem de programação que você mais gosta?. Em seguida, armazene a resposta em uma variável e mostre no console do navegador.
let resposta = prompt("qual linguagem de programação você mais gosta?");
console.log("a linguagem preferida do usuário é " + resposta);

//Crie uma variável chamada "valor1" e outra chamada "valor2", atribuindo a elas valores numéricos de sua escolha. Em seguida, realize a soma desses dois valores e armazene o
// resultado em uma terceira variável chamada "resultado".Utilize o console.log para mostrar a mensagem "A soma de [valor1] e [valor2] é igual a [resultado]." no console.
let valor1 = 5;
let valor2 = 7;
let resultado = valor1 + valor2;
console.log(`a soma de ${valor1} e ${valor2} é igual a ${resultado}`);

//Peça ao usuário para inserir sua idade com prompt. Com base na idade inserida, utilize um if para verificar se a pessoa é maior ou menor de idade,
// exibindo uma mensagem apropriada no console.
let idade = prompt("qual a sua idade?");
let idadeNumero = idade > 1 ? "anos" : "ano";
if (idade >= 18) {
    console.log(`o usuário é maior de idade, pois ele tem ${idade} ${idadeNumero}`);
} else {
    console.log(`o usuário é menor de idade, pois ele tem ${idade} ${idadeNumero}`);
}

//Crie uma variável "numero" e peça um valor com prompt verifique se é positivo, negativo ou zero. Use if-else para imprimir a respectiva mensagem.
let numero = prompt("insira um número, que pode ser negativo ou positivo");
if (numero > 0) {
    console.log(`o número ${numero} é positivo`);
} else if (numero < 0 ) {
    console.log(`o número ${numero} é negativo`);
} else {
    console.log(`o número é 0`);
}

//Use um loop while para imprimir os números de 1 a 10 no console.
let loop = 0;
while(loop < 10){
    loop++;
    console.log(loop);
}

//Crie uma variável "nota" e atribua um valor numérico a ela. Use if-else para determinar se a nota é maior ou igual a 7 e exiba "Aprovado" ou "Reprovado" no console.
let nota = 9;
if (nota >= 7) {
    console.log(`aprovado, pois a nota ${nota} é maior que 7`);
} else {
    console.log(`reprovado, pois a nota ${nota} é menor que 7`);
}

//Use o Math.random para gerar qualquer número aleatório e exiba esse número no console.
console.log(Math.random());

//Use o Math.random para gerar um número inteiro entre 1 e 10 e exiba esse número no console.
console.log(parseInt(Math.random() * 10 + 1));

//Use o Math.random para gerar um número inteiro entre 1 e 1000 e exiba esse número no console.
console.log(parseInt(Math.random() * 1000 + 1));
