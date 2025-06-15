#include "sequencial.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// FUNÇÕES AUXILIARES ==============================================================================
void exibir_menu()
{
    // Exibe o menu com as opções disponíveis para o usuário
    printf("================================================================\n");
    printf("               GERENCIAR LISTA SEQUENCIAL\n");
    printf("================================================================\n");
    printf("1. Criar lista\t\t\t\t6. Obter Elemento por Posição\n");
    printf("2. Inserir Elemento no Final\t\t7. Procurar Elemento\n");
    printf("3. Inserir Elemento em uma Posição\t8. Tamanho da Lista\n");
    printf("4. Remover Elemento por Posição\t\t9. Imprimir Lista\n");
    printf("5. Remover Elemento por Valor\t\t10. Sair\n");
    printf("================================================================\n");
    printf("=========================================== Escolha uma opção:  ");
}

void aguardar_tecla()
{
    // Solicita que o usuário pressione Enter para continuar
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n') // Limpa o buffer até encontrar uma nova linha
        ;
}

int is_numerico(const char *str)
{
    // Verifica se a string contém apenas dígitos
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return false; // Retorna false se encontrar qualquer caractere não numérico
        }
    }
    return true; // Retorna true se todos os caracteres forem dígitos
}

int ler_inteiro()
{
    char input[100]; // Buffer para armazenar a entrada do usuário
    int numero;

    while (true)
    {
        fgets(input, sizeof(input), stdin); // Lê a entrada do usuário
        input[strcspn(input, "\n")] = 0;    // Remove o caractere de nova linha

        if (is_numerico(input))
        {
            numero = atoi(input); // Converte a string para um número inteiro
            break;
        }
        else
        {
            return -1; // Retorna -1 para indicar entrada inválida
        }
    }
    return numero; // Retorna o número inteiro lido
}

void entrada_invalida()
{
    // Mensagem de erro para entrada inválida
    printf("Entrada Inválida! Por favor insira um número inteiro.\n");
    printf("Tente novamente ...\n");
}
// =================================================================================================

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Configura o locale para suportar caracteres em português

    LISTA *lista; // Ponteiro para a lista que será manipulada

    int opcao, valor, posicao, resultado;
    bool listaCriada = false; // Flag para verificar se a lista foi criada

    do
    {
        exibir_menu();         // Exibe o menu para o usuário
        opcao = ler_inteiro(); // Lê a opção escolhida pelo usuário

        switch (opcao)
        {
        case 1:
            lista = criarLista(); // Cria uma nova lista
            printf("\nLista criada com sucesso!\n");
            listaCriada = true; // Marca a lista como criada
            aguardar_tecla();   // Aguarda o usuário pressionar Enter
            break;
        case 2:
            if (listaCriada)
            {
                printf("\nDigite o valor a ser inserido: ");
                valor = ler_inteiro(); // Lê o valor a ser inserido
                if (valor != -1)       // Verifica se a entrada é válida
                {
                    lista = inserirFim(lista, valor); // Insere o valor no final da lista
                }
                else
                {
                    entrada_invalida(); // Exibe mensagem de entrada inválida
                    aguardar_tecla();   // Aguarda o usuário pressionar Enter
                }
            }
            else
            {
                printf("\nVocê deve criar uma lista\n"); // Mensagem se a lista não foi criada
            }
            break;
        case 3:
            if (listaCriada)
            {
                printf("\nDigite o valor a ser inserido: ");
                valor = ler_inteiro(); // Lê o valor a ser inserido
                printf("\nDigite a posição a ser inserida: ");
                posicao = ler_inteiro();          // Lê a posição onde o valor será inserido
                if (valor != -1 && posicao != -1) // Verifica se as entradas são válidas
                {
                    lista = inserirPosicao(lista, valor, posicao); // Insere o valor na posição especificada
                }
                else
                {
                    entrada_invalida(); // Exibe mensagem de entrada inválida
                    aguardar_tecla();   // Aguarda o usuário pressionar Enter
                }
            }
            else
            {
                printf("\nVocê deve criar uma lista\n"); // Mensagem se a lista não foi criada
            }
            break;
        case 4:
            if (listaCriada)
            {
                printf("\nDigite a posição do valor a ser removido: ");
                posicao = ler_inteiro(); // Lê a posição do valor a ser removido
                if (posicao != -1)       // Verifica se a entrada é válida
                {
                    lista = removerPosicao(lista, posicao); // Remove o valor na posição especificada
                }
                else
                {
                    entrada_invalida(); // Exibe mensagem de entrada inválida
                    aguardar_tecla();   // Aguarda o usuário pressionar Enter
                }
            }
            else
            {
                printf("\nVocê deve criar uma lista\n"); // Mensagem se a lista não foi criada
            }
            break;
        case 5:
            if (listaCriada)
            {
                printf("\nDigite o valor a ser removido: ");
                valor = ler_inteiro(); // Lê o valor a ser removido
                if (valor != -1)       // Verifica se a entrada é válida
                {
                    lista = removerValor(lista, valor); // Remove o valor especificado
                }
                else
                {
                    entrada_invalida(); // Exibe mensagem de entrada inválida
                    aguardar_tecla();   // Aguarda o usuário pressionar Enter
                }
            }
            else
            {
                printf("\nVocê deve criar uma lista\n"); // Mensagem se a lista não foi criada
            }
            break;
        case 6:
            if (listaCriada)
            {
                printf("\nDigite a posição do elemento a ser obtido (Inicia em 0): ");
                posicao = ler_inteiro(); // Lê a posição do elemento a ser obtido
                if (posicao != -1)       // Verifica se a entrada é válida
                {
                    valor = obterElementoPosicao(lista, posicao); // Obtém o valor na posição especificada
                    if (valor != -1)                              // Verifica se o valor obtido é válido
                    {
                        printf("Elemento na posição %d: %d\n", posicao, valor); // Exibe o valor obtido
                    }
                    aguardar_tecla(); // Aguarda o usuário pressionar Enter
                }
                else
                {
                    entrada_invalida(); // Exibe mensagem de entrada inválida
                }
            }
            else
            {
                printf("\nVocê deve criar uma lista\n"); // Mensagem se a lista não foi criada
            }
            break;
        case 7:
            if (listaCriada)
            {
                printf("\nDigite o valor a ser procurado: ");
                valor = ler_inteiro(); // Lê o valor a ser procurado
                if (valor != -1)       // Verifica se a entrada é válida
                {
                    posicao = procurarElemento(lista, valor); // Procura o valor na lista
                    if (posicao != -1)                        // Verifica se o valor foi encontrado
                    {
                        printf("Elemento %d encontrado na posição %d.\n", valor, posicao); // Exibe a posição do valor
                    }
                    else
                    {
                        printf("Elemento %d não encontrado.\n", valor); // Mensagem se o valor não foi encontrado
                    }
                    aguardar_tecla(); // Aguarda o usuário pressionar Enter
                }
                else
                {
                    entrada_invalida(); // Exibe mensagem de entrada inválida
                }
            }
            else
            {
                printf("\nVocê deve criar uma lista\n"); // Mensagem se a lista não foi criada
            }
            break;
        case 8:
            if (listaCriada)
            {
                resultado = tamanhoLista(lista);               // Obtém o tamanho da lista
                printf("\nTamanho da lista: %d\n", resultado); // Exibe o tamanho da lista
                aguardar_tecla();                              // Aguarda o usuário pressionar Enter
            }
            else
            {
                printf("\nVocê deve criar uma lista\n"); // Mensagem se a lista não foi criada
            }
            break;
        case 9:
            if (listaCriada)
            {
                exibirLista(lista); // Exibe todos os elementos da lista
                aguardar_tecla();   // Aguarda o usuário pressionar Enter
            }
            else
            {
                printf("\nVocê deve criar uma lista\n"); // Mensagem se a lista não foi criada
            }
            break;
        case 10:
            printf("\nSaindo...\n"); // Mensagem ao sair do programa
            break;
        case -1:                // Adicionado para lidar com entrada inválida
            entrada_invalida(); // Exibe mensagem de entrada inválida
            break;
        default:
            printf("\nOpção inválida! Tente novamente.\n"); // Mensagem para opções inválidas
            break;
        }
        printf("\n");
    } while (opcao != 10); // Continua até o usuário escolher sair

    return 0; // Termina o programa
}