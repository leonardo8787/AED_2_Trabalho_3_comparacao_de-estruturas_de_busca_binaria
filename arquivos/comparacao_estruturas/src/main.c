#include "avl.h"
#include "rbt.h"
//#include "binaria.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 10

void menu_avl();
void menu_rubro_negro();
//void menu_binaria();

int main(){

	int op;

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
				//menu_binaria();
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
	int num;
	clock_t t; //variável para armazenar o tempo

	printf("\nÁrvore AVL em C\n\n");
	printf("autor: Leonardo Campos\n");
	
	do{
	    printf("Escolha uma opção: \n");
	    printf("0 - sair\n");
	    printf("1 - inserir valor\n");
	    printf("2 - remover\n");
	    printf("3 - imprimir árvore\n");
	    printf("4 - limpar tela\n");
	    scanf("%d", &num);
	    switch(num){
	        case 0:
	            printf("\nSaindo...\n");
	            break;
	        case 1:
	            printf("\nDigite um valor: ");
	            scanf("%d", &num);
	            t=clock();
	            r.key = num;
	            r.value = 1;
	            avl_insertTree(&raiz, r);
	            t=clock() - t;
	            printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	            break;
	        case 2:
	            printf("\nDigite um número para remover: \n");
	            t=clock();
	            scanf("%d", &num);
	            r.key = num;
	            avl_removeTree(&raiz, &raiz, r);
	            t=clock() - t;
	            printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	            break;
	        case 3:
	            printf("\nÁrvore\n");
	            t=clock();
	            printf("[");
	            avl_central(raiz);
	            printf("fim]");
	            t=clock() - t;
	            printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	            printf("\n");
	            break;
	        case 4:
	           	system("cls || clear");
	        default:
	            printf("\nEscolha uma opção válida!\n");
	            break;
	    }
	}while(num);
}

void menu_rubro_negro() {
    TNoRB *arvore = NULL;
    clock_t t; //variável para armazenar o tempo
    int opc = -1, flag = 1, n, rn;
    

    do {
        printf("1 - Inserir elemento;\n2 - Remover elemento;\n3 - Ver árvore;\n4 - Sair\n");
        scanf("%d", &opc);

        switch(opc) {
            case 1:
                printf("Elemento a inserir:\n");
                t=clock();
                scanf("%d", &n);
                insereNo(&arvore, NULL, &arvore, n);
                t=clock() - t;
                printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                break;

            case 2:
                printf("Elemento a remover:\n");
                t=clock();
                scanf("%d", &rn);
                removeNo(&arvore, rn);
                t=clock() - t;
                printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                break;

            case 3:
            	t=clock();
                inOrder(arvore);
                t=clock() - t;
                printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
                break;

            case 4:
                flag = 0;
                break;

            default:
                printf("Opção inválida.\n");
        }

        printf("==========\n");
    } while (flag);
}
/*
void menu_binaria(){
	
	Tree_binaria *raiz = binaria_CreateTree();
	Tree_binaria *aux = binaria_CreateTree();
	Record_binaria r;
	int num;

	printf("\nÁrvore binária em C\n\n");
	printf("autor: Leonardo Campos\n");
	
	do{
	    printf("Escolha uma opção: \n");
	    printf("0 - sair\n");
	    printf("1 - inserir valor\n");
	    printf("2 - remover\n");
	    printf("3 - imprimir árvore\n");
	    printf("4 - limpar tela\n");
	    scanf("%d", &num);
	    switch(num){
	        case 0:
	            printf("\nSaindo...\n");
	            break;
	        case 1:
	            printf("\nDigite um valor: \n");
	            scanf("%d", &num);
	            r.key = num;
	            r.value = 1;
	            binaria_insertTree(&raiz, r);
	            break;
	        case 2:
	            printf("\nDigite um número para remover: \n");
	            scanf("%d", &num);
	            r.key = num;
	            binaria_removeTree(&raiz, r);
	            break;
	        case 3:
	            printf("\nÁrvore\n");
	            printf("[");
	            binaria_showTreeInOrder(raiz);
	            printf("]");
	            binaria_showTreeInOrder(aux);
	            printf("\n");
	            break;
	        case 4:
	           	system("cls || clear");
	        default:
	            printf("\nEscolha uma opção válida!\n");
	            break;
	    }
	}while(num != 0);
}
*/