//fichier test 2

#include <stdio.h>
#include <stdlib.h>
#define CAPACITEMAX 1000
//#define getName(var) #var
typedef int ensemble[CAPACITEMAX+2];


void printlnEns(ensemble e){ //écrit un ensemble e sur la sortie standard suivi d’un passage à la ligne ; e1 = [ 2 19 31 33 ]
    //printf("%s = [ ", getName(e)); //nom de l'array
    //char nom[]= e;
    //printf("%s =[ ", e);
    for (int i = 2; i <=e[1]+1; i++){
        if(e[i]==1){
            printf("%d ",i-2);
        } 
    }
    printf("]\n");
}

void affecter(ensemble e1, ensemble e2){// affecte un ensemble e2 à un ensemble e1
    printf("[ ");
     for (int i = 0; i <= e2[1]+1; i++){
         e1[i]=e2[i];
         printf("%d ", e1[i]);
     }
    printf("]\n");
}

int main(){
    ensemble ens = {4,5,1,1,1,0,1}; //ens = [ 0 1 2 4 ]
    ensemble ens1 = {3,5,0,1,1,1,0}; //ens1 = [ 1 2 ]
    printf("ens = [");
    printlnEns(ens);
    printf("ens1 = [");
    printlnEns(ens1);
    affecter(ens, ens1);
    return EXIT_SUCCESS;
}