#include "avl.h"

Tree_avl* avl_CreateTree(){
  return NULL;
}

void avl_insertTree(Tree_avl **t, Record_avl r){

  if(*t == NULL){
    *t = (Tree_avl*)malloc(sizeof(Tree_avl));
    (*t)->esq    = NULL; 
    (*t)->dir    = NULL; 
    (*t)->weight = 0;
    (*t)->reg    = r; 

  } else {
    
    if(r.key < (*t)->reg.key){
      avl_insertTree(&(*t)->esq, r);
      if ((avl_getWeight(&(*t)->esq) - avl_getWeight(&(*t)->dir)) == 2){
        if(r.key < (*t)->esq->reg.key)
          avl_rotacaoSimplesDireita(t);
        else
          avl_rotacaoDuplaDireita(t);
      }
    }
    
    if(r.key > (*t)->reg.key){
      avl_insertTree(&(*t)->dir, r);
      if ((avl_getWeight(&(*t)->dir) - avl_getWeight(&(*t)->esq)) == 2){
        if(r.key > (*t)->dir->reg.key)
          avl_rotacaoSimplesEsquerda(t);
        else
          avl_rotacaoDuplaEsquerda(t);
      }
    }
  
  }

  (*t)->weight = avl_getMaxWeight(avl_getWeight(&(*t)->esq), avl_getWeight(&(*t)->dir)) + 1;

}


void avl_pesquisa(Tree_avl **t, Tree_avl **aux, Record_avl r){

  if(*t == NULL){
    printf("[ERROR]: Node not found!");
    return;
  }

  if((*t)->reg.key > r.key){ avl_pesquisa(&(*t)->esq, aux, r); return;}
  if((*t)->reg.key < r.key){ avl_pesquisa(&(*t)->dir, aux, r); return;}

  *aux = *t;
}

int avl_isInTree(Tree_avl *t, Record_avl r){
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || avl_isInTree(t->esq, r) || avl_isInTree(t->dir, r);
}


void avl_antecessor(Tree_avl **t, Tree_avl *aux){ 

  if ((*t)->dir != NULL){ 
    avl_antecessor(&(*t)->dir, aux);
    return;
    }
    
    aux->reg = (*t)->reg;
    aux = *t; 
    *t = (*t)->esq;
    free(aux);
} 

void avl_rebalanceTree(Tree_avl **t){
  int balance;
    int left = 0;
    int right = 0;

  balance = avl_getWeight(&(*t)->esq) - avl_getWeight(&(*t)->dir);
  if((*t)->esq)
    left = avl_getWeight(&(*t)->esq->esq) - avl_getWeight(&(*t)->esq->dir);
  if((*t)->dir)
    right = avl_getWeight(&(*t)->dir->esq) - avl_getWeight(&(*t)->dir->dir);

  //printf("==== Valores de balanceamento: ====\n");
  //printf("Raiz:%d, Filho esq:%d, Filho dir:%d\n", balance, left, right);
  //printf("===================================\n");

  if(balance == 2 && left >= 0)
    avl_rotacaoSimplesDireita(t);
  if(balance == 2 && left < 0)
    avl_rotacaoDuplaDireita(t);

  if(balance == -2 && right >= 0)
    avl_rotacaoDuplaEsquerda(t);
  if(balance == -2 && right < 0)
    avl_rotacaoSimplesEsquerda(t);  
    
}

void avl_removeTree(Tree_avl **t, Tree_avl **f, Record_avl r){
  Tree_avl *aux;
    
    if (*t == NULL){ 
      printf("[ERROR]: Record not found!!!\n");
      return;
    }

    if (r.key < (*t)->reg.key){ avl_removeTree(&(*t)->esq, t, r); return;}
    if (r.key > (*t)->reg.key){ avl_removeTree(&(*t)->dir, t, r); return;}

    if ((*t)->dir == NULL){ 
      aux = *t;  
      *t = (*t)->esq;
      free(aux);
      avl_rebalanceTree(f);
      return;
    }

    if ((*t)->esq != NULL){ 
      avl_antecessor(&(*t)->esq, *t);
      avl_rebalanceTree(f);
      return;
    }

    aux = *t;  
    *t = (*t)->dir;
    free(aux);
    avl_rebalanceTree(f);   
}

void avl_preordem(Tree_avl *t)
{
  if(!(t == NULL)){
    printf("%f\t", t->reg.key);
    avl_preordem(t->esq); 
    avl_preordem(t->dir); 
  }
}


void avl_central(Tree_avl *t)
{
  if(!(t == NULL)){
    avl_central(t->esq); 
    printf("%f, ", t->reg.key);
    avl_central(t->dir); 
  }
}

void avl_posordem(Tree_avl *t)
{
  if(!(t == NULL)){
    avl_posordem(t->esq); 
    avl_posordem(t->dir); 
    printf("%f\t", t->reg.key);
  }
}


int avl_getWeight(Tree_avl **t){
  if(*t == NULL)
    return -1;
  return (*t)->weight;
}

int avl_getMaxWeight(int left, int right){
  if(left > right)
    return left;
  return right;
}

void avl_rotacaoSimplesDireita(Tree_avl **t){
  Tree_avl *aux;
  aux = (*t)->esq;
  (*t)->esq = aux->dir;
  aux->dir = (*t);
  (*t)->weight = avl_getMaxWeight(avl_getWeight(&(*t)->esq), avl_getWeight(&(*t)->dir)) + 1;
  aux->weight  = avl_getMaxWeight(avl_getWeight(&aux->esq), (*t)->weight) + 1;
  (*t) = aux;
}

void avl_rotacaoSimplesEsquerda(Tree_avl **t){
  Tree_avl *aux;
  aux = (*t)->dir;
  (*t)->dir = aux->esq;
  aux->esq = (*t);
  (*t)->weight = avl_getMaxWeight(avl_getWeight(&(*t)->esq), avl_getWeight(&(*t)->dir)) + 1;
  aux->weight  = avl_getMaxWeight(avl_getWeight(&aux->esq), (*t)->weight) + 1;
  (*t) = aux;
}

void avl_rotacaoDuplaDireita(Tree_avl **t){
  avl_rotacaoSimplesEsquerda(&(*t)->esq);
  avl_rotacaoSimplesDireita(t);
}

void avl_rotacaoDuplaEsquerda(Tree_avl **t){
  avl_rotacaoSimplesDireita(&(*t)->dir);
  avl_rotacaoSimplesEsquerda(t);
}