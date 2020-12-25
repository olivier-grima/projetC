//Olivier GRIMA et Océane MOFID
//ELEC3, TDB.

//exemple :
//ensemble e = {1,4,5} de capacité 10
//présence de l'entier -> 1
//absence de l'entier -> 0
//tableau e = [3,10,0,1,0,0,1,1,0,0,0,0]


//-----------------------------Déclarations------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CAPACITEMAX 1000
typedef int ensemble[CAPACITEMAX+2];

//-----------------------------Procédures------------------------------------------//

void initEns(int ensemble e[CAPACITEMAX+2], int n){ //initialise à vide l'ensemble passé en paramètre

    int ensemble e[n+2]; 
    //not finished
}

//

void plein(ensemble e[int N]){ // remplit l'ensemble passé en paramètre
    
    e[0]=?; //cardinalité effective -> nbr d'éléments
    e[1]=N-2; //capacité effective -> capacité
    for(int i = 2; i<=N-1){
        e[i]=1;
    }
    //not finished
}

//

int egal(ensemble e1[],ensemble e2[]){
    int egaux;
    int i=2;
    if (e1[0]==e2[0]){ //test si même nbr d'élément
        //tester chaque élém ? condition : avoir même capacité pour pouvoir comparer ?
        //int max = fmax(e1[1], e2[1]); //prend la capacité max 

        //boucle for ?
            //compare chaque élément (0 ou 1)
           if(e1[i]=e2[i]){
                egaux=1;
                i++;
            } 
            else {
                egaux=0; //s'arrête dès que des elem sont différents 
                return -1; //ensembles différents
            }
        //boucle infinie ??
        //return 1; //ensembles égaux
        

    else return -1; //ensembles différents

    }
    //not finished
}

//

void appartient(x,y){


}

//

void enlever(x,y){


}

void printlnEns(x){


}

//

void Union(x,y,z){


}

//

void complementaire(x,y){


}

//

//-----------------------------Test------------------------------------------//

int main(){

    printf("hello world");
    return EXIT_SUCCESS;
}









