#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"



// Estrutura do vértice da árvore
typedef struct Vertice {
    Registro *registro;
    struct Vertice *esq;
    struct Vertice *dir;
    struct Vertice *pai;
} Vertice;

// Estrutura da árvore
typedef struct Arvore {
    Vertice *raiz;
    int qtde;
} Arvore;

// Funções de percurso (in-ordem)
void in_ordem_idade(Vertice *raiz);
void in_ordem_ano(Vertice *raiz);
void in_ordem_mes(Vertice *raiz);
void in_ordem_dia(Vertice *raiz);

// Funções de percurso (pré-ordem)
void pre_ordem_idade(Vertice *raiz);
void pre_ordem_ano(Vertice *raiz);
void pre_ordem_mes(Vertice *raiz);
void pre_ordem_dia(Vertice *raiz);

// Funções de percurso (pós-ordem)
void pos_ordem_idade(Vertice *raiz);
void pos_ordem_ano(Vertice *raiz);
void pos_ordem_mes(Vertice *raiz);
void pos_ordem_dia(Vertice *raiz);

// Funções de criação
Vertice *cria_vertice(Registro *registro);
Arvore *cria_arvore();

// Funções de inserção
void inserir_idade(Arvore* arvore, Registro* registro);
void inserir_ano(Arvore* arvore, Registro* registro);
void inserir_mes(Arvore* arvore, Registro* registro);
void inserir_dia(Arvore* arvore, Registro* registro);

// Funções de busca
Vertice buscar_idade(Arvore* arvore, int idade);
Vertice buscar_ano(Arvore* arvore, int ano);
Vertice buscar_mes(Arvore* arvore, int mes);
Vertice buscar_dia(Arvore* arvore, int dia);
