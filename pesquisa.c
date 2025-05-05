#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"

typedef struct Vertice {
    Registro *registro;
    struct Vertice *esq;
    struct Vertice *dir;
    struct Vertice *pai;
} Vertice;

typedef struct Arvore{
	Vertice *raiz;
	int qtde;
} Arvore;

void in_ordem_idade(Vertice *raiz) {
    if (raiz != NULL) {
        in_ordem_idade(raiz->esq);
        printf("--------------------------------------------------\n");
        printf("Idade: %d\n", raiz->registro->idade);
        printf("Nome: %s\n", raiz->registro->nome);
        printf("RG: %s\n", raiz->registro->rg);
        printf("--------------------------------------------------\n");
        in_ordem_idade(raiz->dir);
    }
}

void in_ordem_ano(Vertice *raiz) {
    if (raiz != NULL) {
        in_ordem_ano(raiz->esq);
        printf("--------------------------------------------------\n");
        printf("Ano de entrada: %d\n", raiz->registro->entrada->ano);
        printf("Nome: %s\n", raiz->registro->nome);
        printf("RG: %s\n", raiz->registro->rg);
        in_ordem_ano(raiz->dir);
    }
}

void in_ordem_mes(Vertice *raiz) {
    if (raiz != NULL) {
        in_ordem_mes(raiz->esq);
        printf("--------------------------------------------------\n");
        printf("Mês de entrada: %d\n", raiz->registro->entrada->mes);
        printf("Nome: %s\n", raiz->registro->nome);
        printf("RG: %s\n", raiz->registro->rg);
        printf("--------------------------------------------------\n");
        in_ordem_mes(raiz->dir);
    }
}

void in_ordem_dia(Vertice *raiz) {
    if (raiz != NULL) {
        in_ordem_dia(raiz->esq);
        printf("--------------------------------------------------\n");
        printf("Dia de entrada: %d\n", raiz->registro->entrada->dia);
        printf("Nome: %s\n", raiz->registro->nome);
        printf("RG: %s\n", raiz->registro->rg);
        printf("--------------------------------------------------\n");
        in_ordem_dia(raiz->dir);
    }
}

void pre_ordem_idade(Vertice *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->registro->idade);
        pre_ordem_idade(raiz->esq);
        pre_ordem_idade(raiz->dir);
    }
}

void pre_ordem_ano(Vertice *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->registro->entrada->ano);
        pre_ordem_ano(raiz->esq);
        pre_ordem_ano(raiz->dir);
    }
}

void pre_ordem_mes(Vertice *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->registro->entrada->mes);
        pre_ordem_mes(raiz->esq);
        pre_ordem_mes(raiz->dir);
    }
}

void pre_ordem_dia(Vertice *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->registro->entrada->dia);
        pre_ordem_dia(raiz->esq);
        pre_ordem_dia(raiz->dir);
    }
}

void pos_ordem_idade(Vertice *raiz) {
    if (raiz != NULL) {
        pos_ordem_idade(raiz->esq);
        pos_ordem_idade(raiz->dir);
        printf("%d ", raiz->registro->idade);
    }
}

void pos_ordem_ano(Vertice *raiz) {
    if (raiz != NULL) {
        pos_ordem_ano(raiz->esq);
        pos_ordem_ano(raiz->dir);
        printf("%d ", raiz->registro->entrada->ano);
    }
}

void pos_ordem_mes(Vertice *raiz) {
    if (raiz != NULL) {
        pos_ordem_mes(raiz->esq);
        pos_ordem_mes(raiz->dir);
        printf("%d ", raiz->registro->entrada->mes);
    }
}

void pos_ordem_dia(Vertice *raiz) {
    if (raiz != NULL) {
        pos_ordem_dia(raiz->esq);
        pos_ordem_dia(raiz->dir);
        printf("%d ", raiz->registro->entrada->dia);
    }
}

Vertice *cria_vertice(Registro *registro){
	Vertice* novo = malloc(sizeof(Vertice));
	novo->dir = NULL;
	novo->esq = NULL;
	novo->pai = NULL;
	novo->registro = registro;
	return novo;
}

Arvore *cria_arvore(){
	Arvore *arvore = malloc(sizeof(Arvore));
	arvore->raiz = NULL;
	arvore->qtde = 0;
	return arvore;
}

void inserir_idade(Arvore* arvore, Registro* registro) {
    Vertice* novo = cria_vertice(registro);
    novo->registro = registro;  // Assumindo que Vertice tem campo para armazenar o registro completo

    Vertice* anterior = NULL;
    Vertice* atual = arvore->raiz;

    while(atual != NULL) {
        anterior = atual;
        if(registro->idade <= anterior->registro->idade) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    novo->pai = anterior;
    if(anterior != NULL) {
        if(registro->idade <= anterior->registro->idade) {
            anterior->esq = novo;
        } else {
            anterior->dir = novo;
        }
    } else {
        arvore->raiz = novo;
    }
    arvore->qtde++;
}

void inserir_ano(Arvore* arvore, Registro* registro) {
    Vertice* novo = cria_vertice(registro);
    novo->registro = registro;

    Vertice* anterior = NULL;
    Vertice* atual = arvore->raiz;

    while(atual != NULL) {
        anterior = atual;
        if(registro->entrada->ano <= anterior->registro->entrada->ano) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    novo->pai = anterior;
    if(anterior != NULL) {
        if(registro->entrada->ano <= anterior->registro->entrada->ano) {
            anterior->esq = novo;
        } else {
            anterior->dir = novo;
        }
    } else {
        arvore->raiz = novo;
    }
    arvore->qtde++;
}

void inserir_mes(Arvore* arvore, Registro* registro) {
    Vertice* novo = cria_vertice(registro);
    novo->registro = registro;

    Vertice* anterior = NULL;
    Vertice* atual = arvore->raiz;

    while(atual != NULL) {
        anterior = atual;
        if(registro->entrada->mes <= anterior->registro->entrada->mes) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    novo->pai = anterior;
    if(anterior != NULL) {
        if(registro->entrada->mes <= anterior->registro->entrada->mes) {
            anterior->esq = novo;
        } else {
            anterior->dir = novo;
        }
    } else {
        arvore->raiz = novo;
    }
    arvore->qtde++;
}

void inserir_dia(Arvore* arvore, Registro* registro) {
    Vertice* novo = cria_vertice(registro);
    novo->registro = registro;

    Vertice* anterior = NULL;
    Vertice* atual = arvore->raiz;

    while(atual != NULL) {
        anterior = atual;
        if(registro->entrada->dia <= anterior->registro->entrada->dia) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    novo->pai = anterior;
    if(anterior != NULL) {
        if(registro->entrada->dia <= anterior->registro->entrada->dia) {
            anterior->esq = novo;
        } else {
            anterior->dir = novo;
        }
    } else {
        arvore->raiz = novo;
    }
    arvore->qtde++;
}

Vertice *buscar_idade(Arvore* arvore, int idade) {
    Vertice* atual = arvore->raiz;
    while(atual != NULL) {
        if(idade < atual->registro->idade) {
            atual = atual->esq;
        } else if(idade > atual->registro->idade) {
            atual = atual->dir;
        } else {
            return atual;
        }
    }
    return NULL;
}

Vertice *buscar_ano(Arvore* arvore, int ano) {
    Vertice* atual = arvore->raiz;
    while(atual != NULL) {
        if(ano < atual->registro->entrada->ano) {
            atual = atual->esq;
        } else if(ano > atual->registro->entrada->ano) {
            atual = atual->dir;
        } else {
            return atual;
        }
    }
    return NULL;
}

Vertice *buscar_mes(Arvore* arvore, int mes) {
    Vertice* atual = arvore->raiz;
    while(atual != NULL) {
        if(mes < atual->registro->entrada->mes) {
            atual = atual->esq;
        } else if(mes > atual->registro->entrada->mes) {
            atual = atual->dir;
        } else {
            return atual;
        }
    }
    return NULL;
}

Vertice *buscar_dia(Arvore* arvore, int dia) {
    Vertice* atual = arvore->raiz;
    while(atual != NULL) {
        if(dia < atual->registro->entrada->dia) {
            atual = atual->esq;
        } else if(dia > atual->registro->entrada->dia) {
            atual = atual->dir;
        } else {
            return atual;
        }
    }
    return NULL;
}