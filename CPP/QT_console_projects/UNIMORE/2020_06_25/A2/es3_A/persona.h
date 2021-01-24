#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <vector>

using namespace std;

class Persona
{
    public:
        Persona();
        int giovane(vector <int>);

    private:
        vector <string> nome, cognome;
        vector <int> anno;
        int pos, amin;

};

#endif // PERSONA_H
