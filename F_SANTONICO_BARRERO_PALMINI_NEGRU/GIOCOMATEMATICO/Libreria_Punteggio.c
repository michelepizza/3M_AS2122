/**
 * @file Libreria_Punteggio.c
 * @author Simone Santonico, Carlos Barrero, Roberta Negru, Tiziano Palmini.
 * @brief Libreria che permette di calcolare il punteggio tra 2 intervalli di tempo
 * @version 0.1
 * @date 2021-12-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<sys/time.h>
#include<stdio.h>
#include<unistd.h>
#define PUNTEGGIO_MASSIMO 10000
long start, end;
/**
 * @brief Funzione che prende il tempo appena avviata
 * 
 * @return long 
 */
long currentTimeMillis(){
    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec*1000+time.tv_usec/1000;
}
/**
 * @brief Funzione che inizia il tmer del tempo impiegato
 * 
 * @return long 
 */
long calcolo_punteggio_start(){
    start=currentTimeMillis();
}
/**
 * @brief Funzione che stoppa il timer del tempo impiegato
 * 
 * @return long 
 */
long calcolo_punteggio_end(){
    end=currentTimeMillis();
}
/**
 * @brief Funzione che calcola il punteggio nell'intervallo di tempo del timer
 * 
 * @param start 
 * @param end 
 * @return long 
 */
long calcolo_punteggio_espressioni(long start, long end){
    return(end-start)<PUNTEGGIO_MASSIMO? PUNTEGGIO_MASSIMO-(end-start) : 0;
}