#include <bits/stdc++.h>
#include "conta.hh"

using namespace std;


int main() {
    Conta a("123", Titular("12321312", "Felipe Vidal"));
    
    a.depositar(500);
    a.sacar(200);

    Conta b("312", Titular("418213911", "Raf Bro"));

    cout<<Conta::get_num_contas()<<endl;

    b.~Conta();

    cout<<Conta::get_num_contas()<<endl;

    return 0;
}