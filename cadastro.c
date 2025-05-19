#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"

Celula *criar_celula(Registro registro) {
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->proximo = NULL;

    // alocar e copiar data
    nova->registro = registro;
    nova->registro.entrada = malloc(sizeof(Data));
    *(nova->registro.entrada) = *(registro.entrada);

    return nova;
}

LDE *criar_lista() {
    LDE *lista = (LDE *)malloc(sizeof(LDE));
    lista->primeiro = NULL;
    lista->qtd = 0;
    return lista;
}

void inserir(LDE *lista, Registro registro) {
    Celula *nova = criar_celula(registro);
    nova->proximo = lista->primeiro;
    lista->primeiro = nova;
    lista->qtd++;
}

void remover(LDE *lista, const char *rg) {
    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;

    while (atual != NULL && strcmp(atual->registro.rg, rg) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL){
        printf("RG informado não foi encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        lista->primeiro = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual->registro.entrada);
    free(atual);
    lista->qtd--;
    printf("Remoção feita com sucesso.\n");
}

void mostrar(LDE *lista) {
    Celula *atual = lista->primeiro;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->registro.nome);
        printf("Idade: %d\n", atual->registro.idade);
        printf("RG: %s\n", atual->registro.rg);
        printf("Data de entrada: %02d/%02d/%04d\n",
               atual->registro.entrada->dia,
               atual->registro.entrada->mes,
               atual->registro.entrada->ano);
        printf("--------------------------\n");
        atual = atual->proximo;
    }
}

void atualizar(LDE *lista, const char *rg) {
    Celula *atual = lista->primeiro;
    while (atual != NULL) {
        if (strcmp(atual->registro.rg, rg) == 0) {
            printf("\n--- Atualizar paciente ---\n");
            printf("Novo nome: ");
            fgets(atual->registro.nome, tam_nome, stdin);
            atual->registro.nome[strcspn(atual->registro.nome, "\n")] = 0;

            printf("Nova idade: ");
            scanf("%d", &atual->registro.idade);
            limpar_buffer();

            printf("Nova data de entrada.\n");
            printf("Dia: ");
            scanf("%d", &atual->registro.entrada->dia);
            printf("Mes: ");
            scanf("%d", &atual->registro.entrada->mes);
            printf("Ano: ");
            scanf("%d", &atual->registro.entrada->ano);
            limpar_buffer();

            printf("Paciente atualizado com sucesso!\n");
            return;
        }
        atual = atual->proximo;
    }
    printf("Paciente com RG %s nao encontrado.\n", rg);
}


Registro consultar(LDE *lista, const char *rg) {
    Celula *atual = lista->primeiro;
    while (atual != NULL) {
        if (strcmp(atual->registro.rg, rg) == 0) {
            printf("\n--- Paciente encontrado ---\n");
            printf("Nome: %s\n", atual->registro.nome);
            printf("Idade: %d\n", atual->registro.idade);
            printf("RG: %s\n", atual->registro.rg);
            printf("Data de entrada: %02d/%02d/%04d\n",
                   atual->registro.entrada->dia,
                   atual->registro.entrada->mes,
                   atual->registro.entrada->ano);
            printf("--------------------------\n");
            return atual->registro;
        }
        atual = atual->proximo;
    }

    printf("Paciente com RG %s nao encontrado.\n", rg);
    Registro vazio = {0};  
    return vazio;
}

Registro* consultar_ponteiro (LDE *lista, const char *rg) {
    Celula *atual = lista->primeiro;
    while (atual != NULL) {
        if (strcmp(atual->registro.rg, rg) == 0) {
            return &atual->registro;
        }
        atual = atual->proximo;
    }
    return NULL;
}

int conferir_rg(LDE *lista, const char *rg){
    Celula *atual = lista->primeiro;
    while (atual != NULL) {
        if(strcmp(atual->registro.rg, rg) == 0){
            return 1;
        }
        atual = atual->proximo;
    }
}
