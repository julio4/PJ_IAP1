#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

enum MAX {MAX_TOURS = 10, MAX_EPREUVES = 16, MAX_EQUIPES = 32, MAX_PATINEURS = 50, MAX_MOT = 30};

typedef struct {
	char nom[MAX_MOT+1];
	unsigned int dossard;
} Patineur;

typedef struct {
	char pays[MAX_MOT + 1];
	Patineur dataPatineurs[MAX_PATINEURS];
} Equipe;

typedef struct {
	Equipe dataEpreuve[MAX_EQUIPES];
} Epreuve;

typedef struct {
	Epreuve dataCompetition[MAX_EPREUVES];
} Competition;

void definir_parcours(int* parcours);
void definir_nombre_epreuves(int *epreuves);
//void inscription_equipe(Equipe *ins); 
//void affichage_equipe(const Equipe *ins);


int main() {

	/*INITIALISATION*/
	char mot[MAX_MOT+1];
	int parcours = 0;
	int epreuves = 0;

	while (1) {
		scanf("%s", mot);

		if (strcmp(mot, "definir_parcours") == 0) {
			definir_parcours(&parcours);
			printf("%d Validation parcours", parcours);
		}

		/*if (strcmp(mot, "definir_nombre_épreuves") == 0) {
			definir_nombre_epreuves(&epreuves);
			printf("%d Validation épreuves", epreuves);
		}*/

		if (strcmp(mot, "inscrire_equipe") == 0) {
			inscrire_equipe();
		}
		if (strcmp(mot, "afficher_equipes") == 0) {

		}
		if (strcmp(mot, "enregistrer_temps") == 0) {

		}
		if (strcmp(mot, "detection_fin_poursuite") == 0) {

		}
		if (strcmp(mot, "detection_fin_competition") == 0) {

		}
		if (strcmp(mot, "afficher_temps") == 0) {

		}
		if (strcmp(mot, "afficher_temps_equipes") == 0) {

		}

		if (strcmp(mot, "exit") == 0) {
			exit(0);
		}
	}
}

void definir_parcours(int* parcours) {
	scanf("%d", parcours);
}

void definir_nombre_epreuves(int* epreuves) {
	scanf("%d", epreuves);
}

void inscrire_equipe() {

}