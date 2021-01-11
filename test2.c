//fichier test 2

#include <stdio.h>
#include <stdlib.h>
#define CAPACITEMAX 1000
//#define getName(var) #var
typedef int ensemble[CAPACITEMAX+2];

void initEns(ensemble e, const int n){ //initialise un tableau de capacité n
    e[0]=0;
    e[1]=n;
}

void ajouter(int n, ensemble e){ // ajoute un entier n à un ensemble e
    e[n+2]=1;
    e[0]+=1;
}

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


int main(){
    //ensemble en;
    //ensemble ens  = {5,6,1,1,1,0,1,1}; //ens = [ 0 1 2 4 ]
    ensemble ens1 = {3,6,0,1,0,1,0,0}; //ens1 = [ 1 2 ]
    ensemble ens2;
    initEns(ens2, 10);
    printf("ens2 = ");
    printlnEns(ens2);
    ajouter(3,ens2);
    printf("ens2 = ");
    printlnEns(ens2);
    printf("ens1 = ");
    printlnEns(ens1);
    return EXIT_SUCCESS;
}