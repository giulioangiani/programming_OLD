#ifndef ARTICOLO_H
#define ARTICOLO_H
#include <string>

class Articolo {

    public:
        Articolo(std::string, std::string, float, float);
        float getPrezzo();

    private:
        float prezzo, sconto;
        std::string descrizione, marca;

};

#endif // ARTICOLO_H
