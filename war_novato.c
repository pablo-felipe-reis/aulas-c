#include <stdio.h>  //Bibliotecas padrões
#include <string.h>

/*
    Criação da struct: definir uma struct chamada Territorio com os campos char nome[30], char cor[10] e int tropas.
*/
typedef struct {      //declarando a struct território
    char nome[30];    //nome do território
    char cor[10];      //cor do território
    int tropas;      //quantidade de tropas
}Território;

int main() {  //função principal

    Território territorios[5];  //vetor de armazenamento dos 5 territórios 

    printf("=== CADASTRO DE TERRITÓRIOS ===\n");

    /*
        Cadastro dos territórios: o sistema deve permitir que o usuário cadastre cinco territórios informando o nome, cor do exército e o número de tropas de cada um.
    */
    for (int i = 0; i < sizeof(territorios)/sizeof(territorios[0]); i++) {  //Loop para cadastrar território
        
        printf("Digite o NOME do %dº Território   :",i+1);
        scanf("%29s",territorios[i].nome);  //Para não estourar a quantidade de caracteres do nome 

        printf("Digite o Cor do %dº Território   :",i+1);
        scanf("%9s",territorios[i].cor);  //Para não estourar a quantidade de caracteres de Cor 

        printf("Digite as tropas do %dº Território   :",i+1);
        scanf("%d",&territorios[i].tropas);

        // Limpa o buffer do teclado para evitar problemas no próximo scanf
         while (getchar() != '\n');   

    }
    printf("Parabéns você CONCLUIU O CADASTRO DOS TERRITÓRIOS\n");

    printf("Aqui está a LISTAGEM COMPLETA\n");

    printf("Nome:\t\tCor:\t\tTropas:\n"); //Cabeçalho da impressão 
       
    /*
        Exibição dos dados: o sistema deve exibir as informações de todos os territórios registrados após o cadastro.
    */
    for (int i = 0; i < sizeof(territorios)/sizeof(territorios[0]); i++) {  //Imprimir os dados 
        
        printf("%s\t\t",territorios[i].nome);

        printf("%s\t\t",territorios[i].cor);

        printf("%d\n",territorios[i].tropas);
    }
    
} 