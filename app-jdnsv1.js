alert("Boas vindas ao jogo do número secreto");
let numeroMaximo = parseInt(Math.random() * 100 + 1;
let numeroSecreto = parseInt(Math.random() * numeroMaximo + 1);
console.log(numeroSecreto);
let chute;
let tentativas = 1;

// enquanto o chute não for igual ao número secreto
while (chute != numeroSecreto) {
    chute = prompt(`Escolha um número de 1 a ${numeroMaximo}`);

    // se o chute for igual ao número secreto
    if (chute == numeroSecreto) {
        break;
    } else {
        if (chute > numeroSecreto) {
            alert(`Você errou :( Tente novamente! O número secreto é menor que ${chute}!`);
        } else {
            alert(`Você errou :( Tente novamente! O número secreto é maior que ${chute}!`);
        }
        // tentativas = tentativas + 1;
        // explicação: soma 1 tentativa a cada vez que o prompt do chute é executado
        tentativas++;

    }
}


//if (tentativas > 1) {
//    alert(`Parabéns! Você descobriu o número secreto (${numeroSecreto}) com ${tentativas} tentativas`);
//} else {
//    alert(`Parabéns! Você descobriu o número secreto (${numeroSecreto}) com ${tentativas} tentativa`);
//}
//explicação: o comando "let palavraTentativa = tentativas > 1 ? "tentativas" : "tentativa"" tem a mesma função do ifelse acima
let palavraTentativa = tentativas > 1 ? "tentativas" : "tentativa"
alert(`Parabéns! Você descobriu o número secreto (${numeroSecreto}) com ${tentativas} ${palavraTentativa}`);

