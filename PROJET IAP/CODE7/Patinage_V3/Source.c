#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* INITIALISATION CONSTANTES GLOBALES ET STRUCTURES*/

enum MAX { MAX_TOURS = 10, MAX_EPREUVES = 16, MAX_EQUIPES = 32, MAX_EQUIPES_PARCOURS = 2, MAX_EQUIPIERS = 3, MAX_MOT = 30 }; //Constantes globales
enum INIT { PREMIER_DOSSARD = 101};

typedef struct {
	double temp;
	int equipe;
}Tri;

//Structure Patineur: Nom du patineur + numéro de dossard
typedef struct {
	char nom[MAX_MOT + 1];
	unsigned int dossard;
	double temps[MAX_TOURS];
	unsigned int tour;
}Patineur;

//Structure Equipe: pays + structure Patineur
typedef struct {
	char pays[MAX_MOT + 1];
	Patineur dataPatineurs[MAX_EQUIPIERS];
	unsigned int dernierPatineur;
}Equipe;

typedef struct {
	Equipe equipe[MAX_EQUIPES_PARCOURS];
	unsigned int fini;
	unsigned int equipe_gagnante; // // // //
}Course;

typedef struct {
	unsigned int nbInscrits;
	Course course[MAX_EPREUVES];
	unsigned int nbParcours;
	unsigned int nbEpreuves;
	unsigned int derniere_course;
}Inscrits;

/*PROTOTYPES FONCTIONS*/

void definir_parcours(Inscrits* ins);
void definir_nombre_epreuves(Inscrits* ins);
void inscrire_equipe(Inscrits* ins);
void afficher_equipes(Inscrits* ins);
void enregistrer_temps(Inscrits* ins);
void afficher_temps(Inscrits* ins);
void afficher_temps_equipes(Inscrits* ins);
void detection_fin_poursuite(Inscrits* ins);
void detection_fin_competition(Inscrits* ins);

int crs_en_cour(Inscrits* ins);
int nb_eq_ins(Inscrits* ins);

/*EXECUTION*/

int main() {

	/*INITIALISATION VARIABLES ET STRUCTURES*/

	char mot[MAX_MOT + 1];
	int epreuves = 0;
	Inscrits ins = { .nbInscrits = 0,.nbParcours = 2,.nbEpreuves = 16,.derniere_course = 0 };

	/*PROGRAMME*/

	while (1) {
		scanf("%s", mot);
		if (strcmp(mot, "definir_parcours") == 0) {
			definir_parcours(&ins);
		}
		else if (strcmp(mot, "definir_nombre_epreuves") == 0) {
			definir_nombre_epreuves(&ins);
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
			afficher_temps(&ins);
		}
		else if (strcmp(mot, "afficher_temps_equipes") == 0) {
			afficher_temps_equipes(&ins);
		}
		else if (strcmp(mot, "exit") == 0) {
			exit(0); //Permet de sortir de la boucle infini et finir le programme
		}
		//printf("\n");
	}
}

/*FONCTIONS*/

void definir_parcours(Inscrits* ins) {
	scanf("%d", &ins->nbParcours);
}

void definir_nombre_epreuves(Inscrits* ins) {
	scanf("%d", &ins->nbEpreuves);
}

void inscrire_equipe(Inscrits* ins) {
	int no_crs = ins->derniere_course;
	int no_eq = (nb_eq_ins(ins) - (ins->derniere_course * 2));
	static int dernier_dossard = PREMIER_DOSSARD - 1;
	scanf("%s", ins->course[no_crs].equipe[no_eq].pays);

	for (int i = 0; i < MAX_EQUIPIERS; ++i) {
		scanf("%s", ins->course[no_crs].equipe[no_eq].dataPatineurs[i].nom);
		dernier_dossard++;
		ins->course[no_crs].equipe[no_eq].dataPatineurs[i].dossard = dernier_dossard;
		printf("inscription dossard %d\n", ins->course[no_crs].equipe[no_eq].dataPatineurs[i].dossard);
		ins->nbInscrits++;
	}

	if ((no_eq % 2) == 1 && (ins->derniere_course + 1) != ins->nbEpreuves) {
		ins->derniere_course++;
	}
}

void afficher_equipes(Inscrits* ins) {
	int no_crs = crs_en_cour(ins);

	for (int i = 0; i < MAX_EQUIPES_PARCOURS; ++i) {
		printf("%s ", ins->course[no_crs].equipe[i].pays);
		for (int j = 0; j < MAX_EQUIPIERS; ++j) {
			printf("%s ", ins->course[no_crs].equipe[i].dataPatineurs[j].nom);
			printf("%d", ins->course[no_crs].equipe[i].dataPatineurs[j].dossard);
			if (i == (nb_eq_ins(ins) - 1) && j == (MAX_EQUIPIERS - 1)) {
				continue;
			}
			printf(" ");
		}
		printf("\n");
	}
}

void enregistrer_temps(Inscrits* ins) {
	//dossard
	int dossard;
	scanf("%d", &dossard);

	int numero_joueur = ((dossard - 101) % 3);
	int numero_equipe = ((dossard - 101) / 3) % 2;
	int no_crs = ((dossard - 101) / 3) / 2;

	//tour
	scanf("%d", &ins->course[no_crs].equipe[numero_equipe].dataPatineurs[numero_joueur].tour);

	//temps
	scanf("%lf", &ins->course[no_crs].equipe[numero_equipe].dataPatineurs[numero_joueur].temps[(ins->course[no_crs].equipe[numero_equipe].dataPatineurs[numero_joueur].tour) - 1]);

	detection_fin_poursuite(ins);
	detection_fin_competition(ins);
}

void afficher_temps(Inscrits* ins) {
	int dossard;
	scanf("%d", &dossard);

	int numero_joueur = ((dossard - 101) % 3);
	int no_crs = ((dossard - 101) / 3) / 2;
	int numero_equipe = ((dossard - 101) / 3) % 2;

	for (unsigned int i = 0; i < (ins->course[no_crs].equipe[numero_equipe].dataPatineurs[numero_joueur].tour); ++i) {
		printf("%s ", ins->course[no_crs].equipe[numero_equipe].pays);
		printf("%d ", (i + 1));
		printf("%s ", ins->course[no_crs].equipe[numero_equipe].dataPatineurs[numero_joueur].nom);
		printf("%.1f\n", ins->course[no_crs].equipe[numero_equipe].dataPatineurs[numero_joueur].temps[i]);
	}
}

void afficher_temps_equipes(Inscrits* ins) {
	int no_crs = crs_en_cour(ins);
	int tour;
	scanf("%d", &tour);
	--tour;

	for (int i = 0; i < MAX_EQUIPES_PARCOURS; ++i) {
		int enregistrement = 1;
		for (int j = 0; j < MAX_EQUIPIERS; ++j) {
			if (ins->course->equipe[i].dataPatineurs[j].temps[tour] <= 0.001) {
				enregistrement = 0;
				break;
			}
		}
		if (enregistrement) {
			printf("%s ", ins->course[no_crs].equipe[i].pays);
			double dernier_temps = ins->course[no_crs].equipe[i].dataPatineurs[0].temps[tour];
			for (int j = 1; j < MAX_EQUIPIERS; ++j) {
				if (ins->course[no_crs].equipe[i].dataPatineurs[j].temps[tour] > dernier_temps) {
					dernier_temps = ins->course[no_crs].equipe[i].dataPatineurs[j].temps[tour];
				}
			}
			printf("%.1f", dernier_temps);
		}
		else {
			printf("indisponible\n");
		}
		printf("\n");
	}
}

void detection_fin_poursuite(Inscrits* ins) {
	int no_crs = crs_en_cour(ins);
	int fini = 1;
	for (int i = 0; ( (i < MAX_EQUIPES_PARCOURS) && fini); ++i) {
		for (int j = 0; j < MAX_EQUIPIERS; ++j) {
			if ((ins->course[no_crs].equipe[i].dataPatineurs[j].temps[(ins->nbParcours) - 1]) < 0.001) {
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
		ins->course[no_crs].fini = 1;
		int tour = ins->nbParcours - 1;

		double dernier_temps[MAX_EQUIPES_PARCOURS];
		for (int i = 0; i < MAX_EQUIPES_PARCOURS; ++i) {
			dernier_temps[i] = ins->course[no_crs].equipe[i].dataPatineurs[0].temps[tour];
			ins->course[no_crs].equipe[i].dernierPatineur = 0;
			for (int j = 1; j < MAX_EQUIPIERS; ++j) {
				if (ins->course[no_crs].equipe[i].dataPatineurs[j].temps[tour] > dernier_temps[i]) {
					dernier_temps[i] = ins->course[no_crs].equipe[i].dataPatineurs[j].temps[tour];
					ins->course[no_crs].equipe[i].dernierPatineur = j;
				}
			}
		}
		if (dernier_temps[1] > dernier_temps[0]) {
			ins->course[no_crs].equipe_gagnante = 0;
			printf("%s %.1f\n", ins->course[no_crs].equipe[0].pays, ins->course[no_crs].equipe[0].dataPatineurs[ins->course[no_crs].equipe[0].dernierPatineur].temps[tour]);
			printf("%s %.1f\n", ins->course[no_crs].equipe[1].pays, ins->course[no_crs].equipe[1].dataPatineurs[ins->course[no_crs].equipe[1].dernierPatineur].temps[tour]);		
		}
		else {
			ins->course[no_crs].equipe_gagnante = 1;
			printf("%s %.1f\n", ins->course[no_crs].equipe[1].pays, ins->course[no_crs].equipe[1].dataPatineurs[ins->course[no_crs].equipe[1].dernierPatineur].temps[tour]);
			printf("%s %.1f\n", ins->course[no_crs].equipe[0].pays, ins->course[no_crs].equipe[0].dataPatineurs[ins->course[no_crs].equipe[0].dernierPatineur].temps[tour]);
		}
	}
}

void detection_fin_competition(Inscrits* ins) {
	if (ins->course[ins->nbEpreuves - 1].fini == 1) {
		printf("detection_fin_competition\n");
		Tri tri[MAX_EQUIPES];
		int c = 0;
		for (int i = 0; i < ((nb_eq_ins(ins) / 2)); i++) {
			for (int j = 0; j < MAX_EQUIPES_PARCOURS; j++) {
				tri[c].temp = ins->course[i].equipe[j].dataPatineurs[ins->course[i].equipe[j].dernierPatineur].temps[ins->nbParcours - 1];
				tri[c].equipe = c;
				c++;
			}
		}
		
		for (int i = 0; i < (nb_eq_ins(ins)); i++) {
			for (int j = 0; j < (nb_eq_ins(ins)); j++) {
				if (tri[i].temp < tri[j].temp) {
					double temporaire = tri[i].temp;
					int temporaire_2 = tri[i].equipe;
					tri[i].temp = tri[j].temp;
					tri[i].equipe = tri[j].equipe;
					tri[j].temp = temporaire;
					tri[j].equipe = temporaire_2;
				}
			}
		}
		
		for (int i = 0; i < (nb_eq_ins(ins)); i++) {
			printf("%s %.1f\n", ins->course[(tri[i].equipe / 2)].equipe[(tri[i].equipe) % 2].pays, tri[i].temp);
		}
	}
}

int crs_en_cour(Inscrits* ins) {
	for (unsigned int i = 0; i <= ins->nbEpreuves; ++i) {
		if (ins->course[i].fini == 1) {
			continue;
		}
		else {
			return i;
			break;
		}
	}
	return (ins->nbEpreuves - 1);
}

int nb_eq_ins(Inscrits* ins) {
	return ((ins->nbInscrits) / MAX_EQUIPIERS);
}