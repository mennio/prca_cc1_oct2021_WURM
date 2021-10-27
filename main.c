#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 

//initialisation du mutex
pthread_mutex_t mutexVentes = PTHREAD_MUTEX_INITIALIZER;


typedef struct _product_data {
    char name[LEN];
    unsigned int total;
    pthread_mutex_t lock_pd;
} product_data;


typedef struct _thread_data {
    pthread_t thID;
    unsigned int id;
    unsigned int nbPd;
    //FILE *fv;
    product_data *products;
} thread_data;

void initialisationValeur(){
    
}

void *lecteur(){

}

int main(int argc, char**argv){
    //4 arguments 
    int nbPd = atoi(argv[1]);
    int nbLecteur= atoi(argv[2]);
    //char pathFileProduct[] =  atoi(argv[3]);
    //char pathFileVentes[] =  atoi(argv[4]);

    //test récupération argument
    //printf("test %c",pathFileProduct);
    //printf("test2 %c",pathFileProduct);
    printf("test3 %d",nbLecteur);
    printf("test4 %d",nbPd);

    //création tableua Inventaire avec taille qui est nbProd
    int tab[nbPd];
    FILE* fv = NULL;
    fv = fopen("produits.txt","r+");// ouverture du fichier + lecture
    // si file != null alors on ajoute une cellule 
    if (fv != NULL)
    {
        //boucle pour ajouter element par element
        for(int i =0; i <= nbPd; i++){
            fscanf(fv, "%d", &tab[i]); 
            printf("L'element est : %d \n", &tab[i]);
        }
        fclose(fv); // ferme le fichier
    }

    //ouverture du fichier de vente
    FILE* fileVente = NULL;
    pthread_mutex_lock(&mutexVentes);
        fileVente = fopen("ventes.txt", "r+");
    pthread_mutex_unlock(&mutexVentes);

    //déclaration du thread
    pthread_t th1_lecteur = nbLecteur;

    //boucle création thread en fonction de l'argument passé en paramètre
    for(int i=0; i<nbLecteur; i++){
        pthread_create(th1_lecteur,NULL,lecteur,i);
    }

    //boucle pthreadjoin
    for(int j=0; j<nbLecteur, j++){
        pthread_join(th1_lecteur[j],NULL);
    }
    return 0;
}