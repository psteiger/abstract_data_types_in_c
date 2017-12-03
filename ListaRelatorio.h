#include "Operacao.h"

struct Fila {
	int capacidade;
	struct Operacao *op;
	int primeiro;
	int ultimo;
	int numItens; 
};

void criarFila( struct Fila *f, int c ); 
void inserir(struct Fila *f, int v);
int remover( struct Fila *f ) {; 
int estaVazia( struct Fila *f );
int estaCheia( struct Fila *f );
