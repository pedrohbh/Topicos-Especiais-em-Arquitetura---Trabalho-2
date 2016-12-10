
#include <stdio.h>
#include <string.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int
main()
{
	int pixel;
	int dim = 4;
	int n = 1;
	char nome[1024];
	FILE *f = fopen("arquivo.txt", "r");

	if (f == NULL)
		exit(printf("O arquivo de entrada nao foi encontrado!\n"));
	
	for (int i = 0; i < n; i ++)
	{
		Mat m(Size(dim, dim), CV_8UC1);

		for (int j = 0; j < dim * dim; j++)
		{
			fscanf(f, "%d", &pixel);
			m.data[j] = (unsigned char) pixel;
		}
		
		sprintf(nome, "%05d.png", i);
		imwrite(nome, m);
		printf("Imagem %s salva!\n", nome);
	}
	
	fclose(f);
	return 0;
}


