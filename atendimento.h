#ifndef FILA_H
#define FILA_H

#include "cadastro.h"

typedef struct No {
    Registro *dados;
    struct No *proximo;
} No;

typedef struct {
    No *head;
    No *tail;
    int qtd;
} Fila;

Fila *criar_fila();
void enfileirar(Fila *fila, Registro *r);
Registro *desenfileirar(Fila *fila);
void mostrar_fila(Fila *fila);
int fila_vazia(Fila *fila);

#endif
