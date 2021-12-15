typedef struct NO *ArvRB;
ArvRB *cria_ArvoreRB();
void libera_ArvRB(ArvRB *raiz);
float insere_ArvRB(ArvRB *raiz, float valor);
float remove_ArvRB(ArvRB *raiz, float valor);
float consulta_ArvRB(ArvRB *raiz, float valor);
void emOrdem_ArvRB(ArvRB *raiz, int H);