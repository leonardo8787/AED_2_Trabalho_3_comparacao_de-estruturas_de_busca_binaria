
#ifndef AVL_H 
#define AVL_H

#include<stdio.h>
#include<stdlib.h>

typedef struct Record_avl Record_avl;
typedef struct Tree_avl Tree_avl;

struct Record_avl{
	float key;
	float value;
};

struct Tree_avl{
	Record_avl reg;
	Tree_avl *esq, *dir;
	int weight;
};

Tree_avl* avl_CreateTree();
void avl_insertTree(Tree_avl **t, Record_avl r);
void avl_pesquisa(Tree_avl **t, Tree_avl **aux, Record_avl r);
int avl_isInTree(Tree_avl *t, Record_avl r);

//muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
void avl_removeTree(Tree_avl **t, Tree_avl **f, Record_avl r);
void avl_antecessor(Tree_avl **t, Tree_avl *aux);
void avl_rebalanceTree(Tree_avl **t);

void avl_preordem(Tree_avl *t);
void avl_central(Tree_avl *t);
void avl_posordem(Tree_avl *t);


int avl_getWeight(Tree_avl **t);
int avl_getMaxWeight(int left, int right);


void avl_rotacaoSimplesDireita(Tree_avl **t);
void avl_rotacaoSimplesEsquerda(Tree_avl **t);
void avl_rotacaoDuplaDireita(Tree_avl **t);
void avl_rotacaoDuplaEsquerda(Tree_avl **t);

//void menu_avl();


#endif
