#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "debugmalloc.h"

#include"lista.h"

tel* tel_letrehozas() {
    tel* uj_tel = (tel*)malloc(sizeof(tel));
    if (uj_tel == NULL) {
        perror("Memória foglalási hiba");
        exit(EXIT_FAILURE);
    }

    //Lefoglaljuk a memóriát
    uj_tel->v_nev = (char*)malloc(16 * sizeof(char));
    uj_tel->k_nev = (char*)malloc(16 * sizeof(char));
    uj_tel->nev = (char*)malloc(32 * sizeof(char));
    uj_tel->cim = (char*)malloc(21 * sizeof(char));
    uj_tel->foglalkozas = (char*)malloc(16 * sizeof(char));
    uj_tel->tel = (char*)malloc(12 * sizeof(char));
    uj_tel->kov = NULL;

    return uj_tel;
}

void tel_lista_felszabaditas(tel* fej) {

    //Felszabadítjuk a memóriát (rekurívan)
    if (fej != NULL) {
        if (fej->kov != NULL) tel_lista_felszabaditas(fej->kov);
        free(fej->v_nev);
        free(fej->k_nev);
        free(fej->nev);
        free(fej->cim);
        free(fej->foglalkozas);
        free(fej->tel);
        free(fej);
    }

}

void tel_felszabaditas(tel* rekord) {
    if (rekord != NULL) {
        //Szükséges a harmadik menühöz (nem működik rekurzívan)
        // Felszabadítjuk a memóriát
        free(rekord->v_nev);
        free(rekord->k_nev);
        free(rekord->nev);
        free(rekord->cim);
        free(rekord->foglalkozas);
        free(rekord->tel);
        free(rekord); // Felszabadítjuk magát a rekordot is
    }
}
