/**
 * @file Libreria_Ordinamento_e_aggiornamento_classifica.c
 * @author Simone Santonico, Carlos Barrero, Roberta Negru, Tiziano Palmini.
 * @brief Libreria che ordina e aggiorna la classifica
 * @version 0.1
 * @date 2021-12-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdlib.h>
#include<string.h>
/**
 * @brief Funzione che ordina la classifica
 * 
 * @param riga 
 * @param dimensione 
 */
void ordina(struct riga_classifica riga[], int dimensione){
    int indice1, indice2; //indici per il conronto
    for(indice1=0; indice1<dimensione-1; indice1++)
    for(indice2=0; indice2<dimensione-indice1-1; indice2++){
        if(riga[indice2].punteggio<riga[indice2+1].punteggio){
        struct riga_classifica riga_di_appoggio;
        riga_di_appoggio=riga[indice2];
        riga[indice2]=riga[indice2+1];
        riga[indice2+1]=riga_di_appoggio;
        }
    }
}
/**
 * @brief Funzione che salva la classifica
 * 
 */
void salvataggio(){
    FILE*outfile;
    outfile=fopen("classifica.dat", "w");
    if(outfile==NULL){
        fprintf(stderr, "\nErrore nell'aprire il file\n");
        exit(1);
    }
    struct riga_classifica riga[11]; 
    riga[0]=(struct riga_classifica) {"primo", 10};
    riga[1]=(struct riga_classifica) {"secondo", 9};
    riga[2]=(struct riga_classifica) {"terzo", 8};
    riga[3]=(struct riga_classifica) {"quarto", 7};
    riga[4]=(struct riga_classifica) {"quinto", 6};
    riga[5]=(struct riga_classifica) {"sesto", 5};
    riga[6]=(struct riga_classifica) {"settimo", 4};
    riga[7]=(struct riga_classifica) {"ottavo", 3};
    riga[8]=(struct riga_classifica) {"nono", 2};
    riga[9]=(struct riga_classifica) {"decimo", 1};
    riga[10]=(struct riga_classifica) {"nuovo giocatore", 0};
    int dimensione= sizeof(riga) / sizeof(riga[0]);
    ordina(riga, dimensione);
    for(int contatore=0; contatore<3; contatore++){
    fwrite(&riga[contatore], sizeof(struct riga_classifica), 1, outfile);
    }
    if(&fwrite!=0)
    printf("Classifica memorizzata!\n");
    else
    printf("Errore nella scrittura del file!\n");
    fclose(outfile);
}