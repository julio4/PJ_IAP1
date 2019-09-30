#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TAILLE_STRING_MAX 100

int main() {

		int stop = 1;
		char* buf[TAILLE_STRING_MAX];

		int t = 0;
		int n = 0;

		char pay[32][TAILLE_STRING_MAX];
		char noms_equipes[32][3][TAILLE_STRING_MAX];
		unsigned char dossard[32][3];
		unsigned int dernier_dossart_inscrit = 100;
		int no_equipes = 0;

		while ( stop && ( scanf("%s", buf) == 1 ) ) {

			if (!strcmp(buf, "definir_parcours")) {
				scanf("%d", &t);
				continue;
			}

			if (!strcmp(buf, "definir_nombre_0preuves")) { // accent interprété par 0 par le compilateur
				scanf("%d", &n);
				continue;
			}

			if (!strcmp(buf, "inscrire_equipe")) {
				scanf("%s", pay[no_equipes]); //Inscrit pays
				for (int i = 0; i < 3; ++i) { // Se lance 3 fois
					scanf("%s", noms_equipes[no_equipes][i]); //Inscrit Nom
					dossard[no_equipes][i] = ++dernier_dossart_inscrit; //Inscrit dossard
					printf("inscription dossard %d\n", dossard[no_equipes][i]); //Print dossard
				}
				++no_equipes;
				continue;
			}

			if (!strcmp(buf, "afficher_equipes")) {
				for (int i = 0; i < no_equipes; ++i) {
					printf("%s ", pay[i]);
					for (int j = 0; j < 3; ++j) {
						printf("%s ", noms_equipes[i][j]);
						printf("%d ", dossard[i][j]);
					}
					//printf("\n"); Inutile pour sprint 1
				}
				continue;
			}

			if (!strcmp(buf, "exit")) {
				stop = 0;
			}
		}

	return 0;
}