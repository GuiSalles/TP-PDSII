#include <iostream>
#include <string>
#include "mapeador.h"
#include "normalizador.h"
#include "recuperador.h"

int main(){
    string pasta = "caminho";
    Mapeador mapeador;
    mapeador.mapearPalavra(pasta);

    Recupera recuperador;

    string palavra;
    vector<string> busca; 
    recuperador.recuperacao(mapeador.mapaDe_Palavras, busca);

    return 0;
    

}
