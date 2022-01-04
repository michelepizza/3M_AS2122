#include <stdio.h>
// struct che definisce le righe della classifica
struct riga_classifica
{
    char nome[100];
    int punteggio;
};
//dichiara la variabile e puntatore infile
FILE *infile;
//funzione per ordinare la classifica
void ordina_classifica(struct riga_classifica classifica[]){
    int dimensione = 10;
    //indici per il confronto
    int indice1, indice2;
    for (indice1 = 0; indice1 < dimensione - 1; indice1++){
        for (indice2 = 0; indice2 < dimensione - indice1 - 1; indice2++){
            if (classifica[indice2].punteggio < classifica[indice2 + 1].punteggio){
                struct riga_classifica riga_di_appoggio;
                riga_di_appoggio = classifica[indice2];
                classifica[indice2] = classifica[indice2 + 1];
                classifica[indice2 + 1] = riga_di_appoggio;}}}}
//funzione che apre la classifica
void apri_classifica(){
    //apri il file
    infile = fopen("classifica.dat", "r");
    //se il file non esiste lo crea
    if (infile == NULL){
        //istruzioni per creare il file
        struct riga_classifica vuoto = (struct riga_classifica){"test", 0};
        infile = fopen("classifica.dat", "w");
        //ciclo for per riempire il file appena creato
        for (int i = 0; i < 10; i++){
            fwrite(&vuoto, sizeof(struct riga_classifica), 1, infile);}
            //chiudi il file
        fclose(infile);
    }
}
//funzione che legge la classifica
void leggi_classifica(struct riga_classifica classifica[])
{
    //apri il file
    infile = fopen("classifica.dat", "r");
    //dichiara la variabile intera contatore pari a zero
    int contatore = 0;
    //ciclo while per la lettura della classifica
    while (fread(&classifica[contatore], sizeof(struct riga_classifica), 1, infile))
    {
        //stampa i dati dell'utente
        printf("nickname = %s punteggio = %d\n", classifica[contatore].nome, classifica[contatore].punteggio);
        contatore++;
    }
    //chiudi file
    fclose(infile);
}
//funzione per aggiornare la classifica
void aggiorna_classifica(struct riga_classifica classifica[]){
    //apri il file
    infile = fopen("classifica.dat", "w");
    //ciclo for per scrivere nel file le posizioni della classifica
    for (int contatore = 0; contatore < 10; contatore++)
    {
        fwrite(&classifica[contatore], sizeof(struct riga_classifica), 1, infile);
    }
    //chiudi file
    fclose(infile);
}