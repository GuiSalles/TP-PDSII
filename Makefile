recuperador: main.o mapeador.o normalizador.o
    c++ -I . -std=c++17 main.o mapeador.o normalizador.o -o recuperador

main.o: main.cpp mapeador.h
    c++ -I . -std=c++17 -c main.cpp

mapeador.o: mapeador.cpp mapeador.h normalizador.h
    c++ -I . -std=c++17 -c mapeador.cpp

normalizador.o: normalizador.cpp normalizador.h
    c++ -I . -std=c++17 -c normalizador.cpp
