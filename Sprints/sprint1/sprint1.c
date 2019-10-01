#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TAILLE_STRING_MAX 100

int main() {

		int stop = 0;
		char* lecture[TAILLE_STRING_MAX];

		int t = 0;
		int n = 0;

		char pays[32][TAILLE_STRING_MAX];
		char noms_equipes[32][3][TAILLE_STRING_MAX];
		unsigned char dossard[32][3];
		unsigned int dernier_dossart_inscrit = 100;
		int num_equipe = 0;

		while ( !stop && ( scanf("%s", lecture) == 1 ) ) {

			if (!strcmp(lecture, "definir_parcours")) {
				scanf("%d", &t);
				continue;
			}

			if (!strcmp(lecture, "definir_nombre_0preuves")) { // accent interprété par 0 par le compilateur
				scanf("%d", &n);
				continue;
			}

			if (!strcmp(lecture, "inscrire_equipe")) {
				scanf("%s", pays[num_equipe]); //Inscrit pays
				for (int i = 0; i < 3; ++i) { // Se lance 3 fois
					scanf("%s", noms_equipes[num_equipe][i]); //Inscrit Nom
					dossard[num_equipe][i] = ++dernier_dossart_inscrit; //Inscrit dossard
					printf("inscription dossard %d\n", dossard[num_equipe][i]); //Print dossard
				}
				++num_equipe;
				continue;
			}

			if (!strcmp(lecture, "afficher_equipes")) {
				for (int i = 0; i < num_equipe; ++i) {
					printf("%s ", pays[i]);
					for (int j = 0; j < 3; ++j) {
						printf("%s ", noms_equipes[i][j]);
						printf("%d ", dossard[i][j]);
					}
					//printf("\n"); Inutile pour sprint 1
				}
				continue;
			}

			if (!strcmp(lecture, "exit")) {
				stop = 1;
			}
		}

	return 0;
}