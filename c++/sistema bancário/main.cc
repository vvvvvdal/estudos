#include <iostream>
#include "conta.hh"
#include "conta_corrente.hh"
#include "conta_poupanca.hh"
#include "funcionario.hh"
#include "gerente.hh"
#include "caixa.hh"
#include "autenticavel.hh"
using namespace std;

int main() {
    Conta_corrente a("123", Titular(CPF("80316718424"), "Felipe Vidal", "12345"));
    
    a.depositar(500);
    a.sacar(200);

    Conta_poupanca b("312", Titular(CPF("60202434869"), "Pedro Pereira", "54321"));

    Gerente ger(CPF("05869424836"), "Jose da Silva", 1200.0, "121212");

    cout<<"qtd contas: "<<Conta::get_num_contas()<<endl;

    cout<<b.get_saldo()<<endl;
    cout<<ger.get_nome()<<endl;
    cout<<a.get_saldo()<<endl;

    a.transferencia(b, 100);
    cout<<b.get_saldo()<<endl;

    b.~Conta_poupanca();
    cout<<"qtd contas: "<<Conta::get_num_contas()<<endl;
    
    ger.login("121212");

    return 0;
}
