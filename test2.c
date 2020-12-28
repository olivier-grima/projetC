//fichier test 2

#include <stdio.h>
#include <stdlib.h>
#define CAPACITEMAX 1000
//#define getName(var) #var
typedef int ensemble[CAPACITEMAX+2];

void printEns(ensemble e){ // écrit un ensemble sur la sortie standard 
    //printf("ens = [ ");
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
    int k =0;
    int c = (e1[1]<=e2[1]) ? e1[1] : e2[1];
    //printf("%d\n",c);
    e3[1]=c;
    printf("ens2 = [ ");
    for(int i = 2; i <= c+1; i++){
        if (e1[i]==1 && e2[i]==1){
            e3[i]=1;
            k++;
        }
        else e3[i]=0;
        
        printf("%d ", e3[i]);  
    }
    printf("]");
    e3[0]=k;
    printf("capacité effective = %d et capacité totale = %d\n", e3[0], e3[1]);
}

int main(){
    ensemble ens  = {4,6,1,1,1,0,1,1}; //ens = [ 0 1 2 4 ]
    ensemble ens1 = {3,7,0,1,1,1,0,1,0}; //ens1 = [ 1 2 ]
    ensemble ens2;
    printf("ens = [");
    printlnEns(ens);
    printf("ens1 = [");
    printlnEns(ens1);
    intersection(ens,ens1,ens2);
    return EXIT_SUCCESS;
}