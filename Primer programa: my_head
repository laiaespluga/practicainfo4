#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int my_head() {
  char linia[250], caracter;
  int nombre_linies;

  printf("Introdueix el nom de l'arxiu: ");
  scanf("%s", linia);
  printf("Introdueix el nombre de linies: ");
  scanf("%d", &nombre_linies);

  int arxiu = open(linia, O_RDONLY);

  if (arxiu < 0) {
    perror("Error al obrir l'arxiu (l'arxiu no existeix)");
    return 1;
  }

  if (nombre_linies <= 0) {
    perror("Nombre de línies negatiu o zero");
    return 1;
  } else {
    while ((nombre_linies > 0) && (read(arxiu, &caracter, 1) != 0)) {
      if (caracter == '\n') {
        printf("\n");
        nombre_linies--;
      } else {
        printf("%c", caracter);
      }
    }
    close(arxiu);
    return 0;
  }
}
