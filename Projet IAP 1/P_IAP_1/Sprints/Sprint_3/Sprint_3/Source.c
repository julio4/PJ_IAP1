/*              Projet 1 IAP 2019              */
/* 	                Sprint 3                   */
/*Jules DOUMECHE et Gw�nol� MARTIN - Groupe 111*/
/*     Fin de d�veloppement le 18/10/2019      */

#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6054)
#pragma warning(disable:6262)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


/* INITIALISATION CONSTANTES GLOBALES ET STRUCTURES*/


enum MAX { MAX_TOURS = 10, MAX_EPREUVES = 16, MAX_EQUIPES = 32, MAX_EQUIPIERS = 3, MAX_MOT = 30 };	// Constantes pour les maximums (d�finies dans le CDC)
enum INIT { PREMIER_DOSSARD = 101 - 1 };															// Constantes d'initialisation

typedef struct {
	char nom[MAX_MOT + 1];																			//Nom du patineur
	unsigned int dossard;																			//Num�ro de dossard du patineur
	unsigned int tour;																				//Tour du patineur
	double temps[MAX_TOURS];																		//Temps du patineur (pour chaque tour)
}Patineur;																							//^^ Structure patineur ^^//


typedef struct {
	char pays[MAX_MOT + 1];																			//Nom du pays de l'�quipe
	Patineur dataPatineurs[MAX_EQUIPIERS];															//Tableau de Patineur de la taille de MAX_EQUIPIERS//
}Equipe;																							//^^ Structure �quipe ^^//


typedef struct {
	Equipe equipe[MAX_EQUIPES];																		//Tableau d'�quipes
}Course;																							//^^ Structure course ^^//


typedef struct {
	unsigned int nbInscrits;																		//Variable du nombre de patineurs inscrits au total
	Course course[MAX_EPREUVES];																	//Tableau de course
}Inscrits;																							//^^ Structure Inscrits ^^//


/*PROTOTYPES FONCTIONS*/


void definir_parcours(int* parcours);
void definir_nombre_epreuves(int* epreuves);
void inscrire_equipe(Inscrits* ins);
void afficher_equipes(const Inscrits* ins);
void enregistrer_temps(Course* course);
void afficher_temps(const Course* course);
void afficher_temps_equipes(Inscrits* ins);


/* MAIN */


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

		else if (strcmp(mot, "enregistrer_temps") == 0) {
			enregistrer_temps(&ins.course);
		}

		else if (strcmp(mot, "afficher_temps") == 0) {
			afficher_temps(&ins.course);
		}

		else if (strcmp(mot, "afficher_temps_equipes") == 0) {
			afficher_temps_equipes(&ins);
		}

		else if (strcmp(mot, "exit") == 0) {
			exit(0);
		}
	}
}

/* Enregistre le nombre de "parcours"
 * [in] entier parcours
 * [out] pas de out, changement de la valeur de "parcours" � l'aide d'un pointeur
 */
void definir_parcours(int* parcours) {
	scanf("%d", parcours);
}

/* Enregistre le nombre d'"�preuves"
 * [in] entier epreuves
 * [out] pas de out, changement de la valeur de "epreuves" � l'aide d'un pointeur
 */
void definir_nombre_epreuves(int* epreuves) {
	scanf("%d", epreuves);
}

/* Inscrit les �quipes de Patineur
 * [in] Inscrits ins
 * [out] pas de out, affiche Inscription dossard+num�ro du dossard pour chaque Patineur inscrit
 */
void inscrire_equipe(Inscrits* ins) {

	int nb_eq_inscrites = (ins->nbInscrits) / MAX_EQUIPIERS;
	static int dernier_dossard = PREMIER_DOSSARD;

	scanf("%s", ins->course->equipe[nb_eq_inscrites].pays);

	for (int i = 0; i < MAX_EQUIPIERS; ++i) {

		scanf("%s", ins->course->equipe[nb_eq_inscrites].dataPatineurs[i].nom);
		dernier_dossard++;
		ins->course->equipe[nb_eq_inscrites].dataPatineurs[i].dossard = dernier_dossard;
		printf("inscription dossard %d\n", ins->course->equipe[nb_eq_inscrites].dataPatineurs[i].dossard);
		ins->nbInscrits += 1;
	}

}


/* Affiche les �quipes de Patineur
 * [in] Inscrits ins (en constante pour l'affichage)
 * [out] pas de out, affiche le pays de chaque �quipe puis le nom et le num�ro de dossard de chaque patineur
 */
void afficher_equipes(const Inscrits* ins) {

	int nb_eq_inscrites = (ins->nbInscrits) / MAX_EQUIPIERS;

	for (int i = 0; i < nb_eq_inscrites; ++i) {

		printf("%s ", ins->course->equipe[i].pays);

		for (int j = 0; j < MAX_EQUIPIERS; ++j) {

			printf("%s ", ins->course->equipe[i].dataPatineurs[j].nom);
			printf("%d", ins->course->equipe[i].dataPatineurs[j].dossard);

			if (j == (MAX_EQUIPIERS - 1) && (i == nb_eq_inscrites - 1)) {
				continue;
			}

			printf(" ");

		}

		printf("\n");

	}
}


/* Enregistre un temps pour un dossard et un tour donn�
 * [in] Course course
 * [out] pas de out, enregistre le temps en fonction du dossard et du tour
 */
void enregistrer_temps(Course* course) {
	//calcul avec le dossard pour retrouver le bon patineur
	int dossard;
	scanf("%d", &dossard);
	int numero_equipe = (dossard - 101) / 3;
	int numero_joueur = ((dossard - 101) % 3);

	//enregistrement du num�ro du tour
	scanf("%d", &course->equipe[numero_equipe].dataPatineurs[numero_joueur].tour);

	//enregistrement du temps
	scanf("%lf", &course->equipe[numero_equipe].dataPatineurs[numero_joueur].temps[(course->equipe[numero_equipe].dataPatineurs[numero_joueur].tour) - 1]);
}


/* Affiche le temps d'un Patineur
 * [in] Course course (en constante pour l'affichage)
 * [out] pas de out, affiche le pays et le temps ou les temps (pour chaque tour) d'un patineur en fonction de son num�ro de dossard
 */
void afficher_temps(const Course* course) {
	int dossard;
	scanf("%d", &dossard);
	int numero_equipe = (dossard - 101) / 3;
	int numero_joueur = ((dossard - 101) % 3);

	for (unsigned int i = 0; i < (course->equipe[numero_equipe].dataPatineurs[numero_joueur].tour); ++i) {
		printf("%s ", course->equipe[numero_equipe].pays);
		printf("%d ", (i + 1));
		printf("%s ", course->equipe[numero_equipe].dataPatineurs[numero_joueur].nom);
		printf("%.1f\n", course->equipe[numero_equipe].dataPatineurs[numero_joueur].temps[i]);
	}
}


/* Affiche le temps d'une �quipe de Patineurs
 * [in] Inscrits ins (en constante pour l'affichage)
 * [out] pas de out, affiche le pays et le temps du dernier patineur de chaque �quipe (temps le plus grand)
 */
void afficher_temps_equipes(const Inscrits* ins) {

	int tour;
	scanf("%d", &tour);
	--tour; // d�cr�mente tour pour la position dans le tableau temps

	int nb_eq_inscrites = (ins->nbInscrits) / MAX_EQUIPIERS;

	for (int i = 0; i < nb_eq_inscrites; ++i) {
		double a = ins->course->equipe[i].dataPatineurs[0].temps[tour]; //initialise a, b, et c pour �viter les longues lignes de structures dans les conditions
		double b = ins->course->equipe[i].dataPatineurs[1].temps[tour]; 
		double c = ins->course->equipe[i].dataPatineurs[2].temps[tour]; 
		if (a > 0.0 && b > 0.0 && c > 0.0) {
			printf("%s ", ins->course->equipe[i].pays);
			if (a < b || a < c) {
				if (b < c) {
					printf("%.1f", c);
				}
				else {
					printf_s("%.1f", b);
				}
			}
			else {
				printf_s("%.1f", a);
			}
		}
		else {
			printf("indisponible");
		}
		printf("\n");
	}
}