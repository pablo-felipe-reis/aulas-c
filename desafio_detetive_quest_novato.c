#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Sala
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

/**
 * criarSala - Cria dinamicamente uma nova sala com nome
 * @param nome: Nome da sala a ser criada
 * @return: Ponteiro para a sala criada
 */

Sala* criarSala(const char* nome) {
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));
    if (novaSala == NULL) {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }
    
    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    
    return novaSala;
}

/**
 * explorarSalas - Permite a navegação do jogador pela árvore
 * @param atual: Ponteiro para a sala atual
 */
void explorarSalas(Sala* atual) {
    char escolha;
    
    printf("\n=== EXPLORAÇÃO DA MANSÃO ===\n");
    
    while (atual != NULL) {
        printf("\nVocê está na: %s\n", atual->nome);
        
        // Verifica se é uma sala final (nó folha)
        if (atual->esquerda == NULL && atual->direita == NULL) {
    printf("\n>>> Você chegou a um cômodo final! Exploração concluída.\n");
    return;  // ← Retorna para main, permitindo nova exploração
}
        // Mostra opções disponíveis
        printf("\nOpções disponíveis:\n");
        if (atual->esquerda != NULL) {
            printf("(e) - Ir para a esquerda: %s\n", atual->esquerda->nome);
        }
        if (atual->direita != NULL) {
            printf("(d) - Ir para a direita: %s\n", atual->direita->nome);
        }
        printf("(s) - Sair da exploração\n");
        
        // Solicita escolha do usuário
        printf("\nPara onde deseja ir? ");
        scanf(" %c", &escolha);
        
        // Processa a escolha do usuário
        switch (escolha) {
            case 'e':
                if (atual->esquerda != NULL) {
                    atual = atual->esquerda;
                } else {
                    printf("Não há caminho para a esquerda!\n");
                }
                break;
                
            case 'd':
                if (atual->direita != NULL) {
                    atual = atual->direita;
                } else {
                    printf("Não há caminho para a direita!\n");
                }
                break;
                
            case 's':
                printf("Saindo da exploração...\n");
                return;
                
            default:
                printf("Opção inválida! Use 'e', 'd' ou 's'.\n");
                break;
        }
    }
}

/**
 * liberarArvore - Libera a memória alocada para a árvore
 * @param raiz: Ponteiro para a raiz da árvore
 */
void liberarArvore(Sala* raiz) {
    if (raiz == NULL) return;
    
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

/**
 * main - Monta o mapa inicial e dá início à exploração
 * @return: Código de saída do programa
 */
int main() {
    // Criação do mapa da mansão
    Sala* hallEntrada = criarSala("Hall de Entrada");
    Sala* salaEstar = criarSala("Sala de Estar");
    Sala* cozinha = criarSala("Cozinha");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* jardim = criarSala("Jardim");
    Sala* quarto = criarSala("Quarto Principal");
    Sala* banheiro = criarSala("Banheiro");
    
    // Montagem da estrutura da árvore
    hallEntrada->esquerda = salaEstar;
    hallEntrada->direita = cozinha;
    
    salaEstar->esquerda = biblioteca;
    salaEstar->direita = jardim;
    
    cozinha->esquerda = quarto;
    cozinha->direita = banheiro;
    
    // Biblioteca, Jardim, Quarto e Banheiro são folhas (NULL em ambos os lados)
    
    printf("Bem-vindo à Exploração da Mansão!\n");
    printf("==================================\n");
    
    // Inicia a exploração a partir do Hall de Entrada
    explorarSalas(hallEntrada);
    
    printf("\nObrigado por explorar a mansão!\n");
    
    // Libera a memória alocada
    liberarArvore(hallEntrada);
    
    return 0;
}