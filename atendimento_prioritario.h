#ifndef ATENDIMENTO_PRIORITARIO_H
#define ATENDIMENTO_PRIORITARIO_H
#include "cadastro.h"
#define MAX_HEAP 20

typedef struct {
    Registro *pacientes[MAX_HEAP];
    int qtde;
} Heap;

void inicializar_heap(Heap *h);
int maior(int i, int j);
void peneirar(Heap *h, int i);
void enfileirar_prioritario(Heap *h, Registro *r);
Registro *desenfileirar_prioritario(Heap *h);
void mostrar_heap(Heap *h);

#endif
