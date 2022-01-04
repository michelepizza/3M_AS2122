/**
 * @file Libreria_Apertura_Classifica.c
 * @author Simone Santonico, Carlos Barrero, Roberta Negru, Tiziano Palmini.
 * @brief Libreria che apre la classifica e la stampa.
 * @version 0.1
 * @date 2021-12-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<stdlib.h>
struct riga_classifica //struct per memorizzare i dati nella classifica
{
char nickname[20];
int punteggio;
};
/**
 * @brief Funzione che apre la classifica e la stampa.
 * 
 */
void Apertura_Classifica(){
    FILE *infile;
    struct riga_classifica riga[10];
    infile=fopen("classifica.dat", "r"); //apertura del file
    if(infile==NULL){
        fprintf(stderr, "\nErrore nell'apertura della classifica.\n");
        
    }
    for(int contatore=0; fread(&riga[contatore], sizeof(struct riga_classifica), 1, infile); contatore++) {
        printf("\tNickname=%s \tPunteggio=%d\n", riga[contatore].nickname, riga[contatore].punteggio);
    }
    fclose(infile); //chiusura del file
}