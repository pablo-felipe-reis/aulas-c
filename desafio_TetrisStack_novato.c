#include <stdio.h>  //bibliotecas padrôes 
#include <stdlib.h>
#include <time.h>
/*
Criando uma fila 
Struct do elemento
*/

typedef struct{
    char nome [30];
    int id;

}Pessoa;

/*
Limite desta fila
Inicio, fim e total da Fila. 
*/
#define MAX 5

typedef struct {
    Pessoa itens[MAX];
    int inicio;
    int fim;
    int total;
}Fila;

/*
funções usadas 
Protótipos.
*/

void iniciarlizarFila(Fila *f);
 int filaCheia(Fila *f);
 int filaVazia(Fila *f);
void inserir(Fila *f, Pessoa *p);
void remover(Fila *f, Pessoa *p);
void mostrarFila(Fila *f);
 void menu();
    Pessoa gerarPeca(int id);


/*
Inicialização e verificação da Fila  , se está cheia ou vazia.
função , vazia, que não retorna nenhum valor.
f* é o ponteiro aonde indica a posição da fila.
*/

void iniciarlizarFila(Fila *f){
    f-> inicio = 0;
    f-> fim  =0;
    f-> total =0;
}
 int filaCheia(Fila *f){
    return f->total == MAX;
 }

 int filaVazia(Fila *f){
    return f->total == 0;
 }

 /*
 Inserindo itens da Fila (Enqueue)
 função de inserir, para inserir um novo item , ele usa um if , se a fiila estiver cheia.
 Imprime a mensagem , dizendo, não é possível inserir.
 lógica Circular.
 */
void inserir(Fila *f, Pessoa *p){   // pessoa , é uma struct estruturada. 
    if (f->total == MAX){
        printf("Fila cheia.Não é possível inserir.\n");
        return;
    }
    f->itens [f->fim]= *p;   // neste caso, Colchetes [] são para consultar um ARRAY, itens. vetor da Fila.
    f->fim = (f->fim +1) % MAX; // Parênteses () - Chamada de FUNÇÕES.
    f->total ++;                
}
/*Aqui os parênteses () são usados para agrupamento matemático

(f->fim + 1) significa: "calcule primeiro f->fim + 1"

Não é uma chamada de função, é apenas para definir ordem de cálculo*/

/*
Removendo itens da Fila
Remover - Dequeue
faz o uso do mesmo IF , para verificar. porém neste caso a fila não pode estar vazia. 
*/

void remover(Fila *f, Pessoa *p){
    if (filaVazia(f)){
        printf("Fila vazia. Não é possível remover.\n");
        return;
    }

    *p = f->itens[f->inicio];
    f->inicio = (f->inicio +1) % MAX;
    f->total --;
}

/*
Mostrar a Fila 
idx = abreviação de "index" (índice em inglês)
É um contador temporário que percorre as posições do array
Não modifica os campos originais da fila (inicio e fim)
Na fila circular, os elementos não estão necessariamente nas 
posições 0, 1, 2... consecutivas. Podem estar espalhados.
*/

void mostrarFila(Fila *f) {
    printf("Fila: ");
    for (int i = 0, idx = f->inicio;
         i < f->total;
         i++, idx = (idx + 1) % MAX)
    {
        printf("[%s, %d] ",
               f->itens[idx].nome,
               f->itens[idx].id);
    }
    printf("\n");
}
 void menu() {
    printf("\n=== OPÇÕES ===\n");
    printf("1 - Jogar peça (dequeue)\n");
    printf("2 - Inserir nova peça (enqueue)\n");
    printf("0 - Sair\n");
}
 Pessoa gerarPeca(int id) {
    Pessoa novaPeca;
    char tipos[] = {'I', 'O', 'T', 'L'};

 }
/*
Função MAIN
*/
int main(){
    
     Fila fila;    

    return 0;
}