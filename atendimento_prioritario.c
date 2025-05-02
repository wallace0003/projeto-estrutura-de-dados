#include <stdio.h>
#include <stdlib.h>
#include "atendimento_prioritario.h"
#include "atendimento.h"

void inicializar_heap(Heap *h) {
    h->qtde = 0;
}

int maior(int i, int j) {
    return i > j;
}

void peneirar(Heap *h, int i) {
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    int maior_idx = i;

    if (esq < h->qtde && h->pacientes[esq]->idade > h->pacientes[maior_idx]->idade)
        maior_idx = esq;

    if (dir < h->qtde && h->pacientes[dir]->idade > h->pacientes[maior_idx]->idade)
        maior_idx = dir;

    if (maior_idx != i) {
        Registro *temp = h->pacientes[i];
        h->pacientes[i] = h->pacientes[maior_idx];
        h->pacientes[maior_idx] = temp;
        peneirar(h, maior_idx);
    }
}

void enfileirar_prioritario(Heap *h, Registro *r) {
    if (h->qtde < MAX_HEAP) {
        h->pacientes[h->qtde++] = r;
        for (int i = (h->qtde / 2) - 1; i >= 0; i--)
            peneirar(h, i);
    } else {
        printf("Fila cheia!\n");
    }
}

Registro *desenfileirar_prioritario(Heap *h) {
    if (h->qtde == 0)
        return NULL;

    Registro *atendido = h->pacientes[0];
    h->pacientes[0] = h->pacientes[h->qtde - 1];
    h->qtde--;
    peneirar(h, 0);
    return atendido;
}

void mostrar_heap(Heap *h) {
    for (int i = 0; i < h->qtde; i++) {
        printf("Nome: %s | Idade: %d | RG: %s\n", h->pacientes[i]->nome, h->pacientes[i]->idade, h->pacientes[i]->rg);
    }
}
