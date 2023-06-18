#include "mapeador.h"
#include "normalizador.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <utility>

using std::map;
using std::string;
using std::vector;
using std::ifstream;
using std::endl;
using std::cout;
using std::sort;
using std::pair;

namespace fs = std::filesystem;

void Mapeador::mapearPalavra(string pasta){
    Normaliza normaliza;
    string palavra;
        for(auto arquivo : fs::directory_iterator(pasta)) {
            ifstream file(arquivo.path()); 
            
        while(file >> palavra){
            palavra = normaliza.normalizacao(palavra);
            mapaDe_Palavras[palavra][arquivo.path()]++;
        }
        file.close();
    }
}

void Mapeador::buscarPalavra(vector<string> palavras){
    Normaliza normaliza;

    map<string, vector<pair<string, int>>> resultados;

    for (auto it = palavras.begin(); it != palavras.end(); ++it){
        string palavra_busca = normaliza.normalizacao(*it);
        if(mapaDe_Palavras.count(palavra_busca) > 0){
            for (auto it2 = mapaDe_Palavras.at(palavra_busca).begin(); it2 != mapaDe_Palavras.at(palavra_busca).end(); ++it2){
                string codDoc = it2->first;
                int quant = it2->second;

                resultados[palavra_busca].push_back(make_pair(codDoc, quant));
            }
        }
        else {
            cout << "A palavra está fora dos documentos" << endl;
        }
    }

    for(auto& mapa : resultados){
        vector<pair<string, int>>& aux = mapa.second;

        sort(aux.begin(), aux.end(), [](pair<string, int> a, pair<string, int> b){
            if(a.second == b.second){
                return a.first < b.first;
            } 
                return a.second > b.second;
        });
    }

    for ( auto& mapa : resultados){

        vector<pair<string, int>>& aux = mapa.second;

        cout<< mapa.first << " ";

        for(auto it = aux.begin(); it != aux.end(); ++it){
            cout << "(" << it ->first << ", " << it -> second;
            if (it != aux.end()-1){
                cout << "), ";
            }
            else {
                cout << ")";
            }
        } 
        cout << endl;
    }
}