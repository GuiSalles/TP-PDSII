#ifndef MAPEADOR_H
#define MAPEADOR_H
#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

class Mapeador{
    public:

    void mapearPalavra(string pasta);
    void buscarPalavra(vector<string> palavras);

    private:
    map<string, map<string, int>> mapaDe_Palavras;
};
#endif