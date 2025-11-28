#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 //definindo a struct Item para representar os itens do inventário

typedef struct {
    char nome[30];  //nome do item 
    char tipo [20]; // tipo do item 
    int quantidade; //quantidade do item 

}Item;
 //declaração do vetor de itens com capacidade para 10 itens 
struct Item mochila[10];  
int totalItens = 0;  //contador de itens do inventário  'váriavél contador"

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
//Função para cadastrar um novo iten na mochila 
void inserirItem(){
    //Verifica se a mochila está cheia 
    if (totalItens>=10)
    printf("\n Mochila cheia! Não é possível adicionar mais itens.\n");
    return;
}
void RemoverItem(){

}
void ListarItem(){

}
void BuscarItem(){
    
}