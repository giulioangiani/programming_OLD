#ifndef CALCIATORE_H
#define CALCIATORE_H
#include <string>

class Calciatore
{
    public:
        Calciatore(std::string, std::string, std::string);
        void setGoal(int);
        void setPartiteGiocate(int);
        void setAnnoNascita(int);
        float getMedia();

    private:
        int goal, partitegiocate, annonascita;
        std::string nome, cognome, nazione;
};

#endif // CALCIATORE_H
