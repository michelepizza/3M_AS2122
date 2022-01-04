/**
 * @file Gioco_Matematico.c
 * @author Simone Santonico, Carlos Barrero, Roberta Negru, Tiziano Palmini.
 * @brief Gioco matematico che stampa 10 addizioni o sottrazioni con numeri a 1 cifra, calcola il punteggio e stampa la classifica dei migliori 10 punteggi.
 * @version 0.1
 * @date 2021-12-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>
#include"Libreria_Apertura_Classifica.c"
#include"Libreria_Espressioni_Matematiche.c"
#include"Libreria_Ordinamento_e_aggiornamento_classifica.c"
int main(){
    while(1){
    Apertura_Classifica();
    printf("\n\tMenu':\nPremi il tasto \"1\" per iniziare.\nPremi qualsiasi altro tasto per uscire.\n");
    int tasto;
    scanf("%d", &tasto);
    if(tasto==1){
        printf("\n3\n");
        sleep(1);
        printf("2\n");
        sleep(1);
        printf("1\n");
        sleep(1);
        printf("VIA!!\n");
        espressioni();
    }
    else
    return 0;
    int punteggio_finale=espressioni();
    printf("\nIl tuo punteggio e': %d.\n", punteggio_finale);
    if(punteggio_finale>riga[9].punteggio){
        scanf("%s", &riga[10].nickname);
        punteggio_finale=riga[10].punteggio;
        ordina();
        salvataggio();
    }
    else
    printf("Ritenta, non sei fra i primi 10 classificati!");
}
}