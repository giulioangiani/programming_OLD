#include "persona.h"

Persona::Persona(string n, string c, int a) 
{
	this->nome = n;
	this->cognome = c;
	this->anno = a;
}

int Persona::getAnno()
{
    return this->anno;
}

string Persona::getCognome() {
	return this->cognome;
}

string Persona::getNome() {
	return this->nome;
}

bool Persona::operator< (Persona other) {
	if (this->anno <= other.getAnno()) return true;
	else return false;
}

ostream& operator<<(ostream& os, Persona p) {
	os << "[" << p.getCognome() << " " << p.getNome() << " ]";
	return os;
}
