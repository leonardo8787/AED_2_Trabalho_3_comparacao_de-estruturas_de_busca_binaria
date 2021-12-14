#include "avl.h"
#include "rbt.h"
#include "binaria.h"

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

int main(){

	int op;

	system("clear || cls");

	do{
		printf("\n------MENU------\n\n");
		printf("Qual árvore deseja manusear? \n\n");

		printf("0 - Sair\n");
		printf("1 - árvore binária\n");
		printf("2 - árvore AVL\n");
		printf("3 - árvore Rubro Negra\n");
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
			default:
				printf("Escolha uma opção válida!\n");
				break;
		}
	}while(op != 0);

	printf("Fim...");

	return 0;
}

void menu_avl(){

	system("cls || clear");
	
	Tree_avl *raiz = avl_CreateTree();
	Tree_avl *aux = avl_CreateTree();
	Record_avl r;
	float reg1[MIL];
	float reg2[DEZ_MIL];
	float reg3[CEM_MIL];
	clock_t t; //variável para armazenar o tempo
	int num;
	FILE *file1, *file2, *file3, *file_search_1, *file_search_2, *file_search_3;
	file1 = fopen("1000.txt","w");
	file2 = fopen("10000.txt", "w");
	file3 = fopen("100000.txt", "w");
	file_search_1 = fopen("search_5000.txt", "w");
	file_search_2 = fopen("search_10000.txt", "w");
	file_search_3 = fopen("search_100000.txt", "w");
	char array1[1000];
	char array2[10000];
	char array3[100000];
	char array_search_1[5000];
	char array_search_2[10000];
	char array_search_3[100000];

	printf("\nMENU_AVL\n\n");
	printf("Escolha qual inserção irá medir primeiro:\n");
	printf("1 - 1000 entradas\n");
	printf("2 - 10.000 entradas\n");
	printf("3 - 100.000 entradas\n");
	scanf("%d",&num);

	switch(num) {
		case 1:
			raiz = avl_CreateTree();
			t=clock();
			printf("\nPreenchendo matriz...\n");
			for(int i=0; i<MIL ; i++){
				reg1[i] = rand() % MIL;
			}
			t=clock() - t;
		    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("ELEMENTOS DA ARVORE: { ");

		  	for(int i=0; i<MIL; i++){
	            r.key = reg1[i];
	            r.value = 1;
	            avl_insertTree(&raiz, r);
	            sprintf(array1, "%.6f", reg1[i]);
	            strcat(array1, "\n");
	            fputs(array1, file1);
		    	printf("%f ", reg1[i]);
			}
		  	printf("}\n\n");

			t=clock();
		  	printf("{ ");
		  	avl_central(raiz);
			printf("}\n\n");
			t=clock() - t;
		    printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			
		    printf("\nBusca na árvore AVL\n");
			t=clock();
			printf("\nBuscador de 5.000 entradas...\n");
			for(int i=0; i<5000 ; i++){
				array_search_1[i] = rand() % 5000;
			}
			t=clock() - t;
		    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			printf("ELEMENTOS DA BUSCA: { ");

		  	for(int i=0; i<5000; i++){
	            sprintf(array_search_1, "%.6d", array_search_1[i]);
	            strcat(array_search_1, "\n");
	            fputs(array_search_1, file_search_1);
		    	printf("%d ", array_search_1[i]);
			}
		  	printf("}\n\n");

		  	t=clock();
			printf("\nPesquisa na Árvore de 1000 entradas: ");
			printf("\n{");
			for(int i=0; i<5000; i++) {
				printf("%d ", array_search_1[i]);
			}
			printf("}\n\n");

		  	for(int i=0; i < 5000; i++) {
				r.key = array_search_1[i];
				avl_pesquisa(&raiz, &aux, r);
				printf("encontrado: %d\n", array_search_1[i]);
			}
			t=clock() - t;



			break;
		case 2:
			raiz = avl_CreateTree();
			t=clock();
			printf("\nPreenchendo matriz...\n");
			for(int i=0; i<DEZ_MIL ; i++){
				reg2[i]= rand() % DEZ_MIL;
			}
			t=clock() - t;
		    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("ELEMENTOS DA ARVORE: { ");
		  	for(int i=0; i<DEZ_MIL; i++){
				r.key = reg2[i];
	            r.value = 1;
	            avl_insertTree(&raiz, r);
	            sprintf(array2, "%.6f", reg2[i]);
	            strcat(array2, "\n");
	            fputs(array2, file2);
		    	printf("%f ", reg2[i]);
			}
		  	printf("}\n\n");

			t=clock();
		  	printf("{ ");
		  	avl_central(raiz);
			printf("}\n\n");
			t=clock() - t;
		    printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			
		    printf("\nBusca na árvore AVL\n");
			t=clock();
			printf("\nBuscador de 5.000 entradas...\n");
			for(int i=0; i<5000 ; i++){
				array_search_1[i] = rand() % 5000;
			}
			t=clock() - t;
		    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			printf("ELEMENTOS DA BUSCA: { ");

		  	for(int i=0; i<5000; i++){
	            sprintf(array_search_1, "%.6d", array_search_1[i]);
	            strcat(array_search_1, "\n");
	            fputs(array_search_1, file_search_1);
		    	printf("%d ", array_search_1[i]);
			}
		  	printf("}\n\n");

			t=clock();
			printf("\nBuscador de 10.000 entradas...\n");
			for(int i=0; i<10000 ; i++){
				array_search_2[i] = rand() % 10000;
			}
			t=clock() - t;
		    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			printf("ELEMENTOS DA BUSCA: { ");

		  	for(int i=0; i<10000; i++){
	            sprintf(array_search_2, "%.6d", array_search_2[i]);
	            strcat(array_search_2, "\n");
	            fputs(array_search_2, file_search_2);
		    	printf("%d ", array_search_2[i]);
			}
		  	printf("}\n\n");

			t=clock();
			printf("\nPesquisa de 5000 entradas na Árvore de 10000 entradas: ");
			printf("\n{");
			for(int i=0; i<5000; i++) {
				printf("%d ", array_search_2[i]);
			}
			printf("}\n\n");

		  	for(int i=0; i < 5000; i++) {
				r.key = array_search_1[i];
				avl_pesquisa(&raiz, &aux, r);
				printf("encontrado: %d\n", array_search_1[i]);
			}
			t=clock() - t;

			break;
		case 3:
			raiz = avl_CreateTree();
			t=clock();
			printf("\nPreenchendo matriz...\n");
			for(int i=0; i<CEM_MIL ; i++){
				reg3[i]= rand() % CEM_MIL;
			}
			t=clock() - t;
		    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("ELEMENTOS DA ARVORE: { ");
		  	for(int i=0; i<CEM_MIL; i++){
				r.key = reg3[i];
	            r.value = 1;
	            avl_insertTree(&raiz, r);
	            sprintf(array3, "%.6f", reg3[i]);
	            strcat(array3, "\n");
	            fputs(array3, file3);
		    	printf("%f ", reg3[i]);
			}
		  	printf("}\n\n");

			t=clock();
		  	printf("{ ");
		  	avl_central(raiz);
			printf("}\n\n");
			t=clock() - t;
		    printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			
		    printf("\nBusca na árvore AVL\n");
			t=clock();
			printf("\nBuscador de 5.000 entradas...\n");
			for(int i=0; i<5000 ; i++){
				array_search_1[i] = rand() % 5000;
			}
			t=clock() - t;
		    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			printf("ELEMENTOS DA BUSCA: { ");

		  	for(int i=0; i<5000; i++){
	            sprintf(array_search_1, "%.6d", array_search_1[i]);
	            strcat(array_search_1, "\n");
	            fputs(array_search_1, file_search_1);
		    	printf("%d ", array_search_1[i]);
			}
		  	printf("}\n\n");

			t=clock();
			printf("\nBuscador de 10.000 entradas...\n");
			for(int i=0; i<10000 ; i++){
				array_search_2[i] = rand() % 10000;
			}
			t=clock() - t;
		    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			printf("ELEMENTOS DA BUSCA: { ");

		  	for(int i=0; i<10000; i++){
	            sprintf(array_search_2, "%.6d", array_search_2[i]);
	            strcat(array_search_2, "\n");
	            fputs(array_search_2, file_search_2);
		    	printf("%d ", array_search_2[i]);
			}
		  	printf("}\n\n");

		  	t=clock();
			printf("\nPesquisa de 5000 entradas na Árvore de 100000 entradas: ");
			printf("\n{");
			for(int i=0; i<5000; i++) {
				printf("%d ", array_search_1[i]);
			}
			printf("}\n\n");

		  	for(int i=0; i < 5000; i++) {
				r.key = array_search_1[i];
				avl_pesquisa(&raiz, &aux, r);
				printf("encontrado: %d\n", array_search_1[i]);
			}
			t=clock() - t;

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

void menu_rubro_negro() {
    TNoRB *arvore = NULL;
    clock_t t; //variável para armazenar o tempo
    int opc = -1, flag = 1, n, rn;
    float reg4[MIL];
    float reg5[DEZ_MIL];
    float reg6[CEM_MIL];
    int num;
    //FILE *file;
	//file = fopen("1000.txt","w");
	//file = fopen("10000.txt", "w");
	//file = fopen("100000.txt", "w");
	char array4[1000];
	char array5[10000];
	char array6[100000];

    
		printf("\nMENU_RED_BLACK\n\n");
		printf("Escolha qual inserção irá medir primeiro:\n");
		printf("1 - 1000 entradas\n");
		printf("2 - 10.000 entradas\n");
		printf("3 - 100.000 entradas\n");
		scanf("%d",&num);

        switch(num) {
			case 1:
				arvore = NULL;
				t=clock();
				printf("\nPreenchendo matriz...\n");
				for(int i=0; i<MIL ; i++){
					reg4[i] = rand() % MIL;
				}
				t=clock() - t;
			    printf("Tempo de execucao de teste: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

				printf("ELEMENTOS DA ARVORE: { ");
			  	for(int i=0; i<MIL; i++){
					//r.key = reg4[i];
					//r.value = 1;
					//reg4[i] = n;
					n = reg4[i]; 
					insereNo(&arvore, NULL, &arvore, i);
			    //printf("%f ", reg4[i]);
				}
			  	printf("}\n\n");

				t=clock();
			  	printf("METODO CENTRAL: { ");
			  	inOrder(arvore);
				printf("}\n\n");
				t=clock() - t;
			    printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
				break;

			case 2:
				arvore = NULL;
				t=clock();
				printf("\nPreenchendo matriz...\n");
				for(int i=0; i<DEZ_MIL ; i++){
					reg4[i] = rand() % DEZ_MIL;
				}
				t=clock() - t;
			    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

				printf("ELEMENTOS DA ARVORE: { ");
			  	for(int i=0; i<MIL; i++){
					//r.key = reg5[i];
					//r.value = 1;
					insereNo(&arvore, NULL, &arvore, n);
			    printf("%f ", reg4[i]);
				}
			  	printf("}\n\n");

				t=clock();
			  	printf("METODO CENTRAL: { ");
			  	inOrder(arvore);
				printf("}\n\n");
				t=clock() - t;
			    printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
				break;


			case 3:
				arvore = NULL;
				t=clock();
				printf("\nPreenchendo matriz...\n");
				for(int i=0; i<CEM_MIL ; i++){
					reg4[i] = rand() % CEM_MIL;
				}
				t=clock() - t;
			    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

				printf("ELEMENTOS DA ARVORE: { ");
			  	for(int i=0; i<CEM_MIL; i++){
					//r.key = reg5[i];
					//r.value = 1;
					insereNo(&arvore, NULL, &arvore, n);
			    printf("%f ", reg4[i]);
				}
			  	printf("}\n\n");

				t=clock();
			  	printf("METODO CENTRAL: { ");
			  	inOrder(arvore);
				printf("}\n\n");
				t=clock() - t;
			    printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
				break;

            default:
                printf("Opção inválida.\n");
                break;
        }
    //fclose(file);
}

void menu_binaria(){

	system("clear || cls");

	float reg7[MIL];
	float reg8[DEZ_MIL];
	float reg9[CEM_MIL];
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;
	clock_t t; //variável para armazenar o tempo
	int esc;
	//FILE *file;
	//file = fopen("1000.txt","w");
	//file = fopen("10000.txt", "w");
	//file = fopen("100000.txt", "w");
	char array7[1000];
	char array8[10000];
	char array9[100000];


	printf("\nMENU_Binária\n\n");
	printf("Escolha qual inserção irá medir primeiro:\n");
	printf("1 - 1000 entradas\n");
	printf("2 - 10.000 entradas\n");
	printf("3 - 100.000 entradas\n");
	scanf("%d",&esc);

	switch(esc) {
		case 1:
			raiz = CreateTree();
			t=clock();
			printf("\nPreenchendo matriz...\n");
			for(int i=0; i<MIL ; i++){
				reg7[i] = rand() % MIL;
			}
			t=clock() - t;
		    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("ELEMENTOS DA ARVORE: { ");
		  	for(int i=0; i<MIL; i++){
				r.key = reg7[i];
				r.value = 1;
				insertTree(&raiz, r);
	            //sprintf(array7, "%.6f", reg7[i]);
	            //strcat(array7, "\n");
	            //fputs(array7, file);
		    	printf("%f ", reg7[i]);
			}
		  	printf("}\n\n");

			t=clock();
		  	printf("METODO CENTRAL: { ");
		  	central(raiz);
			printf("}\n\n");
			t=clock() - t;
		    printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			break;
		case 2:
			raiz = CreateTree();
			t=clock();
			printf("\nPreenchendo matriz...\n");
			for(int i=0; i<DEZ_MIL ; i++){
				reg8[i]= rand() % DEZ_MIL;
			}
			t=clock() - t;
		    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("ELEMENTOS DA ARVORE: { ");
		  	for(int i=0; i<DEZ_MIL; i++){
				r.key = reg8[i];
				r.value = 1;
				insertTree(&raiz, r);
	            //sprintf(array8, "%.6f", reg8[i]);
	            //strcat(array8, "\n");
	            //fputs(array8, file);
		    	printf("%f ", reg8[i]);
			}
		  	printf("}\n\n");

			t=clock();
		  	printf("METODO CENTRAL: { ");
		  	central(raiz);
			printf("}\n\n");
			t=clock() - t;
		    printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			break;
		case 3:
			raiz = CreateTree();
			t=clock();
			printf("\nPreenchendo matriz...\n");
			for(int i=0; i<CEM_MIL ; i++){
				reg9[i]= rand() % CEM_MIL;
			}
			t=clock() - t;
		    printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

			printf("ELEMENTOS DA ARVORE: { ");
		  	for(int i=0; i<CEM_MIL; i++){
				r.key = reg9[i];
				r.value = 1;
				insertTree(&raiz, r);
	            //sprintf(array9, "%.6f", reg9[i]);
	            //strcat(array9, "\n");
	            //fputs(array9, file);
		    	printf("%f ", reg9[i]);
			}
		  	printf("}\n\n");

			t=clock();
		  	printf("METODO CENTRAL: { ");
		  	central(raiz);
			printf("}\n\n");
			t=clock() - t;
		    printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			break;
		default:
			printf("Escolha uma opção válida!");
			break;
	}
	//fclose(file1);
	//fclose(file2);
	//fclose(file3);

	//fclose(file_search_1);
	//fclose(file_search_2);
	//fclose(file_search_3);
}
