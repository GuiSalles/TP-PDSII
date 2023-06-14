#ifndef RECUPERADORR_H_
#define RECUPERADORR_H_
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>

using std::string;
using std::isalpha;
using std::tolower;
using std::cin;
using std::cout; 
using std::endl;
using std::map;
using std::vector;
using std::pair;

class Recupera{
    public:

    Recupera();
    void recuperacao(map<string, map<string, int>>& mapaDe_Palavras, vector<string>& busca);


    private:
    string palavra;
    vector<string> busca;
};





#endif