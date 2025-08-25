#include <stdio.h>  //Para entrada e saída de dados
#include <string.h> //Para manipulação de strings
#include <stdlib.h> //Para funções de alocação de memória
#include <time.h> //Para números aleatórios
#include <stdbool.h> 


/*
    Criação da struct: definir uma struct chamada Territorio com os campos char nome[30], char cor[10] e int tropas.
*/
typedef struct {      //declarando a struct território
    char nome[30];    //nome do território
    char cor[10];      //cor do território
    int tropas;      //quantidade de tropas
}Territorio;

int JogarDados();
void PreencherTerritorio(int totalTerritorios, Territorio* territorios);
void ExibirPlacar(int totalTerritorios, Territorio* territorios);
void FinalizarTerritorio(Territorio* territorios);
bool Atacar(Territorio* atacante, Territorio* defensor, int rodada) ;
void atualizarTerritorio(Territorio* territorio) ;


Territorio* selecionarTerritorio(int totalTerritorios, Territorio* territorios, int id);


int main() {  //função principal
    int totalTerritorios=0; //contador de territórios cadastrados
    int idAtacante =-1, idDefensor =-1; //variáveis para armazenar o id do território atacante e defensor


    printf("QUANTOS TERRITÓRIO VOCE QUER CADATRAR? \n");
    scanf("%d",&totalTerritorios); //lendo a quantidade de territórios que o usuário quer cadastrar

    /*
        Alocação dinâmica de territórios: utilizar calloc ou malloc para alocar memória para 
        um vetor de struct Territorio com tamanho informado pelo usuário.
    */
    Territorio* territorios = (Territorio*)malloc(sizeof(Territorio)*totalTerritorios); 
    
    PreencherTerritorio(totalTerritorios,territorios);

    printf("Parabéns você CONCLUIU O CADASTRO DOS TERRITÓRIOS\n");

    printf("Aqui está a LISTAGEM COMPLETA\n");

    printf("Código:\t\tNome:\t\tCor:\t\tTropas:\n"); //Cabeçalho da impressão 
       
    ExibirPlacar(totalTerritorios, territorios); //chamando a função para exibir o placar{

    printf("informe o Código do território atacante :\n");
    scanf("%d",&idAtacante); //lendo o id do território atacante

    Territorio* atacante = selecionarTerritorio(totalTerritorios, territorios, idAtacante);
    if (atacante == NULL) {
        printf("Território atacante inválido!\n");
        FinalizarTerritorio(territorios);
        return 1; // Sai do programa com erro
    }

    printf("informe o numero do território defensor :\n");
    scanf("%d",&idDefensor); //lendo o id do território defensor

    Territorio* defensor = selecionarTerritorio(totalTerritorios, territorios, idDefensor);
    if (defensor == NULL) {
        printf("Território defensor inválido!\n");
        FinalizarTerritorio(territorios);
        return 1; // Sai do programa com erro
    }
    if (idAtacante == idDefensor) {
        printf("O território atacante e defensor não podem ser o mesmo!\n");
        FinalizarTerritorio(territorios);
        return 1; // Sai do programa com erro
    }

    bool fimJogo = false;
    int rodada= 1;
    while (!fimJogo)
    {
        fimJogo = Atacar(atacante,defensor,rodada);
        rodada ++;
    }

    printf("resultado final do jogo");
    printf("total final de tropas do atacante '%d'; total final de tropas do defensor '%d'", (*atacante).tropas,(*defensor).tropas);

    FinalizarTerritorio(territorios);
    return 0; 
}
 /*
        Simulação de ataques: criar uma função que simula um ataque, utilizando números aleatórios como se fossem dados de batalha.
 
    */

int JogarDados(){

    return (rand() % 6) + 1; 
}
bool Atacar(Territorio* atacante, Territorio* defensor,int rodada) {
    
    int totalTropasAtacar =JogarDados(); //número aleatório entre 1 e 6
    int totalTropasDefender =JogarDados(); //número aleatório entre 1 e 6 
    
    printf("'%d°' rodada:.... JOGANDO DADOS\n",rodada);
 
    printf("atacante: '%s', possui '%d' tropas, e vai atacar com '%d'\n",(*atacante).nome ,(*atacante).tropas,totalTropasAtacar);
    printf("defensor: '%s', possui '%d' tropas, e vai defender com '%d'\n",(*defensor).nome ,(*defensor).tropas,totalTropasDefender);
  
    if ((*atacante).tropas <totalTropasAtacar) {
        totalTropasAtacar = totalTropasAtacar;
    }

    if (totalTropasAtacar > totalTropasDefender){
        (*atacante).tropas += totalTropasDefender;
       // (*atacante).tropas = (*atacante).tropas + totalTropasDefender;
        (*defensor).tropas -= totalTropasDefender;
       //(*defensor).tropas =  (*defensor).tropas - totalTropasDefender;

        printf("atacante: '%s',  GANHOU mais '%d' e agora possui '%d' tropas\n",(*atacante).nome ,totalTropasDefender,(*atacante).tropas);
        printf("defensor: '%s', PERDEU menos '%d' e agora possui '%d' tropas\n",(*defensor).nome ,totalTropasDefender,(*defensor).tropas);
    }
    else {
        //total de tropas a atacar é IGUAL (ZERO A ZERO)
        
        // o total de tropas a atacar é MENOR (atacante perde)
        if (totalTropasAtacar < totalTropasDefender){
            (*defensor).tropas += totalTropasAtacar;
            (*atacante).tropas -= totalTropasAtacar;

            printf("defensor: '%s',  GANHOU mais '%d' e agora possui '%d' tropas\n",(*defensor).nome ,totalTropasAtacar,(*defensor).tropas);
            printf("atacante: '%s',  PERDEU menos '%d' e agora possui '%d' tropas\n",(*atacante).nome ,totalTropasAtacar,(*atacante).tropas);
        }
    }
    if (
        (*atacante).tropas ==0 || 
        (*defensor).tropas ==0 
    ){
        printf("Fim de Jogo\n");
        return true;
    }

    return false;

}

void atualizarTerritorio(Territorio* territorio) {
    return *territorio;
}

void ExibirPlacar(int totalTerritorios, Territorio* territorios) {
     /*
        Exibição dos dados: o sistema deve exibir as informações de todos os territórios registrados após o cadastro.
    */
    for (int i = 0; i < totalTerritorios; i++) {  //Imprimir os dados 
        printf("%d\t\t",i+1);

        printf("%s\t\t",territorios[i].nome);

        printf("%s\t\t",territorios[i].cor);

        printf("%d\n",territorios[i].tropas);
    }

}
void PreencherTerritorio(int totalTerritorios, Territorio* territorios){
      printf("=== CADASTRO DE TERRITÓRIOS ===\n");

   
    for (int i = 0; i < totalTerritorios; i++) {  //Loop para cadastrar território
        
        printf("Digite o NOME do %dº Território   :",i+1);
        scanf("%29s",territorios[i].nome);  //Para não estourar a quantidade de caracteres do nome 

        printf("Digite o Cor do %dº Território   :",i+1);
        scanf("%9s",territorios[i].cor);  //Para não estourar a quantidade de caracteres de Cor 

        printf("Digite as tropas do %dº Território   :",i+1);
        scanf("%d",&territorios[i].tropas);

        // Limpa o buffer do teclado para evitar problemas no próximo scanf
         while (getchar() != '\n');   

    }
}

void FinalizarTerritorio(Territorio* territorios){
    free(territorios); //liberando a memória alocada
}

Territorio* selecionarTerritorio(int totalTerritorios, Territorio* territorios, int id){
    
    Territorio* territorioSelecionado = NULL;

     // Verifica se o ID é válido
    
    if (id <= 0 || id > totalTerritorios) {
        printf("ID de território inválido!\n");
        return territorioSelecionado;
    }

    territorioSelecionado = &territorios[id-1]; // Retorna o ponteiro para o território selecionado (ajustando para índice 0)
    return territorioSelecionado;
}