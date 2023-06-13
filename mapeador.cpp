#include "mapeador.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>

using std::map;
using std::string;
using std::vector;
using std::ifstream;

namespace fs = std::filesystem;

string normalizacao(string palavra){
    string palavranormalizada = " ";
    int tam = 0;
    while(tam < palavra.length()){
        char let = palavra[tam];
        if (isalpha(let)){
            palavranormalizada += tolower(let);
        }
        tam++;
    }
    return palavranormalizada;
}

void Mapeador::mapearPalavra(string pasta){
    string palavra;
        for(const auto& arquivo : fs::directory_iterator(pasta)) {
            ifstream file(arquivo.path()); 
            
        while(file >> palavra){
            palavra = normalizacao(palavra);
            mapaDe_Palavras[palavra][arquivo.path()]++;
        }
        file.close();
    }
}