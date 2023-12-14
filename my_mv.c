#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int my_mv() {
    char nom_arxiu[250], nou_arxiu[250];
    char linia[250];

    printf("Introdueix el nom de l'arxiu: ");
    scanf("%s", nom_arxiu);
    printf("Introdueix el nou nom/lloc de l'arxiu: ");
    scanf("%s", nou_arxiu);

    int orig = open(nom_arxiu, O_RDONLY);
    int desc = open(nou_arxiu, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

    if (orig < 0) {
        perror("Error al obrir l'arxiu (l'arxiu no existeix)");
        return 1;
    }
    if (desc < 0) {
        perror("Error al crear el nou arxiu");
        return 1;
    } else {
        while (read(linia, sizeof(linia), orig) != NULL) {
            write(desc, linia, strlen(linia));
        }
    }

    close(orig);
    close(desc);
    unlink(nom_arxiu);


    return 0;
}
