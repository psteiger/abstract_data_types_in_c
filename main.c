#include "Fila.h"
#include "PilhaCaixa.h"
#include <stdio.h>

#ifndef INCLUDE_STDLIB
#define INCLUDE_STDLIB
#include <stdlib.h>
#endif

#include <math.h>
       
void lerCaixasEClientes(void);
void lerOperacaoDaLinha(void);
//void atenderUsuario(struct Fila **fi);

int caixas, clientes, tamanho_fila;
struct Operacao *op;
struct Fila *fi;
int current_i = 0;

int main(void) {
	lerCaixasEClientes();
	tamanho_fila = (int) sqrt(clientes);

	criarFila(&fi, tamanho_fila); // fila de capacidade floor(raiz(N))

	printf("tamanho da fila %d\nnum de caixas %d\n", fi->capacidade, caixas);
	
	struct PilhaCaixa* listOfCaixas[caixas];

	for (int i = 0; i < caixas; i++) {
		struct PilhaCaixa *pi = NULL;
		int capacidade_vetores_pilha = (clientes + (caixas - 1)) / caixas;
		criarPilha(&pi, capacidade_vetores_pilha);
		listOfCaixas[current_i++] = pi;
	}

	int current_i = 0;

	for (int i=1; i <= clientes; i++) { // ler cada op
		lerOperacaoDaLinha();

		if (fi == NULL) { printf("FI IS NULL "); }

		if(!filaEstaCheia(&fi)) {
			//printf("%d\n", op->valor);
			inserirNaFila(&fi, op);
			push(&listOfCaixas[current_i++], &op);
			if (current_i == caixas) {
				printf("todos caixas circulados. current_i = %d\n", current_i);
				current_i = 0;
			} 
			removerDaFila(&fi);
		} else {
			printf("FILA CHEIA! TRATAR");
		} 

	}
	
	return(0);
}

void lerCaixasEClientes(void) {
        scanf("%d %d", &caixas, &clientes);
}

void lerOperacaoDaLinha(void) {
	op = malloc(sizeof(struct Operacao));
	scanf("%d %d %d", &op->codigoCliente, &op->operacao, &op->valor);
}

/*void atenderUsuario(struct Fila **fi) {
	removerDaFila(fi);
}*/