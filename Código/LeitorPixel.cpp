#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int *converteVectorParaArray( vector<int> v )
{
	int *vetor = (int *)malloc(sizeof( int ) * v.size() );
	if ( vetor == NULL )
	{
		cerr << "Erro ao alocar vetor de inteiros de tamanho " << v.size() << "." << endl;
		exit( 0 );
	}
	
	for ( int i = 0; i < v.size(); i++ )
		vetor[ i ] = v[ i ];

	return vetor;
}

void escreveArquivoSaida( string nomeArquivo, string aditivo, int *vetor, int tamanhoVetor )
{
	int tamanhoNovoNome = strlen( nomeArquivo.c_str() ) + strlen( aditivo.c_str() ) + 2;
	char *novoNome = (char *)malloc( sizeof( char ) * tamanhoNovoNome );
	char *nomeTemp = (char *)malloc( sizeof( char ) * ( strlen( nomeArquivo.c_str() ) + 1 ) );
	char *token;
	if ( nomeTemp == NULL || novoNome == NULL )
	{
		cerr << "Erro ao alocar string. Falta de Memória." << endl;
		exit( 0 );
	}
	strcpy( nomeTemp, nomeArquivo.c_str() );
	
	
	token = strtok( nomeTemp, "." );
	strcpy( novoNome, token );
	strcat( novoNome, "_" );
	strcat( novoNome, aditivo.c_str() );
	strcat( novoNome, "." );
	token = strtok( NULL, "." );
	strcat( novoNome, token );
	cout << "Novo nome: " << novoNome << endl;

	ofstream arquivoSaida( novoNome, ios::out );
	if ( !arquivoSaida )
	{
		cerr << "Erro ao criar arquivo de saida \"" << novoNome << "\". Encerrando o programa." << endl;
		exit( 0 );
	}
	
	for ( int i = 0; i < tamanhoVetor - 1; i++ )
	{
		arquivoSaida << vetor[ i ] << " ";
	}
	arquivoSaida << vetor[ tamanhoVetor - 1 ];
	free( novoNome );
	free( nomeTemp );
	
	
}

int *geraArquivoAdptado( string nomeArquivo, int *tamanhoVetor )
{
	vector<int> pixels;
	string nome = nomeArquivo;
	string linha;
	string aditivoNomeLinha;
	char *token;
	char *tokenAditivo;
	int tamanho;

	//cout << "Nome do Arquivo: " << nome << endl;
	
	ifstream arquivoEntrada( nome.c_str(), ios::in );
	if ( !arquivoEntrada )
	{
		cerr << "Erro ao abrir o arquivo de entrada \"" << nome << "\". Encerrando o programa." << endl;
		exit( 0 );
	}

	getline( arquivoEntrada, linha );
	//cout << "Linha" << endl << linha << endl << "Fim Linha" << endl;
	tamanho = strlen( linha.c_str() ) + 1;
	//char splitString[ tamanho ];

	char *splitString = (char *)malloc(sizeof(char) * tamanho );
	if ( splitString == NULL )
	{
		cerr << "Erro ao alocar splitString. Falta de memória" << endl;
		exit( 0 );
	}


	strcpy( splitString, linha.c_str() );

	aditivoNomeLinha = tokenAditivo = strtok( splitString , "," );
	token = strtok( NULL, "," );
	if ( tokenAditivo == NULL || token == NULL )
	{
		cerr << "A linha do arquivo entrada está inconsistente. Por-favor, verifique se o arquivo de entrada segue o padrão correto." << endl;
		exit( 0 );
	}


	strcpy( splitString, token );
	token = strtok( splitString, " " );
	// Leitura de pixels
	while ( token != NULL )
	{
		//cout << token << endl;
		pixels.push_back( atoi( token ) );
		cout << pixels.back() << endl;
		token = strtok( NULL, " " );
	}

	cout << endl;
	int *vetorPixels = converteVectorParaArray( pixels );
	/*for ( int i = 0; i < pixels.size(); i++ )
	{
		cout << vetorPixels[ i ] << endl;
	}*/

	free( splitString );

	escreveArquivoSaida( nome, aditivoNomeLinha, vetorPixels, pixels.size() );
	*tamanhoVetor = pixels.size();
	return vetorPixels;
}

int *geraVetorImagemPorLinha( string nomeArquivo, int *tamanhoVetor, char **nomeArquivoSaida, ifstream &arquivoEntrada )
{
	vector<int> pixels;
	string nome = nomeArquivo;
	string linha;
	string aditivoNomeLinha;
	char *token;
	char *tokenAditivo;
	int tamanho;

	//cout << "Nome do Arquivo: " << nome << endl;
	
	/*ifstream arquivoEntrada( nome.c_str(), ios::in );
	if ( !arquivoEntrada )
	{
		cerr << "Erro ao abrir o arquivo de entrada \"" << nome << "\". Encerrando o programa." << endl;
		exit( 0 );
	}*/

	getline( arquivoEntrada, linha );
	if ( strcmp( linha.c_str(), "\n" ) == 0 || strcmp( linha.c_str(), "" ) == 0 )
		return NULL;
	//cout << "Linha" << endl << linha << endl << "Fim Linha" << endl;
	tamanho = strlen( linha.c_str() ) + 1;
	//char splitString[ tamanho ];

	char *splitString = (char *)malloc(sizeof(char) * tamanho );
	if ( splitString == NULL )
	{
		cerr << "Erro ao alocar splitString. Falta de memória" << endl;
		exit( 0 );
	}


	strcpy( splitString, linha.c_str() );

	aditivoNomeLinha = tokenAditivo = strtok( splitString , "," );
	token = strtok( NULL, "," );
	if ( tokenAditivo == NULL || token == NULL )
	{
		cerr << "A linha do arquivo entrada está inconsistente. Por-favor, verifique se o arquivo de entrada segue o padrão correto." << endl;
		exit( 0 );
	}


	strcpy( splitString, token );
	token = strtok( splitString, " " );
	// Leitura de pixels
	while ( token != NULL )
	{
		//cout << token << endl;
		pixels.push_back( atoi( token ) );
		//cout << pixels.back() << endl;
		token = strtok( NULL, " " );
	}

	//cout << endl;
	int *vetorPixels = converteVectorParaArray( pixels );
	
	free( splitString );

	//escreveArquivoSaida( nome, aditivoNomeLinha, vetorPixels, pixels.size() );
	(*nomeArquivoSaida) = (char *)malloc(sizeof( char ) * ( strlen(aditivoNomeLinha.c_str()) + 1 ) );
	if ( (*nomeArquivoSaida) == NULL )
	{
		cerr << "Erro ao alocar nome do arquivo saida." << endl;
		exit( 0 );
	}
	strcpy( (*nomeArquivoSaida), aditivoNomeLinha.c_str() );
	*tamanhoVetor = pixels.size();
	return vetorPixels;
}

/* PARA TESTES E EXEMPLO DE USO */
/*int main()
{
	int tamanhoVetor;
	geraArquivoAdptado( "exemplo.dat", &tamanhoVetor );
	cout << "SUCESS " << tamanhoVetor << endl;
}*/
