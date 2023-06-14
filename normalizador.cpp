#include "normalizador.h"
#include <string>
#include <filesystem>

using std::string;

string Normaliza::normalizacao(string palavra){
    palavranormalizada = " ";
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