//DOM-GGMS-Controller.h - Projeto Domino - Etapa 3
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

struct tipopeca 
{
    int ladoE;
    int ladoD;
    char status; // 'M' para mesa, 'J' para jogador
};

void fEmbaralha(tipopeca pecas[28]);
void jogo();
void iniciarJogo();


