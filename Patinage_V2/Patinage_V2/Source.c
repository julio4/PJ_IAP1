#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

enum MAX {MAX_TOURS = 10, MAX_EPREUVES = 16, MAX_EQUIPES = 32, MAX_PATINEURS = 50};
enum P {nbPatineurs = 50};
enum MOT {MAX_MOT = 30};

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

int main() {
	Patineur p[MAX_PATINEURS];
	Equipe e[MAX_EQUIPES];
	e[0].dataPatineurs[0].dossard = 1;
	printf("%d", e[0].dataPatineurs[0].dossard);
}

void inscription() {

}