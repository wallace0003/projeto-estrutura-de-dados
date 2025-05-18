#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"

// Renomeada a estrutura para evitar conflito com "Celula" da lista
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

CelulaHistorico *criar_celula_historico(Registro *registro, char operacao[20]) {
    CelulaHistorico *nova = malloc(sizeof(CelulaHistorico));
    if (!nova) {
        printf("Erro de alocação na pilha.\n");
        exit(1);
    }

    nova->anterior = NULL;
    nova->proximo = NULL;
    nova->registro = registro;
    strcpy(nova->operacao, operacao);
    return nova;
}

Pilha *criar_pilha() {
    Pilha *pilha = malloc(sizeof(Pilha));
    if (!pilha) {
        printf("Erro de alocação da pilha.\n");
        exit(1);
    }

    pilha->qtd = 0;
    pilha->topo = NULL;
    return pilha;
}

void push(Pilha *pilha, Registro *registro, char operacao[20]) {
    CelulaHistorico *nova = criar_celula_historico(registro, operacao);
    if (pilha->topo != NULL) {
        pilha->topo->proximo = nova;
        nova->anterior = pilha->topo;
    }
    pilha->topo = nova;
    pilha->qtd++;
}

void pop(Pilha *pilha) {
    if (pilha->qtd == 0 || pilha->topo == NULL) return;

    CelulaHistorico *liberar = pilha->topo;
    pilha->topo = liberar->anterior;
    if (pilha->topo != NULL)
        pilha->topo->proximo = NULL;

    free(liberar);
    pilha->qtd--;
}

void mostrar_historico(Pilha *pilha) {
    CelulaHistorico *atual = pilha->topo;
    printf("\n--- Histórico de operações (topo -> base) ---\n");
    while (atual != NULL) {
        printf("Operação: %s\n", atual->operacao);
        printf("Nome: %s\n", atual->registro->nome);
        printf("RG: %s\n", atual->registro->rg);
        printf("Idade: %d\n", atual->registro->idade);
        printf("Data de entrada: %02d/%02d/%04d\n",
               atual->registro->entrada->dia,
               atual->registro->entrada->mes,
               atual->registro->entrada->ano);
        printf("-----------------------------------\n");
        atual = atual->anterior;
    }
    printf("Fim da pilha\n");
}
