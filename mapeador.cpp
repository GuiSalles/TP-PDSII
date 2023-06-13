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
using std::ifstream;

namespace fs = std::filesystem;

void leitor(string pasta){
    for(const auto& arquivo : fs::directory_iterator(pasta)) {
        if(arquivo.is_regular_file()) {
            ifstream file(arquivo.path()); 
        }
    } 
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