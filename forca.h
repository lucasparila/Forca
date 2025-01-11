
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct jogo* T_jogo;
T_jogo create(char* text);
void destroy(T_jogo str);
int letraexiste(char letra, T_jogo str);
int chuteserrados(T_jogo str);
int enforcou(T_jogo str);
int ganhou(T_jogo str);
void abertura();
void chuta(T_jogo str);
int jachutou(T_jogo str, char letra);
void desenhaforca(T_jogo str);
void imprime_resultado_final(T_jogo str);



