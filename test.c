//fichier test

#include <stdio.h>
#include <stdlib.h>
#define CAPACITEMAX 1000
typedef int ensemble[CAPACITEMAX+2];

void printlnEns(ensemble e){ //écrit un ensemble e sur la sortie standard suivi d’un passage à la ligne ; e1 = [ 2 19 31 33 ]
    printf("ens = [ "); //nom de l'array
    for (int i = 2; i <=e[1]+1; i++){
        if(e[i]==1){
            printf("%d ",i-2);
        } 
    }
    printf("]\n");
}

void complementaire(ensemble e1, ensemble e2){ //calcule e2 complémentaire de e1 dans l’ensemble plein
    e2[1]=e1[1];
    e2[0]=e1[1]-e1[0];
    for(int i = 2; i<=e1[1]+1; i++){
        if(e1[i]==0){
            e2[i]=1;
        }
        else e2[i]=0;
    }
}


int main(){
    ensemble ens = {4,5,1,1,1,0,1}; 
    ensemble ens1;
    complementaire(ens, ens1);
    printlnEns(ens1);
    return EXIT_SUCCESS;
}
