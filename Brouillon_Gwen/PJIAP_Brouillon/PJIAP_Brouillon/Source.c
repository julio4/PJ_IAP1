#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* FONCTIONS */

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

int main() {
	int on = 1;
	int t = 0;
	int n = 0;
	char stop = ' ';
	while (on) {
		//definir_parcours 2 
		scanf("definir_parcours %d", &t);
		printf("\nYES %d\n", t);
		//definir_parcours(t);

		//definir_nombre_épreuves 2
		//scanf("definir_nombre_épreuves %d", &n);
		
		//exit
		//scanf("exi%c", &stop);
		//if (stop == 't') {
		//	on = 0;
		//}
		on = 0;
	}
	system("pause");
	return 0;
}