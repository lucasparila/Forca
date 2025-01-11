#include "forca.h"

#define TAMANHO_PALAVRA 20

// lógica jogo
struct jogo {
    char *palavra;
    char *dica;
    char *chutes;
    int tamanho;
    int chutesdados;
};

void abertura() {
printf("/****************/\n");
printf("/ Jogo de Forca */\n");
printf("/****************/\n\n");
}

T_jogo create(char *text) {
    T_jogo str = malloc(sizeof(struct jogo));

    if (str != NULL) {
        str->tamanho = strlen(text);
        str->palavra = malloc(sizeof(char) * (str->tamanho + 1));
        str->chutes = malloc(sizeof(char) * 26);
        if (str->palavra == NULL || str->chutes == NULL) {
            free(str->palavra);
            free(str->chutes);
            free(str);
            return NULL;
        }
        strcpy(str->palavra, text);
        str->chutesdados = 0;
    }

    return str;
}

void destroy(T_jogo str) {
    if (str != NULL) {
        free(str->palavra);
        free(str->chutes);
        free(str);
    }
}

int letraexiste(char letra, T_jogo str) {
    for (int j = 0; j < str->tamanho; j++) {
        if (letra == str->palavra[j]) {
            return 1;
        }
    }
    return 0;
}

int chuteserrados(T_jogo str) {
    int erros = 0;
    for (int i = 0; i < str->chutesdados; i++) {
        if (!letraexiste(str->chutes[i], str)) {
            erros++;
        }
    }
    return erros;
}

int enforcou(T_jogo str) {
    return chuteserrados(str) >= 5;
}

int ganhou(T_jogo str) {
    for (int i = 0; i < str->tamanho; i++) {
        if (!jachutou(str, str->palavra[i])) {
            return 0;
        }
    }
    return 1;
}

void chuta(T_jogo str) {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);
    while (getchar() != '\n');

    if (letraexiste(chute, str)) {
        printf("Você acertou: a palavra tem a letra %c\n\n", chute);
    } else {
        printf("\nVocê errou: a palavra NÃO tem a letra %c\n\n", chute);
    }

    str->chutes[str->chutesdados] = chute;
    str->chutesdados += 1;
}

int jachutou(T_jogo str, char letra) {
    for (int j = 0; j < str->chutesdados; j++) {
        if (str->chutes[j] == letra) {
            return 1;
        }
    }
    return 0;
}

void desenhaforca(T_jogo str) {
    char palavra_secreta[str->tamanho + 1];
    for (int i = 0; i < str->tamanho; i++) {
        if (jachutou(str, str->palavra[i])) {
            palavra_secreta[i] = str->palavra[i];
        } else {
            palavra_secreta[i] = '_';
        }
    }
    palavra_secreta[str->tamanho] = '\0';

    int erros = chuteserrados(str);

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |              \n");
    printf(" | %s           \n", palavra_secreta);
    printf("\n\n");
}

void imprime_resultado_final(T_jogo str){
     if(ganhou(str)) {
        printf("\nDuas palavras pra você, parabens!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", str->palavra);

        printf("     ______________          \n");
        printf("    //             \\        \n");
        printf("   //               \\       \n");
        printf("\\//                 \\/\\   \n");
        printf("\\|   XXXX     XXXX   | //   \n");
        printf("\\|    XXXX     XXXX  |//    \n");
        printf("  |    XXX     XXX    |      \n");
        printf("  |                   |      \n");
        printf(" \\__      XXX      __//     \n");
        printf("   |\\     XXX     //|       \n");
        printf("   | |             | |       \n");
        printf("   |  I I I I I I I  |       \n");
        printf("   |   I I I I I I   |       \n");
        printf("   \\_             _//       \n");
        printf("     \\_         _//         \n");
        printf("       \\_______//         falisseu\n");
    }
}