#include <stdio.h>  //bibliotecas padrões 
#include <stdlib.h>
#include <time.h>

#define MAX_FILA 5
#define MAX_PILHA 5

/*
Criando uma fila, Pilha e Peças.
Struct do elemento
*/

typedef struct{
    char nome; // Tipos de peças 'I', 'O', 'T', 'L'
    int id; 
} Peca;

typedef struct {
   Peca *itens;
    int inicio;
    int fim;
    int total;
} Fila;

typedef struct {
    Peca *itens;
    int topo;
    int capacidade;
} Pilha;

//Protótipos das Funções. 

//Pilha de peças 
void inicializarPilha(Pilha *p); 
int pilhaCheia(Pilha *p); 
int pilhaVazia(Pilha *p); 
void push(Pilha *p, Peca nova); 
Peca pop(Pilha *p); 
void peek(Pilha *p, Peca *visualizada); 
void mostrarPilha(Pilha *p);
void menu();
void liberarPilha(Pilha *p);

//Fila de peças 

void inicializarFila(Fila *f); 
int filaCheia(Fila *f);
int filaVazia(Fila *f);
void inserir(Fila *f, Peca p); 
Peca remover(Fila *f); 
void mostrarFila(Fila *f);
void liberarFila(Fila *f);

//Inicializando a verificação da Pilha, se está cheia ou vazia.

void inicializarPilha(Pilha *p){  
    p->topo = -1;
    p->capacidade = MAX_PILHA;
    p->itens = (Peca*)malloc(MAX_PILHA * sizeof(Peca)); 
}

int pilhaCheia(Pilha *p){ 
    return p->topo == MAX_PILHA - 1; 
}

int pilhaVazia(Pilha *p){ 
    return p->topo == -1; 
}

/*
Criando uma Pilha
Inserir (push)
Remover (pop)
Consultar (peek)
Exibir 
*/
void push(Pilha *p, Peca nova){  
    if (pilhaCheia(p)) { 
        printf("Pilha cheia. Não é possível inserir.\n");
        return;
    }

    p->topo++;
    p->itens[p->topo] = nova;
}

Peca pop(Pilha *p) {  
    if (pilhaVazia(p)) { 
        printf("Pilha vazia. Não é possível remover.\n");
        Peca vazia = {' ', -1};
        return vazia;
    }
    Peca removida = p->itens[p->topo];
    p->topo--;
    return removida;
}

void peek(Pilha *p, Peca *visualizada){ 
    if (pilhaVazia(p)){ 
        printf("Pilha vazia. Nada para espiar.\n");
        return;
    }
    *visualizada = p->itens[p->topo];
}

void mostrarPilha(Pilha *p) {
    printf("Pilha (topo -> base):\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("%c, %d\n", 
               p->itens[i].nome, p->itens[i].id);
    }
    printf("\n");
}
void liberarPilha(Pilha *p) {
    free(p->itens);  
    p->itens = NULL; 
    p->topo = -1;    
}

//funções da Fila de Peças 

void inicializarFila(Fila *f){ 
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    f->itens = (Peca*)malloc(MAX_FILA * sizeof(Peca)); 
}

int filaCheia(Fila *f){
    return f->total == MAX_FILA;
 }

int filaVazia(Fila *f){
    return f->total == 0;
}

void inserir(Fila *f, Peca p){  
    if (filaCheia(f)){
        printf("Fila cheia.Não é possível inserir.\n");
        return;
    }
    f->itens[f->fim] = p;   
    f->fim = (f->fim + 1) % MAX_FILA; 
    f->total++;                
}

Peca remover(Fila *f){ 
    if (filaVazia(f)){
        printf("Fila vazia. Não é possível remover.\n");
        Peca vazia = {' ', -1};
        return vazia;
    }
    Peca removida = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_FILA;
    f->total--;
    return removida;
}

void mostrarFila(Fila *f) {
    printf("Fila: ");
    for (int i = 0, idx = f->inicio;
         i < f->total;
         i++, idx = (idx + 1) % MAX_FILA)
    {
        printf("[%c, %d] ",
               f->itens[idx].nome, 
               f->itens[idx].id);
    }
    printf("\n");
}

void liberarFila(Fila *f) {
    free(f->itens);  
    f->itens = NULL; 
    f->total = 0;   
    f->inicio = 0;
    f->fim = 0;
}

void menu() {
    printf("\n=== OPÇÕES ===\n");
    printf("1 - Jogar Peça\n");
    printf("2 - Reservar Peça\n");
    printf("3 - Usar Peça Reservada \n");
    printf("0 - Sair \n");
}


int main(){

    Fila fila;         
    Pilha pilha;        


    liberarFila(&fila);
    liberarPilha(&pilha);

    return 0;
}