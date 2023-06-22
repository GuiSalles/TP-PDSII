#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <filesystem>
#include "mapeador.h"

using std::string;
using std::vector;
using std::cin;
using std::getline;
using std::istringstream;


int main(){
    Mapeador mapeador;
    mapeador.mapearPalavra("./documents/");

    string entrada;

    getline(cin, entrada);

    vector<string> palavras;
    istringstream iss(entrada);
    string palavra;

    while (iss>>palavra){
        palavras.push_back(palavra);
    }

    mapeador.buscarPalavra(palavras);

    return 0;
}
