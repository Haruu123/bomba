//DOM-GGMS-Controller.cpp - Projeto Domino - Etapa 3
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

#include "DOM_GGMS_Model.h"
#include "DOM_GGMS_View.cpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

// Vari�veis globais
Mesa mesa[28]; 
tipopeca pecas[28];
char jvez; // Vari�vel global para armazenar o jogador da vez

// Fun��o para limpar a mesa
void limparMesa() 
{
    for (int i = 0; i < 28; i++) 
    {
        mesa[i].ladoE = -1;
        mesa[i].ladoD = -1;
    }
}

// Fun��o para distribuir as pe�as entre o jogador e o oponente
void distribuiPecas() 
{
    for (int i = 0; i < 7; i++) 
    {
        pecas[i].status = 'J'; // 'J' para jogador
        pecas[i + 7].status = 'O'; // 'O' para oponente
    }
}

// Fun��o para embaralhar as pe�as
void fEmbaralha(tipopeca pecas[28]) 
{
    srand(time(NULL));
    for (int i = 0; i < 28; i++) 
    {
        int j = rand() % 28;
        tipopeca temp = pecas[i];
        pecas[i] = pecas[j];
        pecas[j] = temp;
    }
}

// Fun��o placeholder para jogada autom�tica (deve ser implementada)
void jogadaAutomatica() {
    printf("Jogada autom�tica realizada!\n");
    // Implementar l�gica de jogada autom�tica aqui
}

// Fun��o para apresentar o menu geral
void apresentarMenuGeral() {
    int op;
    do {
        printf("1. Iniciar Jogo\n");
        printf("2. Jogada Autom�tica\n");
        printf("3. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                iniciarJogo();
                break;
            case 2:
                jogadaAutomatica();
                break;
            case 3:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Op��o inv�lida! Tente novamente.\n");
        }
    } while (op != 3);
}

// Fun��o para determinar o primeiro lance
void primeiroLance() {
    int i, pj = -1, dupla = -1;
    for (i = 0; i < 14; i++) {
        if (pecas[i].lado1 == pecas[i].lado2 && pecas[i].lado1 > dupla) {
            dupla = pecas[i].lado1;
            pj = i;
        }
    }
    if (pj == -1) {
        dupla = 0;
        for (i = 0; i < 14; i++) {
            if (pecas[i].lado1 + pecas[i].lado2 > dupla) {
                dupla = pecas[i].lado1 + pecas[i].lado2;
                pj = i;
            }
        }
    }
    jvez = pecas[pj].status;
    mesa[0].ladoE = pecas[pj].lado1;
    mesa[0].ladoD = pecas[pj].lado2;
    pecas[pj].status = 'M';
}

// Fun��o para iniciar o jogo
void iniciarJogo() 
{
    limparMesa();
    fEmbaralha(pecas);
    distribuiPecas();
    primeiroLance();
    // Implementar o loop principal do jogo aqui, controlando as rodadas e alternando jogadores
}

int main() {
    apresentarMenuGeral();
    return 0;
}

