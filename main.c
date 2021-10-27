#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct _product_data {
    char name[LEN];
    unsigned int total;
    pthread_mutex_t lock_pd;
} product_data;


typedef struct _thread_data {
    pthread_t thID;
    unsigned int id;
    unsigned int nbPd;
    FILE *fv;
    product_data *products;
} thread_data;

void lectureProduit(){

}

int main(int argc, char**argv){
    //4 arguments 
    int nbPd = atoi(argv[1]);
    int nbLecteur= atoi(argv[2]);
    char pathFileProduct = (char) atoi(argv[3]);
    char pathFileVentes = (char) atoi(argv[4]);

    //test récupération argument
    printf("test %c",pathFileProduct);
    printf("test2 %c",pathFileProduct);
    printf("test3 %d",nbLecteur);
    printf("test4 %d",nbPd);

    //création tableua Inventaire avec taille qui est nbProd
    int tab[nbPd] = {0}; 
    fv = fopen("produits.txt",r);// ouverture du fichier + lecture
    // si file != null alors on ajoute une cellule 
    if (fv != NULL)
    {
        //boucle pour ajouter element par element
        for(int i =0; i <= nbPd; i++){
            fscanf(fv, "%d", &tab[i]); // ajoute les cellule incrementer par i
            printf("L'element est : %d", tab[i]);
        }
        fclose(fv); // ferme le fichier
    }

    //ouverture du fichier de vente
    FILE* fileVente = NULL;
    fileVente = fopen("ventes.txt", "r");

    
    return 0;
}