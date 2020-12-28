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

void intersection(ensemble e1, ensemble e2, ensemble e3){ // calcul si e3 est égale à l'intersection de e1 et e3. Hypothèse : 
    e3[0] =0;
    e3[1]=e1[1]; // capacité totale de l'ensemble e3 est égale à la capacité du plus petit des ensemble e1, e2

    for(int i = 2; i <= e1[1]+1; i++){
        if (e1[i]==1 && e2[i]==1){ //il s'agit d'une intersection des deux ensemble, la valeur est alors ajouté à e3
            e3[i]=1;
            e3[0]++;
        }
        else e3[i]=0; // pas d'intersection, donc pas de valour ajoutée à e3
        printf("%d ", e3[i]);
    }
    printf("\n%d\n",e3[0]);
    printf("%d\n",e3[1]);
    printlnEns(e3);
}

int main(){
    ensemble ens  = {5,6,1,1,1,0,1,1}; //ens = [ 0 1 2 4 ]
    ensemble ens1 = {3,6,0,1,0,1,0,1}; //ens1 = [ 1 2 ]
    ensemble ens2;
    printf("ens = [");
    printlnEns(ens);
    printf("ens1 = [");
    printlnEns(ens1);
    intersection(ens,ens1,ens2);
    return EXIT_SUCCESS;
}