#ifndef MAPEADOR_H
#define MAPEADOR_H
#include <map>
#include <string>

using std::map;
using std::string;

class Mapeador{
    public:

    void mapearPalavra(string pasta);

    private:
    map<string, map<string, int>> mapaDe_Palavras;
};
#endif