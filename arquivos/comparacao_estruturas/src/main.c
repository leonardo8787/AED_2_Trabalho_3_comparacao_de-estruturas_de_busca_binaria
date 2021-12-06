#include "avl.h"
#include "rbt.h"
#include "binaria.h"
#include "gera_aleatorio.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
	float reg1[MIL]={};
	float reg2[DEZ_MIL]={};
	float reg3[CEM_MIL]={};
	clock_t t; //variável para armazenar o tempo
	int num;
	FILE *file;

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
	            file = fopen("1000.txt","w");
	            fclose(file);
		    	printf("%f ", reg1[i]);
			}
		  	printf("}\n\n");

			t=clock();
		  	printf("{ ");
		  	avl_central(raiz);
			printf("}\n\n");
			t=clock() - t;
		    printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
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
		    	printf("%f ", reg2[i]);
			}
		  	printf("}\n\n");

			t=clock();
		  	printf("{ ");
		  	avl_central(raiz);
			printf("}\n\n");
			t=clock() - t;
		    printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
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
		    	printf("%f ", reg3[i]);
			}
		  	printf("}\n\n");

			t=clock();
		  	printf("{ ");
		  	avl_central(raiz);
			printf("}\n\n");
			t=clock() - t;
		    printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			break;
		default:
			printf("Escolha uma opção válida!");
			break;
	}
}

void menu_rubro_negro() {
    TNoRB *arvore = NULL;
    clock_t t; //variável para armazenar o tempo
    int opc = -1, flag = 1, n, rn;
    float reg4[MIL]={};
    float reg5[DEZ_MIL]={};
    float reg6[CEM_MIL]={};
    int num;
    FILE *file;
    
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
}

void menu_binaria(){

	system("clear || cls");

	float reg7[MIL] = {};
	float reg8[DEZ_MIL] = {};
	float reg9[CEM_MIL] = {};
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;
	clock_t t; //variável para armazenar o tempo
	int esc;
	FILE *file;

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
}
