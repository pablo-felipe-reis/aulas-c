
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

//Protótipos das Funções usadas

Territorio* CriarTerritorios (int totalTerritorios);
void PreencherTerritorio(int totalTerritorios, Territorio* territorios);
void ListarTerritorios(int totalTerritorios, Territorio* territorios);
Missao SortearMissao(Missao* missoesExistentes);
Missao* CarregarMissoes();
 void atribuirMissao();
 void verificarMissao();
void exibirMissao();
void atacar();
void exibirMapa();
void liberarMemoria();






int main() {  //função principal
    /*
        No início do jogo, uma missão sorteada de forma automática entre diversas
        descrições pré-definidas
    */

    int totalMissoesDesejadas=0;

    printf("Quantas missões você deseja cadastrar?");
    scanf("%d", &totalMissoesDesejadas);

    Missao* missoesExistentes [] = CarregarMissoes(totalMissoesDesejadas);

    Missao* missaoSorteada = null;
    
    atribuirMissao(missaoSorteada, missoesExistentes, totalMissoesDesejadas);

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



//função de preencher os territórios , com nome, cor e tropas.

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


 //

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




Missao* CarregarMissoes(int totalMissoesDesejadas){
    
    //VERIFICAR LIMPAR A MEMÓRIA, BUFFER, LIBERAR, ETC

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

Missao* SortearMissao(Missao* missoesExistentes[], int totalMissoesCadastradas){

    int numeroSorteio =(rand() % totalMissoesCadastradas);  //0,1,2,3,4..n-1

    Missao missaoSorteada = (missoesExistentes)[numeroSorteio]; // todo: verificar se está correto

    return missaoSorteada;
}    

void atribuirMissao(Missao* destino, Missao* missoes[], int totalMissoes)
{
    &destino = SortearMissao(missoes, totalMissoes);
}

//que sorteia uma missão e copia para a variável de missão do jogador usando strcpy.

    
void verificarMissao(){

}

void exibirMissao(){

}


void atacar(){

}

void exibirMapa(){

}

void liberarMemoria(){
    

}

// função para sortear 

int JogarDados(char tipoJogador[30]) {
    printf("esperando o : '%s', jogar os dados.......\n", tipoJogador);
    Sleep((rand() % 10) +1 );  // Dorme por até 10 segundos
    return (rand() % 6) + 1;     
} 


/*
Requisitos funcionais


A seguir, são apresentadas as etapas para implementar o sistema de missões dos jogadores, desde a criação até a verificação de objetivos.

 

Criação do vetor de missões: declarar um vetor de strings contendo ao menos cinco descrições diferentes de missões estratégicas (ex: Conquistar 3 territórios seguidos, Eliminar todas as tropas da cor vermelha etc.).
 
Sorteio da missão: implementar a função void atribuirMissao(char* destino, char* missoes[], int totalMissoes) que sorteia uma missão e copia para a variável de missão do jogador usando strcpy.
 
Armazenamento e acesso: a missão de cada jogador deve ser armazenada dinamicamente utilizando malloc.
 
Verificação da missão: implementar a função int verificarMissao(char* missao, Territorio* mapa, int tamanho), que avalia se a missão do jogador foi cumprida (crie uma lógica simples inicial para verificação).
 
Exibição condicional: o sistema deve verificar, ao final de cada turno, se algum jogador cumpriu sua missão e declarar o vencedor.

Requisitos não funcionais


Para garantir organização e clareza na execução das missões, algumas práticas e estruturas devem ser seguidas durante a implementação. Vamos lá!

 

Modularização: o código deve estar dividido em funções específicas, como atribuirMissao, verificarMissao, exibirMissao, atacar, exibirMapa, liberarMemoria, e a main.
 
Uso de ponteiros: as missões dos jogadores devem ser manipuladas por meio de ponteiros.
 
Passagem por valor e referência: a missão deve ser passada por valor para exibição e por referência para atribuição e verificação.
 
Interface intuitiva: o sistema deve exibir a missão ao jogador apenas uma vez (no início) e verificar silenciosamente se ela foi cumprida ao longo da execução.

Instruções detalhadas


Os elementos a seguir ajudam a estruturar corretamente o funcionamento do jogo e o gerenciamento da memória. Veja!

 

Bibliotecas necessárias: inclua stdio.h, stdlib.h, string.h e time.h.
 
Estrutura dos territórios: utilize a struct Territorio com os campos char nome[30], char cor[10], int tropas.
 
Alocação de memória: use calloc ou malloc para alocar os vetores de territórios e armazenar a missão de cada jogador.
 
Função de ataque: implemente void atacar(Territorio* atacante, Territorio* defensor) usando rand() para simular uma rolagem de dados (valores entre 1 e 6).
 
Atualização de campos: transfira a cor e metade das tropas para o território defensor se o atacante vencer. Caso contrário, o atacante perde uma tropa.
 
Função de liberação: implemente void liberarMemoria(...) para liberar toda a memória alocada dinamicamente (territórios e missões).

Requisitos técnicos adicionais


Para finalizar a implementação com boas práticas, siga os cuidados técnicos adiante:

 

Use srand(time(NULL)) para gerar números aleatórios.
 
Valide os ataques para que o jogador só possa atacar territórios inimigos.
 
Utilize free() ao final para evitar vazamentos de memória.
 
Comente o código explicando o papel de cada função e lógica importante.

Comentários adicionais


Com a introdução das missões estratégicas, este desafio aproxima ainda mais o sistema War estruturado da lógica original do jogo. Ele promove a prática de modularização, uso de ponteiros, alocação dinâmica de memória e simulação de regras de vitória baseadas em condições específicas. Trata-se de um excelente exercício para integrar diversos conceitos fundamentais da linguagem C em um projeto envolvente e gamificado.


Entregando seu projeto


Vamos ao passo a passo:
 

Desenvolva seu projeto no GitHub: use o mesmo repositório do GitHub dos níveis anteriores.
 
Atualize o arquivo do seu código: edite o arquivo principal do seu projeto, inserindo o código completo já com as novas funcionalidades.
 
Compile e teste: faça isso com rigor, de modo que todas as comparações e cálculos estejam corretos.
 
Faça commit e push: Faça commit das suas alterações e envie (push) para o seu repositório no GitHub.
 
Envie o link do repositório: faça isso por meio da plataforma SAVA.

Para concluir o desafio, é necessário que você faça o commit no GitHub do que você desenvolveu. Certifique-se de organizar e documentar seu repositório como o esperado, pois essa etapa demonstra seu aprendizado.

Por fim, cadastre na Guia de trabalhos da SAVA o link do seu repositório.

Atenção! Caso você atualize o seu repositório, não é necessário alterá-lo na SAVA.






*/
