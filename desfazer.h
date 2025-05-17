#ifndef DESFAZER_H
#define DESFAZER_H

#include "cadastro.h"

typedef struct CelulaHistorico {
    struct CelulaHistorico *anterior;
    Registro *registro;
    char operacao[20];
    struct CelulaHistorico *proximo;
} CelulaHistorico;

typedef struct {
    int qtd;
    CelulaHistorico *topo;
} Pilha;

Pilha *criar_pilha();
CelulaHistorico *criar_celula_historico(Registro *registro, char operacao[20]);
void push(Pilha *pilha, Registro *registro, char operacao[20]);
void pop(Pilha *pilha);
void mostrar_historico(Pilha *pilha);

#endif
