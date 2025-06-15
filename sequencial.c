#include <stdio.h>
#include <stdlib.h>
#include "sequencial.h"

#define MAX 50
// Define a constante MAX como 50, que é o tamanho máximo da lista.

struct lista
{
    int quantidade;     // Armazena o número atual de elementos na lista.
    int elementos[MAX]; // Array que armazena os elementos da lista.
};

LISTA *criarLista()
{
    LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
    // Aloca memória para uma nova lista e atribui o ponteiro à variável lista.

    if (lista == NULL)
    {
        printf("Erro ao alocar memória para criar lista!\n");
        // Exibe uma mensagem de erro se a alocação de memória falhar.
        return NULL;
    }

    lista->quantidade = 0;
    // Inicializa a quantidade de elementos na lista como 0.

    return lista;
    // Retorna o ponteiro para a nova lista criada.
}

LISTA *inserirFim(LISTA *lista, int valor)
{
    if (valor < 0)
    {
        printf("Valor negativo! Não é possível inserir no fim da lista!\n");
        // Exibe uma mensagem de erro se o valor a ser inserido for negativo.
        return NULL;
    }

    lista->elementos[lista->quantidade] = valor;
    // Adiciona o valor no final da lista (na posição atual de quantidade).

    lista->quantidade++;
    // Incrementa a quantidade de elementos na lista.

    return lista;
    // Retorna o ponteiro para a lista atualizada.
}

LISTA *inserirPosicao(LISTA *lista, int valor, int pos)
{
    if (valor < 0)
    {
        printf("Valor negativo! Não é possível inserir na lista!\n");
        // Exibe uma mensagem de erro se o valor a ser inserido for negativo.
        return NULL;
    }

    if (pos < 0 || pos > lista->quantidade)
    {
        printf("Posição inválida! Não é possível inserir na lista!\n");
        // Exibe uma mensagem de erro se a posição especificada for inválida.
        return NULL;
    }

    for (int i = lista->quantidade; i > pos; i--)
    {
        lista->elementos[i] = lista->elementos[i - 1];
        // Move todos os elementos a partir da posição para a direita para abrir espaço para o novo elemento.
    }

    lista->elementos[pos] = valor;
    // Insere o novo valor na posição especificada.

    lista->quantidade++;
    // Incrementa a quantidade de elementos na lista.

    return lista;
    // Retorna o ponteiro para a lista atualizada.
}

LISTA *removerPosicao(LISTA *lista, int pos)
{
    if (pos < 0 || pos >= lista->quantidade)
    {
        printf("Posição inválida! Não é possível remover da lista!\n");
        // Exibe uma mensagem de erro se a posição especificada for inválida.
        return NULL;
    }

    for (int i = pos; i < lista->quantidade - 1; i++)
    {
        lista->elementos[i] = lista->elementos[i + 1];
        // Move todos os elementos após a posição para a esquerda para preencher o espaço vazio.
    }

    lista->quantidade--;
    // Decrementa a quantidade de elementos na lista.

    return lista;
    // Retorna o ponteiro para a lista atualizada.
}

LISTA *removerValor(LISTA *lista, int valor)
{
    if (valor < 0)
    {
        printf("Valor negativo! Não é possível remover da lista!\n");
        // Exibe uma mensagem de erro se o valor a ser removido for negativo.
        return NULL;
    }

    int pos = -1;

    for (int i = 0; i < lista->quantidade; i++)
    {
        if (lista->elementos[i] == valor)
        {
            pos = i;
            break;
            // Encontra a primeira ocorrência do valor e armazena sua posição.
        }
    }

    if (pos == -1)
    {
        printf("Elemento não encontrado! Não é possível remover da lista!\n");
        // Exibe uma mensagem de erro se o valor não for encontrado.
        return NULL;
    }

    for (int i = pos; i < lista->quantidade - 1; i++)
    {
        lista->elementos[i] = lista->elementos[i + 1];
        // Move todos os elementos após o valor removido para a esquerda para preencher o espaço vazio.
    }

    lista->quantidade--;
    // Decrementa a quantidade de elementos na lista.

    return lista;
    // Retorna o ponteiro para a lista atualizada.
}

int obterElementoPosicao(LISTA *lista, int pos)
{
    if (lista == NULL)
    {
        printf("Lista vazia! Não é possível obter elemento!\n");
        // Exibe uma mensagem de erro se a lista for NULL.
        return -1;
    }

    if (pos < 0 || pos >= lista->quantidade)
    {
        printf("Posição inválida! Não é possível obter elemento!\n");
        // Exibe uma mensagem de erro se a posição especificada for inválida.
        return -1;
    }

    return lista->elementos[pos];
    // Retorna o valor do elemento na posição especificada.
}

int procurarElemento(LISTA *lista, int valor)
{
    if (lista == NULL)
    {
        printf("Lista vazia! Não é possível procurar elemento!\n");
        // Exibe uma mensagem de erro se a lista for NULL.
        return -1;
    }

    if (valor < 0)
    {
        printf("Valor negativo! Não é possível procurar elemento!\n");
        // Exibe uma mensagem de erro se o valor a ser procurado for negativo.
        return -1;
    }

    int pos = -1;

    for (int i = 0; i < lista->quantidade; i++)
    {
        if (lista->elementos[i] == valor)
        {
            pos = i;
            break;
            // Encontra a primeira ocorrência do valor e armazena sua posição.
        }
    }

    if (pos == -1)
    {
        printf("Elemento não encontrado! Não é possível procurá-lo\n");
        // Exibe uma mensagem de erro se o valor não for encontrado.
        return -1;
    }

    return pos;
    // Retorna a posição da primeira ocorrência do valor.
}

int tamanhoLista(LISTA *lista)
{
    if (lista == NULL)
    {
        printf("Lista vazia! Não é possível retornar o número de elementos da lista!\n");
        // Exibe uma mensagem de erro se a lista for NULL.
        return -1;
    }

    return lista->quantidade;
    // Retorna o número de elementos na lista.
}

void exibirLista(LISTA *lista)
{
    if (lista == NULL)
    {
        printf("Lista vazia! Não é possível exibi-la\n");
        // Exibe uma mensagem de erro se a lista for NULL.
        return;
    }

    for (int i = 0; i < lista->quantidade; i++)
    {
        printf("%d\n", lista->elementos[i]);
        // Imprime cada elemento da lista.
    }
}

void pressioneBotaoParaContinuar()
{
    printf("\nPressione um botão para exibir o menu novamente...\n");
    getchar();
    getchar();
    // Pausa a execução e espera que o usuário pressione uma tecla.
}

void crieUmaLista()
{
    printf("Crie uma lista!\n");
    // Exibe uma mensagem pedindo ao usuário para criar uma lista.
}

void liberarLista(LISTA *lista)
{
    if (lista == NULL)
    {
        printf("Lista vazia! Não é possível liberar a memória\n");
        // Exibe uma mensagem de erro se a lista for NULL.
        return;
    }

    free(lista);
    // Libera a memória alocada para a lista.
}