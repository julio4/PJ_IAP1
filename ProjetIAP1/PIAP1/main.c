#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

enum taille_tableau { TAILLE_STRING_MAX = 100 };

/*

A FAIRE/ A REFLECHIR:
-Ecrire une fonction strcmp ? ( a demander en amphi vendredi )
-enregistrer les strings possibles ("definir_parcours ... etc"), attribuer un nombre pour chaque string,
fonction qui renvoie le nombre correspondant au string entrée, switch qui renvoie vers une fonction correspondant
Dans ce cas le main est uniquement constitué d'une boucle, d'un switch, et de fonctions.

-Sprint 2: passage de temps.dossart > equipes.dossart pour recup equipes.noms
Objectif lier temps.dossart à equipe.dossart puis à equipe.noms[x](nom correspondant au dossart/ pouvoir associer du dossart a un nom)/equipe.pay
Enregistrer pour un dossart: le temps, le tour ( ?? coureurs.dossart[tour][temps] ou qqchose du genre )


BUG CONNU:
-accent "definir_nombre_épreuves"
:::fonction strcmp
:::encodage
*/

int main() {

		/*INITIALISATION*/

		//Boucle, entrée, erreurs
		int stop = 0;
		char* lecture[TAILLE_STRING_MAX];
		int test_lecture = 0;

		//Variables programmes
		int t = 0; //tours
		int n = 0; //épreuves de poursuites
		unsigned int dernier_dossart_inscrit = 100; //initialisation a 100 puis attribution par incrémentation

		//Structures et tableaux
		struct info_equipes {
			char pays[32][TAILLE_STRING_MAX];
			char noms[32][3][TAILLE_STRING_MAX];
			unsigned char dossard[32][3];
			int num;
		};

		struct info_equipes equipes = { .num = 0 };

		struct donnee_temps {
			unsigned char dossard;
			int tours;
			float chrono;
		};

		struct donnee_temps temps;

		/*LANCEMENT*/

		while ( !stop && ( scanf("%s", lecture) == 1 ) ) {

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
				scanf("%s", equipes.pays[equipes.num]); //Inscrit pays
				if (equipes.num < 32) {
					for (int i = 0; i < 3; ++i) { // Se lance 3 fois
						scanf("%s", equipes.noms[equipes.num][i]); //Inscrit Nom
						equipes.dossard[equipes.num][i] = ++dernier_dossart_inscrit; //Inscrit dossard
						printf("inscription dossard %d\n", equipes.dossard[equipes.num][i]); //Print dossard
					}
					++equipes.num;
				}
				else {
					printf("Nombre d'equipes maximale atteint\n");
				}
				continue;
			}

			if (!strcmp(lecture, "afficher_equipes")) {
				for (int i = 0; i < equipes.num; ++i) {
					printf("%s ", equipes.pays[i]);
					for (int j = 0; j < 3; ++j) {
						printf("%s ", equipes.noms[i][j]);
						printf("%d ", equipes.dossard[i][j]);
					}
					//printf("\n"); Inutile pour sprint 1
				}
				continue;
			}


			///SPRINT2
			
			/*

			if (!strcmp(lecture, "enregistrer_temps")) {
				if (scanf("%d %d %f", &temps.dossard, &temps.tours, &temps.chrono) == 3) {
					//Nom temps.dossart
					//temps.dossard 
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

			///*


			/*FIN*/

			if (!strcmp(lecture, "exit")) {
				stop = 1;
			}
		}

	return 0;
}