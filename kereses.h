#ifndef KERESES_H_INCLUDED
#define KERESES_H_INCLUDED

#include "lista.h"

void nev_alapjan_kereses(tel *fej);
void foglalkozas_alapjan_kereses(tel *fej);
void telefonszam_alapjan_kereses(tel *fej);
void nev_es_telefonszam_alapjan_kereses(tel *fej);
bool osszehas(char egyik[], char masik[], int darab);
bool wildcardkeres(char keres[], char szo[]);

#endif // KERESES_H_INCLUDED
