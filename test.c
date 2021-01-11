//fichier test

#include <stdio.h>
#include <stdlib.h>
#define CAPACITEMAX 1000
typedef int ensemble[CAPACITEMAX+2];

void printEns(ensemble e){ // écrit un ensemble sur la sortie standard 
    printf("[ ");
    for (int i=2; i <=e[1]+1; i++){
        if(e[i]==1){
            printf("%d ",i-2);
        } 
    }
    printf("]");
}

void printlnEns(ensemble e){ //écrit un ensemble e sur la sortie standard suivi d’un passage à la ligne ; e1 = [ 2 19 31 33 ]
    printEns(e);
    printf("\n");
}

void plein(ensemble e){ // remplit l'ensemble passé en paramètre
    e[0]=e[1];
    for(int i=2; i<=e[1]+1; i++){
        e[i]=1;
    }
}

void ajouter(int n, ensemble e){ // ajoute un entier n à un ensemble e
    e[n+2]=1;
    e[0]-=1;
}

void enlever(int n, ensemble e){ //enlève un entier n d’un ensemble e ;
    e[n+2]=0;
    e[0]-=1;
}

int estVide(ensemble e){// test si un ensemble e est vide ou pas
    if (e[0]) return 0; //tableau non vide
    return 1; //tableau vide
}



int main(){
    //ensemble crible = {9,11,0,0,1,1,1,1,1,1,1,1,1};
    ensemble resultat = {1,11,0,0,1,0,0,0,0,0,0,0,0};
    //int i = 4;
    //ajouter(i-2, resultat); //ajoute 2
    //enlever(i-2, crible); //enlève 2
    //printlnEns(resultat);
    if(!estVide(resultat)){
        printf("non vide\n");
    }
    return EXIT_SUCCESS;
}
