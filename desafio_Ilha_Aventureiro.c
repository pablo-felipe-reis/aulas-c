#include <stdio.h>     //bibliotecas padrôes 
#include <stdlib.h>
#include <string.h>
#include <time.h>

// structs 

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
}item;

typedef struct  No{
    item dados;
    struct No* proximo;
}No;
    
/*
Prótotipos das Funções 
*/

int buscaSequencial(int vetor[], int tamanho, int valor);
int buscaBinaria(int vetor[], int tamanho, int valor);
int buscaSequencialIterativa(int vetor[], int tamanho, int valor);
int buscaSequencialRecursivaAux(int vetor[], int indice, int tamanho, int valor);
int buscaSequencialRecursiva(int vetor[], int tamanho, int valor);
int buscaBinariaIterativa(int vetor[], int tamanho, int valor);
int buscaBinariaRecursivaAux(int vetor[], int inicio, int fim, int valor);
int buscaBinariaRecursiva(int vetor[], int tamanho, int valor);


/*

função de busca sequencial 

a sua função proccura por um valor em um vetor de um dado tamanho 
funciona para vetores ordenados ou não ordenados.

Retorno : 

o Índice (posição) do valor , se encontrado.
-1 se o valor não estiver no vetor.*/

int buscaSequencial(int vetor[], int tamanho, int valor) {
    // Percorre o vetor do início ao fim
    for (int i = 0; i < tamanho; i++) {
        // Verifica se o elemento atual é o valor procurado
        if (vetor[i] == valor) {
            return i;  // Valor encontrado! Retorna a posição.
        }
    }

    // Se chegou aqui, o valor não foi encontrado no vetor
    return -1;  // "Cheguei ao fim da fila e não encontrei."
}
/*
A função de busca binária: Procurar por um valor em um vetor Ordenado  de um tamanho específico.
Pré requisitos o vetor, Deve estar em ordem crescente para o algoritmo funcionar.

Retorno : o Índice do valor , se econtrado. -1 se o valor estiver no valor. .
*/

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;
    
    // O loop continua enquanto a fatia busca for válida (inicio não ultrapassou fim).
    while (inicio <= fim) {
        // Calcula o índice do meio da fatia atual.
        int meio = inicio + (fim - inicio) / 2;    // Evita overflow (forma segura)

        // 1. Verificação principal: o valor está no meio?
        if (vetor[meio] == valor) {
            return meio;   // Sucesso! Retorna a posição.
        }

        /*
        2. Se o valor do meio for menor que o valor buscado,
        significa que o alvo só pode estar na metade direita.
        */
        else if (vetor[meio] < valor) {
            inicio = meio + 1; // Ignorar a metade esquerda.
        }
        // 3. Caso contrário, o alvo só pode estar na metade esquerda.
        else {
            fim = meio - 1;     // Ignorar a metade direita.
        }
    }
    // Se o loop terminar, o valor não foi encontrado.
    return -1;
}

//1. Busca Sequencial Iterativa

int buscaSequencialIterativa(int vetor[], int tamanho, int valor) {
    // Percorre o vetor do início ao fim
    for (int i = 0; i < tamanho; i++) {
        // Verifica se o elemento atual é o valor procurado
        if (vetor[i] == valor) {
            return i;  // Valor encontrado! Retorna a posição.
        }
    }
    // Se chegou aqui, o valor não foi encontrado no vetor
    return -1;
}

//2. Busca Sequencial Recursiva

// Função auxiliar recursiva
int buscaSequencialRecursivaAux(int vetor[], int indice, int tamanho, int valor) {
    // Caso base: índice ultrapassou o tamanho do vetor
    if (indice >= tamanho) {
        return -1;  // Valor não encontrado
    }
    
    // Caso base: encontrou o valor na posição atual
    if (vetor[indice] == valor) {
        return indice;  // Retorna a posição atual
    }
    
    // Chamada recursiva: busca a partir do próximo índice
    return buscaSequencialRecursivaAux(vetor, indice + 1, tamanho, valor);
}

// Função principal recursiva
int buscaSequencialRecursiva(int vetor[], int tamanho, int valor) {
    return buscaSequencialRecursivaAux(vetor, 0, tamanho, valor);
}

//3. Busca Binária Iterativa

int buscaBinariaIterativa(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;
    
    // O loop continua enquanto a fatia busca for válida
    while (inicio <= fim) {
        // Calcula o índice do meio (forma segura contra overflow)
        int meio = inicio + (fim - inicio) / 2;

        // Verificação principal: o valor está no meio?
        if (vetor[meio] == valor) {
            return meio;   // Sucesso! Retorna a posição.
        }
        // Se o valor do meio for menor que o valor buscado
        else if (vetor[meio] < valor) {
            inicio = meio + 1; // Buscar na metade direita
        }
        // Se o valor do meio for maior que o valor buscado
        else {
            fim = meio - 1;    // Buscar na metade esquerda
        }
    }
    // Se o loop terminar, o valor não foi encontrado
    return -1;
}

//4. Busca Binária Recursiva

// Função auxiliar recursiva
int buscaBinariaRecursivaAux(int vetor[], int inicio, int fim, int valor) {
    // Caso base: subvetor inválido
    if (inicio > fim) {
        return -1;  // Valor não encontrado
    }
    
    // Calcula o ponto médio
    int meio = inicio + (fim - inicio) / 2;
    
    // Caso base: encontrou o valor
    if (vetor[meio] == valor) {
        return meio;
    }
    // Buscar na metade direita
    else if (vetor[meio] < valor) {
        return buscaBinariaRecursivaAux(vetor, meio + 1, fim, valor);
    }
    // Buscar na metade esquerda
    else {
        return buscaBinariaRecursivaAux(vetor, inicio, meio - 1, valor);
    }
}

// Função principal recursiva
int buscaBinariaRecursiva(int vetor[], int tamanho, int valor) {
    return buscaBinariaRecursivaAux(vetor, 0, tamanho - 1, valor);
}

//
#include <stdio.h>

int main() {
    
    return 0;
}