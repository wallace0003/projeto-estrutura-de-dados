#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Registro ler_paciente() {
    Registro r;
    r.entrada = malloc(sizeof(Data));

    printf("Digite o nome: ");
    fgets(r.nome, tam_nome, stdin);
    r.nome[strcspn(r.nome, "\n")] = 0;

    printf("Digite a idade: ");
    scanf("%d", &r.idade);
    limpar_buffer();

    printf("Digite o RG: ");
    fgets(r.rg, tam_rg, stdin);
    r.rg[strcspn(r.rg, "\n")] = 0;

    printf("Data de entrada.\n");
    printf("Dia: ");
    scanf("%d", &r.entrada->dia);

    printf("Mes: ");
    scanf("%d", &r.entrada->mes);

    printf("Ano: ");
    scanf("%d", &r.entrada->ano);
    limpar_buffer();

    return r;
}

void menu_cadastro(LDE *lista) {
    int opcao;
    char rg_busca[tam_rg];

    do {
        printf("\n--- Cadastrar Paciente ---\n");
        printf("1. Cadastrar novo paciente\n");
        printf("2. Consultar paciente\n");
        printf("3. Mostrar todos os pacientes\n");
        printf("4. Atualizar dados\n");
        printf("5. Remover paciente pelo RG\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: {
                Registro r = ler_paciente();
                inserir(lista, r);
                printf("Paciente cadastrado com sucesso!\n");
                break;
            }
            case 2:
                printf("Digite o RG do paciente a consultar: ");
                fgets(rg_busca, tam_rg, stdin);
                rg_busca[strcspn(rg_busca, "\n")] = 0;
                consultar(lista, rg_busca);
                break;
            case 3:
                printf("\nLista de pacientes:\n");
                mostrar(lista);
                break;
            case 4:
                printf("Digite o RG do paciente a atualizar: ");
                fgets(rg_busca, tam_rg, stdin);
                rg_busca[strcspn(rg_busca, "\n")] = 0;
                atualizar(lista, rg_busca);
                break;
            case 5:
                printf("Digite o RG do paciente a remover: ");
                fgets(rg_busca, tam_rg, stdin);
                rg_busca[strcspn(rg_busca, "\n")] = 0;
                remover(lista, rg_busca);
                printf("Remocao (se aplicável) concluída.\n");
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}