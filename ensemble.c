//Olivier GRIMA et Océane MOFID
//ELEC3, TDB.

//exemple : 
//ensemble e = {1,4,5} de capacité 10
//présence de l'entier -> 1  
//absence de l'entier -> 0  
//tableau e = {3,10,0,1,0,0,1,1,0,0,0,0}

//-----------------------------Déclarations------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CAPACITEMAX 1000
typedef int ensemble[CAPACITEMAX+2];
#define getName(var)  #var


//-----------------------------Procédures------------------------------------------//

void initEns(ensemble e,int n){ //initialise un tableau de capacité n
    ensemble e; 
}

//

void plein(ensemble e){ // remplit l'ensemble passé en paramètre
    e[0]=e[1];
    for(int i = 2; i<=e[1]+1; i++){
        e[i]=1;
    }
}

//

int egal(ensemble e1,ensemble e2){ //hypothèse : les ensembles font la même taille -> capacités égales
    int i=2;
    if (e1[0]==e2[0]){ //test si même nbr d'élément 
        for(int k=2; k<e1[1]+1; k++){
           if(e1[k]!=e2[k]){ //s'arrête dès que des elem ont des val différentes 
                return 0; //ensembles différents
            } 
        }
        return 1; //ensembles égaux
    }
    else{
        return 0; //ensembles ne comportent pas le même nbr d'éléments -> forcément non égaux
    }    
}

//

int appartient(int n, ensemble e){ //teste si entier n appartient à un ensemble e ;
    if(e[n+2]==n){
        return 1;
    }
    else return 0;
}

//

int enlever(int n, ensemble e){ //enlève un entier n d’un ensemble e ;
    e[n+2]=0;
    return EXIT_SUCCESS;
}

//

void printlnEns(ensemble e){ //écrit un ensemble e sur la sortie standard suivi d’un passage à la ligne ; e1 = [ 2 19 31 33 ]
    printf("ens = [ "); //nom de l'array
    for (int i = 2; i <=e[1]+1; i++){
        if(e[i]==1){
            printf("%d ",i-2);
        } 
    }
    printf("]\n");
}

//

void Union(ensemble e1, ensemble e2, ensemble e3){ //calcule e3 = e1 U e2 ;
    for (int i = 2; i <=e1[1]+1; i++){
        if(e1[i]==1 || e2[i]==1){
            e3[i]=1;
        }
    }
    //not finished
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









