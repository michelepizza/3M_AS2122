//dichiarazione delle librerie e dei files utilizzati
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ClassificaAlpha.c"
#include "PunteggioAlpha.c"
#include "ClassificaAlpha.c"
//struct per la composizione delle righe della classifica
struct riga_classifica classifica[10];
void menu();
int main()
{
    apri_classifica();
    //dichiarazione della variabiile char nome o nickname
    char nome[100];
    //richiama la funzione menu
    menu();
    leggi_classifica(classifica);
    //ordina_classifica()
    printf("Inserisci Nickname: ");
    scanf("%s", &nome);
    //ciclo for per il conto alla rovescia
    for (int i = 3; i > 0; i--)
    {
        printf("\rPartenza %d\r", i);
        //attendi un secondo
        sleep(1);
    }
    //richiama la funzione inizio_generatore
    inizio_generatore();
    //dichiarazione della variabile punteggio_totale
    int punteggio_totale = 0;
    //ciclo for per calcolare il punteggio totale
    for (int i = 0; i < 10; i++)
    {
        //tempo di inizio
        long start = currentTimeMillis();
        if (numeri()){
            //tempo finale
            long end = currentTimeMillis();
            //calcolo del punteggio totale
            punteggio_totale += calcolo_punteggio(start, end);}
    }
    //stampa il punteggio totale
    printf("Il punteggio totale e' = %d", punteggio_totale);
    //struct che rappresenta il giocatore attuale
    struct riga_classifica persona = (struct riga_classifica){nome, punteggio_totale};
    //se la condizione dell'if e' vera significa che e' la prima volta che il gioco viene aperto
    if (classifica[0].punteggio == 0)
    {
        //posiziona al primo posto il primo giocatore in assoluto
        strcpy(classifica[0].nome, nome);
        classifica->punteggio = punteggio_totale;
        //richiama funzione aggiorna classifica
        aggiorna_classifica(classifica);
    }
    //se la condizione dell'else e' vera, significa che il gioco e' gia' stato aperto
    else if (classifica[0].punteggio < punteggio_totale){
        printf("\nComplimenti sei il primo");
        struct riga_classifica temp = classifica[9];
        //ciclo for spostare i giocatori di una posizione se il nuovo giocatore arriva primo
        for (int j = 0; j < 10; j++)
        {
            classifica[j] = classifica[j + 1];
        }
        //aggiorna la classifica con il nickname e il punteggio del nuovo utente
        strcpy(classifica[0].nome, nome);
        classifica[0].punteggio = punteggio_totale;
        aggiorna_classifica(classifica);
    }
    //else if per determinare la posizione in classifica del nuovo giocatore
    else if (punteggio_totale > classifica[9].punteggio){
        printf("\nComplimenti sei in classifica");
        for (int i = 8; i > -1; i--){
            if (punteggio_totale < classifica[i].punteggio){
                struct riga_classifica temp = classifica[0];
                //ciclo for spostare i giocatori di una posizione se il nuovo giocatore arriva primo
                for (int j = 0; j < 10; j++){
                    classifica[j] = classifica[j + 1];}
                    //assegna alla variabile classifica0 la variabile temp
                classifica[0] = temp;
                strcpy(classifica[0].nome, nome);
                classifica[0].punteggio = punteggio_totale;
                aggiorna_classifica(classifica);
                break;}}}}
//funzione che stampa il menu
void menu(){
    printf("Videogioco Matematico: questo videogioco in single player si basa sulla capacita' di calcolare il piu' velocemente possibile il risultato di dieci operazioni matematiche casuali.\n Inserisci il tuo Nickname e premi invio per iniziare.\n Puoi premere i tasti + e -; il tasto invio e tutti i tasti numerici.\nClassifica:\n");
}