#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct tel {
    char *v_nev;
    char *k_nev;
    char *nev;
    char *cim;
    char *foglalkozas;
    int  kor;
    char *tel;
    struct tel *kov;
} tel;

tel* tel_letrehozas();
void tel_lista_felszabaditas(tel* fej);
void tel_felszabaditas(tel* rekord);


#endif // LISTA_H_INCLUDED
