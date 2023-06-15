#include <iostream>
#include <string>
#include <sstream>
#include "mapeador.h"
#include "normalizador.h"
#include "recuperador.h"

int main(){

    
    mapeador.mapearPalavra(./documents/);

    string consulta;
    getline(cin, consulta);

    
    vector<string> busca;
    std::stringstream iss(consulta);
    string palavra;
    while (iss >> palavra) {
        busca.push_back(palavra);
    }

    
    Recupera recupera;
    recupera.recuperacao(mapeador.mapaDe_Palavras, busca);

    return 0;
}
    
