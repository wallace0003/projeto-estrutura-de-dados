#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"


int main() {
    LDE *lista = criar_lista();
    Fila *fila = criar_fila();
    int opcao;

    do {
        printf("\n=== Menu Principal ===\n");
        printf("1. Cadastrar (pacientes)\n");
        printf("2. Inserir paciente em uma fila de atendimento.\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1:
                menu_cadastro(lista);
                break;
            case 2:
                menu_atendimento(lista, fila);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
