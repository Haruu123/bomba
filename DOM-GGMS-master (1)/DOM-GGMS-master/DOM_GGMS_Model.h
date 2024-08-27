//DOM-GGMS-Model.h - Projeto Dominó - Etapa 2
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

#ifndef DOM_GGMS_MODEL_H
#define DOM_GGMS_MODEL_H

typedef struct
{
    int lado1;
    int lado2;
    char status; // 'M' para mesa, 'J' para jogador
}tipopeca;

typedef struct 
{
    int ladoE;
    int ladoD;
}Mesa;

void fEmbaralha(tipopeca pecas[28]);
void fCriar(tipopeca pecas[28]);
void distribuiPecas();
void exibePecas(int jogador[7]);

#endif // DOM_GGMS_MODEL_H


