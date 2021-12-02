//binaria.c
/*
void binaria_insertTree(Tree_binaria **t, Record_binaria r)
{
  if(*t == NULL){
    *t = (Tree_binaria*)malloc(sizeof(Tree_binaria));
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->reg = r; 
  } else {
    
    if(r.key < (*t)->reg.key){
      binaria_insertTree(&(*t)->esq, r);
    }
    
    if(r.key > (*t)->reg.key){
      binaria_insertTree(&(*t)->dir, r);
    }
  
  }

}

int binaria_isInTree(Tree_binaria *t, Record_binaria r) {
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || binaria_isInTree(t->esq, r) || binaria_isInTree(t->dir, r);
}

void binaria_showTreeInOrder(Tree_binaria *t)
{
  if(!(t == NULL)){
    binaria_showTreeInOrder(t->esq); 
    printf("%d ", t->reg.key);
    binaria_showTreeInOrder(t->dir); 
  }
}


void binaria_antecessor(Tree_binaria **t, Tree_binaria *aux){ 

	if ((*t)->dir != NULL){ 
		binaria_antecessor(&(*t)->dir, aux);
		return;
  }
  	
  aux->reg = (*t)->reg;
  aux = *t; 
  *t = (*t)->esq;
  free(aux);
} 


void binaria_removeTree(Tree_binaria **t, Record_binaria r){
	Tree *aux;
  	
  	if (*t == NULL){ 
  		printf("[ERROR]: Record not found!!!\n");
    	return;
  	}

  	if (r.key < (*t)->reg.key){ binaria_removeTree(&(*t)->esq, r); return; }
  	if (r.key > (*t)->reg.key){ binaria_removeTree(&(*t)->dir, r); return; }

  	if ((*t)->dir == NULL){ 
  		aux = *t;  
  		*t = (*t)->esq;
    	free(aux);
    	return;
  	}

  	if ((*t)->esq != NULL){ binaria_antecessor(&(*t)->esq, *t); return; }

  	aux = *t;  
  	*t = (*t)->dir;
  	free(aux);
}

void binaria_pesquisa(Tree_binaria **t, Tree_binaria **aux, Record_binaria r){

	if(*t == NULL){
		printf("[ERROR]: Node not found!");
		return;
	}
	if((*t)->reg.key > r.key){ binaria_pesquisa(&(*t)->esq, aux, r); return;}
	if((*t)->reg.key < r.key){ binaria_pesquisa(&(*t)->dir, aux, r); return;}

	*aux = *t;
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
