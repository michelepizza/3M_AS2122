/**
 * @file Libreria_num_casuali.c
 * @author Simone Santonico, Carlos Barrero, Roberta Negru, Tiziano Palmini.
 * @brief Generatore di numeri casuali che genera 10 numeri casuali ogni volta differenti tra loro.
 * @version 0.1
 * @date 2021-12-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/**
 * @brief Funzione che fa in modo che il numero generato non sia semrpe uguale
 * 
 */
void avvio_generatore(){
    time_t tempo;
    srand((unsigned) time(&tempo));
}
/**
 * @brief Funzione che permette di generare un numero casuale
 * 
 * @param minimo 
 * @param massimo 
 * @return int 
 */
int generatore_num_casuale(int minimo, int massimo){
    int num_casuale=rand()%(massimo-minimo+1)+minimo;
    return num_casuale;
}