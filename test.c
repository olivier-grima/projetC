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

void initEns(ensemble e,int n){ //initialise un tableau de capacité n
    e[1]=n; 
    //not finished
}


int main(){
    ensemble ens;
    initEns(ens, 50);
    printf("%d\n", ens[1]);
    return EXIT_SUCCESS;
}
