#ifndef OP_INCLUDED
#define OP_INCLUDED
#include "Operacao.h"
#endif

#ifndef FILA_INCLUDED
#define FILA_INCLUDED
struct Fila {
	int capacidade;
	struct Operacao *operacao;
	int primeiro;
	int ultimo;
	int nItens; 
};
#endif

void criarFila( struct Fila **f, int capacidade); 
void inserirNaFila(struct Fila **f, struct Operacao *operacao);
struct Operacao* removerDaFila(struct Fila **f); 
int filaEstaVazia(struct Fila **f);
int filaEstaCheia(struct Fila **f);
