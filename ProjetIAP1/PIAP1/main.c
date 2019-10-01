#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
enum taille_tableau { TAILLE_STRING_MAX = 100 };

/*

A FAIRE:
-Ecrire une fonction strcmp ? ( a demander en amphi vendredi )
/-> pour regler bug accent dans "definir_nombre_épreuves"
- peut être réorganiser les variables en structure equipe

BUG CONNU:
-accent "definir_nombre_épreuves"

*/

int main() {

		int stop = 0;
		char* lecture[TAILLE_STRING_MAX];
		int test_lecture = 0;

		int t = 0; //tours
		int n = 0; //épreuves de poursuites

		char pays[32][TAILLE_STRING_MAX];
		char noms_equipes[32][3][TAILLE_STRING_MAX];
		unsigned char dossard[32][3];
		unsigned int dernier_dossart_inscrit = 100; //initialisation a 100 puis attribution par incrémentation
		int num_equipe = 0;

		while ( !stop && ( scanf("%s", lecture) == 1 ) ) {

			//printf("%s\n", lecture); DEBUG

			if (!strcmp(lecture, "definir_parcours")) {
				test_lecture = scanf("%d", &t);
				if ((test_lecture != 1) || (t < 2 || t > 10)) {
					printf("Erreur dans la saisie, format definir_parcours -tours[2;10]\n");
					break;
				}
				continue;
			}

			if (!strcmp(lecture, "definir_nombre_épreuves")) { // accent interprété par 0 par le compilateur
				test_lecture = scanf("%d", &n);
				if ( (test_lecture != 1) || (t < 1 || t > 16)) {
					printf("Erreur dans la saisie, format definir_nombre_%cpreuves\n", 130);
				}
				continue;
			}

			if (!strcmp(lecture, "inscrire_equipe")) {
				scanf("%s", pays[num_equipe]); //Inscrit pays
				if (num_equipe < 32) {
					for (int i = 0; i < 3; ++i) { // Se lance 3 fois
						scanf("%s", noms_equipes[num_equipe][i]); //Inscrit Nom
						dossard[num_equipe][i] = ++dernier_dossart_inscrit; //Inscrit dossard
						printf("inscription dossard %d\n", dossard[num_equipe][i]); //Print dossard
					}
					++num_equipe;
				}
				else {
					printf("Nombre d'equipes maximale atteint\n");
				}
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

			///SPRINT2
			/*
			if (!strcmp(lecture, "enregistrer_temps")) {
				if (scanf("%d %d %f", &/ numdossard, &/ nbtour, &/ temps) == 3) {

				}
				else {
					printf("Erreur dans la saisie, format enregistrer_temps -dossard -tour -temps\n");
				}
			}

			if (!strcmp(lecture, "afficher_temps")) {
				if (scanf("%d", &numdossard) == 1) {
					printf("%s %s %d", / pay, / nom, / dossard);
				}
				else {
					printf("Erreur dans la saisie, format afficher_temps -dossard\n");
				}
			}

			///*/

			if (!strcmp(lecture, "exit")) {
				stop = 1;
			}
		}

	return 0;
}