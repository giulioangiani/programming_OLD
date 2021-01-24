#include "calciatore.h"

Calciatore::Calciatore()
{

}

void Calciatore::med(float g, float p)
{
    media =  g / p;
}

float Calciatore::getMed()
{
    return media;
}
