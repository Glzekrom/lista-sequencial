#ifndef LISTA_SEQ_H
#define LISTA_SEQ_H

typedef struct lista LISTA; // Define um tipo de dado chamado LISTA como um ponteiro para a estrutura lista.

// Cria uma nova lista vazia.
// Aloca memória para uma nova lista e inicializa o campo que mantém o controle do número de elementos como 0.
// Retorna um ponteiro para a nova lista criada ou NULL se houver falha na alocação de memória.
LISTA *criarLista();

// Exibe todos os elementos da lista.
// Percorre a lista e imprime cada elemento na tela. Se a lista estiver vazia, exibe uma mensagem informando que não há elementos para exibir.
void exibirLista(LISTA *lista);

// Insere um elemento inteiro no final da lista.
// Adiciona um valor ao final da lista, se houver espaço disponível.
// Retorna um ponteiro para a lista com o novo valor inserido ou NULL se a lista estiver cheia ou o valor for negativo.
LISTA *inserirFim(LISTA *lista, int valor);

// Insere um elemento inteiro em uma posição específica da lista.
// Adiciona um valor em uma posição especificada na lista, movendo os elementos subsequentes para a direita, se houver espaço disponível.
// Retorna um ponteiro para a lista com o novo valor inserido ou NULL se a posição for inválida ou a lista estiver cheia.
LISTA *inserirPosicao(LISTA *lista, int valor, int pos);

// Remove o elemento na posição especificada da lista.
// Remove o elemento na posição dada, deslocando os elementos subsequentes para a esquerda para preencher o espaço vazio.
// Retorna um ponteiro para a lista com o elemento removido ou NULL se a posição for inválida ou a lista estiver vazia.
LISTA *removerPosicao(LISTA *lista, int pos);

// Remove a primeira ocorrência de um elemento com um valor específico.
// Remove o primeiro elemento com o valor especificado da lista e ajusta os elementos subsequentes, se encontrado.
// Retorna um ponteiro para a lista com o elemento removido ou NULL se o valor não for encontrado na lista.
LISTA *removerValor(LISTA *lista, int valor);

// Obtém o elemento na posição especificada da lista.
// Retorna o valor do elemento na posição dada da lista. Se a posição for inválida, retorna um valor indicativo de erro.
int obterElementoPosicao(LISTA *lista, int pos);

// Procura o valor na lista e retorna a posição da primeira ocorrência.
// Percorre a lista procurando a primeira ocorrência do valor especificado e retorna a posição onde o valor foi encontrado.
// Retorna um valor indicativo de não encontrado se o valor não estiver na lista.
int procurarElemento(LISTA *lista, int valor);

// Retorna o número de elementos atualmente na lista.
// Retorna o número de elementos que estão atualmente na lista.
int tamanhoLista(LISTA *lista);

// Pausa a execução até que o usuário pressione uma tecla.
// Dá tempo ao usuário de ler mensagens no console.
void pressioneBotaoParaContinuar();

// Exibe uma mensagem para o usuário sobre a criação de uma lista.
// Usada para informar ao usuário que a lista precisa ser criada antes de executar outras funções.
void crieUmaLista();

// Libera a memória alocada para a lista.
// Libera a memória que foi alocada para a lista quando ela não é mais necessária, evitando vazamentos de memória.
void liberarLista(LISTA *lista);

#endif