#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estruturas de dados
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// Variáveis globais para contagem de comparações
int comparacoes_sequencial = 0;
int comparacoes_binaria = 0;

// Protótipos das funções para vetor
void inserirItemVetor(Item mochilaVetor[], int *quantidade, int capacidade);
void removerItemVetor(Item mochilaVetor[], int *quantidade);
void listarItensVetor(Item mochilaVetor[], int quantidade);
void buscarSequencialVetor(Item mochilaVetor[], int quantidade);
void ordenarVetor(Item mochilaVetor[], int quantidade);
void buscarBinariaVetor(Item mochilaVetor[], int quantidade);

// Protótipos das funções para lista encadeada
void inserirItemLista(No **inicio);
void removerItemLista(No **inicio);
void listarItensLista(No *inicio);
void buscarSequencialLista(No *inicio);

// Funções auxiliares
void limparBuffer();
void resetarContadores();

int main() {
    int opcao, subOpcao;
    int capacidade = 100; // Capacidade máxima da mochila
    int quantidadeVetor = 0;
    
    // Alocação dinâmica para o vetor
    Item *mochilaVetor = (Item*)malloc(capacidade * sizeof(Item));
    No *mochilaLista = NULL; // Lista encadeada
    
    if (mochilaVetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }
    
    printf("=== SISTEMA DE GERENCIAMENTO DE MOCHILA ===\n");
    
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Trabalhar com Vetor (Lista Sequencial)\n");
        printf("2. Trabalhar com Lista Encadeada\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();
        
        switch(opcao) {
            case 1: // Vetor
                do {
                    printf("\n--- MOCHILA COM VETOR ---\n");
                    printf("1. Inserir Item\n");
                    printf("2. Remover Item\n");
                    printf("3. Listar Itens\n");
                    printf("4. Buscar Item (Sequencial)\n");
                    printf("5. Ordenar Itens (Bubble Sort)\n");
                    printf("6. Buscar Item (Binaria - apenas apos ordenacao)\n");
                    printf("7. Voltar ao Menu Principal\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &subOpcao);
                    limparBuffer();
                    
                    resetarContadores();
                    
                    switch(subOpcao) {
                        case 1:
                            inserirItemVetor(mochilaVetor, &quantidadeVetor, capacidade);
                            break;
                        case 2:
                            removerItemVetor(mochilaVetor, &quantidadeVetor);
                            break;
                        case 3:
                            listarItensVetor(mochilaVetor, quantidadeVetor);
                            break;
                        case 4:
                            buscarSequencialVetor(mochilaVetor, quantidadeVetor);
                            break;
                        case 5:
                            ordenarVetor(mochilaVetor, quantidadeVetor);
                            break;
                        case 6:
                            buscarBinariaVetor(mochilaVetor, quantidadeVetor);
                            break;
                        case 7:
                            printf("Retornando ao menu principal...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(subOpcao != 7);
                break;
                
            case 2: // Lista Encadeada
                do {
                    printf("\n--- MOCHILA COM LISTA ENCADEADA ---\n");
                    printf("1. Inserir Item\n");
                    printf("2. Remover Item\n");
                    printf("3. Listar Itens\n");
                    printf("4. Buscar Item (Sequencial)\n");
                    printf("5. Voltar ao Menu Principal\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &subOpcao);
                    limparBuffer();
                    
                    resetarContadores();
                    
                    switch(subOpcao) {
                        case 1:
                            inserirItemLista(&mochilaLista);
                            break;
                        case 2:
                            removerItemLista(&mochilaLista);
                            break;
                        case 3:
                            listarItensLista(mochilaLista);
                            break;
                        case 4:
                            buscarSequencialLista(mochilaLista);
                            break;
                        case 5:
                            printf("Retornando ao menu principal...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(subOpcao != 5);
                break;
                
            case 3:
                printf("Saindo do sistema...\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 3);
    
    // Liberar memória
    free(mochilaVetor);
    
    // Liberar lista encadeada
    No *atual = mochilaLista;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    
    return 0;
}

// Implementação das funções para VETOR

/**
 * Insere um novo item no vetor da mochila
 * Complexidade: O(1) - inserção no final
 */
void inserirItemVetor(Item mochilaVetor[], int *quantidade, int capacidade) {
    if (*quantidade >= capacidade) {
        printf("Erro: Mochila cheia!\n");
        return;
    }
    
    Item novoItem;
    
    printf("Digite o nome do item: ");
    fgets(novoItem.nome, 30, stdin);
    novoItem.nome[strcspn(novoItem.nome, "\n")] = 0; // Remove quebra de linha
    
    printf("Digite o tipo do item: ");
    fgets(novoItem.tipo, 20, stdin);
    novoItem.tipo[strcspn(novoItem.tipo, "\n")] = 0;
    
    printf("Digite a quantidade: ");
    scanf("%d", &novoItem.quantidade);
    limparBuffer();
    
    mochilaVetor[*quantidade] = novoItem;
    (*quantidade)++;
    
    printf("Item '%s' inserido com sucesso!\n", novoItem.nome);
}

/**
 * Remove um item do vetor pelo nome
 * Complexidade: O(n) - busca + deslocamento
 */
void removerItemVetor(Item mochilaVetor[], int *quantidade) {
    if (*quantidade == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    
    char nome[30];
    printf("Digite o nome do item a ser removido: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = 0;
    
    int encontrado = 0;
    for (int i = 0; i < *quantidade; i++) {
        comparacoes_sequencial++;
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            encontrado = 1;
            printf("Item '%s' removido com sucesso!\n", nome);
            
            // Desloca os elementos para preencher o espaço
            for (int j = i; j < *quantidade - 1; j++) {
                mochilaVetor[j] = mochilaVetor[j + 1];
            }
            (*quantidade)--;
            break;
        }
    }
    
    if (!encontrado) {
        printf("Item '%s' nao encontrado na mochila!\n", nome);
    }
}

/**
 * Lista todos os itens do vetor
 * Complexidade: O(n)
 */
void listarItensVetor(Item mochilaVetor[], int quantidade) {
    if (quantidade == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    
    printf("\n=== ITENS NA MOCHILA (VETOR) ===\n");
    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
    printf("---------------------------------------------\n");
    
    for (int i = 0; i < quantidade; i++) {
        printf("%-20s %-15s %-10d\n", 
               mochilaVetor[i].nome, 
               mochilaVetor[i].tipo, 
               mochilaVetor[i].quantidade);
    }
    printf("Total de itens: %d\n", quantidade);
}

/**
 * Busca sequencial no vetor pelo nome
 * Complexidade: O(n)
 */
void buscarSequencialVetor(Item mochilaVetor[], int quantidade) {
    if (quantidade == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    
    char nome[30];
    printf("Digite o nome do item a ser buscado: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = 0;
    
    int encontrado = 0;
    for (int i = 0; i < quantidade; i++) {
        comparacoes_sequencial++;
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            printf("\nItem encontrado:\n");
            printf("Nome: %s\n", mochilaVetor[i].nome);
            printf("Tipo: %s\n", mochilaVetor[i].tipo);
            printf("Quantidade: %d\n", mochilaVetor[i].quantidade);
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        printf("Item '%s' nao encontrado!\n", nome);
    }
    
    printf("Comparacoes realizadas (busca sequencial): %d\n", comparacoes_sequencial);
}

/**
 * Ordena o vetor usando Bubble Sort por nome
 * Complexidade: O(n²)
 */
void ordenarVetor(Item mochilaVetor[], int quantidade) {
    if (quantidade == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    
    clock_t inicio = clock();
    
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            comparacoes_sequencial++;
            if (strcmp(mochilaVetor[j].nome, mochilaVetor[j + 1].nome) > 0) {
                // Troca os elementos
                Item temp = mochilaVetor[j];
                mochilaVetor[j] = mochilaVetor[j + 1];
                mochilaVetor[j + 1] = temp;
            }
        }
    }
    
    clock_t fim = clock();
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Vetor ordenado com sucesso!\n");
    printf("Comparacoes realizadas (ordenacao): %d\n", comparacoes_sequencial);
    printf("Tempo de execucao: %.6f segundos\n", tempo);
}

/**
 * Busca binária no vetor (requer vetor ordenado)
 * Complexidade: O(log n)
 */
void buscarBinariaVetor(Item mochilaVetor[], int quantidade) {
    if (quantidade == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    
    char nome[30];
    printf("Digite o nome do item a ser buscado: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = 0;
    
    int inicio = 0;
    int fim = quantidade - 1;
    int encontrado = 0;
    
    clock_t start = clock();
    
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        comparacoes_binaria++;
        
        int comparacao = strcmp(mochilaVetor[meio].nome, nome);
        
        if (comparacao == 0) {
            printf("\nItem encontrado (busca binaria):\n");
            printf("Nome: %s\n", mochilaVetor[meio].nome);
            printf("Tipo: %s\n", mochilaVetor[meio].tipo);
            printf("Quantidade: %d\n", mochilaVetor[meio].quantidade);
            encontrado = 1;
            break;
        } else if (comparacao < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    
    clock_t end = clock();
    double tempo = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    if (!encontrado) {
        printf("Item '%s' nao encontrado!\n", nome);
    }
    
    printf("Comparacoes realizadas (busca binaria): %d\n", comparacoes_binaria);
    printf("Tempo de execucao: %.6f segundos\n", tempo);
}

// Implementação das funções para LISTA ENCADEADA

/**
 * Insere um novo item no início da lista encadeada
 * Complexidade: O(1)
 */
void inserirItemLista(No **inicio) {
    No *novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }
    
    printf("Digite o nome do item: ");
    fgets(novoNo->dados.nome, 30, stdin);
    novoNo->dados.nome[strcspn(novoNo->dados.nome, "\n")] = 0;
    
    printf("Digite o tipo do item: ");
    fgets(novoNo->dados.tipo, 20, stdin);
    novoNo->dados.tipo[strcspn(novoNo->dados.tipo, "\n")] = 0;
    
    printf("Digite a quantidade: ");
    scanf("%d", &novoNo->dados.quantidade);
    limparBuffer();
    
    novoNo->proximo = *inicio;
    *inicio = novoNo;
    
    printf("Item '%s' inserido com sucesso!\n", novoNo->dados.nome);
}

/**
 * Remove um item da lista encadeada pelo nome
 * Complexidade: O(n)
 */
void removerItemLista(No **inicio) {
    if (*inicio == NULL) {
        printf("Mochila vazia!\n");
        return;
    }
    
    char nome[30];
    printf("Digite o nome do item a ser removido: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = 0;
    
    No *atual = *inicio;
    No *anterior = NULL;
    int encontrado = 0;
    
    while (atual != NULL) {
        comparacoes_sequencial++;
        if (strcmp(atual->dados.nome, nome) == 0) {
            encontrado = 1;
            
            if (anterior == NULL) {
                // Remove do início
                *inicio = atual->proximo;
            } else {
                // Remove do meio/fim
                anterior->proximo = atual->proximo;
            }
            
            printf("Item '%s' removido com sucesso!\n", nome);
            free(atual);
            break;
        }
        
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (!encontrado) {
        printf("Item '%s' nao encontrado na mochila!\n", nome);
    }
}

/**
 * Lista todos os itens da lista encadeada
 * Complexidade: O(n)
 */
void listarItensLista(No *inicio) {
    if (inicio == NULL) {
        printf("Mochila vazia!\n");
        return;
    }
    
    printf("\n=== ITENS NA MOCHILA (LISTA ENCADEADA) ===\n");
    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
    printf("---------------------------------------------\n");
    
    No *atual = inicio;
    int contador = 0;
    
    while (atual != NULL) {
        printf("%-20s %-15s %-10d\n", 
               atual->dados.nome, 
               atual->dados.tipo, 
               atual->dados.quantidade);
        atual = atual->proximo;
        contador++;
    }
    printf("Total de itens: %d\n", contador);
}

/**
 * Busca sequencial na lista encadeada pelo nome
 * Complexidade: O(n)
 */
void buscarSequencialLista(No *inicio) {
    if (inicio == NULL) {
        printf("Mochila vazia!\n");
        return;
    }
    
    char nome[30];
    printf("Digite o nome do item a ser buscado: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = 0;
    
    No *atual = inicio;
    int encontrado = 0;
    
    while (atual != NULL) {
        comparacoes_sequencial++;
        if (strcmp(atual->dados.nome, nome) == 0) {
            printf("\nItem encontrado:\n");
            printf("Nome: %s\n", atual->dados.nome);
            printf("Tipo: %s\n", atual->dados.tipo);
            printf("Quantidade: %d\n", atual->dados.quantidade);
            encontrado = 1;
            break;
        }
        atual = atual->proximo;
    }
    
    if (!encontrado) {
        printf("Item '%s' nao encontrado!\n", nome);
    }
    
    printf("Comparacoes realizadas (busca sequencial): %d\n", comparacoes_sequencial);
}

// Funções auxiliares

/**
 * Limpa o buffer de entrada
 */
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Reseta os contadores de comparações
 */
void resetarContadores() {
    comparacoes_sequencial = 0;
    comparacoes_binaria = 0;
}