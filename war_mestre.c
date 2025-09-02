
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct {      //declarando a struct território
    char continente[30];   
    char cor[10];     
    int tropas;     
} Territorio;


typedef struct {      //declarando a struct missao
    char descricao[100];   
    int totalTerritoriosConquistar;
    bool seguidos;
    int totalTropas;
    Territorio* territorio
}Missao;

Territorio* CriarTerritorios (int totalTerritorios);
void PreencherTerritorio(int totalTerritorios, Territorio* territorios);
void ListarTerritorios(int totalTerritorios, Territorio* territorios);


int main() {  //função principal

    int totalTerritorios = 0; //contador de territórios cadastrados
    int idAtacante = -1, idDefensor = -1; //variáveis para armazenar o id do território atacante e defensor
    
    srand(time(NULL));

    printf("QUANTOS TERRITÓRIO VOCE QUER CADATRAR? \n");
    scanf("%d", &totalTerritorios); //lendo a quantidade de territórios que o usuário quer cadastrar

    /*
        Alocação dinâmica de territórios: utilizando calloc para alocar memória
        e inicializar todos os bytes com zero
    */
   
    Territorio* territorios = CriarTerritorios(totalTerritorios);
    
    // Verifica se a alocação foi bem-sucedida
    if (territorios == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    //Passando um território por referencia , para alterar diretamente a lista.
    PreencherTerritorio(totalTerritorios, territorios);

    printf("Parabéns você CONCLUIU O CADASTRO DOS TERRITÓRIOS\n");
    printf("Aqui está a LISTAGEM COMPLETA\n");
    
       
    ListarTerritorios(totalTerritorios, territorios); //chamando a função para exibir o placar
}




void PreencherTerritorio(int totalTerritorios, Territorio* territorios) {
    printf("=== CADASTRO DE TERRITÓRIOS ===\n");
    while (getchar() != '\n'); // Limpa o buffer do teclado

    for (int i = 0; i < totalTerritorios; i++) {
        printf("Digite o NOME do %dº Território: ", i + 1);
        scanf("%29s", territorios[i].continente);

         while (getchar() != '\n'); // Limpa o buffer do teclado
        printf("Digite o Cor do %dº Território: ", i + 1);
        scanf("%9s", territorios[i].cor);
        
         while (getchar() != '\n'); // Limpa o buffer do teclado
        printf("Digite as tropas do %dº Território: ", i + 1);
        scanf("%d", &territorios[i].tropas);
        while (getchar() != '\n'); // Limpa o buffer do teclado
    }
}



void ListarTerritorios(int totalTerritorios, Territorio* territorios) {
    
    printf("====================TERRITÓRIOS=========================\n"); //Cabeçalho da impressão 

    for (int i = 0; i < totalTerritorios; i++) {        
        
        printf("%d. %-35s(Exercito: %-15s, Tropas: %d\n", i + 1,territorios[i].continente,territorios[i].cor,territorios[i].tropas);
     
    }

    printf("====================TERRITÓRIOS=========================\n"); //Cabeçalho da impressão 

}

Territorio* CriarTerritorios (int totalTerritorios){
    Territorio* territorios = (Territorio*)calloc(totalTerritorios, sizeof(Territorio));
    return territorios;
    

}


Missao* CarregarMissoes(){
    
    Missao missao[5];
   
    /* 1a missão: Conquistar 3 territórios asiáticos seguidos de exército amarelo*/
    (*missao[0].descricao) = "Conquistar 3 territórios asiáticos seguidos de exército amarelo";
    ( missao[0].seguidos) = true;
    ( missao[0].totalTerritoriosConquistar) = 3;

    (*missao[0].territorio->continente) = "Ásia";
    (*missao[0].territorio->cor) = "Amarelo";
    ( missao[0].territorio->tropas) = -1; //para indicar todas
    
  (*missao[0].descricao) = "Conquistar 1  território, tropas azul";
    ( missao[0].seguidos) = false;
    ( missao[0].totalTerritoriosConquistar) = 1;
    (*missao[0].territorio->cor) = "azul";
    ( missao[0].territorio->tropas) = -1;



    
}        


