#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

using std::map;
using std::string;
using std::vector;

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

void mapear(){
}