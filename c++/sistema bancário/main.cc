#include <iostream>
#include "conta.hh"
#include "funcionario.hh"
using namespace std;

int main() {
    Conta a("123", Titular(CPF("80316718424"), "Felipe Vidal"));
    
    a.depositar(500);
    a.sacar(200);

    Conta b("312", Titular(CPF("60202434869"), "Raf Bro"));

    Funcionario fun(CPF("05869424836"), "Trabalhador", 1200.0);

    cout<<Conta::get_num_contas()<<endl;

    b.~Conta();

    cout<<Conta::get_num_contas()<<endl;
    cout<<fun.get_nome()<<endl;

    return 0;
}
