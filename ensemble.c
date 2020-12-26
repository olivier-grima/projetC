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

void initEns(int n){ 
    ensemble e[n+2]; //initialise un tableau de capacité n
}

//

void plein(ensemble e[]){ // remplit l'ensemble passé en paramètre
    int N=e[1];
    //e[0]=?; //cardinalité effective -> nbr d'éléments
    //e[1] = {N-2}; //capacité effective -> capacité
    for(int i = 2; i<=N-1; i++){
        //e[i]=1; -> error assignment
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

        for(int k=2;k<CAPACITEMAX+2;k++){
            //compare chaque élément (0 ou 1)
           if(e1[i]==e2[i]){
                egaux=1;
                i++;
            } 
            else {
                egaux=0; //s'arrête dès que des elem sont différents 
                return 0; //ensembles différents
            }
        //boucle infinie ??
        }
        return 1; //ensembles égaux
    }
    else{
        return 0;
    }     //ensembles différents
    //not finished
}

//

int appartient(int n,ensemble ens[]){ //teste si entier n appartient à un ensemble e ;
    if(ens[n+2]==n){
        return 1;
    }
    else return 0;
}

//

int enlever(int n,ensemble ens[]){ //enlève un entier n d’un ensemble e ;
    //ens[n+2]=0;
    return EXIT_SUCCESS;
}

void printlnEns(ensemble ens[]){ //printlnEns (1 paramètre), écrit un ensemble e sur la sortie standard 
                        //suivi d’un passage à la ligne ; e1 = [ 2 19 31 33 ]
    printf("%s = "); //nom de l'array
    for (int i = 2; i < ens[1]-1; i++){
        printf("%d",ens[i]); 
    }
    printf("]\n");

}

//

void Union(int x,int y,int z){


}

//

void complementaire(int x,int y){


}

//

//-----------------------------Test------------------------------------------//

int main(){

    printf("hello world");
    return EXIT_SUCCESS;
}









