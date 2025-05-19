#ifndef CADASTRO_H
#define CADASTRO_H

#define tam_nome 50
#define tam_rg 10

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[tam_nome];
    int idade;
    char rg[tam_rg];
    Data *entrada; // Data de entrada no sistema
} Registro;

typedef struct celula {
    Registro registro;
    struct celula *proximo;
} Celula;

typedef struct {
    Celula *primeiro;
    int qtd;
} LDE;

LDE *criar_lista();
Celula *criar_celula(Registro registro);
void inserir(LDE *lista, Registro registro);
void remover(LDE *lista, const char *rg);
void mostrar(LDE *lista);
Registro consultar(LDE *lista, const char *rg);
void atualizar(LDE *lista, const char *rg);
Registro* consultar_ponteiro (LDE *lista, const char *rg);
int conferir_rg(LDE *lista, const char *rg);

#endif
