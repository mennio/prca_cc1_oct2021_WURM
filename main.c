#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 

//initialisation du mutex
pthread_mutex_t mutexVentes = PTHREAD_MUTEX_INITIALIZER;


typedef struct _product_data {
    //char name[LEN];
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

void *lectureProduit(int tailleTb){
    FILE* fv = NULL;
    char element[tailleTb];
    fv = fopen("produits.txt","r+");// ouverture du fichier + lecture
    // si file != null alors on ajoute une cellule 
    if (fv != NULL)
    {
        //lecture du fichier
        while (fgets(element, tailleTb, fv) != NULL){
            printf("L'element produit est : %s \n", element);
        }  
        //ecriture dans le tableau  
        for(int i; i<tailleTb; i++){
            if(fgets(element, tailleTb, fv) != NULL){
                fscanf(fv, "%s", fgets(element, tailleTb, fv));
            }
        }
        fclose(fv); // ferme le fichier
    }
}

void *lectureVente(int tailleTb){
    FILE* fv = NULL;
    char element[tailleTb];
    fv = fopen("ventes.txt","r+");// ouverture du fichier + lecture
    // si file != null alors on ajoute une cellule 
    if (fv != NULL)
    {
        //lecture du fichier
        while (fgets(element, tailleTb, fv) != NULL){
            printf("L'element ventes est : %s \n", element);
        }  
        //ecriture dans le tableau  
        for(int i; i<tailleTb; i++){
            if(fgets(element, tailleTb, fv) != NULL){
                fscanf(fv, "%s", fgets(element, tailleTb, fv));
            }
        }
        fclose(fv); // ferme le fichier
    }
}


int main(int argc, char**argv){
    //4 arguments 
    int nbPd = atoi(argv[1]);
    int nbLecteurVentes= atoi(argv[2]);
    //char pathFileProduct[] =  atoi(argv[3]);
    //char pathFileVentes[] =  atoi(argv[4]);
    
    //fonction de lecture+ecriture produit
    lectureProduit(nbPd);

    //ouverture du fichier de vente
    FILE* fileVente = NULL;
    pthread_mutex_lock(&mutexVentes);
        lectureVente(nbLecteurVentes);
    pthread_mutex_unlock(&mutexVentes);

    //déclaration du thread
    pthread_t th1_lecteur;
    //boucle création thread en fonction de l'argument passé en paramètre
    for(int i=0; i<nbLecteur; i++){
        pthread_create(th1_lecteur,NULL,lectureProduit,i);
    }
    //boucle pthreadjoin
    for(int j=0; j<nbLecteur; j++){
        pthread_join(th1_lecteur[j],NULL);
    }
    return 0;
}