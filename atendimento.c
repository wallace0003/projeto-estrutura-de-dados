#include <stdio.h>
#include <stdlib.h>
#include "atendimento.h"

Fila *criar_fila() {
    Fila *fila = malloc(sizeof(Fila));
    fila->head = NULL;
    fila->tail = NULL;
    fila->qtd = 0;
    return fila;
}

void enfileirar(Fila *fila, Registro *r) {
    No *novo = malloc(sizeof(No));
    novo->dados = r;
    novo->proximo = NULL;

    if (fila->tail == NULL) {
        fila->head = fila->tail = novo;
    } else {
        fila->tail->proximo = novo;
        fila->tail = novo;
    }
    fila->qtd++;
    printf("Paciente enfileirado com sucesso.\n");
}

Registro *desenfileirar(Fila *fila) {
    if (fila->head == NULL) {
        printf("Fila vazia.\n");
        return NULL;
    }

    No *removido = fila->head;
    Registro *r = removido->dados;

    fila->head = fila->head->proximo;
    if (fila->head == NULL) {
        fila->tail = NULL;
    }
    free(removido);
    fila->qtd--;
    return r;
}

void mostrar_fila(Fila *fila) {
    No *atual = fila->head;
    int qtd_fila = fila->qtd;
    printf("Quantidade de pacientes na fila: %d\n", qtd_fila);
    printf("----------Pacientes:----------\n");
    printf("\n");
    while (atual != NULL) {
        Registro *r = atual->dados;
        printf("Nome: %s\n", r->nome);
        printf("Idade: %d\n", r->idade);
        printf("RG: %s\n", r->rg);
        printf("Data de entrada: %02d/%02d/%04d\n",
               r->entrada->dia, r->entrada->mes, r->entrada->ano);
        printf("----------------------\n");
        atual = atual->proximo;
    }
}

int fila_vazia(Fila *fila) {
    return fila->head == NULL;
}
