#include "recuperador.h"

    Recupera::Recupera(){
        vector<string> busca;
    }

    void Recupera::recuperacao(map<string, map<string, int>>& mapaDe_Palavras, vector<string>& busca){
        
    //Declaração de um vetor de pares que armazenará o codigo do documento e a quantidade
    map<string, vector<pair<string, int>>> resultados;
    
    //Iterando as palavras do vetor busca
    for (auto it = busca.begin(); it != busca.end(); ++it){
        string palavra = *it;
        //Verifica se contém a palavra no Indice
        if(mapaDe_Palavras.count(palavra) > 0){
            //Iterando sobre as palavras
            for (auto it = mapaDe_Palavras.at(palavra).begin(); it != mapaDe_Palavras.at(palavra).end(); ++it){
                string codDoc = it -> first;
                int quant = it -> second;

                //Adiciona os itens ao pair
                resultados[palavra].push_back(make_pair(codDoc, quant));
            }
        }
        else {
            cout << "A palavra está fora dos documentos" << endl;
        }

    }
    //Ordenando o vetor de pair
    for(auto& mapa : resultados){
        vector<pair<string, int>>& aux = mapa.second;

        sort(aux.begin(), aux.end(), [](pair<string, int> a, pair<string, int> b){
            if(a.second == b.second){
                return a.first < b.first;
            }
                return a.second > b.second;
        });
    }
    // Imprimindo o map resultados
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

    }
