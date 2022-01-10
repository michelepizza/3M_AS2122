#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/time.h>
 long currentTimeMillis()
    {
        struct timeval time;
        gettimeofday(&time,NULL);
        return time.tv_sec * 1000 + time.tv_usec /1000;
    }
//nickname;classifica
//inserire i pari merito
//per poter inserire la scritta hai perso inserire numero limitato di giocatori?
//inserire le parentesi; quando viene ad esempio 9--8 renderlo 9-(-8)
//inserire controllo input
int main(){
    int a,b,c,risultato,risposta,rrisposta,continua,sicuro;
    float punteggio=0;
      time_t t;
        time_t secondsstart;
        time_t secondsend;
        int domande=0;
        char nickname[20];
        struct riga_classifica{
        char nickname[20];
        int punteggio;
    };   
        struct riga_classifica rigaclassifica[10];
      strcpy( rigaclassifica[0].nickname,"BLANK");
      strcpy( rigaclassifica[1].nickname,"BLANK");
     strcpy( rigaclassifica[2].nickname,"BLANK");
       strcpy( rigaclassifica[3].nickname,"BLANK");
       strcpy( rigaclassifica[4].nickname,"BLANK");
         strcpy( rigaclassifica[5].nickname,"BLANK");
         strcpy( rigaclassifica[6].nickname,"BLANK");
     strcpy( rigaclassifica[7].nickname,"BLANK");
        strcpy( rigaclassifica[8].nickname,"BLANK");
         strcpy( rigaclassifica[9].nickname,"BLANK");
         char perdente[400];
          strcpy( perdente,"BLANK");
         rigaclassifica[0].punteggio=0;
          rigaclassifica[1].punteggio=0;
          rigaclassifica[2].punteggio=0;
          rigaclassifica[3].punteggio=0;
          rigaclassifica[4].punteggio=0;
          rigaclassifica[5].punteggio=0;
          rigaclassifica[6].punteggio=0;
          rigaclassifica[7].punteggio=0;
          rigaclassifica[8].punteggio=0;
          rigaclassifica[9].punteggio=0;
     char lista_perdenti[400]="";
      printf("BATTAGLIA DEI NUMERI\n");
         printf("qui andrà la classifica e la guida di come si gioca\n");
    
     FILE *input_file;
     FILE *creation_file;
     
     creation_file=fopen("classifica.dat","a"); 
      fclose(creation_file);  
     input_file=fopen("classifica.dat","r");
      
     
    if (input_file==NULL){
      printf("\nerrore nell'aprertura/creazione del file");
      
     exit(1);
    }
    
    
 fread( &rigaclassifica[0].punteggio, sizeof(int),1,input_file);
 fread( &rigaclassifica[0].nickname, sizeof(char[20]),1,input_file);
     fread( &rigaclassifica[1].punteggio, sizeof(int),1,input_file);
     fread( &rigaclassifica[1].nickname, sizeof(char[20]),1,input_file);
      fread( &rigaclassifica[2].punteggio, sizeof(int),1,input_file);
      fread( &rigaclassifica[2].nickname, sizeof(char[20]),1,input_file);
         fread( &rigaclassifica[3].punteggio, sizeof(int),1,input_file);
         fread( &rigaclassifica[3].nickname, sizeof(char[20]),1,input_file);
         fread( &rigaclassifica[4].punteggio, sizeof(int),1,input_file);
         fread( &rigaclassifica[4].nickname, sizeof(char[20]),1,input_file);
     fread( &rigaclassifica[5].punteggio, sizeof(int),1,input_file);
     fread( &rigaclassifica[5].nickname, sizeof(char[20]),1,input_file);
      fread( &rigaclassifica[6].punteggio, sizeof(int),1,input_file);
      fread( &rigaclassifica[6].nickname, sizeof(char[20]),1,input_file);
         fread( &rigaclassifica[7].punteggio, sizeof(int),1,input_file);
         fread( &rigaclassifica[7].nickname, sizeof(char[20]),1,input_file);
         fread(& rigaclassifica[8].punteggio, sizeof(int),1,input_file);
         fread( &rigaclassifica[8].nickname, sizeof(char[20]),1,input_file);
         fread( &rigaclassifica[9].punteggio, sizeof(int),1,input_file);
         fread( &rigaclassifica[9].nickname, sizeof(char[20]),1,input_file);
        fclose(input_file);
      
         if(strcmp(rigaclassifica[0].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[0].nickname,": ",rigaclassifica[0].punteggio);
        printf(" COMPLIMENTI HAI VINTO!\n");
        }
        if(strcmp(rigaclassifica[1].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[1].nickname,": ",rigaclassifica[1].punteggio);
        printf(" COMPLIMENTI SEI IL SECONDO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[2].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[2].nickname,": ",rigaclassifica[2].punteggio);
        printf(" COMPLIMENTI SEI IL TERZO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[3].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[3].nickname,": ",rigaclassifica[3].punteggio);
        printf(" COMPLIMENTI SEI IL QUARTO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[4].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[4].nickname,": ",rigaclassifica[4].punteggio);
        printf(" COMPLIMENTI SEI IL QUINTO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[5].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[5].nickname,": ",rigaclassifica[5].punteggio);
        printf(" COMPLIMENTI SEI IL SESTO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[6].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[6].nickname,": ",rigaclassifica[6].punteggio);
        printf(" COMPLIMENTI SEI IL SETTIMO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[7].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[7].nickname,": ",rigaclassifica[7].punteggio);
        printf(" COMPLIMENTI SEI L'OTTAVO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[8].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[8].nickname,": ",rigaclassifica[8].punteggio);
        printf(" COMPLIMENTI SEI IL NONO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[9].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[9].nickname,": ",rigaclassifica[9].punteggio);
        printf(" COMPLIMENTI SEI IL DECIMO CLASSIFICATO!\n");
        }
        
       do{
           do{
        printf("premi 1 per iniziare e 0 per uscire\n");
        sicuro=1;
        
            scanf("%d",&continua);
        }while(continua!=0&&continua!=1);
        if(continua==1){
        do{
            punteggio=0;
        
            domande=0;
            do{
         printf("inserisci il tuo nickname\n");
        scanf("%s",nickname);
        if(strcmp(nickname,"BLANK")==0){
            printf("nickname non valido, inserirne uno nuovo\n");
        }
            }while(strcmp(nickname,"BLANK")==0);
        // strcat (nickname,": ");/////////////////
 while(domande<10){     
    /* Intializes random number generator */
   srand((unsigned) time(&t));
   domande=domande+1;
   a=(rand() % (9-(-9))+1)-9;//+0 se si vuole fare operazioni con numeri da 0 a 9//a=rand() % (massimo-minimo+1)+minimo;//+0 se si vuole fare operazioni con numeri da 0 a 9
   b=(rand() % (9-(-9))+1)-9;
   c=(rand() % 2)+0;//operator
   if(domande==1){
       
    printf("3\n");
   usleep(1000000);
    printf("2\n");
  usleep(1000000);
    printf("1\n");
   usleep(1000000);
  printf("VIA!\n");
   }
   if(c==1){
         rrisposta=a+b;
         if (a<0){
           printf("%s%d%s","(", a,")");   
         }
         else if (a>=0){
          printf("%d", a);      
         }
        if (b<0){
           printf("%s%d%s\n","+(",b,")");   
         }
          else if (b>=0){
         printf("%s%d\n","+",b);  
         }
        
   }
 if(c==0){
        rrisposta=a-b;
          if (a<0){
           printf("%s%d%s","(", a,")");   
         }
         else if (a>=0){
          printf("%d", a);      
         }
        if (b<0){
           printf("%s%d%s\n","-(",b,")");   
         }
          else if (b>=0){
         printf("%s%d\n","-",b);  
         }
        
  }
    
     secondsstart = time(NULL);
      long millistart = currentTimeMillis();
// printf("%ld\n",secondsstart);
 	//usleep(1000000);//aspetta 1 millisecondo
scanf("%d",&risposta);
secondsend = time(NULL);
 long millisend = currentTimeMillis();
//printf("%ld\n",secondsend);
double time_spent = ((double)(secondsend - secondsstart));
long millis_spent = ((long)((millisend - millistart)));//se si vuole una precisione al millisecondo
 printf("%s%.0lf%s\n","ci hai messo ",time_spent," secondi");
 
 
if(rrisposta==risposta){
    punteggio=punteggio+(200-(time_spent));
    if(punteggio<0){
        printf("waw, scarso!\n");
        punteggio=0;
    }
}
  
printf("%s%.0f%s","Punteggio: ",punteggio,"\n");
  
}
printf("%s%s%s%.0f%s","Punteggio di ",nickname,": ",punteggio,"\n");
//scanf("%f",&punteggio);//per i test//////////////////////////////////////////////////
if(punteggio>=rigaclassifica[0].punteggio){
   //if(punteggio==rigaclassifica[0].punteggio{
       //strcat(rigaclassifica[0].nickname,", ");
       //strcat(rigaclassifica[0].nickname,nickname);
  // }
    //ifpunteggio==rigaclassifica[0].punteggio
    printf("COMPLIMENTI PER ORA SEI IL PRIMO CLASSIFICATO!\n");
    if(punteggio==rigaclassifica[0].punteggio&&strcmp(rigaclassifica[0].nickname,"BLANK")!=0){
       strcat(rigaclassifica[0].nickname,", ");
      strcat(rigaclassifica[0].nickname,nickname);
 }
else{
     
      if(strcmp(rigaclassifica[9].nickname,"BLANK")!=0){
           strcat(rigaclassifica[9].nickname,": ");
      printf("%s%d%s\n",rigaclassifica[9].nickname,rigaclassifica[9].punteggio," non è più in classifica");
     strcpy (perdente,rigaclassifica[9].nickname);
      
char pun[10];
sprintf(pun,"%d",rigaclassifica[9].punteggio); 
strcat (perdente,pun); 
strcat (perdente," HAI PERSO,RITENTA!\n"); 
strcat(perdente,lista_perdenti);
strcpy(lista_perdenti,perdente); 
strcpy(perdente,"BLANK");

     }
    strcpy (rigaclassifica[9].nickname,rigaclassifica[8].nickname);
    rigaclassifica[9].punteggio=rigaclassifica[8].punteggio,
    strcpy (rigaclassifica[8].nickname, rigaclassifica[7].nickname);
    rigaclassifica[8].punteggio=rigaclassifica[7].punteggio;
    strcpy (rigaclassifica[7].nickname,rigaclassifica[6].nickname);
    rigaclassifica[7].punteggio=rigaclassifica[6].punteggio;
    strcpy (rigaclassifica[6].nickname,rigaclassifica[5].nickname);
    rigaclassifica[6].punteggio=rigaclassifica[5].punteggio;
    strcpy (rigaclassifica[5].nickname,rigaclassifica[4].nickname);
    rigaclassifica[5].punteggio=rigaclassifica[4].punteggio;
    strcpy (rigaclassifica[4].nickname,rigaclassifica[3].nickname);
    rigaclassifica[4].punteggio=rigaclassifica[3].punteggio;
    strcpy (rigaclassifica[3].nickname,rigaclassifica[2].nickname);
    rigaclassifica[3].punteggio=rigaclassifica[2].punteggio;
    strcpy (rigaclassifica[2].nickname,rigaclassifica[1].nickname);
    rigaclassifica[2].punteggio=rigaclassifica[1].punteggio;
    strcpy (rigaclassifica[1].nickname,rigaclassifica[0].nickname);
    rigaclassifica[1].punteggio=rigaclassifica[0].punteggio;
    strcpy (rigaclassifica[0].nickname,nickname);
    rigaclassifica[0].punteggio=punteggio;
}
}
else if(punteggio>=rigaclassifica[1].punteggio){
     printf("COMPLIMENTI PER ORA SEI IL SECONDO CLASSIFICATO!\n");
       if(punteggio==rigaclassifica[1].punteggio&&strcmp(rigaclassifica[1].nickname,"BLANK")!=0){
       strcat(rigaclassifica[1].nickname,", ");
      strcat(rigaclassifica[1].nickname,nickname);
 }
else{
     if(strcmp(rigaclassifica[9].nickname,"BLANK")!=0){
         strcat(rigaclassifica[9].nickname,": ");
      printf("%s%d%s\n",rigaclassifica[9].nickname,rigaclassifica[9].punteggio," non è più in classifica");
    strcpy (perdente,rigaclassifica[9].nickname);    
     
char pun[10];
sprintf(pun,"%d",rigaclassifica[9].punteggio); 
strcat (perdente,pun); 
strcat (perdente," HAI PERSO,RITENTA!\n"); 
strcat(perdente,lista_perdenti);
strcpy(lista_perdenti,perdente); 
strcpy(perdente,"BLANK");

     }
  strcpy (rigaclassifica[9].nickname,rigaclassifica[8].nickname);
    rigaclassifica[9].punteggio=rigaclassifica[8].punteggio,
    strcpy (rigaclassifica[8].nickname, rigaclassifica[7].nickname);
    rigaclassifica[8].punteggio=rigaclassifica[7].punteggio;
    strcpy (rigaclassifica[7].nickname,rigaclassifica[6].nickname);
    rigaclassifica[7].punteggio=rigaclassifica[6].punteggio;
    strcpy (rigaclassifica[6].nickname,rigaclassifica[5].nickname);
    rigaclassifica[6].punteggio=rigaclassifica[5].punteggio;
    strcpy (rigaclassifica[5].nickname,rigaclassifica[4].nickname);
    rigaclassifica[5].punteggio=rigaclassifica[4].punteggio;
    strcpy (rigaclassifica[4].nickname,rigaclassifica[3].nickname);
    rigaclassifica[4].punteggio=rigaclassifica[3].punteggio;
    strcpy (rigaclassifica[3].nickname,rigaclassifica[2].nickname);
    rigaclassifica[3].punteggio=rigaclassifica[2].punteggio;
    strcpy (rigaclassifica[2].nickname,rigaclassifica[1].nickname);
    rigaclassifica[2].punteggio=rigaclassifica[1].punteggio;
    strcpy (rigaclassifica[1].nickname,nickname);
    rigaclassifica[1].punteggio=punteggio;
}
}
else if(punteggio>=rigaclassifica[2].punteggio){
     printf("COMPLIMENTI PER ORA SEI IL TERZO CLASSIFICATO!\n");
       if(punteggio==rigaclassifica[2].punteggio&&strcmp(rigaclassifica[2].nickname,"BLANK")!=0){
       strcat(rigaclassifica[2].nickname,", ");
      strcat(rigaclassifica[2].nickname,nickname);
 }
else{
     if(strcmp(rigaclassifica[9].nickname,"BLANK")!=0){
         strcat(rigaclassifica[9].nickname,": ");
      printf("%s%d%s\n",rigaclassifica[9].nickname,rigaclassifica[9].punteggio," non è più in classifica");
    strcpy (perdente,rigaclassifica[9].nickname); 
     
char pun[10];
sprintf(pun,"%d",rigaclassifica[9].punteggio); 
strcat (perdente,pun); 
strcat (perdente,": HAI PERSO,RITENTA!\n"); 
strcat(perdente,lista_perdenti);
strcpy(lista_perdenti,perdente); 
strcpy(perdente,"BLANK");

     }
    strcpy (rigaclassifica[9].nickname,rigaclassifica[8].nickname);
    rigaclassifica[9].punteggio=rigaclassifica[8].punteggio,
    strcpy (rigaclassifica[8].nickname, rigaclassifica[7].nickname);
    rigaclassifica[8].punteggio=rigaclassifica[7].punteggio;
    strcpy (rigaclassifica[7].nickname,rigaclassifica[6].nickname);
    rigaclassifica[7].punteggio=rigaclassifica[6].punteggio;
    strcpy (rigaclassifica[6].nickname,rigaclassifica[5].nickname);
    rigaclassifica[6].punteggio=rigaclassifica[5].punteggio;
    strcpy (rigaclassifica[5].nickname,rigaclassifica[4].nickname);
    rigaclassifica[5].punteggio=rigaclassifica[4].punteggio;
    strcpy (rigaclassifica[4].nickname,rigaclassifica[3].nickname);
    rigaclassifica[4].punteggio=rigaclassifica[3].punteggio;
    strcpy (rigaclassifica[3].nickname,rigaclassifica[2].nickname);
    rigaclassifica[3].punteggio=rigaclassifica[2].punteggio;
    strcpy (rigaclassifica[2].nickname,nickname);
    rigaclassifica[2].punteggio=punteggio;
} 
}
else if(punteggio>=rigaclassifica[3].punteggio){
     printf("COMPLIMENTI PER ORA SEI IL QUARTO CLASSIFICATO!\n");
       if(punteggio==rigaclassifica[3].punteggio&&strcmp(rigaclassifica[3].nickname,"BLANK")!=0){
       strcat(rigaclassifica[3].nickname,", ");
      strcat(rigaclassifica[3].nickname,nickname);
 }
else{
     if(strcmp(rigaclassifica[9].nickname,"BLANK")!=0){
         strcat(rigaclassifica[9].nickname,": ");
      printf("%s%d%s\n",rigaclassifica[9].nickname,rigaclassifica[9].punteggio," non è più in classifica");
     strcpy (perdente,rigaclassifica[9].nickname);
      
char pun[10];
sprintf(pun,"%d",rigaclassifica[9].punteggio); 
strcat (perdente,pun); 
strcat (perdente," HAI PERSO,RITENTA!\n"); 
strcat(perdente,lista_perdenti);
strcpy(lista_perdenti,perdente); 
strcpy(perdente,"BLANK");

     }
   strcpy (rigaclassifica[9].nickname,rigaclassifica[8].nickname);
    rigaclassifica[9].punteggio=rigaclassifica[8].punteggio,
    strcpy (rigaclassifica[8].nickname, rigaclassifica[7].nickname);
    rigaclassifica[8].punteggio=rigaclassifica[7].punteggio;
    strcpy (rigaclassifica[7].nickname,rigaclassifica[6].nickname);
    rigaclassifica[7].punteggio=rigaclassifica[6].punteggio;
    strcpy (rigaclassifica[6].nickname,rigaclassifica[5].nickname);
    rigaclassifica[6].punteggio=rigaclassifica[5].punteggio;
    strcpy (rigaclassifica[5].nickname,rigaclassifica[4].nickname);
    rigaclassifica[5].punteggio=rigaclassifica[4].punteggio;
    strcpy (rigaclassifica[4].nickname,rigaclassifica[3].nickname);
    rigaclassifica[4].punteggio=rigaclassifica[3].punteggio;
    strcpy (rigaclassifica[3].nickname,nickname);
    rigaclassifica[3].punteggio=punteggio;
   
}  
}
else if(punteggio>=rigaclassifica[4].punteggio){
     printf("COMPLIMENTI PER ORA SEI IL QUINTO CLASSIFICATO!\n");
       if(punteggio==rigaclassifica[4].punteggio&&strcmp(rigaclassifica[4].nickname,"BLANK")!=0){
       strcat(rigaclassifica[4].nickname,", ");
      strcat(rigaclassifica[4].nickname,nickname);
 }
else{
     if(strcmp(rigaclassifica[9].nickname,"BLANK")!=0){
         strcat(rigaclassifica[9].nickname,": ");
      printf("%s%d%s\n",rigaclassifica[9].nickname,rigaclassifica[9].punteggio," non è più in classifica");
      strcpy (perdente,rigaclassifica[9].nickname);   
       
char pun[10];
sprintf(pun,"%d",rigaclassifica[9].punteggio); 
strcat (perdente,pun); 
strcat (perdente," HAI PERSO,RITENTA!\n"); 
strcat(perdente,lista_perdenti);
strcpy(lista_perdenti,perdente); 
strcpy(perdente,"BLANK");

     }
 strcpy (rigaclassifica[9].nickname,rigaclassifica[8].nickname);
    rigaclassifica[9].punteggio=rigaclassifica[8].punteggio,
    strcpy (rigaclassifica[8].nickname, rigaclassifica[7].nickname);
    rigaclassifica[8].punteggio=rigaclassifica[7].punteggio;
    strcpy (rigaclassifica[7].nickname,rigaclassifica[6].nickname);
    rigaclassifica[7].punteggio=rigaclassifica[6].punteggio;
    strcpy (rigaclassifica[6].nickname,rigaclassifica[5].nickname);
    rigaclassifica[6].punteggio=rigaclassifica[5].punteggio;
    strcpy (rigaclassifica[5].nickname,rigaclassifica[4].nickname);
    rigaclassifica[5].punteggio=rigaclassifica[4].punteggio;
    strcpy (rigaclassifica[4].nickname,nickname);
    rigaclassifica[4].punteggio=punteggio;
   
}  
}
else if(punteggio>=rigaclassifica[5].punteggio){
     printf("COMPLIMENTI PER ORA SEI IL SESTO CLASSIFICATO!\n");
       if(punteggio==rigaclassifica[5].punteggio&&strcmp(rigaclassifica[5].nickname,"BLANK")!=0){
       strcat(rigaclassifica[5].nickname,", ");
      strcat(rigaclassifica[5].nickname,nickname);
 }
else{
     if(strcmp(rigaclassifica[9].nickname,"BLANK")!=0){
         strcat(rigaclassifica[9].nickname,": ");
      printf("%s%d%s\n",rigaclassifica[9].nickname,rigaclassifica[9].punteggio," non è più in classifica");
      strcpy (perdente,rigaclassifica[9].nickname);     
     
char pun[10];
sprintf(pun,"%d",rigaclassifica[9].punteggio); 
strcat (perdente,pun); 
strcat (perdente," HAI PERSO,RITENTA!\n"); 
strcat(perdente,lista_perdenti);
strcpy(lista_perdenti,perdente); 
strcpy(perdente,"BLANK");

     }
  strcpy (rigaclassifica[9].nickname,rigaclassifica[8].nickname);
    rigaclassifica[9].punteggio=rigaclassifica[8].punteggio,
    strcpy (rigaclassifica[8].nickname, rigaclassifica[7].nickname);
    rigaclassifica[8].punteggio=rigaclassifica[7].punteggio;
    strcpy (rigaclassifica[7].nickname,rigaclassifica[6].nickname);
    rigaclassifica[7].punteggio=rigaclassifica[6].punteggio;
    strcpy (rigaclassifica[6].nickname,rigaclassifica[5].nickname);
    rigaclassifica[6].punteggio=rigaclassifica[5].punteggio;
    strcpy (rigaclassifica[5].nickname,nickname);
    rigaclassifica[5].punteggio=punteggio;
 
}
}
else if(punteggio>=rigaclassifica[6].punteggio){
     printf("COMPLIMENTI PER ORA SEI IL SETTIMO CLASSIFICATO!\n");
       if(punteggio==rigaclassifica[6].punteggio&&strcmp(rigaclassifica[6].nickname,"BLANK")!=0){
       strcat(rigaclassifica[6].nickname,", ");
      strcat(rigaclassifica[6].nickname,nickname);
 }
else{
     if(strcmp(rigaclassifica[9].nickname,"BLANK")!=0){
         strcat(rigaclassifica[9].nickname,": ");
      printf("%s%d%s\n",rigaclassifica[9].nickname,rigaclassifica[9].punteggio," non è più in classifica");
    strcpy (perdente,rigaclassifica[9].nickname);       
    
char pun[10];
sprintf(pun,"%d",rigaclassifica[9].punteggio); 
strcat (perdente,pun); 
strcat (perdente," HAI PERSO,RITENTA!\n"); 
strcat(perdente,lista_perdenti);
strcpy(lista_perdenti,perdente); 
strcpy(perdente,"BLANK");

     }
     strcpy (rigaclassifica[9].nickname,rigaclassifica[8].nickname);
    rigaclassifica[9].punteggio=rigaclassifica[8].punteggio,
    strcpy (rigaclassifica[8].nickname, rigaclassifica[7].nickname);
    rigaclassifica[8].punteggio=rigaclassifica[7].punteggio;
    strcpy (rigaclassifica[7].nickname,rigaclassifica[6].nickname);
    rigaclassifica[7].punteggio=rigaclassifica[6].punteggio;
    strcpy (rigaclassifica[6].nickname,nickname);
    rigaclassifica[6].punteggio=punteggio;
   
} 
}
else if(punteggio>=rigaclassifica[7].punteggio){
     printf("COMPLIMENTI PER ORA SEI L'OTTAVO CLASSIFICATO!\n");
       if(punteggio==rigaclassifica[7].punteggio&&strcmp(rigaclassifica[7].nickname,"BLANK")!=0){
       strcat(rigaclassifica[7].nickname,", ");
      strcat(rigaclassifica[7].nickname,nickname);
 }
else{
     if(strcmp(rigaclassifica[9].nickname,"BLANK")!=0){
         strcat(rigaclassifica[9].nickname,": ");
      printf("%s%d%s\n",rigaclassifica[9].nickname,rigaclassifica[9].punteggio," non è più in classifica");
   strcpy (perdente,rigaclassifica[9].nickname);       
char pun[10];
sprintf(pun,"%d",rigaclassifica[9].punteggio); 
strcat (perdente,pun); 
strcat (perdente," HAI PERSO,RITENTA!\n"); 
strcat(perdente,lista_perdenti);
strcpy(lista_perdenti,perdente); 
strcpy(perdente,"BLANK");

     }
   strcpy (rigaclassifica[9].nickname,rigaclassifica[8].nickname);
    rigaclassifica[9].punteggio=rigaclassifica[8].punteggio,
    strcpy (rigaclassifica[8].nickname, rigaclassifica[7].nickname);
    rigaclassifica[8].punteggio=rigaclassifica[7].punteggio;
    strcpy (rigaclassifica[7].nickname,nickname);
    rigaclassifica[7].punteggio=punteggio;
 
}
}
else if(punteggio>=rigaclassifica[8].punteggio){
     printf("COMPLIMENTI PER ORA SEI IL NONO CLASSIFICATO!\n");
       if(punteggio==rigaclassifica[8].punteggio&&strcmp(rigaclassifica[8].nickname,"BLANK")!=0){
       strcat(rigaclassifica[8].nickname,", ");
      strcat(rigaclassifica[8].nickname,nickname);
 }
else{
     if(strcmp(rigaclassifica[9].nickname,"BLANK")!=0){
          strcat(rigaclassifica[9].nickname,": ");
      printf("%s%d%s\n",rigaclassifica[9].nickname,rigaclassifica[9].punteggio," non è più in classifica");
      strcpy (perdente,rigaclassifica[9].nickname);   
      
char pun[10];
sprintf(pun,"%d",rigaclassifica[9].punteggio); 
strcat (perdente,pun); 
strcat (perdente," HAI PERSO,RITENTA!\n"); 
strcat(perdente,lista_perdenti);
strcpy(lista_perdenti,perdente); 
strcpy(perdente,"BLANK");

     }
 strcpy (rigaclassifica[9].nickname,rigaclassifica[8].nickname);
    rigaclassifica[9].punteggio=rigaclassifica[8].punteggio,
    strcpy (rigaclassifica[8].nickname, nickname);
 rigaclassifica[8].punteggio=punteggio;
 
}
}
else if(punteggio>=rigaclassifica[9].punteggio){
    printf("COMPLIMENTI PER ORA SEI IL DECIMO CLASSIFICATO!\n");
      if(punteggio==rigaclassifica[9].punteggio&&strcmp(rigaclassifica[9].nickname,"BLANK")!=0){
       strcat(rigaclassifica[9].nickname,", ");
      strcat(rigaclassifica[9].nickname,nickname);
 }
else{
     if(strcmp(rigaclassifica[9].nickname,"BLANK")!=0){
          strcat(rigaclassifica[9].nickname,": ");
      printf("%s%d%s\n",rigaclassifica[9].nickname,rigaclassifica[9].punteggio," non è più in classifica");
     //
       
strcpy (perdente,rigaclassifica[9].nickname);    
 
char pun[10];
sprintf(pun,"%d",rigaclassifica[9].punteggio); 
strcat (perdente,pun); 
strcat (perdente," HAI PERSO,RITENTA!\n"); 
strcat(perdente,lista_perdenti);
strcpy(lista_perdenti,perdente); 
strcpy(perdente,"BLANK");

     }
    strcpy (rigaclassifica[9].nickname,nickname);
    rigaclassifica[9].punteggio=punteggio;
 
}
}
else{
    printf("NON SEI TRA I PRIMI DIECI\n HAI PERSO,RIPROVA!\n");
    //
       strcpy (perdente,nickname);
        strcat(perdente,": ");
       char pun[10];
sprintf(pun,"%.0f",punteggio);
strcat (perdente,pun);
strcat (perdente," HAI PERSO,RITENTA!\n");
strcat(perdente,lista_perdenti);
strcpy(lista_perdenti,perdente);
strcpy(perdente,"BLANK");
//
}
do{
    printf("continuare?1=si 0=no\n");
scanf("%d",&continua);
}while(continua!=1&&continua!=0);
}while(continua==1);

        if(strcmp(rigaclassifica[0].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[0].nickname,": ",rigaclassifica[0].punteggio);
        printf(" COMPLIMENTI HAI VINTO!\n");
        }
        if(strcmp(rigaclassifica[1].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[1].nickname,": ",rigaclassifica[1].punteggio);
        printf(" COMPLIMENTI SEI IL SECONDO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[2].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[2].nickname,": ",rigaclassifica[2].punteggio);
        printf(" COMPLIMENTI SEI IL TERZO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[3].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[3].nickname,": ",rigaclassifica[3].punteggio);
        printf(" COMPLIMENTI SEI IL QUARTO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[4].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[4].nickname,": ",rigaclassifica[4].punteggio);
        printf(" COMPLIMENTI SEI IL QUINTO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[5].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[5].nickname,": ",rigaclassifica[5].punteggio);
        printf(" COMPLIMENTI SEI IL SESTO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[6].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[6].nickname,": ",rigaclassifica[6].punteggio);
        printf(" COMPLIMENTI SEI IL SETTIMO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[7].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[7].nickname,": ",rigaclassifica[7].punteggio);
        printf(" COMPLIMENTI SEI L'OTTAVO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[8].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[8].nickname,": ",rigaclassifica[8].punteggio);
        printf(" COMPLIMENTI SEI IL NONO CLASSIFICATO!\n");
        }
        if(strcmp(rigaclassifica[9].nickname,"BLANK")!=0){
        printf("%s%s%d",rigaclassifica[9].nickname,": ",rigaclassifica[9].punteggio);
        printf(" COMPLIMENTI SEI IL DECIMO CLASSIFICATO!\n");
        }
         if(strcmp(lista_perdenti,"")!=0){
         printf("%s%s","LISTA NON CLASSIFICATI:\n",lista_perdenti);
         }
         
         FILE* output_file ;
    output_file= fopen("classifica.dat", "w");
    if (output_file==NULL) {
       fprintf(stderr,"\nERRORE nell'aprire il file\n");
        exit(1);
    }

    fwrite( &rigaclassifica[0].punteggio, sizeof(int),1,output_file);
 fwrite( &rigaclassifica[0].nickname, sizeof(char[20]),1,output_file);
     fwrite( &rigaclassifica[1].punteggio, sizeof(int),1,output_file);
     fwrite( &rigaclassifica[1].nickname, sizeof(char[20]),1,output_file);
      fwrite( &rigaclassifica[2].punteggio, sizeof(int),1,output_file);
      fwrite( &rigaclassifica[2].nickname, sizeof(char[20]),1,output_file);
         fwrite( &rigaclassifica[3].punteggio, sizeof(int),1,output_file);
         fwrite( &rigaclassifica[3].nickname, sizeof(char[20]),1,output_file);
         fwrite( &rigaclassifica[4].punteggio, sizeof(int),1,output_file);
         fwrite( &rigaclassifica[4].nickname, sizeof(char[20]),1,output_file);
     fwrite( &rigaclassifica[5].punteggio, sizeof(int),1,output_file);
     fwrite( &rigaclassifica[5].nickname, sizeof(char[20]),1,output_file);
      fwrite( &rigaclassifica[6].punteggio, sizeof(int),1,output_file);
      fwrite( &rigaclassifica[6].nickname, sizeof(char[20]),1,output_file);
         fwrite( &rigaclassifica[7].punteggio, sizeof(int),1,output_file);
         fwrite( &rigaclassifica[7].nickname, sizeof(char[20]),1,output_file);
        fwrite(& rigaclassifica[8].punteggio, sizeof(int),1,output_file);
         fwrite( &rigaclassifica[8].nickname, sizeof(char[20]),1,output_file);
         fwrite( &rigaclassifica[9].punteggio, sizeof(int),1,output_file);
        fwrite( &rigaclassifica[9].nickname, sizeof(char[20]),1,output_file);
if (&fwrite != 0){
printf("classifica memorizzata\n");
}
else{
    printf("errore nella scrittura del file\n");
}
    fclose(output_file);
       
}
else{
    do{
        printf("sicuro? 1=si 2=no\n");
    scanf("%d",&sicuro);
    }while(sicuro!=0&&sicuro!=1);
}
}while(sicuro!=1);

}
/*
char str[10];
//char
 pun[10];
sprintf(str,"%.0f",punteggio);
printf("%s\n",str);
return 0;
}
*///converte float in string
//}
/* here, do your time-consuming job */

/*#include <stdio.h>
#include <time.h>

int main () {
   time_t seconds;

   seconds = time(NULL);
   printf("Hours since January 1, 1970 = %ld\n", seconds/3600);
  
   return(0);
}



}
*/

