#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


/* INITIALISATION CONSTANTES GLOBALES ET STRUCTURES*/


enum MAX { MAX_TOURS = 10, MAX_EPREUVES = 16, MAX_EQUIPES = 32, MAX_EQUIPIERS = 3, MAX_MOT = 30 }; //Constantes globales
enum INIT { PREMIER_DOSSARD = 101 - 1 };

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
	int numEq;
	int dernierPatineur;
}Equipe;


typedef struct {
	Equipe equipe[MAX_EQUIPES];
	unsigned int fini;
}Course;


typedef struct {
	unsigned int nbInscrits;
	Course course[MAX_EPREUVES];
	unsigned int nbParcours;
}Inscrits;


/*PROTOTYPES FONCTIONS*/


void definir_parcours(Inscrits* ins);
void definir_nombre_epreuves(int* epreuves);
void inscrire_equipe(Inscrits* ins);
void afficher_equipes(const Inscrits* ins);
void enregistrer_temps(Inscrits* ins);
void afficher_temps(const Course* course);
void afficher_temps_equipes(Inscrits* ins);
void detection_fin_poursuite(Inscrits* ins);


/*EXECUTION*/


int main() {

	/*INITIALISATION VARIABLES ET STRUCTURES*/

	char mot[MAX_MOT + 1];
	int epreuves = 0;
	Inscrits ins = { .nbInscrits = 0, .nbParcours = 0 };


	/*PROGRAMME*/


	while (1) { //Boucle infini tant que exit n'est pas appelé
		scanf("%s", mot); // A chaque itération de la boucle, la chaine de caractère correspondant à une fonction est mémorisée dans mot


		//Condition pour trouver la fonction correspondant à la chaine de caractère entrée dans mot
		//Un test de condition par fonction existante

		//Si mot = "fonction"
		//Alors lancer fonction()

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
			exit(0); //Permet de sortir de la boucle infini et finir le programme
		}

		printf("\n");
	}
}


/*FONCTIONS*/


//Attribue à parcours la valeur entrée après la fonction definir_parcours
void definir_parcours(Inscrits* ins) {
	scanf("%d", &ins->nbParcours);
}

//Attribue à épreuves la valeur entrée après la fonction definir_nombre_epreuves
void definir_nombre_epreuves(int* epreuves) {
	scanf("%d", epreuves);
}

//Inscrit une nouvelle equipe dans une structure Equipe : une variable 'equipe' par équipe, accessible avec un numéro d'équipe
void inscrire_equipe(Inscrits* ins) {

	int nb_eq_inscrites = (ins->nbInscrits) / MAX_EQUIPIERS;
	static int dernier_dossard = PREMIER_DOSSARD; //initialise une variable correspondant au dernier dossard inscrit, avec comme valeur le numéro du premier dossard 
	scanf("%s", ins->course->equipe[nb_eq_inscrites].pays); //Recupère le pays de l'équipe et le mémorise dans le membre 'pays' de la variable 'equipe'

	for (int i = 0; i < MAX_EQUIPIERS; ++i) { // Boucle qui permet d'inscrire n équipiers pour l'équipe, avec n = MAX_EQUIPIERS

		scanf("%s", ins->course->equipe[nb_eq_inscrites].dataPatineurs[i].nom); //Recupère le nom et l'attribue dans le membre 'nom' de la sous-variable 'dataPatineurs' de la variable 'equipe'
		dernier_dossard++; //Incrémente dernier_dossard pour obtenir le prochain dossard à être attribué lors de l'inscription d'un joueur
		ins->course->equipe[nb_eq_inscrites].dataPatineurs[i].dossard = dernier_dossard; //Attribue au nom nouvellement inscrit ce numéro de dossard 
		printf("inscription dossard %d\n", ins->course->equipe[nb_eq_inscrites].dataPatineurs[i].dossard); //Affiche un message confirmant l'inscription du dossard
		ins->nbInscrits += 1;
	}

}

//Permet d'afficher le Pays, et les joueurs suivis de leurs dossards pour chaque équipe inscrite
void afficher_equipes(const Inscrits* ins) {

	//int nb_eq_inscrites = init_nb_eq_inscrites(0); //Récupère le nombre d'équipe inscrite
	int nb_eq_inscrites = (ins->nbInscrits) / MAX_EQUIPIERS;

	for (int i = 0; i < nb_eq_inscrites; ++i) { //Boucle qui permet d'afficher une équipe par itération, qui s'execute n fois avec n = 'nb_eq_inscrites'

		printf("%s ", ins->course->equipe[i].pays); // Affiche le pays de l'équipe
		for (int j = 0; j < MAX_EQUIPIERS; ++j) { //Boucle qui affiche un coéquiper suivi de son dossard corespond, qui s'execute n fois avec n = 'MAX_EQUIPIERS' par équipe
			printf("%s ", ins->course->equipe[i].dataPatineurs[j].nom); //Affiche le nom du joueur
			printf("%d", ins->course->equipe[i].dataPatineurs[j].dossard); //Affiche le numéro de dossard associé au joueur

			//Condition qui empêche l'affichage d'un espace après l'affichage de la dernière équipe
			if (i == (nb_eq_inscrites - 1) && j == (MAX_EQUIPIERS - 1)) {
				continue;
			}
			printf(" ");
		}
	}
}


void enregistrer_temps(Inscrits* ins) {
	//dossard
	int dossard;
	scanf("%d", &dossard);
	int numero_equipe = (dossard - 101) / 3;
	int numero_joueur = ((dossard - 101) % 3);

	//tour
	scanf("%d", &ins->course->equipe[numero_equipe].dataPatineurs[numero_joueur].tour);

	//temps
	scanf("%lf", &ins->course->equipe[numero_equipe].dataPatineurs[numero_joueur].temps[(ins->course->equipe[numero_equipe].dataPatineurs[numero_joueur].tour) - 1]);

	detection_fin_poursuite(ins);
}

void afficher_temps(Course* course) {
	int dossard;
	scanf("%d", &dossard);
	int numero_equipe = (dossard - 101) / 3;
	int numero_joueur = ((dossard - 101) % 3);

	for (int i = 0; i < (course->equipe[numero_equipe].dataPatineurs[numero_joueur].tour); ++i) {
		printf("%s ", course->equipe[numero_equipe].pays);
		printf("%d ", (i + 1));
		printf("%s ", course->equipe[numero_equipe].dataPatineurs[numero_joueur].nom);
		printf("%.1f", course->equipe[numero_equipe].dataPatineurs[numero_joueur].temps[i]);
	}
}

void afficher_temps_equipes(Inscrits* ins) {

	int tour;
	(ins->course->fini) ? (tour = ins->nbParcours) : (scanf("%d", &tour));
	--tour; // décrémente tour pour la position dans le tableau temps

	int nb_eq_inscrites = (ins->nbInscrits) / MAX_EQUIPIERS;

	for (int i = 0; i < nb_eq_inscrites; ++i) {
		if (ins->course->equipe[i].dataPatineurs[0].temps[tour] > 0.0 && ins->course->equipe[i].dataPatineurs[1].temps[tour] > 0.0 &&
			ins->course->equipe[i].dataPatineurs[2].temps[tour] > 0.0) {
			printf("%s ", ins->course->equipe[i].pays);
			if (ins->course->equipe[i].dataPatineurs[0].temps[tour] < ins->course->equipe[i].dataPatineurs[1].temps[tour] ||
				ins->course->equipe[i].dataPatineurs[0].temps[tour] < ins->course->equipe[i].dataPatineurs[2].temps[tour]) {
				if (ins->course->equipe[i].dataPatineurs[1].temps[tour] < ins->course->equipe[i].dataPatineurs[2].temps[tour]) {
					printf("%.1f", ins->course->equipe[i].dataPatineurs[2].temps[tour]);

				}
				else {
					printf("%.1f", ins->course->equipe[i].dataPatineurs[1].temps[tour]);
				}
			}
			else {
				printf("%.1f", ins->course->equipe[i].dataPatineurs[0].temps[tour]);
			}
		}
		else {
			printf("indisponible\n");
		}
		printf("\n");
	}
}

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