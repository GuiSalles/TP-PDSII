#include "recuperador.h"

    Recupera::Recupera(){
        vector<string> busca;
        
    }

    void Recupera::recuperacao(map<string, map<string, int>>& mapaDe_Palavras, vector<string>& busca){

    map<string, vector<pair<string, int>>> resultados;
    
    for (auto it = busca.begin(); it != busca.end(); ++it){
        string palavra_busca = *it;

        if(mapaDe_Palavras.count(palavra_busca) > 0){
            for (auto it = mapaDe_Palavras.at(palavra_busca).begin(); it != mapaDe_Palavras.at(palavra_busca).end(); ++it){
                string codDoc = it -> first;
                int quant = it -> second;

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

