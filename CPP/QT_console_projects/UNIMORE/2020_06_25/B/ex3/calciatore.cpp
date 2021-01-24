#include "calciatore.h"

Calciatore::Calciatore(std::string n, std::string c, std::string naz) {
	nome = n;
	cognome = c;
	nazione = naz;
	annonascita = 2000;
	partitegiocate = 0;
	goal = 0;
}

void Calciatore::setGoal(int g) {
	goal = g;
}
void Calciatore::setPartiteGiocate(int p) {
	partitegiocate = p;
}
void Calciatore::setAnnoNascita(int a) {
	annonascita = a;
}

float Calciatore::getMedia()
{
    return float(goal)/partitegiocate;
}
