#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <fstream>
#include <filesystem>

using std::map;
using std::string;
using std::vector;

namespace fs = std::filesystem;

void leitor(const string& pasta){
    
}

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