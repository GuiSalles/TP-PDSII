#include <iostream>
#include <map>
#include <string>
#include <fstream>

using std::map;
using std::string;

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

string main(){

map<string, int> cout;
string file



}