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



//-----------------------------Procédures------------------------------------------//

void initEns(ensemble e, int n){ //initialise un tableau de capacité n
    e[1]=n; 
    //not finished
}

void vide(ensemble e){// vide l'emsemble passé en paramètre
    e[0] = 0;
    for (int i = 2; i <= e[1]+1; i++){
        e[i]=0;
    } 
}

void plein(ensemble e){ // remplit l'ensemble passé en paramètre
    e[0]=e[1];
    for(int i=2; i<=e[1]+1; i++){
        e[i]=1;
    }
}

int estVide(ensemble e){// test si un ensemble e est vide ou pas
    if (e[0]) return 0; //tableau non vide
    return 1; //tableau vide
}

int egal(ensemble e1, ensemble e2){ //hypothèse : les ensembles font la même taille -> capacités égales
    if (e1[0]==e2[0]){ //test si même nbr d'élément 
        for(int k=2; k<=e1[1]+1; k++){
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

void affecter(ensemble e1, ensemble e2){// affecte un ensemble e2 à un ensemble e1
     for (int i = 0; i <= e2[1]+1; i++){
         e1[i]=e2[i]; // affecte un à un les éléments de e2 à e1
     }
}

int appartient(int n, ensemble e){ //teste si entier n appartient à un ensemble e ;
    if(e[n+2]==n){
        return 1;
    }
    else return 0;
}

int ajouter(int n, ensemble e){ // ajoute un entier n à un ensemble e
    e[n+2]=n;
    return EXIT_SUCCESS;
}

int enlever(int n, ensemble e){ //enlève un entier n d’un ensemble e ;
    e[n+2]=0;
    return EXIT_SUCCESS;
}

void printEns(ensemble e){ // écrit un ensemble sur la sortie standard 
    printf("ens = [ ");
    for (int i=2; i <=e[1]+1; i++){
        if(e[i]==1){
            printf("%d ",i-2);
        } 
    }
    printf("]");
}

void printlnEns(ensemble e){ //écrit un ensemble e sur la sortie standard suivi d’un passage à la ligne ; e1 = [ 2 19 31 33 ]
    printEns(e);
    printf("]\n");
}

void intersection(ensemble e1, ensemble e2, ensemble e3){ // calcul si e3 est égale à l'intersection de e1 et e3. Hypothèse : les ensembles e1 et e2 ont la même capacité.
    e3[0] =0; // on initialise la capacité effective de e3
    e3[1]=e1[1]; // capacité totale de l'ensemble e3

    for(int i = 2; i <= e1[1]+1; i++){
        if (e1[i]==1 && e2[i]==1){ //il s'agit d'une intersection des deux ensemble, la valeur est alors ajoutée à e3
            e3[i]=1;
            e3[0]++; // la capacité effective de e3 augmente
        }
        else e3[i]=0; // pas d'intersection, donc pas de valeur ajoutée à e3
    }
}

void Union(ensemble e1, ensemble e2, ensemble e3){ //calcule e3 = e1 U e2 ; hypothèse capacités egales
    e3[0]=e1[0]+e2[0]; //nbr d'éléments dépend de l'union
    e3[1]=e1[1]; //capacités égales
    for (int i=2; i <=e1[1]+1; i++){
        if(e1[i]==1 || e2[i]==1){
            e3[i]=1;
            if(e1[i]==1 && e2[i]==1){ 
                e3[0]-=1;
            }
        }
    }
}

void difference(ensemble e1, ensemble e2, ensemble e3){ // calcul un ensemble e3 qui est la différence des ensemble e1 et e2
    e3[0]=e1[0];
    e3[1]=e1[1];
    
    for(int i= 2; i <= e1[1]+1; i++){
        if(e1[i] == e2[i]){
            e3[i]=0;
            e3[0]--;
        }
        else e3[i] = e1[i];
    }
}

void complementaire(ensemble e1, ensemble e2){ //calcule e2 complémentaire de e1 dans l’ensemble plein
    e2[1]=e1[1];
    e2[0]=e1[1]-e1[0];
    for(int i=2; i<=e1[1]+1; i++){
        if(e1[i]==0){
            e2[i]=1;
        }
        else {
            e2[i]=0;
        }    
    }
}

void diffSym(ensemble e1, ensemble e2, ensemble e3){ // calcul la différence symétrique des ensembles e1 et e2
}

//-----------------------------Test------------------------------------------//

int main(){
    printf("hello world");
    return EXIT_SUCCESS;
}









