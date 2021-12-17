#include "menu.h"
#include "avl.h"

void menu_avl(){

	system("clear");
	
	Tree_avl *raiz = avl_CreateTree();
	Tree_avl *aux = avl_CreateTree();
	Record_avl r;
	clock_t t; //variável para armazenar o tempo
	int num;

	FILE *file1, *file2, *file3, *file_search_1, *file_search_2, *file_search_3;
	file1 = fopen("1000.txt","r");
	file2 = fopen("10000.txt", "r");
	file3 = fopen("1000000.txt", "r");
	file_search_1 = fopen("search_5000.txt", "r");
	file_search_2 = fopen("search_10000.txt", "r");
	file_search_3 = fopen("search_100000.txt", "r");

	char *result; 
	char linha[50];

	printf("\nMENU_AVL\n\n");
	printf("Escolha qual árvore irá medir primeiro:\n");
	printf("1 - 1000 entradas\n");
	printf("2 - 10.000 entradas\n");
	printf("3 - 1.000.000 entradas\n");
	scanf("%d",&num);


	switch(num) {
		case 1:
			raiz = avl_CreateTree();
			t=clock();
			if(file1 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file1)) {
					result = fgets(linha, 50, file1);
		 			if(result){
			            r.key = atof(linha);
			            r.value = 1;
						avl_insertTree(&raiz, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("buscas na árvore: 5000 entradas\n");
			t=clock();
			if(file_search_1 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_1)) {
					result = fgets(linha, 50, file_search_1);
		 			if(result){
						r.key = atof(linha);
						avl_pesquisa(&raiz, &aux, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("buscas na árvore: 10.000 entradas\n");
			t=clock();
			if(file_search_2 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_2)) {
					result = fgets(linha, 50, file_search_2);
		 			if(result){
		 				r.key = atof(result);
						avl_pesquisa(&raiz, &aux, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("buscas na árvore: 100.000 entradas\n");
			t=clock();
			if(file_search_3 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_3)) {
					result = fgets(linha, 50, file_search_3);
		 			if(result){
						r.key = atof(result);
						avl_pesquisa(&raiz, &aux, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			break;

		case 2:
			raiz = avl_CreateTree();

			t=clock();
			if(file2 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file2)) {
					result = fgets(linha, 50, file2);
		 			if(result){
			            r.key = atof(linha);
			            r.value = 1;
						avl_insertTree(&raiz, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("buscas na árvore: 5000 entradas\n");
			t=clock();
			if(file_search_1 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_1)) {
					result = fgets(linha, 50, file_search_1);
		 			if(result){
						r.key = atof(linha);
						avl_pesquisa(&raiz, &aux, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("buscas na árvore: 10.000 entradas\n");
			t=clock();
			if(file_search_2 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_2)) {
					result = fgets(linha, 50, file_search_2);
		 			if(result){
						r.key = atof(linha);
						avl_pesquisa(&raiz, &aux, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("buscas na árvore: 100.000 entradas\n");
			t=clock();
			if(file_search_3 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_3)) {
					result = fgets(linha, 50, file_search_3);
		 			if(result){
						r.key = atof(linha);
						avl_pesquisa(&raiz, &aux, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			break;
		case 3:
			raiz = avl_CreateTree();

			t=clock();
			if(file3 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file3)) {
					result = fgets(linha, 50, file3);
		 			if(result){
			            r.key = atof(linha);
			            r.value = 1;
						avl_insertTree(&raiz, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("buscas na árvore: 5.000 entradas\n");
			t=clock();
			if(file_search_1 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_1)) {
					result = fgets(linha, 50, file_search_1);
		 			if(result){
						r.key = atof(linha);
						avl_pesquisa(&raiz, &aux, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("buscas na árvore: 10.000 entradas \n");
			t=clock();
			if(file_search_2 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_2)) {
					result = fgets(linha, 50, file_search_2);
		 			if(result){
						r.key = atof(linha);
						avl_pesquisa(&raiz, &aux, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("buscas na árvore: 100.000 entradas\n");
			t=clock();
			if(file_search_3 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_3)) {
					result = fgets(linha, 50, file_search_3);
		 			if(result){
						r.key = atof(linha);
						avl_pesquisa(&raiz, &aux, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));

			break;
		default:
			printf("Escolha uma opção válida!");
	}
	fclose(file1);
	fclose(file2);
	fclose(file3);
	fclose(file_search_1);
	fclose(file_search_2);
	fclose(file_search_3);
}