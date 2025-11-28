#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_Pilha 5
#define MAX_Fila 3
 
//definindo as structs 

typedef struct {
    char nome ;
    int id;
} Peca;

typedef struct {
    Peca dados [ MAX_Fila];
    int inicio, fim; 
}Fila;

typedef struct {
    Peca dados[ MAX_Pilha];
    int topo;
}Pilha;

//Prototipos das Funções 














//Operações Básicas , da Fila.

void inserir(Fila *f,Peca p){
    if (f->fim <  MAX_Fila) {
        f->dados[f->fim++] = p;
    }
}

Peca remover(Fila *f){
    return f->dados[f->inicio++];
}

//Operações Básicas, da Pilha 

void push(Pilha *p,Peca pes){
    if (p->topo <  MAX_Pilha - 1){
        p->dados[++p->topo] = pes;
    }
}

Peca pop(Pilha *p){
    return p->dados[p->topo --];
}

Peca peek(Pilha *p){
    return p->dados[p->topo --];
}

void exibirPilha(Pilha p){
    while (p.topo >= 0){
       Peca atual = pop (&p);
        printf("Nome: %s | Id: %d\n" , atual.nome, atual.id);
    }
}

// Implementação da Main

int main(){
    






}