//fichier test 2

#include <stdio.h>
#include <stdlib.h>
#define CAPACITEMAX 1000
//#define getName(var) #var
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

void difference(ensemble e1, ensemble e2, ensemble e3){
    e3[0]=e1[0];
    e3[1]=e1[1];
    
    for(int i= 2; i <= e1[1]+1; i++){
        if(e1[i] == e2[i]){
            e3[i]=0;
            e3[0]--;
        }
        else e3[i] = e1[i];
        //printf("%d ", e3[i]);
    }
    printf("%d\n", e3[0]);
    printlnEns(e3);
}

int main(){
    ensemble ens  = {5,6,1,1,1,0,1,1}; //ens = [ 0 1 2 4 ]
    ensemble ens1 = {2,7,0,0,0,1,0,1,0}; //ens1 = [ 1 2 ]
    ensemble ens2;
    printf("ens = [");
    printlnEns(ens);
    printf("ens1 = [");
    printlnEns(ens1);
    difference(ens,ens1,ens2);
    return EXIT_SUCCESS;
}