#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TAILLE_STRING_MAX 100

/*A FAIRE*/
/*

- ENUM MAX des tableaux

*/


int main() {

	int on = 1;

	/*
	int t = 0;
	int n = 0;
	int nb_equipes = 0;
	int dossart = 101;
	char no_dossart[20];
	char stop = ' ';
	char affichage = ' ';*/

	while (on) {

		int stop = 1;
		char* buf[TAILLE_STRING_MAX];

		int t = 0;
		int n = 0;
		int dossard = 101;

		char *equipes[8][32];
		int nb_equipes = 0;

		while ( stop && ( scanf("%s", buf) == 1 ) ) {

			if (!strcmp(buf, "definir_parcours")) {
				scanf("%d", &t);
				printf("\ntour =%d\n", t);
				continue;
			}

			if (!strcmp(buf, "definir_nombre_0preuves")) { // accent interprété par 0 par le compilateur
				scanf("%d", &n);
				printf("\nparcours =%d\n", n);
				continue;
			}

			if (!strcmp(buf, "inscrire_equipe")) {
				scanf("%s", buf);
				equipes[0][nb_equipes] = buf;
				printf("%s\n", equipes[0][nb_equipes]);
				for (int i = 1; i < 7; i = i + 2) {
					scanf("%s", buf);
					equipes[i][nb_equipes] = buf; //Nom
					printf("%s\n", equipes[i][nb_equipes]);
					equipes[i+1][nb_equipes] = dossard; //Dossard
					printf("%s\n", equipes[i+1][nb_equipes]); //ERREUR ICI : violation d'acces
					printf("inscription dossard %d\n", dossard);
					++dossard;
				}
				++nb_equipes;
				continue;
			}

			if (!strcmp(buf, "afficher_equipes")) {
				for (int i = 0; i < nb_equipes; ++i) {
					printf("%s ", equipes[0][i]); //Pays //ERREUR ICI : envoi afficher_equipes ??
					for (int j = 1; j < 7; ++j) {
						printf("%s ", equipes[j][i]);
					}
					printf("\n");
				}
				continue;
			}

			if (!strcmp(buf, "exit")) {
				stop = 0;
			}
		}
		//system("pause");
		on = 0;
	}
	return 0;
}