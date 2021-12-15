#include "menu.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX 10
#define MIL 1000
#define DEZ_MIL 10000
#define CEM_MIL 100000

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
		}
	}while(op != 0);

	return 0;
}