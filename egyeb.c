#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "debugmalloc.h"

#include "lista.h"
#include "egyeb.h"


void vCard_keszit(tel *akt) {
    FILE *vCardFile;
    char vCardFilename[50];

    // Vezetéknév és keresztnév összefűzése
    sprintf(vCardFilename, "%s_%s.vcf", akt->v_nev, akt->k_nev);

    // vCard fájl megnyitása
    vCardFile = fopen(vCardFilename, "w");
    if (vCardFile == NULL) {
        perror("Nem sikerult megnyitni a vCard fajlt");
    }

    // vCard adatok írása a fájlba
    fprintf(vCardFile, "BEGIN:VCARD\n");
    fprintf(vCardFile, "VERSION:3.0\n");
    fprintf(vCardFile, "FN:%s\n", akt->nev);
    fprintf(vCardFile, "ORG:%s\n", akt->foglalkozas);
    fprintf(vCardFile, "TEL:%s\n", akt->tel);
    //Plusz hozzáadás, illetve a kort nem lehet megadni
    //fprintf(vCardFile, "ADR:%s\n", akt->cim);
    fprintf(vCardFile, "END:VCARD\n");



    // Fájl bezárása
    fclose(vCardFile);

    system("cls");
    //Rajz módosítás
    printf("            _.._           \n");
    printf("     __.--\"\" __ \"--.__    \n");
    printf("   .'//   .-\"  \"-.   \\\\`,  \n");
    printf("  : :'  .'.  :;  ,`.  `; ; \n");
    printf(" /; ;  /  T. $$ ,P  \\  : : \n");
    printf("/: :  ;    T.:;,P    :  ; ;\n");
    printf(")| | :      `  '      ; | |\n");
    printf("`j | :.--------------.: | |\n");
    printf(" ; ; |                | : :\n");
    printf(" ; ; |  Nev           | : :\n");
    printf(" | | |  Foglalkozas   | | |\n");
    printf(" | | |  Telefonszam   | | |\n");
    printf(" : : |                | ; ;\n");
    printf(" : : :________________: ; ;\n");
    printf("  ; ;__    _...._    __: : \n");
    printf("  | ;  \"-./ ,--, \\,-\"  : | \n");
    printf("  | '._   \\ ;  : /   _.' | \n");
    printf("  :  __`-. `.\",\"' .-'__  ; \n");
    printf("   ;`.__> `.J__L.' <__.':  \n");
    printf("   ;.--._   .--.   _.--,:  \n");
    printf("   |`.__.' `.__.' `.__.'|  \n");
    printf("   |.--._   .--.   _.--,|  \n");
    printf("   |`.__.' `.__.' `.__.'|  \n");
    printf("   |.--._   .--.   _.--,|  \n");
    printf("   ;`.__.' `.__.' `.__.':  \n");
    printf("  : .--._   .--.   _.--, ; \n");
    printf("  ; `.__.' `.__.' `.__.' : \n");
    printf("  ;                      : \n");
    printf("  '--..__          __..--' \n");

    //Kiíratás
    for(int i=0; i<60; i++)
        printf("*");
    printf("\n");
    printf("Nev:%s\n",akt->nev);
    printf("Foglalozas:%s\n",akt->foglalkozas);
    printf("Telefonszam:%s\n",akt->tel);
    for(int i=0; i<60; i++)
        printf("*");
    printf("\n");

    printf("vCard letrehozva: %s\n", vCardFilename);
}

void listazas(tel *akt, int rekord_szam) {

     if (akt == NULL) {
        printf("Nincs mit megjeleniteni! A telefonkonyv ures.\n");
        return;  // Kilépünk a függvényből, nincs mit kiírni
    }

    // Kiírjuk a táblázat fejlécét
    if (rekord_szam == 1) {
    printf("\n");
    printf("%-12s", "Rekord:");
    printf("%-18s", "Nev:");
    printf("%-13s", "Cim:");
    printf("%-18s", "Foglalkozas:");
    printf("%-8s", "Kor:");
    printf("%s", "Telefonszam:\n");
    for (int i = 0; i < 83; i++)
        printf("-");
    printf("\n");
    }

    //Módosítás
    // Pirosra színezett kiíratás a törölt rekordok esetén
    /*if (akt->valos == 'T') {
        printf("\033[1;31m");
    }*/
    printf("| %-6d", rekord_szam);
    printf(" %-20s", akt->nev);
    printf(" %-14s ", akt->cim);
    printf(" %-15s ", akt->foglalkozas);
    printf(" %-5d ", akt->kor);
    printf(" %-10s |", akt->tel);
    printf("\033[0m");
    printf("\n");
    for (int i = 0; i < 83; i++)
        printf("-");
    printf("\n");
}
