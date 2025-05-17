#ifndef MENU_H
#define MENU_H

#include "cadastro.h"
#include "atendimento.h"
#include "atendimento_prioritario.h"
#include "desfazer.h"

void limpar_buffer();
Registro ler_paciente();
void menu_cadastro(LDE *lista);
void menu_atendimento(LDE *lista, Fila *fila, Pilha *pilha);
void menu_atendimento_prioritario(LDE *lista, Heap *heap);
void menu_pesquisa(LDE *lista);
void menu_salvar_carrega(Fila *fila, Heap *heap);
void menu_desfazer(Pilha *historico, Fila *fila);
void menu_sobre();
#endif
