#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


int main( int argc, char *argv[] )
{
	if ( argc < 1 )
	{
		cerr << "Erro. Esqueceu de passar o arquivo via linha de comando." << endl;
		exit( 0 );
	}

	string nome = argv[ 1 ];
	string nomeSaida = nome + ".pos";
	string dado;
	string lixo;

	ifstream entrada( nome.c_str(), ios::in );
	ofstream saida( nomeSaida.c_str(), ios::out );
	if (!entrada || !saida )
	{
		cerr << "ERRO" << endl;
		exit( 0 );
	}

	while ( !entrada.eof() )
	{
		//getline( entrada, linha );
		entrada >> dado >> lixo;
		saida << dado << endl;		
	}
	entrada.close();
	saida.close();
	cout << "Concluído para \"" << nome << "\"." << endl;
}
