#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

vector<string> arquivos;

void abreArquivo( string nome )
{
	ifstream entrada( nome.c_str(), ios::in );
	string dado;
	string lixo;
	if ( !entrada )
	{
		cerr << "Erro ao abrir o arquivo \"" << nome << "\". Encerrando o programa." << endl;
		exit( 0 );
	}

	while ( !entrada.eof() )
	{
		entrada >> dado >> lixo;
		arquivos.push_back( dado );
	}
	entrada.close();	

}



int main()
{
	string nomeEntrada; //= "BaseTesteII.pos";
	string diretorio;
	string atual;
	bool buscaLocal = false;
	bool buscaGlobal = true;

	cout << "Digite o nome do arquivo de entrada (exemplo \"BaseTesteII.csv\"): ";
	cin >> nomeEntrada;
	
	cout << "Digite o diretório onde se encontram os arquivos (para o diretório local digite \"./\"): ";
	cin >> diretorio;
	
	abreArquivo( nomeEntrada );

	cout << endl << endl << "========================================Iniciando busca de arquivos contidos em \"" << nomeEntrada << "\"===================================================================" << endl << endl;
	DIR *dp;
	struct dirent *ep;

	for ( int i = 0; i < arquivos.size(); i++ )
	{
		atual = arquivos[ i ];
		dp = opendir(diretorio.c_str());
		if ( dp != NULL )
		{
			while ( ep = readdir( dp ) )
			{
				if ( strcmp( atual.c_str(), ep->d_name ) == 0 )
				{
					buscaLocal = true;
					break;
				}					
				
			}
			if ( buscaLocal == false )
			{
				cout << "O arquivo \"" << atual << "\" não foi encontrado." << endl;
				buscaGlobal = false;
			}
			buscaLocal = false;
			(void) closedir( dp );			
		}
		else
		{
			perror("Não foi possível abrir o especificado. Verifique se o mesmo existe");
			exit( 0 );
		}
	}
		if ( buscaGlobal == true )
			cout << "Todos os arquivos de \"" << nomeEntrada << "\" foram encontrados com sucesso." << endl;

		buscaGlobal = true;

	cout << endl << endl << "===================================================================FIM BUSCA===============================================================================================================" << endl;
	
	/*dp = opendir("./");
	if ( dp != NULL )
	{
		for ( int i = 0; i < arquivos.size(); i++ )
		{
			while ( ep = readdir(dp) )
				puts( ep->d_name );
			(void) closedir( dp );
		}
	}
	else
		perror("Couldn't open the direcotry");*/
	return 0;
}
