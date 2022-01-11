/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>
#include <sys/time.h>
#define PUNTEGGIO_MASSIMO 10000

 int risultato_tot;

typedef enum {addizione,sottrazione} operazione;

//funzione per stampare la guida 
void guida_comandi(){
    printf("Hey giocatore!\n Non so cosa ti spinge quì ma sei pronto per giocare a gioco per allenare la tua matematica, \n e quella nocciolina che hai in testa?\n si?\n Allora andiamo!\n TP:saranno 10 i quesiti sbrigati e farai più punti\n\n\n");
}
//funzione per il tasto per giocare 
void pulsante_per_giocare(){
    char tasto;
    printf("Vuoi iniziare a giocare? \nPremi s per iniziare altrimenti premi n per uscire\n");
    scanf("%1c", &tasto);
 if (tasto != 's'){   //tasto è diverso da s allora esci dal gioco
     exit(0);
}
}
//funzione per il conto alla rovescia
void conto_alla_rovescia(){
    for(int i=3; i >= 0; i--){
        printf("%d\n", i);
        sleep(1);
    }
}
//funzione per il punteggio 
long timer_punteggio()
{ struct  timeval time;
  gettimeofday(&time, NULL);
  return time.tv_sec *1000 + time.tv_usec / 1000;
}
//funzione per generare numeri casuali
void inizia_generatore(){
    time_t tempo;
    srand((unsigned) time(&tempo));
}
int genera_numero_casuale(int minimo, int massimo){
    int numcasuale= rand()%(massimo-minimo+1)+minimo; 
    return numcasuale;
} //fine funzione 

//generatore di espressioni 
int generatore_espressioni(){
        inizia_generatore();
        long start;
        long end;
        int risultato[10];  //dichiarazioni delle variabili
        int risultato_reale[10];
    int punteggio[10];
        

    for(int contatore= 0; contatore < 10; contatore++)
    {
        int addendo1 = genera_numero_casuale(-9,9);
        int addendo2 = genera_numero_casuale(-9,9);
        operazione simbolo = genera_numero_casuale(0,1);
        switch(simbolo)
        {
            case addizione:
            risultato_reale[contatore]=addendo1+addendo2;
            printf("\n%2d + %2d = ", addendo1, addendo2); //stampa l'espressione
            start = timer_punteggio(); //inizia timer per il punteggio 
            scanf("%3d", &risultato[contatore]);  //risposta che da l'utente
            end = timer_punteggio(); //finisce timer per il punteggio
            break;
            case sottrazione:
            risultato_reale[contatore]=addendo1-addendo2;
            printf("\n%2d - %2d = ",addendo1, addendo2);
             start = timer_punteggio();
            scanf("%3d", &risultato[contatore]);
             end = timer_punteggio();
            break;
        }
        printf("\n");
        if (risultato_reale[contatore] == risultato[contatore]){ //se il risultato del calcolatore è uguale a quello che l'utente da allora calcola il punteggio parziale 
            punteggio[contatore] = (end  - start ) < PUNTEGGIO_MASSIMO ? PUNTEGGIO_MASSIMO - (end  -  start) : 0;
            printf("Punteggio e'di %d punti\n", punteggio[contatore]);
        }
        else{
            punteggio[contatore]=0;
            printf("0\n");
        }      
    }
    //punteggio totale 
    risultato_tot= punteggio[0] + punteggio[1] + punteggio[2] +punteggio[3] + punteggio[4] + punteggio[5] + punteggio[6]+ punteggio[7] + punteggio[8] + punteggio[9];
    printf("\nil tuo punteggio totale e' di %d punti\n\n", risultato_tot);
}
//funzione per la lettura della classifica 
    struct riga_classifica {
    int id;
    char nickname[20];
    int punteggio;
};

int lettura_classifica(){
    FILE *infile;
    struct riga_classifica classifica[10];
    infile = fopen ("classifica.dat", "r"); //apri il file per leggere la classifica 
    if (infile == NULL)// se non c'è allora stampa un errore
    {
        fprintf(stderr, "\nErrore nell'aprire il file\n");
        exit(1);
    }
    int contatore = 0;

    while(fread(&classifica[contatore], sizeof(struct riga_classifica), 1, infile)) {
        printf ("id = %d name = %s punteggio = %d\n", classifica[contatore].id, classifica[contatore].nickname, classifica[contatore].punteggio);
        contatore++;
    }
    fclose(infile);
}
//funzione che mette in ordine la classifica 
void ordina_classifica(struct riga_classifica arr[], int n){
    int indice1, indice2;
    for(indice1 = 0; indice1 < n - indice1 - 1; indice1++){
    for(indice2 = 0;indice2 < n - indice1 - 1; indice2++){
        if(arr[indice2].punteggio < arr[indice2 + 1].punteggio)
        {
            struct riga_classifica riga_di_appoggio;
            riga_di_appoggio = arr[indice2];
            arr[indice2] = arr[indice2 + 1];
            arr[indice2 + 1] = riga_di_appoggio;   
        }
    }
}
}
//funzione con la classifica gia ordinata
int classifica_ordinata_salvata(){
    struct riga_classifica classifica[11];

    FILE *outfile;

    outfile = fopen("classifica.dat", "w");
    if(outfile == NULL){
        fprintf(stderr,"\nErrore nell'aprire il file\n");
        exit(1);
    }
    classifica[0] =(struct riga_classifica){1,"er sium", 90000};
    classifica[1] = (struct riga_classifica){2,"monky", 89901};
    classifica[2] = (struct riga_classifica){3,"arfred", 88264};
    classifica[3] = (struct riga_classifica){4,"lollo", 87923};
    classifica[4] = (struct riga_classifica){5,"zazza", 84848};
    classifica[5] = (struct riga_classifica){6,"ismael", 82749}; 
    classifica[6] = (struct riga_classifica){7,"makima", 80849};
    classifica[7] = (struct riga_classifica){8,"zero two", 76374};
    classifica[8] = (struct riga_classifica){9,"aaaa", 71731};
    classifica[9] = (struct riga_classifica){10,"baddy meu", 69893};
    classifica[10] = (struct riga_classifica){11,"newplayer",risultato_tot };
    
    if(classifica[10].punteggio > classifica[9].punteggio){ // se il punteggio del nuovo giocatore super quello del nono giocatore allora passa avanti e scrive il suo nome ed entra in classifica se non lo supera stampa che non è riuscito ad entrare
        printf("Daje!! sei forte tipo na cifra e allora sei entrato nei primi 10 metti il tuo nikname:\n");
        scanf("%s",classifica[10].nickname);
    }
    else 
    printf("Dannazione brodero sei forte ma non abbastanza riprova andra meglio credimi\n");

    int n = sizeof(classifica) / sizeof(classifica[0]);
    ordina_classifica(classifica, n);
    printf("classifica : \n\n ");
    //funzione per la scrittura dei dati sul file
    for (int contatore = 0; contatore < 10; contatore++)
    {
        fwrite (&classifica[contatore], sizeof(struct riga_classifica), 1, outfile);
    }
    if (&fwrite!=0)
    printf("la classifica e' stata memorizzata\n\n");
    else 
    printf("errore nella scrittura del file !!!!\n");
    fclose (outfile);//chiude il file
}
 
int main() // funzione principale per il funzionamento del gioco 
{
    guida_comandi();
    sleep(5);
    lettura_classifica();
    pulsante_per_giocare();
    conto_alla_rovescia();
    int genera_numero_casuale();
    generatore_espressioni();
    timer_punteggio();
    classifica_ordinata_salvata();
    lettura_classifica();
}