#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

vector<string> arquivosEntrada;

void abreArquivo( string nome )
{
	ifstream entrada( nome.c_str(), ios::in );
	if ( !entrada )
	{
		cerr << "Erro ao abrir o arquivo \"" << nome << "\". Encerrando o programa." << endl;
		exit( 0 );
	}

	

}



int main()
{



	DIR *dp;
	struct dirent *ep;
	
	dp = opendir("./");
	if ( dp != NULL )
	{
		while ( ep = readdir(dp) )
			puts( ep->d_name );
		(void) closedir( dp );
	}
	else
		perror("Couldn't open the direcotry");
	return 0;
}
