#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include <string>

class Automobile {

    public:
        Automobile(std::string, std::string, float v, int km);
        float getPrezzo();
        void cambia(std::string);
        int getMarcia();

    private:
        float prezzo;
        int kilometri;
        int marcia;
        std::string descrizione, marca;

};

#endif // AUTOMOBILE_H
