/*              Projet 1 IAP 2019              */
/* 	                Sprint 4                   */
/*Jules DOUMECHE et Gwénolé MARTIN - Groupe 111*/
/*     Fin de développement le 23/10/2019      */

#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6054)
#pragma warning(disable:6262)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


/* INITIALISATION CONSTANTES GLOBALES ET STRUCTURES*/


enum MAX { MAX_TOURS = 10, MAX_EPREUVES = 16, MAX_EQUIPES = 32, MAX_EQUIPIERS = 3, MAX_MOT = 30 };	// Constantes pour les maximums (définies dans le CDC)
enum INIT { PREMIER_DOSSARD = 101 - 1 };															// Constantes d'initialisation

typedef struct {
	char nom[MAX_MOT + 1];																			//Nom du patineur
	unsigned int dossard;																			//Numéro de dossard du patineur
	unsigned int tour;																				//Tour du patineur
	double temps[MAX_TOURS];																		//Temps du patineur (pour chaque tour)
}Patineur;																							//^^ Structure patineur ^^//


typedef struct {
	char pays[MAX_MOT + 1];																			//Nom du pays de l'équipe
	Patineur dataPatineurs[MAX_EQUIPIERS];															//Tableau de Patineur de la taille de MAX_EQUIPIERS//
	int dernierPatineur;
}Equipe;																							//^^ Structure équipe ^^//


typedef struct {
	Equipe equipe[MAX_EQUIPES];																		//Tableau d'équipes
	unsigned int fini;
}Course;																							//^^ Structure course ^^//


typedef struct {
	unsigned int nbInscrits;																		//Variable du nombre de patineurs inscrits au total
	Course course[MAX_EPREUVES];																	//Tableau de course
	unsigned int nbParcours;
}Inscrits;																							//^^ Structure Inscrits ^^//


/*PROTOTYPES FONCTIONS*/


void definir_parcours(Inscrits* ins);
void definir_nombre_epreuves(int* epreuves);
void inscrire_equipe(Inscrits* ins);
void afficher_equipes(const Inscrits* ins);
void enregistrer_temps(Inscrits* ins);
void afficher_temps(const Course* course);
void afficher_temps_equipes(Inscrits* ins);
void detection_fin_poursuite(Inscrits* ins);


/* MAIN */


int main() {

	char mot[MAX_MOT + 1];
	int parcours = 0;
	int epreuves = 0;
	Inscrits ins = { .nbInscrits = 0 };

	while (1) {

		scanf("%s", mot);

		if (strcmp(mot, "definir_parcours") == 0) {
			definir_parcours(&ins);
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
			enregistrer_temps(&ins);
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
 * [out] pas de out, changement de la valeur de "parcours" à l'aide d'un pointeur
 */
void definir_parcours(Inscrits *ins) {
	scanf("%d", &ins->nbParcours);
}

/* Enregistre le nombre d'"épreuves"
 * [in] entier epreuves
 * [out] pas de out, changement de la valeur de "epreuves" à l'aide d'un pointeur
 */
void definir_nombre_epreuves(int* epreuves) {
	scanf("%d", epreuves);
}

/* Inscrit les équipes de Patineur
 * [in] Inscrits ins
 * [out] pas de out, affiche Inscription dossard+numéro du dossard pour chaque Patineur inscrit
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


/* Affiche les équipes de Patineur
 * [in] Inscrits ins (en constante pour l'affichage)
 * [out] pas de out, affiche le pays de chaque équipe puis le nom et le numéro de dossard de chaque patineur
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


/* Enregistre un temps pour un dossard et un tour donné
 * [in] Course course
 * [out] pas de out, enregistre le temps en fonction du dossard et du tour
 */
void enregistrer_temps(Inscrits* ins) {
	//calcul avec le dossard pour retrouver le bon patineur
	int dossard;
	scanf("%d", &dossard);
	int numero_equipe = (dossard - 101) / 3;
	int numero_joueur = ((dossard - 101) % 3);

	//enregistrement du numéro du tour
	scanf("%d", &ins->course->equipe[numero_equipe].dataPatineurs[numero_joueur].tour);

	//enregistrement du temps
	scanf("%lf", &ins->course->equipe[numero_equipe].dataPatineurs[numero_joueur].temps[(ins->course->equipe[numero_equipe].dataPatineurs[numero_joueur].tour) - 1]);

	detection_fin_poursuite(ins);
}


/* Affiche le temps d'un Patineur
 * [in] Course course (en constante pour l'affichage)
 * [out] pas de out, affiche le pays et le temps ou les temps (pour chaque tour) d'un patineur en fonction de son numéro de dossard
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


/* Affiche le temps d'une équipe de Patineurs
 * [in] Inscrits ins (en constante pour l'affichage)
 * [out] pas de out, affiche le pays et le temps du dernier patineur de chaque équipe (temps le plus grand)
 */
void afficher_temps_equipes(const Inscrits* ins) {

	int tour;
	(ins->course->fini) ? (tour = ins->nbParcours) : (scanf("%d", &tour));
	--tour; // décrémente tour pour la position dans le tableau temps

	int nb_eq_inscrites = (ins->nbInscrits) / MAX_EQUIPIERS;

	for (int i = 0; i < nb_eq_inscrites; ++i) {
		double a = ins->course->equipe[i].dataPatineurs[0].temps[tour]; //initialise a, b, et c pour éviter les longues lignes de structures dans les conditions
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
/**/
void detection_fin_poursuite(Inscrits* ins) {
	int nb_eq_inscrites = (ins->nbInscrits) / MAX_EQUIPIERS;
	int fini = 1;
	for (int i = 0; (i < nb_eq_inscrites && fini); ++i) {
		for (int j = 0; j < MAX_EQUIPIERS; ++j) {
			if ((ins->course->equipe[i].dataPatineurs[j].temps[(ins->nbParcours) - 1]) < 0.1) {
				fini = 0;
				break;
			}
			else {
				continue;
			}
		}
	}
	if (fini) {
		printf("detection_fin_poursuite\n");
		ins->course->fini = 1;
		int tour = ins->nbParcours - 1;
		for (int i = 0; i < nb_eq_inscrites; ++i) {
			if (ins->course->equipe[i].dataPatineurs[0].temps[tour] < ins->course->equipe[i].dataPatineurs[1].temps[tour] ||
				ins->course->equipe[i].dataPatineurs[0].temps[tour] < ins->course->equipe[i].dataPatineurs[2].temps[tour]) {
				if (ins->course->equipe[i].dataPatineurs[1].temps[tour] < ins->course->equipe[i].dataPatineurs[2].temps[tour]) {
					ins->course->equipe[i].dernierPatineur = 2;
				}
				else {
					ins->course->equipe[i].dernierPatineur = 1;
				}
			}
			else {
				ins->course->equipe[i].dernierPatineur = 0;
			}
		}
		if (ins->course->equipe[0].dataPatineurs[ins->course->equipe[0].dernierPatineur].temps[tour] > ins->course->equipe[0].dataPatineurs[ins->course->equipe[0].dernierPatineur].temps[tour]) {
			printf("%s %.1f\n", ins->course->equipe[0].pays, ins->course->equipe[0].dataPatineurs[ins->course->equipe[0].dernierPatineur].temps[tour]);
			printf("%s %.1f\n", ins->course->equipe[1].pays, ins->course->equipe[1].dataPatineurs[ins->course->equipe[1].dernierPatineur].temps[tour]);
		}
		else {
			printf("%s %.1f\n", ins->course->equipe[1].pays, ins->course->equipe[1].dataPatineurs[ins->course->equipe[1].dernierPatineur].temps[tour]);
			printf("%s %.1f\n", ins->course->equipe[0].pays, ins->course->equipe[0].dataPatineurs[ins->course->equipe[0].dernierPatineur].temps[tour]);
		}

	}
}