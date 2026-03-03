#pragma once // diz pro compilador: "compile os includes somente uma vez, se eles repetirem a mesma biblioteca"

#include <bits/stdc++.h>
#include "fx_arquivos.hh"
#include "fx_palavras.hh"
#include "fx_prints.hh"
#include "fx_verificar.hh"
using namespace std;

// variaveis extern dizem pro compilador: "essas variaveis existem em algum lugar do codigo"
extern string PALAVRA;
extern map<char, bool> chutou;
extern vector<char> errados;