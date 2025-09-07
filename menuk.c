#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "debugmalloc.h"

#include "menuk.h"
#include "egyeb.h"
#include "kereses.h"

void elso_menu(tel *fej){

    printf("Rekord letrehozasa\n");

    tel *akt = tel_letrehozas();

    printf("Kilepes (Vezeteknev: 0), utana nem lesz ra alkalma!\n"); //Kilépés 0-val
    printf("Vezeteknev: ");
    scanf("%15s", akt->v_nev);
    if (strcmp(akt->v_nev, "0") == 0) {
        tel_lista_felszabaditas(akt); //Felszabadítás
        system("cls");
        printf("Rekord letrehozasa megszakitva.\n");
        return;
    }
    while (getchar() != '\n');
    printf("Keresztnev: ");
    scanf("%15s", akt->k_nev);
    while (getchar() != '\n');

    strcpy(akt->nev, akt->v_nev);
    strcat(akt->nev, " ");
    strcat(akt->nev, akt->k_nev);

    printf("Cim: ");
    scanf("%20s", akt->cim);
    while (getchar() != '\n');
    printf("Foglalkozas: ");
    scanf("%15s", akt->foglalkozas);
    while (getchar() != '\n');
    printf("Kor: ");
    while (true) {
        int temp_kor;  // ideiglenes változó az életkor tárolásához
        if (scanf("%d", &temp_kor) == 1) {
            if (temp_kor < 0 || temp_kor > 100) {
                printf("Hibas bemenet! Kerek egy egesz szamot 0 es 100 kozott: ");
            } else {
                akt->kor = temp_kor;  // Módosítjuk az életkort csak, ha a felhasználó érvényes értéket adott meg
                break;
            }
        } else {
            printf("Hibas bemenet! Kerek egy egesz szamot: ");
            while (getchar() != '\n');
        }
    }
    //Módosítás
    printf("Telefonszam: ");
    char temp_tel[12];
    while (true) {
        if (scanf("%11s", temp_tel) == 1) {
            // Ellenőrizzük, hogy a bemenet "érvényes szám-e"
            int valid = 1;
            for (int i = 0; temp_tel[i] != '\0'; i++) {
                if (temp_tel[i] < '0' || temp_tel[i] > '9') {
                    valid = 0;
                    break;
                }
            }
            if (valid && strlen(temp_tel) == 11) {
                strcpy(akt->tel, temp_tel);
                break;
            } else {
                printf("Hibas telefonszam! Kerek egy 11 jegyu telefonszamot: ");
            }
        } else {
            printf("Hibas bemenet! Kerek egy egesz szamot: ");
            while (getchar() != '\n');
        }
    }
    //akt->valos = 'V';
    akt->kov = NULL;

    while (fej->kov != NULL) fej = fej->kov;
    fej->kov = akt;

    system("cls");
    printf("Rekord letrehozva\n");
}

void masodik_menu(tel *fej){

    int rekord_megvalasztas;
    int rekord_szam = 1;
    tel *akt = fej;
    while (akt != NULL) {
        listazas(akt, rekord_szam);
        rekord_szam++;
        akt = akt->kov;
    }


    // Módosítjuk a kiválasztott rekordot
    printf("Rekord modositas\n");
    printf("Adja meg a modositani kivant rekord sorszamat (Kilepes = 0): ");
    while (true) {
        if (scanf("%d", &rekord_megvalasztas) == 1) {
            if (rekord_megvalasztas == 0) {
                system("cls");
                return;  // Kilépés, ha a felhasználó 0-t választ
            } else if (rekord_megvalasztas > 0 && rekord_megvalasztas <= rekord_szam - 1) {
                break;  // Jó választás esetén kilép a ciklusból
            } else {
                printf("Hibas bemenet! Kerek egy egesz szamot a 1 - %d tartomanyban: ", rekord_szam - 1);
            }
        }
    }

    system("cls");

    akt = fej;
    int aktualis_rekord = 1;

    while (aktualis_rekord != rekord_megvalasztas) {
        akt = akt->kov;
        aktualis_rekord++;
    }
    for (int i = 0; i < 83; i++)
        printf("-");
    printf("\n");
    printf("Jelenlegi adatok a rekordhoz:\n");
    printf("Nev: %s %s\n", akt->v_nev, akt->k_nev);
    printf("Cim: %s\n", akt->cim);
    printf("Foglalkozas: %s\n", akt->foglalkozas);
    printf("Kor: %d\n", akt->kor);
    printf("Telefonszam: %.*s\n", 11, akt->tel);

    for (int i = 0; i < 83; i++)
        printf("-");

    printf("\n");
    printf("Adja meg az uj adatokat:\n");
    printf("(Ha nem szeretned modositani akkor irj be egy '0'-t)\n");

    char input[20];

    printf("Vezeteknev: ");
    scanf("%15s", input);
    while (getchar() != '\n');

    if (strcmp(input, "0") != 0) {
        strcpy(akt->v_nev, input);
    }

    printf("Keresztnev: ");
    scanf("%15s", input);
    while (getchar() != '\n');
    if (strcmp(input, "0") != 0) {
        strcpy(akt->k_nev, input);
    }

    strcpy(akt->nev, akt->v_nev);
    strcat(akt->nev, " ");
    strcat(akt->nev, akt->k_nev);

    printf("Cim: ");
    scanf("%20s", input);
    while (getchar() != '\n');
    if (strcmp(input, "0") != 0) {
        strcpy(akt->cim, input);
    }

    printf("Foglalkozas: ");
    scanf("%15s", input);
    while (getchar() != '\n');
    if (strcmp(input, "0") != 0) {
        strcpy(akt->foglalkozas, input);
    }

    printf("Kor: ");
    while (true) {
        int temp_kor;  // ideiglenes változó az életkor tárolásához
        if (scanf("%d", &temp_kor) == 1) {
            if (temp_kor == 0) {
                // Nem módosítjuk a kort, hagyjuk az eredeti értéket
                break;
            } else if (temp_kor < 0 || temp_kor > 100) {
                printf("Hibas bemenet! Kerek egy egesz szamot 0 es 100 kozott: ");
            } else {
                akt->kor = temp_kor;  // Módosítjuk az életkort csak, ha a felhasználó érvényes értéket adott meg
                break;
            }
        } else {
            printf("Hibas bemenet! Kerek egy egesz szamot: ");
            while (getchar() != '\n');
        }
    }

    //Módosítás
    printf("Telefonszam: ");
    char temp_tel[12]; // Ideiglenes változó a telefonszám karakterláncként való tárolására
    while (true) {
        if (scanf("%11s", temp_tel) == 1) {
            if (strcmp(temp_tel, "0") == 0) {
                break;
            }
            // Ellenőrizzük, hogy a bemenet "érvényes szám-e"
            int valid = 1;
            for (int i = 0; temp_tel[i] != '\0'; i++) {
                if (temp_tel[i] < '0' || temp_tel[i] > '9') {
                    valid = 0;
                    break;
                }
            }
            if (valid && strlen(temp_tel) == 11) {
                strcpy(akt->tel, temp_tel);
                break;
            } else {
                printf("Hibas telefonszam! Kerek egy 11 jegyu telefonszamot: ");
            }
        } else {
            printf("Hibas bemenet! Kerek egy egesz szamot: ");
            while (getchar() != '\n');
        }
    }

    //Módosítás
    //akt->valos = 'V';
    /*printf("Valos (V) vagy Torolt (T) rekord? ");
    while (true) {
        char input_char;
        scanf(" %c", &input_char);
        if (input_char == 'V' || input_char == 'T') {
            akt->valos = input_char;
            break;
        } else {
            printf("Hibas bemenet! Kerek egy 'V' vagy 'T' karaktert: ");
            while (getchar() != '\n');
        }
    }*/
    system("cls");
    printf("Rekord modositva!\n");

}

void harmadik_menu(tel **fej) {
    int rekord_megvalasztas;
    int rekord_szam = 1;
    tel* akt = *fej;
    tel* elozo = NULL;

    while (akt != NULL) {
        listazas(akt, rekord_szam);
        rekord_szam++;
        akt = akt->kov;
    }
    printf("\nRekord torlese\n");
    printf("Adja meg a torlesre kivant rekord sorszamat (Kilepes = 0): ");
    while (true) {
        while (getchar() != '\n');  // Tisztítja a bemeneti (p/b)uffert
        if (scanf("%d", &rekord_megvalasztas) == 1) {
            if (rekord_megvalasztas == 0) {
                system("cls");
                return;  // Kilépés, ha a felhasználó 0-t választ
            } else if (rekord_megvalasztas > 0 && rekord_megvalasztas < rekord_szam) {
                // Helyes választás esetén törlés
                break;
            } else {
                printf("Hibas bemenet! Kerek egy egesz szamot 1 - %d tartomanyban: ", rekord_szam - 1);
            }
        }
    }

    // Kiválasztott rekord megkeresése
    akt = *fej;
    for (int i = 1; i < rekord_megvalasztas; i++) {
        elozo = akt;
        akt = akt->kov;
    }

    // Ha az első rekordot kell törölni
    if (elozo == NULL) {
        *fej = akt->kov;  // Fej frissítése
    } else {
        elozo->kov = akt->kov;  // Az előző rekord mutatójának frissítése
    }

     // Felszabadítjuk a memóriát a törölt elem számára
    tel_felszabaditas(akt);


    system("cls");
    printf("Rekord torolve!\n");
}

void negyedik_menu(tel *fej){
    int kereses_opcio;

    // Keresési opciók megjelenítése
    while (true) {
        kereses_opcio = 0;

        for (int i = 0; i < 60; i++)
            printf("_");

        printf("\n%31s", "Kereses\n\n");
        printf("%43s", "Valasszon keresesi opciot:\n\n");
        printf("%30s", "1 - Listazas\n");
        printf("%33s", "2 - Nev alapjan\n");
        printf("%41s", "3 - Foglalkozas alapjan\n");
        printf("%41s", "4 - Telefonszam alapjan\n");
        printf("%48s", "5 - Nev es telefonszam alapjan\n");
        printf("%39s", "6 - Vissza a fomenube\n");
        for (int i = 0; i < 60; i++)
            printf("_");

        printf("\nValaszlehetoseg: ");
        if (scanf("%d", &kereses_opcio) != 1) {
            printf("Ervenytelen bemenet! Kerem, adjon meg egy szamot.\n");
            while (getchar() != '\n');
            continue;
        }
        system("cls");

        switch (kereses_opcio) {
            case 1:
                {
                tel *akt = fej;
                for (int rekord_szam = 1; akt != NULL; rekord_szam++) {
                    listazas(akt, rekord_szam);
                    akt = akt->kov;
                }
                break;
                }
            case 2:
                nev_alapjan_kereses(fej);
                break;
            case 3:
                foglalkozas_alapjan_kereses(fej);
                break;
            case 4:
                telefonszam_alapjan_kereses(fej);
                break;
            case 5:
                nev_es_telefonszam_alapjan_kereses(fej);
                break;
            case 6:
                return;
            default:
                printf("Ervenytelen valasz!\n");
                break;
        }
    }
}

void otodik_menu(tel *fej){

    int rekord_szam = 1;
    // Kiírás
    tel *akt = fej;
    while (akt != NULL) {
        listazas(akt, rekord_szam);
        rekord_szam++;
        akt = akt->kov;
    }

    // Választás a felhasználótól, hogy melyik rekordból készüljön vCard
    int rekord_megvalasztas;
    printf("Adja meg a vCard kesziteshez kivant rekord szamat (Kilepes = 0): ");
    while (true) {
        if (scanf("%d", &rekord_megvalasztas) == 1) {
            if (rekord_megvalasztas == 0) {
                system("cls");
                return;  // Kilépés, ha a felhasználó 0-t választ
            } else if (rekord_megvalasztas > 0 && rekord_megvalasztas <= rekord_szam - 1) {
                // Elérjük a kiválasztott rekordot
                tel* akt = fej;
                for (int i = 1; i < rekord_megvalasztas; i++) {
                    akt = akt->kov;
                }
                vCard_keszit(akt);
                break;  // Kilépés a ciklusból jó választás esetén
            } else {
                printf("Hibas bemenet! Kerek egy egesz szamot a 1 - %d tartomanyban: ", rekord_szam - 1);
            }
        } else {
            printf("Hibas bemenet! Kerek egy egesz szamot.\n");
            while (getchar() != '\n');  // Tisztítjuk a hibás karaktereket a bemeneti bufferbõl
        }
    }
}
