#include <bits/stdc++.h>
#include "conta.hh"

using namespace std;


int main() {
    Conta a("123", "12312321", "Felipe");
    
    a.depositar(500);
    a.sacar(200);

    Conta b("312", "831923819", "Raf");

    cout<<Conta::get_num_contas()<<endl;

    b.~Conta();

    cout<<Conta::get_num_contas()<<endl;

    return 0;
}