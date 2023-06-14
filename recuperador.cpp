#include "recuperador.h"

    Recupera::Recupera(){
        vector<string> busca;
    }

    void Recupera::recuperacao(map<string, map<string, int>>& mapaDe_Palavras, vector<string>& busca){

    map<string, vector<pair<string, int>>> resultados;
    
    for (auto it = busca.begin(); it != busca.end(); ++it){
        string palavra = *it;

        if(mapaDe_Palavras.count(palavra) > 0){
            for (auto it = mapaDe_Palavras.at(palavra).begin(); it != mapaDe_Palavras.at(palavra).end(); ++it){
                string codDoc = it -> first;
                int quant = it -> second;

                resultados[palavra].push_back(make_pair(codDoc, quant));
            }
        }
        else {
            cout << "A palavra está fora dos documentos" << endl;
        }

    }
    
}

