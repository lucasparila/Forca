
#include "forca.h"
#include <conio.h>
#define MAX 26
#define TAMANHO_MAX_BANCO 100

//Função para limpar a tela e deixar o jogo mais limpo e estático
void limpa_tela() {
if (_WIN32){
     system("cls"); // Para Windows
}else
    system("clear"); // Para Linux/MacOS

}

// Função para capturar a palavra sem exibir no terminal
void capturarPalavra(char* palavra, int max) {
    int i = 0;
    char ch;
    while ((ch = getch()) != '\r' && i < max - 1) { // '\r' é Enter
        if (ch == '\b' && i > 0) { // '\b' é Backspace
            printf("\b \b");
            i--;
        } else if (ch != '\b') {
            palavra[i] = ch;
            printf("*"); 
            i++;
        }
    } 
    palavra[i] = '\0'; // Termina a string
    printf("\n");
}

// Função para validação de entrada do menu
int valida_opcao() {
    int opcao;
    printf("Escolha uma opção válida (1-3 ou 0 para sair): ");
    while (scanf("%d", &opcao) != 1 || opcao < 0 || opcao > 3) {
        printf("Opção inválida. Tente novamente: ");
        while (getchar() != '\n'); // Limpa o buffer
    }
    return opcao;
}

// Função para o modo Jogador vs Jogador
void modo_jogador_vs_jogador() {
    char palavra[MAX];
    char dica[MAX];
    T_jogo jogo;

    for (int rodadas = 0; rodadas < 3; rodadas++) {
        printf("\nRodada %d\n", rodadas + 1);
        printf("Digite a palavra secreta da rodada %d:\n", rodadas + 1);
        capturarPalavra(palavra, MAX);
        jogo = create(palavra);
        printf("Digite a dica para a palavra secreta:\n");
        scanf("%s", dica);

        do{
           
            printf("                              DICA: %s\n", dica);
            desenhaforca(jogo);
            chuta(jogo);
             limpa_tela();
        }while (!ganhou(jogo) && !enforcou(jogo));

        desenhaforca(jogo);
        
    }
    imprime_resultado_final(jogo);
}

int main() {
    int opcoes;
    abertura();

    do {
        printf("\n1- JOGADOR VS JOGADOR\n2- JOGADOR VS MAQUINA\n3- RANKING\n0- SAIR DO JOGO\n");
        opcoes = valida_opcao();

        switch (opcoes) {
        case 1:
            modo_jogador_vs_jogador();
            break;

        case 2:
            printf("Modo Jogador vs Máquina ainda não implementado.\n");
            break;

        case 3:
            printf("Ranking ainda não implementado.\n");
            break;

        case 0:
            printf("Saindo...\n");
            break;

        }

    } while (opcoes != 0);

    return 0;
}
