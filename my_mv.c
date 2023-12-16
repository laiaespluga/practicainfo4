#include <stdio.h> //Afegim les biblioteques corresponents que utilitzarem durant el programa
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() { //Definim la funció principal
  char buffer[406]; //Declarem un array de tipus 'buffer' per emmagatzemar dades temporals
  char nom_arxiu[250], nou_arxiu[250]; //Declarem dos arrays de tipus 'char' per emmagatzemar els noms de l'arxiu original i el nou arxiu
  ssize_t bytesLlegits; //Variable que emmagatzema el número de bytes llegits d'un fitxer

    printf("Introdueix el nom de l'arxiu: "); //Demanem a l'usuari que introdueixi el nom de l'arxiu
    scanf("%s", nom_arxiu);
    printf("Introdueix el nou nom/lloc de l'arxiu: "); //Demanem a l'usuari que introdueixi el nou nom o el lloc de l'arxiu
    scanf("%s", nou_arxiu);

   int desc = open(nou_arxiu, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU); //Obrim l'arxiu amb permisos de lectura, escriptura i execució per l'usuari
   if (desc == -1) { //Si hi ha hagut un error al obrir l'arxiu, mostra un missatge d'error i acaba el programa
        perror("Error al crear el nou arxiu.");
        return;
      }
    int descArxiuOriginal = open(nom_arxiu, O_RDONLY); //Obrim l'arxiu original en mode lectura
    if (descArxiuOriginal == -1) { //Si hi ha hagut un error al obrir l'arxiu, mostra un missatge d'error, tanca l'arxiu i acaba el programa
      perror("Error a l'obrir l'arxiu original");
      close(desc);
          return;
      }
  
    while ((bytesLlegits = read(descArxiuOriginal, buffer, sizeof(buffer))) > 0) { //Utilitzem el bucle while per llegir les dades del fitxer original i escriure-les al nou arxiu
      write(desc, buffer, bytesLlegits);
    }

  close(descArxiuOriginal); //Després de completar la còpia tanquem els dos arxius
  close(desc);

  if (unlink(nom_arxiu) == -1) { //Utilitzem la comanda 'unlink' per eliminar l'arxiu original
      perror("Error al borrar l'arxiu original"); //Si hi ha un error es mostra per pantalla un missatge d'error
  }

  printf("L'arxiu ha estat mogut."); //Si no hi ha hagut cap error, es mostra per pantalla que el programa s'ha completat correctament

}
