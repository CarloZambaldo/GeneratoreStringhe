#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 5
#define m 3

int main(){
    // apertura del file sul quale vado a scrivere
    FILE *buoni;
    buoni = fopen("buoni.txt", "a");
    if(buoni == NULL){
        printf("Impossibile aprire il file. Errore!");
        exit(1);
    }

    // generalita'
    srand(time(NULL));
    unsigned int i, j, r;
    char c[17];
    printf("Quanti buoni vuoi creare? ");
    scanf("%u", &j);
    fprintf(buoni, "\nStampo %u buoni.\n",j);

    // genero la stringa del buono
    for(r=0; r<j; r++){
        for(i=0; i<(n*m+2); i++){
            if(rand()%3==0){
                c[i]='0'+rand()%10;
            } else {
                c[i]='A'+rand()%23;
                if((c[i]>='A')&&(c[i]<='Z')&&(rand()%4==0)) // sostituisco
                    c[i]+=('a'-'A');
            }
            if((i==4) || (i==10)){  // metto il trattino dopo 5 caratteri
                i++;
                c[i]='-';
            }
        }
        
        // stampo il buono finto sul file
        for(i=0; i<(n*m+2); i++){
            fprintf(buoni, "%c", c[i]);
        }
        fprintf(buoni, "\n");
    }

    printf("I tuoi buoni sono stati stampati.");
    fclose(buoni);
    printf("\n\n");
    system("PAUSE");
    return 0;
}
