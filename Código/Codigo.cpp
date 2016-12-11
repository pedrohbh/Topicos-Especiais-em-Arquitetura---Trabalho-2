#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "LeitorPixel.h"
using namespace cv;
using namespace std;

int main( int argc, char *argv[] )
{
	string nome;

	if ( argc < 2 )
	{
		cout << "Digite o nome do arquivo de entrada completo. Exemplo: \"exemplo_imagens.csv\" (sem as aspas)." << endl;
		cout << "Arquivo Entrada: ";
		cin >> nome;
	}
	else
		nome = argv[ 1 ];

	ifstream entrada( nome.c_str(), ios::in );
	if ( !entrada )
	{
		cerr << "Erro ao abrir o arquivo \"" << nome << "\". Verifique se o mesmo existe ou se foi digitado corretamente." << endl;
		exit( 0 );
	}

	char *nomeSaida;
	int *vetor;
	int tamanhoVetor;
	int dim = 48;

	while ( !entrada.eof() )
	{
		vetor = geraVetorImagemPorLinha( nome, &tamanhoVetor, &nomeSaida, entrada );
		if ( vetor == NULL )
			continue;
		string saida = nomeSaida;
		saida = saida + ".png";
		
		Mat m(Size(dim, dim), CV_8UC1);

		for (int j = 0; j < dim * dim; j++)
		{
			//fscanf(f, "%d", &pixel);
			m.data[j] = (unsigned char) vetor[ j ];
		}
		
		imwrite(saida, m);
		cout << "Imagem " << saida << " salva!" << endl;
		free( nomeSaida );
		free( vetor );
	}
	entrada.close();

}


