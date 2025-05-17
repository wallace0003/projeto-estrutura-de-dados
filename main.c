#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "atendimento_prioritario.h"
#include "desfazer.h"

int main() {
    LDE *lista = criar_lista();
    Fila *fila = criar_fila();
    Heap *prioridade = malloc(sizeof(Heap));
    Pilha *pilha = criar_pilha();
    inicializar_heap(prioridade);

    int opcao;

    do {
        printf("\n=== Menu Principal ===\n");
        printf("1. Cadastrar pacientes\n");
        printf("2. Atendimento comum (fila)\n");
        printf("3. Atendimento prioritário (por idade)\n");
        printf("4. Pesquisa(idade/dia/mês/ano)\n");
        printf("5. Desfazer\n");
        printf("6. Salvar e carregar\n");
        printf("7. Sobre\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1:
                menu_cadastro(lista);
                break;
            case 2:
                menu_atendimento(lista, fila, pilha);
                break;
            case 3:
                menu_atendimento_prioritario(lista, prioridade);
                break;
            case 4:
                menu_pesquisa(lista);
                break;
            case 5:
                menu_desfazer(pilha, fila);
                break;
            case 6:
                menu_salvar_carrega(fila, prioridade);
                break;
            case 7:
                menu_sobre();
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    free(prioridade);
    return 0;
}
