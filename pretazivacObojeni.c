#include <stdio.h>
#include <string.h>

#define CRVENILO "\033[0;31m"
#define RESET "\033[0m"

int main(int argc, char *argv[]) {
    char red[200];    // unos linije teksta
    if (argc != 3) {
      fprintf(stderr, "Kako koristiti fju?: %s <trazena rec> <ime fajla>\n", argv[0]);
    return 1;
    }
    char *trazenaRec = argv[1];
    char *imeFajla = argv[2];

    FILE *datoteka = fopen(imeFajla, "r");
    if (datoteka == NULL) {
        printf("Nemoguće otvoriti datoteku.\n");
        return 1;
    }

    printf("Rezultati pretrage:\n");

    int brojReda = 1; // Broj trenutne linije
    while (fgets(red, sizeof(red), datoteka)) {
        if (strstr(red, trazenaRec) != NULL) {
            printf("Linija %d: ", brojReda);

            char *found = strstr(red, trazenaRec);
            while (found != NULL) {
                // Ispisujem sve reci pre pronadjene
                fwrite(red, 1, found - red, stdout);

                // Ovde bojim rec u crveno
                printf(CRVENILO);
                fwrite(found, 1, strlen(trazenaRec), stdout);
                printf(RESET);

                //kopiram ostatak reda
                strcpy(red, found + strlen(trazenaRec));

                //ako postoji novo pojavljivanje trazene reci, ovde ce se sacuvati i while petlja ce se nastaviti
                found = strstr(red, trazenaRec);
            }

            // Ispisujem liniju obojeno
            printf("%s", red);
        }

        brojReda++;
    }
	
    fclose(datoteka);

    return 0;
}
