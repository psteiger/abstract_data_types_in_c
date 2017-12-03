#ifndef OP_INCLUDED
#define OP_INCLUDED
#include "Operacao.h"
#endif

#ifndef PILHA_CAIXA_INCLUDED
#define PILHA_CAIXA_INCLUDED
struct PilhaCaixa {
	int capacidade;
	int nItems;
	int primeiro;
	int ultimo;
	struct Operacao *operacao;
};
#endif

extern void criarPilha(struct PilhaCaixa **pilha, int capacidade);
extern int vazia(struct PilhaCaixa **pilha);
extern void push(struct PilhaCaixa **pilha, struct Operacao **operacao);
extern struct Operacao* pop(struct PilhaCaixa **pilha);
