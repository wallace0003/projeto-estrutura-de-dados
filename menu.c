#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"
#include "atendimento.h"
#include "atendimento_prioritario.h"
#include "pesquisa.h"

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

void menu_atendimento(LDE *lista, Fila *fila){
    int opcao;
    char rg_busca[tam_rg];

    do {
        printf("\n--- Atendimento ---\n");
        printf("1. Enfileirar paciente\n");
        printf("2. Desenfileirar paciente\n");
        printf("3. Mostrar fila\n");
        printf("0. Voltar ao menu principal\n");
        printf("Digite uma opção: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao){
            case 1: {
                printf("RG do paciente que deseja enfileirar: ");
                fgets(rg_busca, tam_rg, stdin);
                rg_busca[strcspn(rg_busca, "\n")] = 0;

                Registro *r = consultar_ponteiro(lista, rg_busca);
                if (r != NULL) {
                    enfileirar(fila, r);
                } else {
                    printf("Paciente não encontrado!\n");
                }
                break;
            }

            case 2: {
                Registro *r = desenfileirar(fila);
                if (r != NULL) {
                    printf("Paciente: %s\n", r->nome);
                    printf("RG: %s\n", r->rg);
                }
                break;
            }

            case 3:
                mostrar_fila(fila);
                break;

            case 0:
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while(opcao != 0);
}


void menu_atendimento_prioritario(LDE *lista, Heap *heap) {
    int opcao;
    char rg_busca[tam_rg];

    do {
        printf("\n--- Atendimento Prioritário ---\n");
        printf("1. Enfileirar paciente por prioridade\n");
        printf("2. Atender paciente prioritário\n");
        printf("3. Mostrar fila prioritária\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: {
                printf("RG do paciente: ");
                fgets(rg_busca, tam_rg, stdin);
                rg_busca[strcspn(rg_busca, "\n")] = 0;

                Registro *r = consultar_ponteiro(lista, rg_busca);
                if (r != NULL) {
                    enfileirar_prioritario(heap, r);
                } else {
                    printf("Paciente não encontrado!\n");
                }
                break;
            }

            case 2: {
                Registro *r = desenfileirar_prioritario(heap);
                if (r != NULL) {
                    printf("Paciente atendido: %s | Idade: %d | RG: %s\n", r->nome, r->idade, r->rg);
                } else {
                    printf("Fila prioritária vazia!\n");
                }
                break;
            }

            case 3:
                mostrar_heap(heap);
                break;

            case 0:
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);
}

void menu_pesquisa(LDE *lista) {
    int opcao;
    do {
        printf("\n--- Pesquisa de Pacientes (Árvore Binária) ---\n");
        printf("1. Mostrar registros ordenados por ANO de entrada\n");
        printf("2. Mostrar registros ordenados por MÊS de entrada\n");
        printf("3. Mostrar registros ordenados por DIA de entrada\n");
        printf("4. Mostrar registros ordenados por IDADE\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limpar_buffer();

        Arvore *arvore = cria_arvore();

        Celula *atual = lista->primeiro;  // Alterado de No* para Celula*
        while (atual != NULL) {
            switch (opcao) {
                case 1:
                    inserir_ano(arvore, &(atual->registro));  // Passa o endereço do registro
                    break;
                case 2:
                    inserir_mes(arvore, &(atual->registro));
                    break;
                case 3:
                    inserir_dia(arvore, &(atual->registro));
                    break;
                case 4:
                    inserir_idade(arvore, &(atual->registro));
                    break;
            }
            atual = atual->proximo;
        }

        switch (opcao) {
            case 1:
                printf("\n--- Pacientes ordenados por ANO de entrada ---\n");
                in_ordem_ano(arvore->raiz);
                printf("\n");
                break;
            case 2:
                printf("\n--- Pacientes ordenados por MÊS de entrada ---\n");
                in_ordem_mes(arvore->raiz);
                printf("\n");
                break;
            case 3:
                printf("\n--- Pacientes ordenados por DIA de entrada ---\n");
                in_ordem_dia(arvore->raiz);
                printf("\n");
                break;
            case 4:
                printf("\n--- Pacientes ordenados por IDADE ---\n");
                in_ordem_idade(arvore->raiz);
                printf("\n");
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }

        // Liberar memória da árvore (implementar se necessário)
        // liberar_arvore(arvore);

    } while (opcao != 0);
}

void menu_desfazer(){

}

void menu_salvar_carrega(Fila *fila, Heap *heap) {
    int op;
    printf("\n1. Salvar pacientes\n");
    printf("2. Carregar pacientes\n");
    printf("Opcao: ");
    scanf("%d", &op);
    limpar_buffer();

    switch (op) {
        case 1: {
            FILE *arquivo = fopen("fila.txt", "w");
            if (!arquivo) {
                printf("Erro ao abrir o arquivo.\n");
                break;
            }

            // Salvar prioritários
            for (int i = 0; i < heap->qtde; i++) {
                Registro *r = heap->pacientes[i];
                fprintf(arquivo, "PRIORITARIO\n");
                fprintf(arquivo, "NOME: %s\n", r->nome);
                fprintf(arquivo, "IDADE: %d\n", r->idade);
                fprintf(arquivo, "RG: %s\n", r->rg);
                fprintf(arquivo, "DIA DA ENTRADA: %02d/%02d/%04d\n\n",
                        r->entrada->dia, r->entrada->mes, r->entrada->ano);
            }

            // Salvar na fila normal
            No *atual = fila->head;
            while (atual != NULL) {
                Registro *r = atual->dados;
                fprintf(arquivo, "NORMAL\n");
                fprintf(arquivo, "NOME: %s\n", r->nome);
                fprintf(arquivo, "IDADE: %d\n", r->idade);
                fprintf(arquivo, "RG: %s\n", r->rg);
                fprintf(arquivo, "ENTRADA DIA MES ANO: %02d/%02d/%04d\n\n",
                        r->entrada->dia, r->entrada->mes, r->entrada->ano);
                atual = atual->proximo;
            }

            fclose(arquivo);
            printf("Pacientes salvos com sucesso.\n");
            break;
        }

        case 2: {
            FILE *arquivo = fopen("fila.txt", "r");
            if (!arquivo) {
                printf("Erro ao abrir o arquivo para leitura.\n");
                break;
            }

            char tipo[20];
            while (fscanf(arquivo, "%s", tipo) != EOF) {
                Registro *r = malloc(sizeof(Registro));
                r->entrada = malloc(sizeof(Data));

                fscanf(arquivo, " NOME: %[^\n]", r->nome);
                fscanf(arquivo, " IDADE: %d", &r->idade);
                fscanf(arquivo, " RG: %[^\n]", r->rg);
                fscanf(arquivo, " ENTRADA DIA MES ANO: %d/%d/%d\n",
                       &r->entrada->dia, &r->entrada->mes, &r->entrada->ano);

                if (strcmp(tipo, "PRIORITARIO") == 0) {
                    enfileirar_prioritario(heap, r);
                } else if (strcmp(tipo, "NORMAL") == 0) {
                    enfileirar(fila, r);
                }
                fscanf(arquivo, "\n"); // consome a linha em branco
            }

            fclose(arquivo);
            printf("Pacientes carregados com sucesso.\n");
            break;
        }

        default:
            printf("Opcao invalida.\n");
    }
}

void menu_sobre(){
    printf("         --- DESENVOLVEDORES ---         \n");
    printf("Nomes:\n");
    printf(" - Pedro Henrique da Fonseca do Nascimento   RA: 22.123.099-8\n");
    printf(" - Wallace dos Santos Izidoro               RA: 22.123.104-8\n");
    printf("-----------------------------------------\n");
    printf("Curso: CIÊNCIA DA COMPUTAÇÃO\n");
    printf("Disciplina: ESTRUTURA DE DADOS\n");
    printf("Data: 19/05/2025\n");
    printf("------------------------------------------\n");

}