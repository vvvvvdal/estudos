#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "ui.h"

char desenhoparede[4][7] = {
	{"......" },
	{"......" },
	{"......" },
	{"......" }
};

char desenhofantasma[4][7] = {
	{" .-.  " },
	{"| OO| " },
	{"|   | " },
	{"'^^^' " }
};

char desenhoheroi[4][7] = {
	{" .--. "  },
	{"/ _.-'"  },
	{"\\  '-." },
	{" '--' "  }
};

char desenhopilula[4][7] = {
	{"      "},
	{" .-.  "},
	{" '-'  "},
	{"      "}
};

char desenhovazio[4][7] = {
	{"      "},
	{"      "},
	{"      "},
	{"      "}
};

void imprimir_parte(char desenho[4][7], int parte) {
	printf("%s", desenho[parte]);
}

void imprimir_mapa(Mapa *mapa) {
	for(int i = 0; i < mapa->linhas; i++) {

		for(int parte = 0; parte < 4; parte++) {
			for(int j = 0; j < mapa->colunas; j++) {

				switch(mapa->m[i][j]) {
					case FANTASMA:
						imprimir_parte(desenhofantasma, parte);
						break;
					case HEROI:
						imprimir_parte(desenhoheroi, parte);
						break;
					case PILULA:
						imprimir_parte(desenhopilula, parte);
						break;
					case PAREDE_VERTICAL:
					case PAREDE_HORIZONTAL:
						imprimir_parte(desenhoparede, parte);
						break;
					case VAZIO:
						imprimir_parte(desenhovazio, parte);
						break;
				}
				
			}
			printf("\n");
		}

	}
}