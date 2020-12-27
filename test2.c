//fichier test 2

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

void vide(ensemble e){// vide l'emsemble passé en paramètre
    printf("ens = [ ");
    e[0]=0;
    for (int i = 2; i <= e[1]+1; i++){
        e[i]=0;
        printf("%d ", e[i]);
    }
    printf("]\n");
}

int estVide(ensemble e){// test si un ensemble e est vide ou pas
    if (e[0]){
        printf("pas bon le tableau n'est pas vide\n");
        return 0;
    }
    printf("c'est bon le tableau est bien vide\n");
    return 1;
}


int main(){
    ensemble ens = {4,5,1,1,1,0,1}; //ens = [ 0 1 2 4 ]
    ensemble ens1 = {3,5,0,1,1,1,0}; //ens1 = [ 1 2 ]
    printlnEns(ens);
    vide(ens);
    estVide(ens);
    estVide(ens1);
    return EXIT_SUCCESS;
}