#include "avl.h"
#include "avl.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "rbt.h"

#define MAX 10

void menu_avl();
void menu_rubro_negro();

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
				//arvore_binaria();
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
	
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;
	int num;

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
	            return 0;
	            break;
	        case 1:
	            printf("\nDigite um valor: ");
	            scanf("%d", &num);
	            r.key = num;
	            r.value = 1;
	            insertTree(&raiz, r);
	            break;
	        case 2:
	            printf("\nDigite um número para remover: \n");
	            scanf("%d", &num);
	            r.key = num;
	            removeTree(&raiz, &raiz, r);
	            break;
	        case 3:
	            printf("\nÁrvore\n");
	            printf("[");
	            central(raiz);
	            printf("fim]");
	            //showTreeInOrder(aux);
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

    int opc = -1, flag = 1, n, rn;
    

    do {
        printf("1 - Inserir elemento;\n2 - Remover elemento;\n3 - Ver árvore;\n4 - Sair\n");
        scanf("%d", &opc);

        switch(opc) {
            case 1:
                printf("Elemento a inserir:\n");
                scanf("%d", &n);
                insereNo(&arvore, NULL, &arvore, n);
                break;

            case 2:
                printf("Elemento a remover:\n");
                scanf("%d", &rn);
                removeNo(&arvore, rn);
                break;

            case 3:
                inOrder(arvore);
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