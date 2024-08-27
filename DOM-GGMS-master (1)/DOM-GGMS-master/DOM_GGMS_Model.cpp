//DOM-GGMS-Model.cpp - Projeto Domino - Etapa 3
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

#include "DOM_GGMS_Model.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Mesa mesa[28];
tipopeca pecas[28];
int jogador1[7], jogador2[7];

void fEmbaralha(tipopeca pecas[28]) 
{
    srand(time(NULL));
    
    for (int i = 0; i < 28; i++) {
        int j = rand() % 28;
        
        // Troca as pecas de lugar
        tipopeca temp = pecas[i];
        pecas[i] = pecas[j];
        pecas[j] = temp;
    }
}

void fCriar(tipopeca pecas[28]) {
    int k = 0;
    
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            pecas[k].lado1 = i;    // contador atribuido pra lado1
            pecas[k].lado2 = j;    // contador atribuido pra lado2
            pecas[k].status = 'N'; // 'N' para não distribuída
            k++;
        }
    }
}

void distribuiPecas() {
    for (int i = 0; i < 7; i++) {
        jogador1[i] = i;             
        jogador2[i] = i + 7;         
        pecas[jogador1[i]].status = 'J'; // 'J' para jogador 1
        pecas[jogador2[i]].status = 'O'; // 'O' para jogador 2 (oponente)
    }
}

void exibePecas(int jogador[7]) {
    for (int i = 0; i < 7; i++) {
        tipopeca peca = pecas[jogador[i]];
        printf("[%d|%d] ", peca.lado1, peca.lado2);
    }
    printf("\n");
}

int main() {
    fCriar(pecas);
    fEmbaralha(pecas); // Embaralha as peças após criá-las
    distribuiPecas();
    
    printf("Pecas do Jogador 1:\n");
    exibePecas(jogador1);
    
    printf("Pecas do Jogador 2:\n");
    exibePecas(jogador2);
    
    return 0;
}
