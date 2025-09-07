#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "debugmalloc.h"

#include "menuk.h"
#include "lista.h"
#include "egyeb.h"

//Készítette: Kálmán Patrik
//Neptun kód: XG5YQ1
//Utolsó módosítás: 2024.11.22

//Források:
//InfoC
//https://infoc.eet.bme.hu/fajlkezeles/
//https://infoc.eet.bme.hu/scanf/
//https://infoc.eet.bme.hu/scanf_hibakezeles/
//https://infoc.eet.bme.hu/debugmalloc/
//https://infoc.eet.bme.hu/megjelenites/ itt nem használom a c-econio-t csak megnéztem ANSI escape kódokat milyen a piros szín
//https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a ANSI escape kódolás
//pl: printf("\033[1;31m"); itt \33 ANSI escape kódja , 1 az félkövér, a 31 a szöveg színe ami jelen esetben a piros
//https://docs.fileformat.com/hu/email/vcf/ itt a vCard
//https://en.wikipedia.org/wiki/VCard itt is vCard
//https://github.com/eventable/vobject itt is vCard
//https://www.asciiart.eu/ ->rajzok



//Főprogram
int main()
{
    //Rajz
    printf("              ,---------------------------,\n");
    printf("              |  /---------------------\\  |\n");
    printf("              | |                       | |\n");
    printf("              | |                       | |\n");
    printf("              | |      Elektronikus     | |\n");
    printf("              | |      Telefonkonyv     | |\n");
    printf("              | |                       | |\n");
    printf("              | |                       | |\n");
    printf("              |  \\_____________________/  |\n");
    printf("              |___________________________|\n");
    printf("            ,---\\_____     []     _______/------,\n");
    printf("          /         /______________\\           /|\n");
    printf("        /___________________________________ /  | ___\n");
    printf("        |                                   |   |    )\n");
    printf("        |  _ _ _                 [-------]  |   |   (\n");
    printf("        |  o o o                 [-------]  |  /    _)_  \n");
    printf("        |__________________________________ |/     /  /\n");
    printf("    ,-------------------------------------/|      ( )/\n");
    printf("   /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /   \n");
    printf("  /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /\n");
    printf("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    FILE *fp;
    //Leírás
    printf("Egyszeru elektronikus Telefonkonyv kezeles\n");
    printf("A programban a rekord egy telefonszamhoz tartozo tartalmakat tartalmaz, amely adatok \n");
    printf("Nev (vezeteknev, keresztnev), cim, foglalkozas, kor, telefonszam\n");
    printf("A program kezeles soran a feltuntetett, megjelenitett lehetosegeket biztositja\n");
    //Módosítás
    //printf("A program a torolt rekordokat piros szinnel kezeli\n");
    printf("A program nem hasznal ekezeteket");
    printf("\n \n");
    printf("Kezdhetjuk? (nyomjon 'Enter'-t a folytatashoz...)\n");
    while (getchar() != '\n');

    system("cls");

    fp = fopen("tel_.txt", "r");

    tel *fej = NULL, *akt = NULL;

     while (true) {
        tel* uj_tel = tel_letrehozas();
        int eredmeny = fscanf(fp, "%s %s %s %s %d %s", uj_tel->v_nev, uj_tel->k_nev, uj_tel->cim, uj_tel->foglalkozas, &uj_tel->kor, uj_tel->tel);
        if (eredmeny != 6) {
            tel_lista_felszabaditas(uj_tel);
            break;
        }
        else {
            strcpy(uj_tel->nev, uj_tel->v_nev);
            strcat(uj_tel->nev, " ");
            strcat(uj_tel->nev, uj_tel->k_nev);


            // Hozzáadjuk az aktot a láncolt listához
            if (fej == NULL) {
                fej = akt = uj_tel;
            }
            else {
                akt->kov = uj_tel;
                akt = akt->kov;
            }
        }
    }

    fclose(fp);


    //Menü részekre bontása
    int valasz;
    while(true)
    {
        valasz=0;
        for(int i=0; i<60; i++)
            printf("_");
        printf("\n");
        printf("%31s", "Fomenu\n\n");
        printf("%40s"," 1 - Rekord letrehozas \n");
        printf("%38s"," 2 - Rekord modositas\n");
        printf("%37s"," 3 - Rekord torlese \n");
        printf("%30s"," 4 - Kereses \n");
        printf("%28s"," 5 - vCard \n");
        printf("%30s"," 6 - Kilepes \n");
        for(int i=0; i<60; i++)
            printf("_");
        printf("\n");
        printf("Valaszlehetoseg: ");
        if (scanf("%d", &valasz) != 1)
        {
            printf("Hibas bemenet! Kerek egy egesz szamot.\n");
            while (getchar() != '\n');
            continue;
        }
        system("cls");
        switch(valasz)
        {
        case 1:
            elso_menu(fej);
            break;
        case 2:
            masodik_menu(fej);
            break;
        case 3:
            harmadik_menu(&fej);
            break;
        case 4:
            negyedik_menu(fej);
            break;
        case 5:
            otodik_menu(fej);
            break;
        case 6:
            //Kilépés után a fájlba írjuk az adatokat
            fp = fopen("tel_.txt", "w");
            tel *akt =  fej;
            while (akt->kov != NULL) {
                fprintf(fp, "%s %s %s %d %s\n", akt->nev, akt->cim, akt->foglalkozas, akt->kor, akt->tel);
                akt = akt->kov;
            }
            fprintf(fp, "%s %s %s %d %s\n", akt->nev, akt->cim, akt->foglalkozas, akt->kor, akt->tel);
            fclose(fp);
            //Felszabadítjuk a memóriát
            tel_lista_felszabaditas(fej);


            exit(0);
            break;
        default:
            printf("Ervenytelen valasz!\n");
            break;
        }
    }


    return 0;
}
