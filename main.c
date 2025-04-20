#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"
#include "menu.h"

int main() {
    LDE *lista = criar_lista();
    int opcao;

    do {
        printf("\n=== Menu Principal ===\n");
        printf("1. Cadastrar (pacientes)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1:
                menu_cadastro(lista);
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
