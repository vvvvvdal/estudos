let amigosIncluidos = [];


function adicionar() {
    let nomeAmigo = document.getElementById('nome-amigo'); // ex: felipe
    let nomeAmigoCaixa = nomeAmigo.value;

    let listaAmigos = document.getElementById('lista-amigos'); 
    if(nomeAmigoCaixa === '') {
      alert('Insira um nome válido (não nulo)'); // interrompe a função se o nome adicionado for vazio ('')
      return;
    } else if(amigosIncluidos.includes(nomeAmigoCaixa)) {
      alert('Insira um nome não repetido!')
      nomeAmigo.value = '';
      return;
    }
    amigosIncluidos.push(nomeAmigoCaixa); // [felipe, duarte, rafael]
    listaAmigos.innerHTML = amigosIncluidos.join(', '); // 'felipe, duarte, rafael' // o .join(', ') deixa um espaço dps da vírgula

    
    nomeAmigo.value = ''; // limpa o campo 'Nome do amigo'
}



function sortear() {
    shuffleListaAmigos(); // embaralha o array
    
    if(amigosIncluidos.length < 3) {
      alert('A quantidade de nomes deve ser no mínimo 3!');
      return;
    }
  
    let listaSorteio = document.getElementById('lista-sorteio');
    let resultado = ''; // resultado começa vazio
  
    for (let i = 0; i < amigosIncluidos.length; i++) {
      let amigoAtual = amigosIncluidos[i];
      let amigoSecreto = amigosIncluidos[(i + 1) % amigosIncluidos.length]; // comentário no final do código *
      resultado += `${amigoAtual} → ${amigoSecreto}<br>`; // resultado = resultado + `${amigoAtual} → ${amigoSecreto}<br>`
    }
  
    listaSorteio.innerHTML = resultado; // joga o resultado no HTML

    document.getElementById('botao-adicionar').setAttribute('disabled', true);
  }

function shuffleListaAmigos() {
    for (let i = amigosIncluidos.length - 1; i > 0; i--) {
      let j = Math.floor(Math.random() * (i + 1));
      let temp = amigosIncluidos[i]; // temp é uma variável temporária que serve para trocar os elementos dentro do array
      amigosIncluidos[i] = amigosIncluidos[j];
      amigosIncluidos[j] = temp;
    }
}

function reiniciar() { // limpa o array, o campo dos amigos incluídos e o campo do sorteio
    amigosIncluidos = [];
    document.getElementById('lista-amigos').innerHTML = '';
    document.getElementById('lista-sorteio').innerHTML = '';
    document.getElementById('botao-adicionar').removeAttribute('disabled');
}


// * acho válido comentar a linha de código 'let amigoSecreto = amigosIncluidos[(i + 1) % amigosIncluidos.length];' pq eu achei ela muito 
// interessante e até mesmo confusa. o que acontece é que o '% amigosIncluidos.lenght' retorna para o começo da lista quando chega no último
// nome de amigo, criando um sorteio circular, em que o primeiro nome que aparece na primeira linha retorna como o último nome na última linha.
