#include "avl.h"
//#include "rbt.h"
#include "binaria.h"
//#include "treeRB.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX 10
#define MIL 1000
#define DEZ_MIL 10000
#define CEM_MIL 100000

void menu_avl();
void menu_rubro_negro();
void menu_binaria();
void preenche();

int main(){

	int op;

	system("clear");

	do{
		printf("\n------MENU------\n\n");
		printf("Qual árvore deseja manusear? \n\n");

		printf("0 - Sair\n");
		printf("1 - árvore binária\n");
		printf("2 - árvore AVL\n");
		printf("3 - árvore Rubro Negra\n");
		printf("4 - Preencher arquivos");
		scanf("%d", &op);
		switch(op){
			case 0:
				printf("Saindo...");
				break;
			case 1:
				printf("Árvore Binária");
				menu_binaria();
				break;
			case 2:
				printf("Árvore AVL");
				menu_avl();
				break;
			case 3:
				printf("Árvore Rubro Negra");
				menu_rubro_negro();
				break;
			case 4:
				printf("preenchendo...");
				preenche();
				break;
			default:
				printf("Escolha uma opção válida!\n");
				break;
		}
	}while(op != 0);

	printf("Fim...");

	return 0;
}

void menu_avl(){

	system("clear");
	
	Tree_avl *raiz = avl_CreateTree();
	Tree_avl *aux = avl_CreateTree();
	Record_avl r;
	clock_t t; //variável para armazenar o tempo
	int num;
	int cont = 0;

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
				printf("teste2\n");
				while(!feof(file1)) {
					result = fgets(linha, 50, file1);
		 			if(result){
			            r.key = atof(linha);
			            r.value = 1;
						//printf("%s", linha);
						avl_insertTree(&raiz, r, &cont);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			printf("contador de 1000 : %d\n", cont);
// /*
// 			t=clock();
// 			printf("\nÁrvore AVL ordenada\n");
// 		  	printf("{ ");
// 		  	avl_central(raiz);
// 			printf("}\n\n");
// 			t=clock() - t;
// */
			printf("buscas na árvore: 5000 entradas\n");
			t=clock();
			if(file_search_1 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_1)) {
					result = fgets(linha, 50, file_search_1);
		 			if(result){
						r.key = atof(linha);
						//printf("%s", linha);
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
						//printf("%s", linha);
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
						//printf("%s", linha);
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
						//printf("%s", linha);
						avl_insertTree(&raiz, r, &cont);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			printf("contador de 10000 : %d\n", cont);
/*
			t=clock();
			printf("\nÁrvore AVL ordenada\n");
		  	printf("{ ");
		  	avl_central(raiz);
			printf("}\n\n");
			t=clock() - t;
*/

			printf("buscas na árvore: 5000 entradas\n");
			t=clock();
			if(file_search_1 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_1)) {
					result = fgets(linha, 50, file_search_1);
		 			if(result){
						//printf("%s", linha);
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
						//printf("%s", linha);
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
						//printf("%s", linha);
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
					result = fgets(linha, 50, file1);
		 			if(result){
			            r.key = atof(linha);
			            r.value = 1;
						//printf("%s", linha);
						avl_insertTree(&raiz, r, &cont);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			printf("contador de 1.000.000 : %d\n", cont);
/*
			t=clock();
			printf("\nÁrvore AVL ordenada\n");
		  	printf("{ ");
		  	avl_central(raiz);
			printf("}\n\n");
			t=clock() - t;
*/

			printf("buscas na árvore: 5.000 entradas\n");
			t=clock();
			if(file_search_1 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_1)) {
					result = fgets(linha, 50, file_search_1);

		 			if(result){
						//printf("%s", linha);
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
						//printf("%s", linha);
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
						//printf("%s", linha);
						r.key = atof(linha);
						avl_pesquisa(&raiz, &aux, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

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

void menu_rubro_negro() {

    // TNoRB *arvore = NULL;
    // clock_t t; //variável para armazenar o tempo
    // int opc = -1, flag = 1, n, rn;
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

    
		printf("\nMENU_RED_BLACK\n\n");
		printf("Escolha qual inserção irá medir primeiro:\n");
		printf("1 - 1000 entradas\n");
		printf("2 - 10.000 entradas\n");
		printf("3 - 1.000.000 entradas\n");
		scanf("%d",&num);

        switch(num) {
			case 1:/*
				t=clock();
				if(file3 == NULL)
				  printf("Erro ao abrir\n");
				else {
					while(!feof(file3)) {
						result = fgets(linha, 50, file1);
			 			if(result){
				            n = atof(linha);
							//printf("%s", linha);
							insereNo(&arvore, NULL, &arvore, n);
			 			}
				 	}
				}
				t=clock() - t;

				printf("buscas na árvore: 5.000 entradas\n");
				t=clock();
				if(file_search_1 == NULL)
				  printf("Erro ao abrir\n");
				else {
					while(!feof(file_search_1)) {
						result = fgets(linha, 50, file_search_1);
			 			if(result){
							//printf("%s", linha);
							n = atof(linha);
							searchRB(&arvore, n);
			 			}
				 	}
				}
				t=clock() - t;

				printf("buscas na árvore: 10.000 entradas \n");
				t=clock();
				if(file_search_2 == NULL)
				  printf("Erro ao abrir\n");
				else {
					while(!feof(file_search_2)) {
						result = fgets(linha, 50, file_search_2);
			 			if(result){
							//printf("%s", linha);
							n = atof(linha);
							searchRB(&arvore, n);
			 			}
				 	}
				}
				t=clock() - t;

				printf("buscas na árvore: 100.000 entradas\n");
				t=clock();
				if(file_search_3 == NULL)
				  printf("Erro ao abrir\n");
				else {
					while(!feof(file_search_3)) {
						result = fgets(linha, 50, file_search_3);
			 			if(result){
							//printf("%s", linha);
							n = atof(linha);
							searchRB(&arvore, n);
			 			}
				 	}
				}
				t=clock() - t;*/
				break;

			case 2:/*
				t=clock();
				if(file3 == NULL)
				  printf("Erro ao abrir\n");
				else {
					while(!feof(file3)) {
						result = fgets(linha, 50, file1);
			 			if(result){
				            n = atof(linha);
							//printf("%s", linha);
							insereNo(&arvore, NULL, &arvore, n);
			 			}
				 	}
				}
				t=clock() - t;

				t=clock();
				printf("\nÁrvore AVL ordenada\n");
			  	printf("{ ");
			  	avl_central(raiz);
				printf("}\n\n");
				t=clock() - t;


				printf("buscas na árvore: 5.000 entradas\n");
				t=clock();
				if(file_search_1 == NULL)
				  printf("Erro ao abrir\n");
				else {
					while(!feof(file_search_1)) {
						result = fgets(linha, 50, file_search_1);
			 			if(result){
							//printf("%s", linha);
							n = atof(linha);
							searchRB(&arvore, n);
			 			}
				 	}
				}
				t=clock() - t;

				printf("buscas na árvore: 10.000 entradas \n");
				t=clock();
				if(file_search_2 == NULL)
				  printf("Erro ao abrir\n");
				else {
					while(!feof(file_search_2)) {
						result = fgets(linha, 50, file_search_2);
			 			if(result){
							//printf("%s", linha);
							n = atof(linha);
							searchRB(&arvore, n);
			 			}
				 	}
				}
				t=clock() - t;

				printf("buscas na árvore: 100.000 entradas\n");
				t=clock();
				if(file_search_3 == NULL)
				  printf("Erro ao abrir\n");
				else {
					while(!feof(file_search_3)) {
						result = fgets(linha, 50, file_search_3);
			 			if(result){
							//printf("%s", linha);
							n = atof(linha);
							searchRB(&arvore, n);
			 			}
				 	}
				}
				t=clock() - t;*/
				break;


			case 3:/*
				t=clock();
				if(file3 == NULL)
				  printf("Erro ao abrir\n");
				else {
					while(!feof(file3)) {
						result = fgets(linha, 50, file1);
			 			if(result){
				            n = atof(linha);
							//printf("%s", linha);
							insereNo(&arvore, NULL, &arvore, n);
			 			}
				 	}
				}
				t=clock() - t;

				t=clock();
				printf("\nÁrvore AVL ordenada\n");
			  	printf("{ ");
			  	avl_central(raiz);
				printf("}\n\n");
				t=clock() - t;


				printf("buscas na árvore: 5.000 entradas\n");
				t=clock();
				if(file_search_1 == NULL)
				  printf("Erro ao abrir\n");
				else {
					while(!feof(file_search_1)) {
						result = fgets(linha, 50, file_search_1);
			 			if(result){
							//printf("%s", linha);
							n = atof(linha);
							searchRB(&arvore, n);
			 			}
				 	}
				}
				t=clock() - t;

				printf("buscas na árvore: 10.000 entradas \n");
				t=clock();
				if(file_search_2 == NULL)
				  printf("Erro ao abrir\n");
				else {
					while(!feof(file_search_2)) {
						result = fgets(linha, 50, file_search_2);
			 			if(result){
							//printf("%s", linha);
							n = atof(linha);
							searchRB(&arvore, n);
			 			}
				 	}
				}
				t=clock() - t;

				printf("buscas na árvore: 100.000 entradas\n");
				t=clock();
				if(file_search_3 == NULL)
				  printf("Erro ao abrir\n");
				else {
					while(!feof(file_search_3)) {
						result = fgets(linha, 50, file_search_3);
			 			if(result){
							//printf("%s", linha);
							n = atof(linha);
							searchRB(&arvore, n);
			 			}
				 	}
				}
				t=clock() - t;*/
				break;

            default:
                printf("Opção inválida.\n");
                break;
        }
	fclose(file1);
	fclose(file2);
	fclose(file3);

	fclose(file_search_1);
	fclose(file_search_2);
	fclose(file_search_3);
}


void menu_binaria(){

	system("clear");

	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;
	clock_t t; //variável para armazenar o tempo
	int esc;

	FILE *file1, *file2, *file3, *file_search_1, *file_search_2, *file_search_3;
	file1 = fopen("1000.txt","r");
	file2 = fopen("10000.txt", "r");
	file3 = fopen("1000000.txt", "r");
	file_search_1 = fopen("search_5000.txt", "r");
	file_search_2 = fopen("search_10000.txt", "r");
	file_search_3 = fopen("search_100000.txt", "r");

	char *result; 
	char linha[50];

	printf("\nMENU_Binária\n\n");
	printf("Escolha:\n");
	printf("1 - 1000 entradas\n");
	printf("2 - 10.000 entradas\n");
	printf("3 - 1.000.000 entradas\n");
	scanf("%d",&esc);

	switch(esc) {
		case 1:
			raiz = CreateTree();

			t=clock();
			if(file1 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file1)) {
					result = fgets(linha, 50, file1);
		 			if(result){
		            	r.key = atof(linha);
			            r.value = 1;
			            insertTree(&raiz, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

/*
			t=clock();
			printf("\nÁrvore AVL ordenada\n");
		  	printf("{ ");
		  	central(raiz);
			printf("}\n\n");
			t=clock() - t;
*/
			printf("buscas na árvore: 5.000 entradas\n");
			t=clock();
			if(file_search_1 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_1)) {
					result = fgets(linha, 50, file_search_1);
		 			if(result){
						r.key = atof(linha);
						pesquisa(&raiz, &aux, r);
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
						pesquisa(&raiz, &aux, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("buscas na árvore: 100.000 entradas \n");
			t=clock();
			if(file_search_3 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_3)) {
					result = fgets(linha, 50, file_search_3);
		 			if(result){
						r.key = atof(linha);
						pesquisa(&raiz, &aux, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			break;
		case 2:
			raiz = CreateTree();

			t=clock();
			if(file2 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file2)) {
					result = fgets(linha, 50, file2);
		 			if(result){
		            	r.key = atof(linha);
			            r.value = 1;
			            insertTree(&raiz, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

/*
			t=clock();
			printf("\nÁrvore AVL ordenada\n");
		  	printf("{ ");
		  	central(raiz);
			printf("}\n\n");
			t=clock() - t;
*/
			printf("buscas na árvore: 5.000 entradas\n");
			t=clock();
			if(file_search_1 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_1)) {
					result = fgets(linha, 50, file_search_1);
		 			if(result){
						r.key = atof(linha);
						pesquisa(&raiz, &aux, r);
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
						pesquisa(&raiz, &aux, r);
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
						pesquisa(&raiz, &aux, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			break;
		case 3:
			raiz = CreateTree();

			t=clock();
			if(file3 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file3)) {
					result = fgets(linha, 50, file3);
		 			if(result){
		            	r.key = atof(linha);
			            r.value = 1;
			            insertTree(&raiz, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

/*
			t=clock();
			printf("\nÁrvore AVL ordenada\n");
		  	printf("{ ");
		  	central(raiz);
			printf("}\n\n");
			t=clock() - t;
*/
			printf("buscas na árvore: 5.000 entradas\n");
			t=clock();
			if(file_search_1 == NULL)
			  printf("Erro ao abrir\n");
			else {
				while(!feof(file_search_1)) {
					result = fgets(linha, 50, file_search_1);
		 			if(result){
						r.key = atof(linha);
						pesquisa(&raiz, &aux, r);
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
						pesquisa(&raiz, &aux, r);
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
						pesquisa(&raiz, &aux, r);
		 			}
			 	}
			}
			t=clock() - t;
			printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			break;
		default:
			printf("Escolha uma opção válida!");
			break;
	}
	fclose(file1);
	fclose(file2);
	fclose(file3);

	fclose(file_search_1);
	fclose(file_search_2);
	fclose(file_search_3);
}

void preenche() {
	system("clear");

	float arq_1[MIL], arq_2[DEZ_MIL], arq_3[1000000], array_search_1[5000], array_search_2[10000], array_search_3[100000];
	char array_1[1000];
	char array_2[10000];
	char array_3[1000000];
	char array_search_primeiro[5000];
	char array_search_segundo[10000];
	char array_search_terceiro[100000];
	FILE *file1, *file2, *file3, *file_search_1, *file_search_2, *file_search_3;
	file1 = fopen("1000.txt","w");
	file2 = fopen("10000.txt", "w");
	file3 = fopen("1000000.txt", "w");
	file_search_1 = fopen("search_5000.txt", "w");
	file_search_2 = fopen("search_10000.txt", "w");
	file_search_3 = fopen("search_100000.txt", "w");


	printf("\nPreenchendo arquivo MIL...\n");
	for(int i=0; i<MIL ; i++){
		arq_1[i] = 1 + (float)rand() / (float)RAND_MAX *100000;
	    sprintf(array_1, "%.6f", arq_1[i]);
	    strcat(array_1, "\n");
	    fputs(array_1, file1);
	}

	printf("Preenchendo arquivo DEZ_MIL...\n");
	for(int i=0; i<DEZ_MIL ; i++){
		arq_2[i] = 1 + (float)rand() / (float)RAND_MAX *100000;
	    sprintf(array_2, "%.6f", arq_2[i]);
	    strcat(array_2, "\n");
	    fputs(array_2, file2);
	}

	printf("Preenchendo arquivo UM_MILHAO...\n");
	for(int i=0; i<1000000 ; i++){
		arq_3[i] = 1 + (float)rand() / (float)RAND_MAX *100000;
	    sprintf(array_3, "%.6f", arq_3[i]);
	    strcat(array_3, "\n");
	    fputs(array_3, file3);
	}

	printf("Preenchendo arquivo search_5000...\n");

		  	for(int i=0; i<5000; i++){
		  		array_search_1[i] = 1 + (float)rand() / (float)RAND_MAX *100000;
	            sprintf(array_search_primeiro, "%.6f", array_search_1[i]);
	            strcat(array_search_primeiro, "\n");
	            fputs(array_search_primeiro, file_search_1);
			}

	printf("Preencher arquivo search_10000...\n");


		  	for(int i=0; i<10000; i++){
		  		array_search_2[i] = 1 + (float)rand() / (float)RAND_MAX *100000;
	            sprintf(array_search_segundo, "%.6f", array_search_2[i]);
	            strcat(array_search_segundo, "\n");
	            fputs(array_search_segundo, file_search_2);
			}

	printf("Preencher arquivo search_100000...\n");


		  	for(int i=0; i<100000; i++){
		  		array_search_3[i] = 1 + (float)rand() / (float)RAND_MAX *100000;
	            sprintf(array_search_terceiro, "%.6f", array_search_3[i]);
	            strcat(array_search_terceiro, "\n");
	            fputs(array_search_terceiro, file_search_3);
			}

	fclose(file1);
	fclose(file2);
	fclose(file3);

	fclose(file_search_1);
	fclose(file_search_2);
	fclose(file_search_3);
}