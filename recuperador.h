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
using std::map;
using std::vector;

class{
    public:
    void recuperacao(map<string, map<string, int>>& mapaDe_Palavras, vector<string>& busca);


    private:
    string palavra;
    vector<string> busca;
};





#endif