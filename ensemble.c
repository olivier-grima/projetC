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

void initEns(ensemble e, const int n){ //initialise un tableau de capacité n
    e[0]=0;
    e[1]=n;
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

int egal(ensemble e1, ensemble e2){ //test si les ensembles sont égaux ; hypothèse : les ensembles font la même taille -> capacités égales
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
    if(e[n+2]==1){
        return 1;
    }
    else return 0;
}

void ajouter(int n, ensemble e){ // ajoute un entier n à un ensemble e
    e[n+2]=1;
    e[0]+=1;
}

void enlever(int n, ensemble e){ //enlève un entier n d’un ensemble e ;
    e[n+2]=0;
    e[0]-=1;
}

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
    e3[0] =0; // on initialise la capacité effective de e3
    e3[1]=e1[1]; // capacité totale de l'ensemble e3

    for(int i = 2; i <= e1[1]+1; i++){
        if ((e1[i]==1 && e2[i]==1) || (e1[i]==0 && e2[i]==0)){ //il s'agit d'une intersection des deux ensemble ou les deux ensemble sont vide pour cette valeur
            e3[i]=0; // aucune valeur n'est donc affectée à e3
        }
        else{
            e3[i]=1; // pas d'intersection entre e1 e2 ni de double tableau vide donc valeur ajouté à e3
            e3[0]++; // la capacité effective de e3 augmente
        } 
    }
}

//-----------------------------Crible d'Erasthostène------------------------------------------//

void nbPremiers(int n, ensemble resultat){
  ensemble crible; 
  initEns(crible,n+1);
  plein(crible);
  enlever(0, crible);
  enlever(1, crible);

  int i = 4;
  int multiple;

  while(estVide (crible)==0){
    
    if(crible[i]==1){

      ajouter(i-2, resultat);
      enlever(i-2, crible);
      multiple = 2*(i-2);

      while(multiple <= crible[1]-1){ //enlève tous les multiples

        if(crible[multiple+2]==1){ //vérifie si le multiple a déjà été enlevé ou non
          enlever(multiple, crible);
        }
        multiple += (i-2);
      }
    }
    i++;
  }
}

//-----------------------------Fin des procédures------------------------------------------//






//-----------------------------Test------------------------------------------//

int main(){
//-----------------------------Ensemble------------------------------------------//
    ensemble e1, e2, e3, e4;
    //déclarer et initialiser 2 ensembles e1 et e2 à une capacité de 50 
    initEns(e1, 50);
    initEns(e2, 50); 
    //ajouter 2, 19, 31 dans e1 et 10, 19, 34 dans e2 -> e1 = [ 2 19 31 ] e2 = [ 10 19 34 ]
    ajouter(2,e1);
    ajouter(19,e1);
    ajouter(31,e1);
    ajouter(10,e2);
    ajouter(19,e2);
    ajouter(34,e2);
    //écrire sur la s/s les ensembles e1 et e2 -> e1 = [ 2 19 31 ] e2 = [ 10 19 34 ]
    printf("e1 = ");
    printlnEns(e1);
    printf("e2 = ");
    printlnEns(e2);
    //tester si 10 et 19 appartiennent à e1 -> 0 et 1
    printf("%d\n",appartient(10,e1));
    printf("%d\n",appartient(19,e1));
    //ajouter 33 à e1 et e2
    ajouter(33,e1);
    ajouter(33,e2);
    //écrire sur la s/s les ensembles e1 et e2 -> e1 = [ 2 19 31 33 ] e2 = [ 10 19 33 34 ]
    printf("e1 = ");
    printlnEns(e1);
    printf("e2 = ");
    printlnEns(e2);
    //écrire sur la s/s, l’intersection de e1 et e2 -> e1 n e2 = [ 19 33 ]
    intersection(e1,e2,e3);
    printf("e1 n e2 = ");
    printlnEns(e3);
    //écrire sur la s/s, l’union de e1 et e2 -> e1 u e2 = [ 2 10 19 31 33 34 ]
    Union(e1,e2,e3);
    printf("e1 U e2 = ");
    printlnEns(e3);
    //écrire sur la s/s, la différence de e1 et e2 -> e1 - e2 = [ 2 31 ]
    difference(e1,e2,e3);
    printf("e1 - e2 = ");
    printlnEns(e3);
    //écrire sur la s/s, le complémentaire de e1 -> ~e1 = [ 0 1 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 20 21 22 23 24 25
    //26 27 28 29 30 32 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 ]
    complementaire(e1,e3);
    printf("~e1 = ");
    printlnEns(e3);
    //vide(e3);
    //écrire sur la s/s, la différence symétrique de e1 et e2 -> e1 delta e2 = [ 2 10 31 34 ]
    diffSym(e1,e2,e3);
    printf("e1 delta e2 = ");
    printlnEns(e3);
    //vérifier que le complémentaire de intersection de e1 et e2 est la réunion de leurs complémentaires (loi de De Morgan) -> De Morgan : 1
    intersection(e1,e2,e3); //e3 = e1 n e2
    complementaire(e3,e3); //e3 = ~(e1 n e2)
    complementaire(e1,e1); //e1 = ~e2
    complementaire(e2,e2); //e2 = ~e3
    Union(e1,e2,e4); //e4 = ~e1 U ~e2
    printf("De Morgan : %d\n", egal(e3,e4));
    complementaire(e2,e2); //annule le complémentaire fait plus tôt pour continuer avec l'affectation
    //affecter e2 à e1 et vérifier que e1 = e2 -> affectation : e1 = e2 => e1==e2 = 1
    affecter(e1,e2);
    printf("affectation : e1 = e2 => e1==e2 = %d\n", egal(e1,e2));

//-----------------------------Crible------------------------------------------//
    int n = 22;
    ensemble resultat;
    initEns(resultat,n+1);
    nbPremiers(n, resultat);
    printf("Les nombres premiers compris entre 2 et %d sont : ",n);
    printlnEns(resultat);

    return EXIT_SUCCESS;
}