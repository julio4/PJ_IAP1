#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6054)
#pragma warning(disable:6262)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


/* INITIALISATION CONSTANTES GLOBALES ET STRUCTURES*/


enum MAX { MAX_TOURS = 10, MAX_EPREUVES = 16, MAX_EQUIPES = 32, MAX_EQUIPIERS = 3, MAX_MOT = 30 }; 
enum INIT { PREMIER_DOSSARD = 101 - 1 };

typedef struct {
	char nom[MAX_MOT + 1];
	unsigned int dossard;
}Patineur;


typedef struct {
	char pays[MAX_MOT + 1];
	Patineur dataPatineurs[MAX_EQUIPIERS];
}Equipe;


typedef struct {
	Equipe equipe[MAX_EQUIPES];
}Course;


typedef struct {
	unsigned int nbInscrits;
	Course course[MAX_EPREUVES];
}Inscrits;


/*PROTOTYPES FONCTIONS*/


void definir_parcours(int* parcours);
void definir_nombre_epreuves(int* epreuves);
void inscrire_equipe(Inscrits* ins);
void afficher_equipes(const Inscrits* ins);


/*EXECUTION*/


int main() {

	char mot[MAX_MOT + 1];
	int parcours = 0;
	int epreuves = 0;
	Inscrits ins = { .nbInscrits = 0 };

	while (1) { 

		scanf("%s", mot); 

		if (strcmp(mot, "definir_parcours") == 0) {
			definir_parcours(&parcours);
		}

		else if (strcmp(mot, "definir_nombre_epreuves") == 0) {
			definir_nombre_epreuves(&epreuves);
		}

		else if (strcmp(mot, "inscrire_equipe") == 0) {
			inscrire_equipe(&ins);
		}

		else if (strcmp(mot, "afficher_equipes") == 0) {
			afficher_equipes(&ins);
		}

		else if (strcmp(mot, "exit") == 0) {
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


void inscrire_equipe(Inscrits* ins) {

	int nb_eq_inscrites = (ins->nbInscrits) / MAX_EQUIPIERS;
	static int dernier_dossard = PREMIER_DOSSARD; 

	scanf("%s", ins->course->equipe[nb_eq_inscrites].pays); 

	for (int i = 0; i < MAX_EQUIPIERS; ++i) { 

		scanf("%s", ins->course->equipe[nb_eq_inscrites].dataPatineurs[i].nom);
		dernier_dossard++;
		ins->course->equipe[nb_eq_inscrites].dataPatineurs[i].dossard = dernier_dossard;
		printf("inscription dossard %d\n\n", ins->course->equipe[nb_eq_inscrites].dataPatineurs[i].dossard);
		ins->nbInscrits += 1;
	}

}

void afficher_equipes(const Inscrits* ins) {

	int nb_eq_inscrites = (ins->nbInscrits) / MAX_EQUIPIERS;

	for (int i = 0; i < nb_eq_inscrites; ++i) { 

		printf("%s ", ins->course->equipe[i].pays);

		for (int j = 0; j < MAX_EQUIPIERS; ++j) { 

			printf("%s ", ins->course->equipe[i].dataPatineurs[j].nom);
			printf("%d", ins->course->equipe[i].dataPatineurs[j].dossard);

			if (j == (MAX_EQUIPIERS - 1)) {
				continue;
			}

			printf(" ");

		}

		printf("\n\n");

	}
}