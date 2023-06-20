#include "mapeador.h"
#include "normalizador.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>

using std::ifstream;
using std::endl;
using std::cout;

namespace fs = std::filesystem;

void Mapeador::mapearPalavra(string pasta) {
    Normaliza normaliza;
    string palavra;
    for (auto arquivo : fs::directory_iterator(pasta)) {
        ifstream file(arquivo.path());

        while (file >> palavra) {
            palavra = normaliza.normalizacao(palavra);
            mapaDe_Palavras[palavra][arquivo.path()]++;
        }
        file.close();
    }
}

void Mapeador::buscarPalavra(vector<string> palavras) {
    Normaliza normaliza;

    vector<string> arquivosComTodasAsPalavras;

    for (const string& palavra : palavras) {
        string palavraBusca = normaliza.normalizacao(palavra);
        if (mapaDe_Palavras.count(palavraBusca) > 0) {
            const map<string, int>& ocorrencias = mapaDe_Palavras[palavraBusca];
            if (arquivosComTodasAsPalavras.empty()) {
                for (const auto& it : ocorrencias) {
                    arquivosComTodasAsPalavras.push_back(it.first);
                }
            } else {
                vector<string> arquivosTemp;
                for (const auto& arquivo : arquivosComTodasAsPalavras) {
                    if (ocorrencias.count(arquivo) > 0) {
                        arquivosTemp.push_back(arquivo);
                    }
                }
                arquivosComTodasAsPalavras = arquivosTemp;
            }
        } else {
            cout << "A(s) palavra(s) não foi/foram encontrada(s) nos documentos" << endl;
            return;
        }
    }

    for (const string& palavra : palavras) {
        cout << palavra << " ";
    }
    cout << endl;

    if (arquivosComTodasAsPalavras.empty()) {
        cout << "Palavras existem, mas em arquivos diferentes" << endl;
    } else {
        sort(arquivosComTodasAsPalavras.begin(), arquivosComTodasAsPalavras.end(), [&](const string& arquivo1, const string& arquivo2) {
            int ocorrencias1 = 0;
            int ocorrencias2 = 0;
            for (const string& palavra : palavras) {
                ocorrencias1 += mapaDe_Palavras[normaliza.normalizacao(palavra)][arquivo1];
                ocorrencias2 += mapaDe_Palavras[normaliza.normalizacao(palavra)][arquivo2];
            }
            return ocorrencias1 > ocorrencias2;
        });
        for (const string& arquivo : arquivosComTodasAsPalavras) {
            cout << fs::path(arquivo).filename() << endl;
        }
    }
}
