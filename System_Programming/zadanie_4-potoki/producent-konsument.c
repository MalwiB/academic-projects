#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main() { 
  
  
  //Jeżeli rodzic chce otrzymywać dane od p. potomnego zamykamy filedes[1],a u potomka filedes[0].
  //Jeżeli ma być odwrotnie, rodzic zamyka filedes[0], a potomek zamyka filedes[1].
  
  int filedes[2];	//filedes[0]- czytanie(wejscie); filedes[1]- pisanie(koncowka wyjsciowa)
  char bufor[60];
  int i;
  

  
  FILE * magazyn;		//otwieranie pliku magazyn.txt funkcją fopen
  magazyn = fopen ("magazyn.txt","r");
  if (magazyn == NULL)		//obsluga bledow
  {
    perror("Blad otwierania pliku magazyn.txt");
    exit(1);
  }
  else
    printf("Plik 'magazyn.txt' otwarty pomyślnie!\n");
  
  
  if ((pipe(filedes)) == -1) {		//funkcja pipe- tworzenie potoku
    perror("Blad funkcji pipe");
    exit(2);
  }
  
  
  pid_t pid = fork();
  
  
  
  
  switch (pid) {

    
    case -1: {
      perror("Blad funkcji fork");
      exit(1);
    }

    
    case 0: {		//proces potomny
      if (close(filedes[1]) == -1) {		//zamykanie końcówki wyjściowej potoku
	perror("Błąd funkcji close");
	exit(1);
      }
      
      FILE * produkty;		//otwieranie pliku produkty.txt
      produkty = fopen ("produkty.txt","w");
      if (produkty == NULL)
      {
	perror("Blad otwierania pliku produkty.txt");
	exit(2);
      }
      else
	printf("Plik 'produkty.txt' otwarty pomyślnie!\n");
      
      while ((read(filedes[0], &bufor , 50)) > 0) {
	fprintf(produkty, &bufor);
	fprintf(produkty, " ");
	printf("Zapisano: ~~%s~~.\n", &bufor);
	sleep(2);
      }
      
      printf("Plik zostal zapisany!\n");
      
      if (fclose(produkty) == EOF) {
	perror("Błąd funkcji fclose");
	exit(3);
      }
      
      if (close(filedes[0]) == -1) {
	perror("Błąd funkcji close");
	exit(4);
      }
      
    }
    

    default: {		//w procesie macierzystym
      
      if (close(filedes[0]) == -1) {		//zamykanie końcowki wejściowej potoku
	perror("Błąd funkcji close");
	exit(1);
      }
      
      while(fscanf(magazyn, "%s", &bufor) != EOF) {		//zapisywanie do bufora tekstu z pliku
	if (write(filedes[1], &bufor, 50) == -1) {			//wypisywanie do potoku z bufora porcji bajtow tekstu w kazdej iteracji
	  perror("Błąd funkcji write");
	  exit(2);
	}
	printf("Produkt: ~~%s~~ wysłany.\n", &bufor);	//wypisywanie tekstu wyslanego do potoku
	sleep(1);					//czekanie 2
      }
  
  
      printf("Plik wysłany w calosci do potoku!\n");
      
      if (fclose(magazyn) == EOF) {
	perror("Błąd funkcji fclose");
	exit(3);
      }
	
      if (close(filedes[1]) == -1) {
	perror("Błąd funkcji close");
	exit(4);
      }
      
      wait(NULL);		//czekanie na proces potomny
  
    }
   
  }
  
  return 0;
}
