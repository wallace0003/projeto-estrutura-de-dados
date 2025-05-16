#ifndef MENU_H
#define MENU_H

#include "cadastro.h"
#include "atendimento.h"
#include "atendimento_prioritario.h"

void limpar_buffer();
Registro ler_paciente();
void menu_cadastro(LDE *lista);
void menu_atendimento(LDE *lista, Fila *fila);
void menu_atendimento_prioritario(LDE *lista, Heap *heap);
void menu_pesquisa(LDE *lista);
void menu_sobre();
#endif
