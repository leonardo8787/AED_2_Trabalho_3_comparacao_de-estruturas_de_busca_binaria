#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	int key;
	int value;
};

struct Tree{
	Record reg;
	Tree *esq, *dir;
};

Tree* CreateTree(){
	return NULL;
}

void insertTree(Tree **t, Record r)
{
  if(*t == NULL){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->reg = r; 
  } else {
    
    if(r.key < (*t)->reg.key){
      insertTree(&(*t)->esq, r);
    }
    
    if(r.key > (*t)->reg.key){
      insertTree(&(*t)->dir, r);
    }
  
  }

}

int isInTree(Tree *t, Record r) {
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || isInTree(t->esq, r) || isInTree(t->dir, r);
}

void showTreeInOrder(Tree *t)
{
  if(!(t == NULL)){
    showTreeInOrder(t->esq); 
    printf("%d ", t->reg.key);
    showTreeInOrder(t->dir); 
  }
}


void antecessor(Tree **t, Tree *aux){ 

	if ((*t)->dir != NULL){ 
		antecessor(&(*t)->dir, aux);
		return;
  }
  	
  aux->reg = (*t)->reg;
  aux = *t; 
  *t = (*t)->esq;
  free(aux);
} 


void removeTree(Tree **t, Record r){
	Tree *aux;
  	
  	if (*t == NULL){ 
  		printf("[ERROR]: Record not found!!!\n");
    	return;
  	}

  	if (r.key < (*t)->reg.key){ removeTree(&(*t)->esq, r); return; }
  	if (r.key > (*t)->reg.key){ removeTree(&(*t)->dir, r); return; }

  	if ((*t)->dir == NULL){ 
  		aux = *t;  
  		*t = (*t)->esq;
    	free(aux);
    	return;
  	}

  	if ((*t)->esq != NULL){ antecessor(&(*t)->esq, *t); return; }

  	aux = *t;  
  	*t = (*t)->dir;
  	free(aux);
}

void pesquisa(Tree **t, Tree **aux, Record r){

	if(*t == NULL){
		printf("[ERROR]: Node not found!");
		return;
	}
	if((*t)->reg.key > r.key){ pesquisa(&(*t)->esq, aux, r); return;}
	if((*t)->reg.key < r.key){ pesquisa(&(*t)->dir, aux, r); return;}

	*aux = *t;
}

int RandomInteger(int low, int high)
{
    int k;
    srand( (unsigned)time(NULL) );
    k = (rand() % high) + low;
    return k;
}

int main(){
	
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;
	int num;
	int a;
	clock_t t; //variável para armazenar o tempo
	int TAM=1000;
	int TAM_2=10000;
	int TAM_3=1000000;
	int vetor[TAM]; //vetor com 10000 posições
	int val = 0;

	printf("\nÁrvore binária em C\n");
	printf("autor: Leonardo Campos\n");

	do{
		printf("Escolha uma opção: ");
		printf("0 - sair\n");
		printf("1 - 1000 entradas\n");
		printf("2 - 10000 entradas\n");
		printf("3 - 1000000 entradas\n");
		scanf("%d", &val);
		switch(val){
			case 0:
				break;
			case 1:
			  t=clock();
			  
			  for(int a = 0; a < TAM; a++)
			  	//vetor[a] = RandomInteger(0, TAM);
			  	vetor[a] = rand() % TAM;
			  	r.key = vetor[a];
					r.value = 1;
					insertTree(&raiz, r);
				
				t=clock() - t;
				
				printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
				
			  t=clock();
				printf("\nÁrvore\n");
				printf("[");
				showTreeInOrder(raiz);
				printf("]\n");
			  t=clock() - t;

			  printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
				
				printf("\nNúmeros");
				printf("{");
				for(int i=0; i<TAM; i++){
					printf(" %d ",vetor[i]);
				}
				printf("}\n");
				break;
			case 2:
			  t=clock();
			  
			  for(int a = 0; a < TAM_2; a++)
			  	//vetor[a] = RandomInteger(0, TAM);
			  	vetor[a] = rand() % TAM_2;
			  	r.key = vetor[a];
					r.value = 1;
					insertTree(&raiz, r);
				
				t=clock() - t;
				
				printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
				
			  t=clock();
				printf("\nÁrvore\n");
				printf("[");
				showTreeInOrder(raiz);
				printf("]\n");
			  t=clock() - t;

			  printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
				
				printf("\nNúmeros");
				printf("{");
				for(int i=0; i<TAM_2; i++){
					printf(" %d ",vetor[i]);
				}
				printf("}\n");
				break;
			case 3:
			  t=clock();
			  
			  for(int a = 0; a < TAM_3; a++)
			  	//vetor[a] = RandomInteger(0, TAM);
			  	vetor[a] = rand() % TAM_3;
			  	r.key = vetor[a];
					r.value = 1;
					insertTree(&raiz, r);
				
				t=clock() - t;
				
				printf("Tempo de execucao de inserção: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
				
			  t=clock();
				printf("\nÁrvore\n");
				printf("[");
				showTreeInOrder(raiz);
				printf("]\n");
			  t=clock() - t;

			  printf("Tempo de execucao de busca: %lf segundos!\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
				
				printf("\nNúmeros");
				printf("{");
				for(int i=0; i<TAM_3; i++){
					printf(" %d ",vetor[i]);
				}
				printf("}\n");
				break;
			default:
				printf("Escolha uma opção válida!\n");
				break;
		}
	}while(val != 0);
    return 0;
}
