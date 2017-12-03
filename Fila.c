#ifndef INCLUDE_FILA
#define INCLUDE_FILA
#include "Fila.h"
#endif

#ifndef INCLUDE_STDLIB
#define INCLUDE_STDLIB
#include <stdlib.h>
#endif

#ifndef INCLUDE_STDIO
#define INCLUDE_STDIO
#include <stdio.h>
#endif


void criarFila(struct Fila **f, int c) {
	*f = malloc(sizeof(struct Fila));
	(*f)->capacidade = c;
	(*f)->operacao = malloc ((*f)->capacidade * sizeof(struct Operacao)); // tamanho bottom sqrt M
	(*f)->primeiro = 0;
	(*f)->ultimo = -1;
	(*f)->nItens = 0; 
}

void inserirNaFila(struct Fila **f, struct Operacao *operacao) {
	if((*f)->ultimo == (*f)->capacidade-1)
		(*f)->ultimo = -1;

	(*f)->ultimo++;
	(*f)->operacao[(*f)->ultimo] = *operacao;
	(*f)->nItens++; // mais um item inserido
}

struct Operacao* removerDaFila( struct Fila **f ) { 
	struct Operacao *temp = &(*f)->operacao[(*f)->primeiro++]; 

	if((*f)->primeiro == (*f)->capacidade)
		(*f)->primeiro = 0;

	(*f)->nItens--;  // um item retirado
	return temp;
}

int filaEstaVazia( struct Fila **f ) {
	return (*f)->nItens==0;
}

int filaEstaCheia( struct Fila **f ) { 
	printf("filaEstaCheia? capacidade = %d , itens = %d\n", (*f)->capacidade, (*f)->nItens); 
	return (*f)->nItens == (*f)->capacidade;
}

