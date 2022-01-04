/**
 * @file Libreria_Espressioni_Matematiche.c
 * @author Simone Santonico, Carlos Barrero, Roberta Negru, Tiziano Palmini.
 * @brief Libreria che genera 10 espressioni matematiche con numeri a una cifra compresi tra -9 e 9.
 * @version 0.1
 * @date 2021-12-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include"Libreria_Numeri_Casuali.c"
#include"Libreria_Punteggio.c"
#include<sys/time.h>
#include<stdio.h>
#include<unistd.h>
typedef enum {addizione, sottrazione} operazione;
operazione simbolo;
/**
 * @brief Funzione che genera 10 espressioni matematiche con numeri a una cifra compresi tra -9 e 9.
 * 
 * @return int 
 */
int espressioni(){
    int num1, num2, risultato, input_utente, punteggio_finale=0, punteggio[10];
    avvio_generatore();
    for(int i=0; i<9; i++){
        num1= generatore_num_casuale(-9,+9);
        num2= generatore_num_casuale(-9,+9);
        simbolo= generatore_num_casuale(0,1);
        if(simbolo==0){
            risultato=num1+num2;
            calcolo_punteggio_start();
            printf("\n%2d + %2d = ", num1, num2);
            scanf("%d", &input_utente);
            calcolo_punteggio_end();
            if(risultato==input_utente){
            printf("\nEsatto!\n");
            punteggio[i]=calcolo_punteggio_espressioni(start, end);
            }
            else{
            printf("\nSbagliato!\n");
            punteggio[i]=0;
            }
        }
        if(simbolo==1){
            risultato=num1-num2;
            calcolo_punteggio_start();
            printf("\n%2d - %2d = ", num1, num2);
            scanf("%d", &input_utente);
            calcolo_punteggio_end();
            if(risultato==input_utente){
            printf("\nEsatto!\n");
            punteggio[i]=calcolo_punteggio_espressioni(start, end);
            }
            else{
            printf("\nSbagliato!\n");
            punteggio[i]=0;
            }
        }
        i++;
    }
    punteggio_finale=punteggio[0]+punteggio[1]+punteggio[2]+punteggio[3]+punteggio[4]+punteggio[5]+punteggio[6]+punteggio[7]+punteggio[8]+punteggio[9];
    printf("\n");
    return punteggio_finale;
}