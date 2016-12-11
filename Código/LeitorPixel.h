#ifndef LEITORPIXEL_H
#define LEITORPIXEL_H
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int *geraArquivoAdptado( string nomeArquivo, int *tamanhoVetor );

int *geraVetorImagemPorLinha( string nomeArquivo, int *tamanhoVetor, char **nomeArquivoSaida, ifstream &arquivoEntrada );

#endif
