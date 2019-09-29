#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* FONCTIONS */
/*
int definir_parcours() {
	return 1;
}

int inscrire_equipe() {
	return 1;
}

int afficher_equipe() {
	return 1;
}

int enregistrer_temps() {
	return 1;
}

int detection_fin_poursuite() {
	return 1;
}

int detection_fin_competition() {
	return 1;
}

int afficher_temps() {
	return 1;
}

int afficher_temps_equipe() {
	return 1;
}
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
		char* buf[100];


		while ( (scanf("%s %c", buf)) == 1  && (stop)) {
			printf("%s\n", buf);

			if (!strcmp(buf, "exit")) {
				stop = 0;
			}
		}


		/*

		//definir_parcours 2 
		scanf("definir_parcours %d", &t);

		//definir_nombre_épreuves 2
		scanf("definir_nombre_épreuves %d", &n);



		
		char equipes[2][7] = ""; //Par equipe : 1 Pays, 3 Noms + 3 dossarts
		nb_equipes = 2;

		//inscrire_equipe Canada Blondin Weidemann Morrison
		for (int i = 0; i < 2; ++i) {
			scanf("inscrire_equipe %s %s %s %s", &equipes[0][0], &equipes[0][1], &equipes[0][3], &equipes[0][5]);
			for (int j = 1; j < 5; ++j) {
				sprintf(no_dossart, "%d", dossart); // convertit int dossart en char no_dossart
				equipes[i][j + 1] = no_dossart; //mais sa marche pas
				printf("Inscription dossart %d\n", dossart);
				++dossart;
			}
			++nb_equipes;
		}

		//afficher_equipes
		scanf("afficher_equipe%c", &affichage);
		if (affichage == 's') {
			for (int i = 0; i < nb_equipes - 1; ++i) {
				printf("%s", equipes[i][0]); // Pays
				for (int j = 1; j < 5; ++j) {
					printf("%s %c", equipes[i][j], equipes[i][j + 1]); //Noms + dossarts
				}
			}
		}
		

		//exit
		scanf("exi%c", &stop);
		if (stop == 't') {
			on = 0;
		}

		*/

		system("pause");
		on = 0;
	}
	return 0;
}