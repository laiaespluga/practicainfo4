#include <stdio.h> //Afegim les biblioteques corresponents que utilitzarem durant el programa
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int my_head() { //Definim la funció 'my_head' que retornarà un enter
  char linia[250], caracter; //Declarem un array de 250 elements de tipus 'char' per emmagatzemar el nombre de l'arxiu i un caràcter pels caràcters llegits. 
  int nombre_linies; //Declarem una variable de tipus enter per emmagatzemar el nombre de linies que s'imprimiran

  printf("Introdueix el nom de l'arxiu: "); //Mostra per pantalla a l'usuari un missatge per demanar el nom de l'arxiu i el número de línies que volem imprimir
  scanf("%s", linia);
  printf("Introdueix el nombre de linies: ");
  scanf("%d", &nombre_linies); //Apliquem la comanda 'scanf' per llegir els valors des de l'entrada estàndard 

  int arxiu = open(linia, O_RDONLY); //Apliquem la comanda 'open' per obrir l'arxiu en mode lectura, el resultant s'emmagatzema dins la variable arxiu

  if (arxiu < 0) { //Verifica si hi ha algún error en l'obertura de l'arxiu
    perror("Error al obrir l'arxiu (l'arxiu no existeix)"); //Mostra per pantalla el missatge d'error aplicant la comanda 'perror'
    return 1; //Retorna 1 indicant l'error
  }

  if (nombre_linies <= 0) { //Verifica si el nombre de linies no és positiu
    perror("Nombre de línies negatiu o zero"); //Mostra per pantalla el missatge d'error aplicant la comanda 'perror'
    return 1; //Retorna 1 indicant l'error 
  } else { //Si no hi ha cap error, procedim a llegir e imprimir les linies
    while ((nombre_linies > 0) && (read(arxiu, &caracter, 1) != 0)) { //Utilitzem el bulce while per llegir els caràcters de l'arxiu i mostrar-los en sortida estàndard 
      if (caracter == '\n') { //Si el caràcter llegit és un salt de línia es redueix el nombre de línies restants
        printf("\n");
        nombre_linies--;
      } else { //Si no és un salt de línia, es mostra per pantalla el caracter llegit
        printf("%c", caracter);
      }
    } //El bucle quan s'arriba al nombre de línies especificat o s'arriba al final de l'arxiu
    close(arxiu); //Tanquem l'arxiu amb la comanda 'close'
    return 0; //Retorna 0 indicant que s'ha executat correctament el programa 
  }
}
