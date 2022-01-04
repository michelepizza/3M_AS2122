/**Programma che stampa dieci operazioni matematiche casuali con rispettivi risultati**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Dichiarazione di un nuovo tipo di variabile chiamata operazione*/
typedef enum{
    somma,
    differenza} operazione;
/*Dichiarazione della variabile di tipo operazione chiamata segno*/
operazione segno;
/*Funzione generatore*/
void inizio_generatore()
{
    time_t t;
    srand((unsigned)time(&t));
}
/*Funzione per il calcolo di numeri casuali*/
int calcolo_numero_casuale(int minimo, int massimo)
{
    int numero;
    numero = rand() % (massimo - minimo + 1) + minimo;
    return numero;
}
int numeri()
{
    /*Dichiarazione delle variabili intere chiamate risultato e risultatoutente*/
    int risultato, risultatoutente;
    /*Dichiarazione dei due addendi delle operazioni*/
    int addendo1, addendo2;
    /*Richiama la funzione inizio_generatore*/
    inizio_generatore();
    /*Richiama la funzione calcolo_numero_casuale, i due addendi sono variabili casuali comprese tra - e + 9*/
    /*Le variabili sono ottenute prendendo i valori dei secondi dall'orologio del pc*/
    addendo1 = calcolo_numero_casuale(-9, 9);
    addendo2 = calcolo_numero_casuale(-9, 9);
    /*La variabile segno può assumere solo due valori, 0 o 1, ossia + o -*/
    segno = calcolo_numero_casuale(0, 1);
    switch (segno)
    {
        /*Nel caso in cui l'operazione sia una somma, esegui le istruzioni fino al primo break*/
    case somma:
        risultato = addendo1 + addendo2;
        printf("%2d + %2d = ", addendo1, addendo2);
        break;
        /*Nel caso in cui l'operazione sia una differenza,ignora le istruzioni della somma ed esegui le altre*/
    case differenza:
        risultato = addendo1 - addendo2;
        printf("%2d - %2d = ", addendo1, addendo2);
        break;
    }
    /*Acquisisci da tastiera il risultatoutente*/
    if (scanf("%d", &risultatoutente) != 1) {
        printf("Non hai inserito un numero, riprova\n");}
    /*se il risultato utente e' uguale a quello calcolato dal pc stampa risposta giusta*/
    if (risultato == risultatoutente)
    {
        printf("Risposta giusta\n");
        return 1;
    }
    /*in caso contrario stampa risposta sbagliata*/
    else
    {
        printf("Risposta sbagliata\n");
        return 0;
    }
    printf("\n");
}