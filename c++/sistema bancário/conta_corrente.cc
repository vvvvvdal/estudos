#include <iostream>
#include "conta_corrente.hh"

Conta_corrente::Conta_corrente(std::string id, Titular titular): Conta(id,titular) {
}

float Conta_corrente::taxa_saque() const {
    return 0.05;
}

void Conta_corrente::transferencia(Conta &destino, float valor) {
    using namespace std;

    auto resultado = sacar(valor);
    if(resultado.index() == 1) destino.depositar(valor);
}

void Conta_corrente::operator+=(Conta_corrente &origem) {
    origem.transferencia(*this, origem.get_saldo()/2);
}