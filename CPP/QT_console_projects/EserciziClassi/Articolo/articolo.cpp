#include "articolo.h"

Articolo::Articolo(std::string d, std::string m, float p, float s) {
	descrizione = d;
	marca = m;
	prezzo = p;
	sconto = s;
}

float Articolo::getPrezzo() { 
	
	return	prezzo * (100-sconto)/100;
}

