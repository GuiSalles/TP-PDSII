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
<<<<<<< HEAD
    mapeador.mapearPalavra("./Documents/");

    string entrada;
=======

    Mapeador.mapearPalavra("./Documents/");
>>>>>>> 5a9e0ab22b52febba03bde881c88900aede22899

    getline(cin, entrada);

    vector<string> palavras;
    istringstream iss(entrada);
    string palavra;

    while (iss>>palavra){
        palavras.push_back(palavra);
    }

    mapeador.buscarPalavra(palavras);

    return 0;
<<<<<<< HEAD
}
=======
}
    

>>>>>>> 5a9e0ab22b52febba03bde881c88900aede22899
