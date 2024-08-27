//DOM-GGMS-View.cpp - Projeto Domino - Etapa 3
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

#include "DOM_GGMS_Controller.h"
#include <stdio.h>

void exibirMesa(const mesaPeca mesa[28]) {
    for (int i = 0; i < 28; i++) {
        if (mesa[i].ladoE != -1 && mesa[i].ladoD != -1) {
            printf("[%d|%d] ", mesa[i].ladoE, mesa[i].ladoD);
        }
    }
    printf("\n");
}

void exibirPecasJogador(const tipopeca pecas[28], char jogador) {
    for (int i = 0; i < 28; i++) {
        if (pecas[i].status == jogador) {
            printf("[%d|%d] ", pecas[i].lado1, pecas[i].lado2);
        }
    }
    printf("\n");
}

int apresentarMenuGeral() {
    int op;
    printf("1. Iniciar Jogo\n");
    printf("2. Jogada Automática\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

void menuGeral() {
    int op = apresentarMenuGeral();
    switch (op) {
        case 1:
            iniciarJogo();
            break;
        case 2:
            jogadaAutomatica();
            break;
        case 3:
            printf("Sair\n");
            exit(0);
        default:
            printf("Opção inválida, tente novamente.\n");
            menuGeral();
            break;
    }
}


