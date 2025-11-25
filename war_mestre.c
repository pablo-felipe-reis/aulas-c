
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
    /*
        No início do jogo, uma missão sorteada de forma automática entre diversas
        descrições pré-definidas
    */
    

    Missao* missoesExistentes = CarregarMissoes();

    Missao missaoSorteada = SortearMissao(&missoesExistentes);


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

/* atribuirMissao, verificarMissao, exibirMissao, atacar, exibirMapa, liberarMemoria, 

OK - e a main.

*/

/*

Criação do vetor de missões: declarar um vetor de strings contendo ao menos cinco descrições diferentes de missões 
estratégicas (ex: Conquistar 3 territórios seguidos, Eliminar todas as tropas da cor vermelha etc.).*/

Missao* CriarMissoes (int totalMissoes){
    Missao* missoes = (Missao*)calloc(totalMissoes, sizeof(Missao));
    return missoes;
    

}




Missao* CarregarMissoes(){
    
    //VERIFICAR LIMPAR A MEMÓRIA, BUFFER, LIBERAR, ETC
    int totalMissoesDesejadas;
    printf("Quantas missões você deseja cadastrar?");
    scanf("%d", &totalMissoesDesejadas);

    Missao* missao = CriarMissoes(totalMissoesDesejadas);   
    
    for (int i = 0; i < totalMissoesDesejadas; i++) 
    {        
        printf("Quantos territórios vc deseja conquistar para esta missão?");
        scanf("%d", &missao[i].totalTerritoriosConquistar);

        printf("Esses territórios são seguidos?");
        scanf("%d", &missao[i].seguidos);

        printf("Qual a cor desejadas para esses territórios?");
        scanf("%c", missao[i].territorio->cor);

        printf("Quantas tropas de cada território?. Use '-1' para indicar todas"); // todo: melhorar a usabilidade, pablo :)
        scanf("%d", &missao[i].territorio->tropas);

        char buffer[100]; 
        sprintf(buffer, "Conquistar %d territórios seguidos com %dtropas", missao[i].totalTerritoriosConquistar, missao[i].territorio->tropas);
        strcpy(missao[i].descricao, buffer);
    }

    return missao;
}    

Missao SortearMissao(Missao* missoesExistentes){

    int totalMissoesCadastradas =  sizeof(missoesExistentes)/sizeof(missoesExistentes[0]);


    int numeroSorteio =(rand() % totalMissoesCadastradas);  //0,1,2,3,4..n-1

    Missao missaoSorteada = (missoesExistentes)[numeroSorteio]; // todo: verificar se está correto

    return missaoSorteada;
}    


int JogarDados(char tipoJogador[30]) {
    printf("esperando o : '%s', jogar os dados.......\n", tipoJogador);
    Sleep((rand() % 10) +1 );  // Dorme por até 10 segundos
    return (rand() % 6) + 1;     
} 