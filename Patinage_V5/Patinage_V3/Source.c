#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


/* INITIALISATION CONSTANTES GLOBALES ET STRUCTURES*/


enum MAX { MAX_TOURS = 10, MAX_EPREUVES = 16, MAX_EQUIPES = 32, MAX_EQUIPIERS = 3, MAX_MOT = 30 }; //Constantes globales
enum INIT { PREMIER_DOSSARD = 101 - 1 };

//Structure Patineur: Nom du patineur + num�ro de dossard
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
void enregistrer_temps(Course* course);
void afficher_temps(const Course* course);
void afficher_temps_equipes(Inscrits* ins);


/*EXECUTION*/


int main() {

	/*INITIALISATION VARIABLES ET STRUCTURES*/

	char mot[MAX_MOT + 1];
	int parcours = 0;
	int epreuves = 0;
	Inscrits ins = { .nbInscrits = 0 };


	/*PROGRAMME*/


	while (1) { //Boucle infini tant que exit n'est pas appel�
		scanf("%s", mot); // A chaque it�ration de la boucle, la chaine de caract�re correspondant � une fonction est m�moris�e dans mot


		//Condition pour trouver la fonction correspondant � la chaine de caract�re entr�e dans mot
		//Un test de condition par fonction existante

		//Si mot = "fonction"
		//Alors lancer fonction()

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
		else if (strcmp(mot, "detection_fin_poursuite") == 0) {

		}
		else if (strcmp(mot, "detection_fin_competition") == 0) {

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


//Attribue � parcours la valeur entr�e apr�s la fonction definir_parcours
void definir_parcours(int* parcours) {
	scanf("%d", parcours);
}

//Attribue � �preuves la valeur entr�e apr�s la fonction definir_nombre_epreuves
void definir_nombre_epreuves(int* epreuves) {
	scanf("%d", epreuves);
}

//Inscrit une nouvelle equipe dans une structure Equipe : une variable 'equipe' par �quipe, accessible avec un num�ro d'�quipe
void inscrire_equipe(Inscrits* ins) {

	int nb_eq_inscrites = (ins->nbInscrits) / MAX_EQUIPIERS;
	static int dernier_dossard = PREMIER_DOSSARD; //initialise une variable correspondant au dernier dossard inscrit, avec comme valeur le num�ro du premier dossard 
	scanf("%s", ins->course->equipe[nb_eq_inscrites].pays); //Recup�re le pays de l'�quipe et le m�morise dans le membre 'pays' de la variable 'equipe'

	for (int i = 0; i < MAX_EQUIPIERS; ++i) { // Boucle qui permet d'inscrire n �quipiers pour l'�quipe, avec n = MAX_EQUIPIERS

		scanf("%s", ins->course->equipe[nb_eq_inscrites].dataPatineurs[i].nom); //Recup�re le nom et l'attribue dans le membre 'nom' de la sous-variable 'dataPatineurs' de la variable 'equipe'
		dernier_dossard++; //Incr�mente dernier_dossard pour obtenir le prochain dossard � �tre attribu� lors de l'inscription d'un joueur
		ins->course->equipe[nb_eq_inscrites].dataPatineurs[i].dossard = dernier_dossard; //Attribue au nom nouvellement inscrit ce num�ro de dossard 
		printf("inscription dossard %d\n", ins->course->equipe[nb_eq_inscrites].dataPatineurs[i].dossard); //Affiche un message confirmant l'inscription du dossard
		ins->nbInscrits += 1;
	}

}

//Permet d'afficher le Pays, et les joueurs suivis de leurs dossards pour chaque �quipe inscrite
void afficher_equipes(const Inscrits* ins) {

	//int nb_eq_inscrites = init_nb_eq_inscrites(0); //R�cup�re le nombre d'�quipe inscrite
	int nb_eq_inscrites = (ins->nbInscrits) / MAX_EQUIPIERS;

	for (int i = 0; i < nb_eq_inscrites; ++i) { //Boucle qui permet d'afficher une �quipe par it�ration, qui s'execute n fois avec n = 'nb_eq_inscrites'

		printf("%s ", ins->course->equipe[i].pays); // Affiche le pays de l'�quipe
		for (int j = 0; j < MAX_EQUIPIERS; ++j) { //Boucle qui affiche un co�quiper suivi de son dossard corespond, qui s'execute n fois avec n = 'MAX_EQUIPIERS' par �quipe
			printf("%s ", ins->course->equipe[i].dataPatineurs[j].nom); //Affiche le nom du joueur
			printf("%d", ins->course->equipe[i].dataPatineurs[j].dossard); //Affiche le num�ro de dossard associ� au joueur

			//Condition qui emp�che l'affichage d'un espace apr�s l'affichage de la derni�re �quipe
			if (i == (nb_eq_inscrites - 1) && j == (MAX_EQUIPIERS - 1)) {
				continue;
			}
			printf(" ");
		}
	}
}


void enregistrer_temps(Course* course) {
	//dossard
	int dossard;
	scanf("%d", &dossard);
	int numero_equipe = (dossard - 101) / 3;
	int numero_joueur = ((dossard - 101) % 3);

	//tour
	scanf("%d", &course->equipe[numero_equipe].dataPatineurs[numero_joueur].tour);

	//temps
	scanf("%lf", &course->equipe[numero_equipe].dataPatineurs[numero_joueur].temps[(course->equipe[numero_equipe].dataPatineurs[numero_joueur].tour) - 1]);
} 

void afficher_temps(Course* course) {
	int dossard;
	scanf("%d", &dossard);
	int numero_equipe = (dossard - 101) / 3;
	int numero_joueur = ((dossard - 101) % 3);

	for (int i = 0; i < (course->equipe[numero_equipe].dataPatineurs[numero_joueur].tour); ++i) {
		printf("%s ", course->equipe[numero_equipe].pays);
		printf("%d ", (i+1));
		printf("%s ", course->equipe[numero_equipe].dataPatineurs[numero_joueur].nom);
		printf("%.1f", course->equipe[numero_equipe].dataPatineurs[numero_joueur].temps[i]);
	}
}

void afficher_temps_equipes(Inscrits* ins) {

	int tour;
	scanf("%d", &tour);
	--tour; // d�cr�mente tour pour la position dans le tableau temps

	int nb_eq_inscrites = (ins->nbInscrits) / MAX_EQUIPIERS;

	for (int i = 0; i < nb_eq_inscrites; ++i) {
		double a = ins->course->equipe[i].dataPatineurs[0].temps[tour]; //initialise a, b, et c pour �viter les longues lignes de structures dans les conditions
		double b = ins->course->equipe[i].dataPatineurs[1].temps[tour]; //--> Mais prend de la place dans la m�moire donc peut etre a supprimer
		double c = ins->course->equipe[i].dataPatineurs[2].temps[tour]; //Donc a voir si rentable ou pas
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
			printf("indisponible\n");
		}
		printf("\n");
	}
}