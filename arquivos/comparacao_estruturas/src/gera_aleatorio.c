//gera_aleatorio

#include <time.h>
#include <stdlib.h>

bool Existe(int valores[], int tam, int valor){
	for(int i=0; i<tam;i++){
		if(valores[i]==valor){
			return true;
		}
	}
	return false;
}

void GerarAleatorios(int numeros[], int quantNumeros, int Limite){
	srand(time(NULL));

	int v;
	for(int i=0; i<quantNumeros; i++){
		v=rand() % Limite;
		while(Existe(numeros,i,v)){
			v=rand()%Limite;
		}
		numeros[i]=v;
	}
}