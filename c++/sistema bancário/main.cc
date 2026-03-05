#include <bits/stdc++.h>
#include "conta.hh"

using namespace std;


int main() {
    Conta a("123", Titular(CPF("12345678941"), "Felipe Vidal"));
    
    a.depositar(500);
    a.sacar(200);

    Conta b("312", Titular(CPF("12345678948"), "Raf Bro"));

    cout<<Conta::get_num_contas()<<endl;

    b.~Conta();

    cout<<Conta::get_num_contas()<<endl;

    return 0;
}
