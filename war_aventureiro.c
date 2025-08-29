#include <stdio.h>  //Para entrada e saída de dados
#include <string.h> //Para manipulação de strings
#include <stdlib.h> //Para funções de alocação de memória
#include <time.h> //Para números aleatórios
#include <stdbool.h> 
#include <unistd.h>

/*
    Criação da struct: definir uma struct chamada Territorio com os campos char nome[30], char cor[10] e int tropas.
*/
typedef struct {      //declarando a struct território
    char nome[30];   
    char cor[10];     
    int tropas;     
} Territorio;

int JogarDados();
void PreencherTerritorio(int totalTerritorios, Territorio* territorios);
void ExibirPlacar(int totalTerritorios, Territorio* territorios);
void FinalizarTerritorio(Territorio* territorios);
bool Atacar(Territorio* atacante, Territorio* defensor, int rodada);
void atualizarTerritorio(Territorio* territorio);
Territorio* CriarTerritorios (int totalTerritorios);
Territorio* selecionarTerritorio(int totalTerritorios, Territorio* territorios, int id);

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

    PreencherTerritorio(totalTerritorios, territorios);

    printf("Parabéns você CONCLUIU O CADASTRO DOS TERRITÓRIOS\n");
    printf("Aqui está a LISTAGEM COMPLETA\n");
    printf("Código:\t\tNome:\t\tCor:\t\tTropas:\n"); //Cabeçalho da impressão 
       
    ExibirPlacar(totalTerritorios, territorios); //chamando a função para exibir o placar

    printf("informe o Código do território atacante :\n");
    scanf("%d", &idAtacante); //lendo o id do território atacante

    Territorio* atacante = selecionarTerritorio(totalTerritorios, territorios, idAtacante);
    if (atacante == NULL) {
        printf("Território atacante inválido!\n");
        FinalizarTerritorio(territorios);
        return 1; // Sai do programa com erro
    }

    printf("informe o numero do território defensor :\n");
    scanf("%d", &idDefensor); //lendo o id do território defensor

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
    int rodada = 1;
    while (!fimJogo) {
        fimJogo = Atacar(atacante, defensor, rodada);
        rodada++;
    }

    printf("resultado final do jogo\n");
    printf("total final de tropas do atacante '%d'; total final de tropas do defensor '%d'\n", atacante->tropas, defensor->tropas);

    FinalizarTerritorio(territorios);
    return 0; 
}

int JogarDados(char tipoJogador[30]) {
    printf("esperando o : '%s', jogar os dados.......\n", tipoJogador);
    sleep((rand() % 10) +1 );  // Dorme por até 10 segundos
    return (rand() % 6) + 1;     
}

bool Atacar(Territorio* atacante, Territorio* defensor, int rodada) {
    int totalTropasAtacar = JogarDados("JOGADOR ATACANTE"); //número aleatório entre 1 e 6
    int totalTropasDefender = JogarDados("JOGADOR DEFENSOR"); //número aleatório entre 1 e 6 
    
    printf("'%d°' rodada:.... JOGANDO DADOS\n", rodada);
    printf("atacante: '%s', possui '%d' tropas, e vai atacar com '%d'\n", atacante->nome, atacante->tropas, totalTropasAtacar);
    printf("defensor: '%s', possui '%d' tropas, e vai defender com '%d'\n", defensor->nome, defensor->tropas, totalTropasDefender);
  
    if (atacante->tropas < totalTropasAtacar) {
        totalTropasAtacar = atacante->tropas;
    }

    if (totalTropasAtacar > totalTropasDefender) {
        atacante->tropas += totalTropasDefender;
        defensor->tropas -= totalTropasDefender;

        printf("atacante: '%s', GANHOU mais '%d' e agora possui '%d' tropas\n", atacante->nome, totalTropasDefender, atacante->tropas);
        printf("defensor: '%s', PERDEU menos '%d' e agora possui '%d' tropas\n", defensor->nome, totalTropasDefender, defensor->tropas);
    } else {
        if (totalTropasAtacar < totalTropasDefender) {
            defensor->tropas += totalTropasAtacar;
            atacante->tropas -= totalTropasAtacar;

            printf("defensor: '%s', GANHOU mais '%d' e agora possui '%d' tropas\n", defensor->nome, totalTropasAtacar, defensor->tropas);
            printf("atacante: '%s', PERDEU menos '%d' e agora possui '%d' tropas\n", atacante->nome, totalTropasAtacar, atacante->tropas);
        }
    }
    
    if (atacante->tropas == 0 || defensor->tropas == 0) {
        printf("Fim de Jogo\n");
        return true;
    }

    return false;
}

void atualizarTerritorio(Territorio* territorio) {
    // Esta função parece não fazer nada útil, pode ser removida se não for necessária
}

void ExibirPlacar(int totalTerritorios, Territorio* territorios) {
    for (int i = 0; i < totalTerritorios; i++) {
        printf("%d\t\t", i + 1);
        printf("%s\t\t", territorios[i].nome);
        printf("%s\t\t", territorios[i].cor);
        printf("%d\n", territorios[i].tropas);
    }
}

void PreencherTerritorio(int totalTerritorios, Territorio* territorios) {
    printf("=== CADASTRO DE TERRITÓRIOS ===\n");
    while (getchar() != '\n'); // Limpa o buffer do teclado

    for (int i = 0; i < totalTerritorios; i++) {
        printf("Digite o NOME do %dº Território: ", i + 1);
        scanf("%29s", territorios[i].nome);

         while (getchar() != '\n'); // Limpa o buffer do teclado
        printf("Digite o Cor do %dº Território: ", i + 1);
        scanf("%9s", territorios[i].cor);
        
         while (getchar() != '\n'); // Limpa o buffer do teclado
        printf("Digite as tropas do %dº Território: ", i + 1);
        scanf("%d", &territorios[i].tropas);
        while (getchar() != '\n'); // Limpa o buffer do teclado
    }
}

void FinalizarTerritorio(Territorio* territorios) {
    free(territorios); //liberando a memória alocada
}

Territorio* selecionarTerritorio(int totalTerritorios, Territorio* territorios, int id) {
    if (id <= 0 || id > totalTerritorios) {
        printf("ID de território inválido!\n");
        return NULL;
    }
    return &territorios[id - 1];
}

Territorio* CriarTerritorios (int totalTerritorios){
    Territorio* territorios = (Territorio*)calloc(totalTerritorios, sizeof(Territorio));
    return territorios;
    

}