#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "debugmalloc.h"

#include "kereses.h"

bool osszehas(char egyik[], char masik[], int darab) {
    for (int i = 0; i < darab; i++)
        if (egyik[i] != masik[i]) return false;

    return true;
}

bool wildcardkeres(char keres[], char szo[]) {

    for (int i = 0; i < strlen(keres); i++) {
        if (keres[i] == '*') {
            // Ellenőrizzük, hogy a csillag után következő karakterek megfelelnek-e a 'szo' karakterláncnak
            if (!osszehas(keres, szo, i))
                return false;
            if (keres[i + 1] == '\0')
                return true;
            for (int a = i; a < strlen(szo); a++)
            // Rekurzívan hívjuk a wildcardkeres függvényt a következő karakterekkel
                if (wildcardkeres(&keres[i + 1], &szo[a]))
                    return true;
        }
    }

    if (!strcmp(keres, szo))
        return true;
    else
        return false;
}

void nev_alapjan_kereses(tel *akt) {
    char keresett_nev[31];
    int talalat = 0;

    printf("Adja meg a keresett nevet: ");
    scanf(" %[^\n]", keresett_nev);

    //Táblázat fejléce
    printf("\n%-20s %-14s %-15s %-5s %-10s\n", "Nev:", "Cim:", "Foglalkozas:", "Kor:", "Telefonszam:");
    for (int i = 0; i < 83; i++)
        printf("-");
    printf("\n");

    while (akt != NULL) {

        //Wildcard alapján keresés
        if (wildcardkeres(keresett_nev, akt->nev)) {
            printf("%-20s %-14s %-15s %-5d %-10s\n", akt->nev, akt->cim, akt->foglalkozas, akt->kor, akt->tel);
            for (int i = 0; i < 83; i++)
                printf("-");
            printf("\n");
            talalat = 1;
        }
        /*//Sima keresés
        if (strstr(akt->nev, keresett_nev) != NULL) {
            printf("%-20s %-14s %-15s %-5d %-10s\n", akt->nev, akt->cim, akt->foglalkozas, akt->kor, akt->tel);
            for (int i = 0; i < 83; i++)
                printf("-");
            printf("\n");
            talalat = 1;
        }*/

        akt = akt->kov;
    }
    // Ha nincs találat
    if (talalat == 0) {
        printf("Nincs talalat!\n");
    }
}

void foglalkozas_alapjan_kereses(tel *akt) {
    char keresett_foglalkozas[16];
    int talalat = 0;

    printf("Adja meg a keresett foglalkozast: ");
    scanf("%s", keresett_foglalkozas);

    //Táblázat fejléce
    printf("\n%-20s %-14s %-15s %-5s %-10s\n", "Nev:", "Cim:", "Foglalkozas:", "Kor", "Telefonszam:");
    for (int i = 0; i < 83; i++)
        printf("-");
    printf("\n");

    //Sima keresés
    while (akt != NULL) {
        if (strcmp(akt->foglalkozas, keresett_foglalkozas) == 0) {
            printf("%-20s %-14s %-15s %-5d %-10s\n", akt->nev, akt->cim, akt->foglalkozas, akt->kor, akt->tel);
            for (int i = 0; i < 83; i++)
                printf("-");
            printf("\n");
            talalat = 1;
        }
        akt = akt->kov;
    }
    // Ha nincs találat
    if (talalat == 0) {
        printf("Nincs talalat!\n");
    }
}

void telefonszam_alapjan_kereses(tel *akt) {
    char keresett_telefonszam[12];
    int talalat = 0;

    printf("Adja meg a keresett telefonszamot: ");
    scanf("%s", keresett_telefonszam);

    printf("\n%-20s %-14s %-15s %-5s %-10s\n", "Nev:", "Cim:", "Foglalkozas:", "Kor:", "Telefonszam:");
    for (int i = 0; i < 83; i++)
        printf("-");
    printf("\n");

    while (akt != NULL) {

        //Módosítás
        if (wildcardkeres(keresett_telefonszam, akt->tel)) {
            printf("%-20s %-14s %-15s %-5d %-10s\n", akt->nev, akt->cim, akt->foglalkozas, akt->kor, akt->tel);
            for (int i = 0; i < 83; i++)
                printf("-");
            printf("\n");
            talalat = 1;
        }
        akt = akt->kov;
    }
    // Ha nincs találat
    if (talalat == 0) {
        printf("Nincs talalat!\n");
    }
}

void nev_es_telefonszam_alapjan_kereses(tel *akt) {
    //Módosítás
    char keresett_nev[31];
    char keresett_telefonszam[12];
    int talalat = 0;

    printf("Adja meg a keresett nevet: ");
    scanf(" %[^\n]", keresett_nev);

    printf("Adja meg a keresett telefonszamot: ");
    scanf("%s", keresett_telefonszam);

    //Táblázat fejléce
    printf("\n%-20s %-14s %-15s %-5s %-10s\n", "Nev:", "Cim:", "Foglalkozas:", "Kor:", "Telefonszam:");
    for (int i = 0; i < 83; i++)
        printf("-");
    printf("\n");

    while (akt != NULL) {
        // Wildcard keresés név és telefonszám alapján
        bool nev_egyezik = wildcardkeres(keresett_nev, akt->nev);
        bool tel_egyezik = wildcardkeres(keresett_telefonszam, akt->tel);

        // Ha mindkettő megegyezik, kiíratjuk az adatokat
        if (nev_egyezik && tel_egyezik) {
            printf("%-20s %-14s %-15s %-5d %-10s\n", akt->nev, akt->cim, akt->foglalkozas, akt->kor, akt->tel);
            for (int i = 0; i < 83; i++)
                printf("-");
            printf("\n");
            talalat = 1;
        }

        akt = akt->kov;
    }
    // Ha nincs találat
    if (talalat == 0) {
        printf("Nincs talalat!\n");
    }
}



