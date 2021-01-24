#include "automobile.h"

Automobile::Automobile(std::string d, std::string m, float p, int km) {
	descrizione = d;
	marca = m;
	prezzo = p;
	kilometri = km;
	marcia = 0;
}

float Automobile::getPrezzo() { 
	return	prezzo - 1000*(kilometri/10000);
}

void Automobile::cambia(std::string tipo) {
	if (tipo == "UP") {
		marcia++;
	}
	if (tipo == "DOWN") {
		marcia--;
	}
	if (marcia < -1) marcia = -1; // minimo
	if (marcia > 6) marcia = 6; // massimo
}

int Automobile::getMarcia() {
	return marcia;
}

