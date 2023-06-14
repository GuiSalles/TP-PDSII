#include "normalizador.h"
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

void Mapeador::mapearPalavra(string pasta){
    Normaliza normaliza;
    string palavra;
        for(const auto& arquivo : fs::directory_iterator(pasta)) {
            ifstream file(arquivo.path()); 
            
        while(file >> palavra){
            palavra = normaliza.normalizacao(palavra);
            mapaDe_Palavras[palavra][arquivo.path()]++;
        }
        file.close();
    }
}