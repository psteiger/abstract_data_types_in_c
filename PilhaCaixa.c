#ifndef INCLUDE_PILHA_CAIXA
#define INCLUDE_PILHA_CAIXA
#include "PilhaCaixa.h"
#endif

#ifndef INCLUDE_STDLIB
#define INCLUDE_STDLIB
#include <stdlib.h>
#endif

int vazia(struct PilhaCaixa **f) {
	return (*f)->nItems;
}

void criarPilha(struct PilhaCaixa **pilha, int capacidade) {
	*pilha = malloc(sizeof(struct PilhaCaixa));
	(*pilha)->capacidade = capacidade;
	(*pilha)->operacao = (struct Operacao*) malloc((*pilha)->capacidade * sizeof(struct Operacao)); // inclui usuario, op e valor	pilha->tamanho = 0
	(*pilha)->primeiro = 0;
	(*pilha)->ultimo = -1;
}

void push(struct PilhaCaixa **f, struct Operacao **op) {
	if((*f)->ultimo == (*f)->capacidade-1)
		(*f)->ultimo = -1;

	(*f)->ultimo++;
	(*f)->operacao[(*f)->ultimo] = **op; // incrementa ultimo e insere
	(*f)->nItems++; // mais um item inserido
}


struct Operacao *pop(struct PilhaCaixa **f) {
	//checar nao remover vazio, etc

	struct Operacao *temp = &(*f)->operacao[(*f)->ultimo--]; // pega o valor e incrementa o primeiro
	
	(*f)->nItems--;  // um item retirado
	return temp;

}

