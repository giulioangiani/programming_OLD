#include "persona.h"

Persona::Persona()
{

}

int Persona::giovane(vector <int> a)
{
    for (int i = 0; i <= (int)a.size(); i++){
        if (amin < a[i]){
            amin = a[i];
            pos = i;
        }
    }

    return pos;
}
