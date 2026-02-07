let numerosSorteados;
let listaNumerosSorteados = [];


function botaoSortear() {
    let quantidadeNumeros = Number(document.getElementById('quantidadeNumeros').value);
    let numeroMinimo = Number(document.getElementById('numeroMinimo').value);
    let numeroMaximo = Number(document.getElementById('numeroMaximo').value);

    let quantidadeNumerosDisponiveis = numeroMaximo - numeroMinimo + 1;


    if (quantidadeNumeros > quantidadeNumerosDisponiveis) {
        document.getElementById('resultado').innerHTML = `<label class="texto__paragrafo">Escolha uma quantidade de números menor que
        ${quantidadeNumerosDisponiveis}, pois esse é um valor maior que a quantidade de números disponíveis
        entre ${numeroMinimo} e ${numeroMaximo}</label>`;
        document.getElementById('btn-sortear').setAttribute('disabled', true);
        alterarStatusBotaoReiniciar();
        return;
    } else if (quantidadeNumeros < 1) {
        document.getElementById('resultado').innerHTML = `<label class="texto__paragrafo">Escolha uma quantidade de números maior ou igual a 1</label>`;
        document.getElementById('btn-sortear').setAttribute('disabled', true);
        alterarStatusBotaoReiniciar();
        return;
    }

    for (let i = 0; i < quantidadeNumeros; i++) {
        let numerosSorteados = sortearNumeros(numeroMinimo, numeroMaximo);

        // se for sorteado um número já armazenado na lista, o while repetirá o sorteio até que apareça um número 'inédito'.
        while (listaNumerosSorteados.includes(numerosSorteados)) {
            numerosSorteados = sortearNumeros(numeroMinimo, numeroMaximo);
        }

        listaNumerosSorteados.push(numerosSorteados);
    }

    // desabilita o botão "Sortear" após ele ser clicado e habilita o botão "Reiniciar"
    document.getElementById('resultado').innerHTML = `<label class="texto__paragrafo">Números sorteados: ${listaNumerosSorteados.join(', ')}</label>`;
    document.getElementById('btn-sortear').setAttribute('disabled', true);
    alterarStatusBotaoReiniciar();
    
}

// função que sorteia números inteiros pertencentes ao intervalo entre o número mínimo e o máximo.
function sortearNumeros(min, max) {
    let numeroSorteado = parseInt(Math.random() * (max - min + 1)) + min;
    return numeroSorteado;
}

// se tem 'desabilitado' -> remove. se não tem 'desabilitado' -> adiciona.
function alterarStatusBotaoReiniciar() {
    let botaoReiniciar = document.getElementById('btn-reiniciar');

    if (botaoReiniciar.classList.contains('container__botao-desabilitado')) {
        botaoReiniciar.classList.remove('container__botao-desabilitado');
        botaoReiniciar.classList.add('container__botao');
        botaoReiniciar.removeAttribute('disabled');
    } else {
        botaoReiniciar.classList.remove('container__botao');
        botaoReiniciar.classList.add('container__botao-desabilitado');
        botaoReiniciar.setAttribute('disabled', true);
    }
}


// reinicia o jogo limpando os campos onde os números são escritos, limpando a array onde os números são sorteados, sorteando uma nova lista de números, habilitando o botão "Sortear" e desabilitando o botão "Reiniciar".
function botaoReiniciar() {
    document.getElementById('quantidadeNumeros').value = '';
    document.getElementById('numeroMinimo').value = '';
    document.getElementById('numeroMaximo').value = '';
    document.getElementById('resultado').innerHTML = '<label class="texto__paragrafo">Números sorteados:  nenhum até agora</label>';
    listaNumerosSorteados = [];
    document.getElementById('btn-sortear').removeAttribute('disabled');
    alterarStatusBotaoReiniciar();
}
