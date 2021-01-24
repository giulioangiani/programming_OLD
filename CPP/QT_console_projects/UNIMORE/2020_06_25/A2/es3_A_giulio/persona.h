#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <vector>

using namespace std;

class Persona
{
    public:
        Persona(string n, string c, int a);
        int getAnno();
        string getCognome();
        string getNome();
		bool operator< (Persona other);

    private:
        string nome, cognome;
        int anno;
};


#endif // PERSONA_H
