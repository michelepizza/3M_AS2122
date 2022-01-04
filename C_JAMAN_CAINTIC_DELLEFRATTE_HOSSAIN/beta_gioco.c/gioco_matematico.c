/**
 * @file giocoV1.c
 * @author your name (you@domain.com)
 * @brief la versioe beta del gioco matematico
 * @version 0.1
 * @date 2021-12-10
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

#define PUNTEGGIOa_MASSIMO 10000
int contenitore_punti[10]; // contiene i punti ottenuti dalle singole operazioni

typedef enum
{
    false,
    true
} boolean;
typedef enum
{
    sottrazione,
    addizione
} operatore;

struct riga_classifica
{
    int id;
    char nickname[20];
    int punteggio;
};

void start_generatore();
int numero_random(int, int);
long currentTimeMillis();
int punteggio_parziale(long, long);
int punteggio_totale();
void conto_alla_rovescia();
void guida();
void tasto_gioco();
void stampa_guida();
boolean generatore_espressioni();
int lettura_classifica();
int operazione_con_punteggio();
void ordina(struct riga_classifica arr[], int n);
void aggiornamento_classifica();

/**
 * @brief nel main ci sono tutte le funzione che messi insieme compongono il gioco,
 *
 * @return int
 */
int main()
{
    guida();
    lettura_classifica();
    tasto_gioco();
    conto_alla_rovescia();
    for (int i = 0; i < 10; i++)
    {
        contenitore_punti[i] = operazione_con_punteggio();
    }
    aggiornamento_classifica();
    lettura_classifica();
}
/**
 * @brief calcola i punti ottenuti dal giocare sommando i punti ottenuti dalle operazioni singoli.
 *
 * @return int
 */
int punteggio_totale()
{
    int punteggio_totale = 0;
    for (int i = 0; i < 10; i++)
    {
        punteggio_totale += contenitore_punti[i];
    }
    return punteggio_totale;
}
/**
 * @brief è la funzione che prende il tempo tra le varie operazione e li collega con la funzione punteggio_parziale per
 * dare  il punteggio.
 *
 * @return int
 */
int operazione_con_punteggio()
{
    long start = currentTimeMillis();
    boolean rispostsa = generatore_espressioni();
    long end = currentTimeMillis();
    return (rispostsa == true) ? punteggio_parziale(start, end) : 0;
}
/**
 * @brief genera un espressione, e chiede il risultato, in caso di risposta errata ritorna
 *        false altrimenti true.
 *
 * @return boolean
 */
boolean generatore_espressioni()
{
    start_generatore();
    int risultato_calcolato;
    int risultato_giocatore;
    int primo_operando = numero_random(-9, 9);
    int secondo_operando = numero_random(-9, 9);
    operatore simbolo = numero_random(0, 1);
    switch (simbolo)
    {
    case sottrazione:
        printf("\n%d - %d = ", primo_operando, secondo_operando);
        risultato_calcolato = primo_operando - secondo_operando;
        scanf("%3d", &risultato_giocatore);
        break;
    case addizione:
        printf("\n%d + %d = ", primo_operando, secondo_operando);
        risultato_calcolato = primo_operando + secondo_operando;
        scanf("%3d", &risultato_giocatore);
        break;
    default:
        break;
    }
    return (risultato_calcolato != risultato_giocatore) ? false : true;
}
/**
 * @brief generera un numero pseudo-casuale con un minimo e un massimo
 *
 * @param min
 * @param max
 * @return int
 */
int numero_random(int min, int max)
{
    int number = rand() % (max - min + 1) + min;
    return number;
}

void start_generatore()
{
    time_t tempo;
    srand((unsigned)time(&tempo));
}
/**
 * @brief la funzione prende il tempo e lo trasforma in milli secondi
 *
 * @return long
 */
long currentTimeMillis()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec * 1000 + time.tv_usec / 1000;
}
/**
 * @brief la funzione calcola il puntegio in base al tempo preso dai parametri.
 *
 * @param start
 * @param end
 * @return int
 */
int punteggio_parziale(long start, long end)
{
    int punteggio = (end - start < PUNTEGGIOa_MASSIMO) ? PUNTEGGIOa_MASSIMO - (end - start) : 0;
    return punteggio;
}
/**
 * @brief la funzione avvia un conto alla rovescia
 *
 */
void conto_alla_rovescia()
{
    sleep(1);
    for (int i = 3; i >= 1; i--)
    {
        printf("%d\n", i);
        sleep(1);
    }
}
/**
 * @brief la funzione mette a disposizione 2 tasti, uno per iniziare a giocarer e l'altro per uscire
 *
 */
void tasto_gioco()
{
    char pulsante;
    printf("\nNuova Partita?\nPremi: Y e invia per si, N per uscire\n");
    scanf("%c", &pulsante);
    if (pulsante == 'n' || pulsante == 'N')
    {
        exit(0);
    }
    else if (pulsante == 'y' || pulsante == 'Y')
    {
        printf("\ncaricament...\n");
        sleep(1);
    };
}
void guida()
{
    printf("\nBenvenuto brodero giocatore!\n\nIl gioco consiste nel svolgere delle operazioni \nnel minor tempo possibile e puntasre ad arrivare nella top 10.\nEsso e' costituito dal premere il tasto Y per iniziare a giocare\nIn seguito appaiano le operazioni e bisogna inserire la risposta,\nse la rsposta e' giusta verranno assegnati dei punti in base al tempo.\nSe si rientra nella TOP 10 viene mostrato un messaggio con la\nposizione presieduta momentaneamente\n");
    sleep(3);
}
/**
 * @brief legge il documeto che contiene la classifica e la stampa
 *
 */
int lettura_classifica()
{
    FILE *infile;
    struct riga_classifica classifica[10];
    infile = fopen("classifica.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError nell'apertura di file");
        return -1;
    }
    int contatore = 0;
    printf("\nQuesta e' la classifica\n");
    while (fread(&classifica[contatore], sizeof(struct riga_classifica), 1, infile))
    {
        printf("id = %d, name = %s, punteggio = %d\n", classifica[contatore].id, classifica[contatore].nickname,
               classifica[contatore].punteggio);
        contatore++;
    }
    fclose(infile);
    return 0;
}
/**
 * @brief la funzione salva la classifica ordinata nel documento prendendo il punteggio ottenuto e
 * integrando alla classifica
 *
 */
void aggiornamento_classifica()
{
    struct riga_classifica classifica[11];

    FILE *outfile;

    outfile = fopen("classifica.dat", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError nell'aprire il file\n");
        exit(1);
    }
    classifica[0] = (struct riga_classifica){1, "kirby", 70100};
    classifica[1] = (struct riga_classifica){2, "prokid", 38990};
    classifica[2] = (struct riga_classifica){3, "lattex", 10330};
    classifica[3] = (struct riga_classifica){4, "pinky", 14010};
    classifica[4] = (struct riga_classifica){5, "tech_nine", 81130};
    classifica[5] = (struct riga_classifica){6, "herry", 12250};
    classifica[6] = (struct riga_classifica){7, "rossi", 50723};
    classifica[7] = (struct riga_classifica){8, "koala", 69158};
    classifica[8] = (struct riga_classifica){9, "unnamed", 12200};
    classifica[9] = (struct riga_classifica){10, "hertz", 33111};
    classifica[10] = (struct riga_classifica){11, "new_user", punteggio_totale()};

    int n = sizeof(classifica) / sizeof(classifica[0]);

    if (classifica[10].punteggio < classifica[8].punteggio)
    {
        printf("\nScusa brodero! Non hai abbastanza punti per entrare nella classifica");
        printf("PUNTI OTTENUTI: %d", classifica[10].punteggio);
    }
    else
    {
        printf("\nBravo brodero, sei nella classifica!\nImmetti un nickname: ");
        scanf("%s", classifica[10].nickname);
    }

    ordina(classifica, n);

    for (int i = 0; i < 10; i++)
    {
        fwrite(&classifica[i], sizeof(struct riga_classifica), 1, outfile);
    }
    fclose(outfile);
}
/**
 * @brief ordian la classifica
 *
 * @param arr
 * @param n
 */
void ordina(struct riga_classifica arr[], int n)
{
    int indice1, indice2;
    for (indice1 = 0; indice1 < n - 1; indice1++)
    {
        for (indice2 = 0; indice2 < n - indice1 - 1; indice2++)
        {
            if (arr[indice2].punteggio < arr[indice2 + 1].punteggio)
            {
                struct riga_classifica riga_di_appoggio;
                riga_di_appoggio = arr[indice2];
                arr[indice2] = arr[indice2 + 1];
                arr[indice2 + 1] = riga_di_appoggio;
            }
        }
    }
}