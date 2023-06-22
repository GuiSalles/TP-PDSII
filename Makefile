recuperador: build/main.o build/mapeador.o build/normalizador.o
	c++ -I include -std=c++17 build/main.o build/mapeador.o build/normalizador.o -o recuperador

build/main.o: src/main.cpp include/mapeador.h
	c++ -I include -std=c++17 -c src/main.cpp -o build/main.o

build/mapeador.o: src/funcoes/mapeador.cpp include/mapeador.h include/normalizador.h
	c++ -I include -std=c++17 -c src/funcoes/mapeador.cpp -o build/mapeador.o

build/normalizador.o: src/funcoes/normalizador.cpp include/normalizador.h
	c++ -I include -std=c++17 -c src/funcoes/normalizador.cpp -o build/normalizador.o