#include <stdio.h>
#include <stdlib.h>	
#include <fcntl.h>
#include <time.h>

int main(int argc, char *argv[]){

	clock_t s, e;
	s = clock();

	int tam = atoi(argv[1]), i;
	unlink("mdfile");
	int archivo = open("mdfile", O_CREAT | O_WRONLY, 0666);

	if(argc > 2){
		switch(argv[2][0]){
			case 'G':
				tam*=1000;
			case 'M':
				tam*=1000;
			case 'K':
				tam*=1000;
				break;
		}
	} 

	for(i = 0; i < tam; i++){
		if(write(archivo, "J", sizeof(char))<=0)
			printf("Error\n");
	}

	close(archivo);
	e = clock();
	printf("TIEMPO: %f segundos\n", ((double) (e - s) / CLOCKS_PER_SEC));
	
	return 0;
}