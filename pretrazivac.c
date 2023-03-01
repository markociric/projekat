#include <stdio.h>
#include <string.h>

#define MAX_DUZINA_REDA 1024

int main(int argc, char *argv[]) {
    if (argc < 3 || argc>4) {
        fprintf(stderr, "Kako koristiti fju?: %s <trazena rec> <ime fajla>\n", argv[0]);
        return 1;
    }

    char *trazenaRec = argv[1];
    char *imeFajla = argv[2];

    FILE *file = fopen(imeFajla, "r");
    if (!file) {
        fprintf(stderr, "GRESKA! Ne moze da se otvori fajl %s\n", imeFajla);
        return 1;
    }

    char red[MAX_DUZINA_REDA];
    int brojReda = 0;
    while (fgets(red, MAX_DUZINA_REDA, file)) {
        brojReda++;
        if (strstr(red, trazenaRec)) {
            printf("%s:%d: %s", imeFajla, brojReda, red);
        }
    }

    fclose(file);

    return 0;
}
