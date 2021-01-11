/* crible d'Erastosthène */

#include <stdio.h>
#define CAPACITEMAX 1000
typedef int ensemble[CAPACITEMAX+2];

void initEns(ensemble e, int n){ //initialise un tableau de capacité n
    e[0]=0;
    e[1]=n;
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

void plein(ensemble e){ // remplit l'ensemble passé en paramètre
    e[0]=e[1];
    for(int i=2; i<=e[1]+1; i++){
        e[i]=1;
    }
}

void ajouter(int n, ensemble e){ // ajoute un entier n à un ensemble e
    e[n+2]=1;
    e[0]-=1;
}

void enlever(int n, ensemble e){ //enlève un entier n d’un ensemble e ;
    e[n+2]=0;
    e[0]-=1;
}

int estVide(ensemble e){// test si un ensemble e est vide ou pas
    if (e[0]) return 0; //tableau non vide
    return 1; //tableau vide
}


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

int main(){
  int n = 22;
  ensemble resultat;
  initEns(resultat,n+1);
  nbPremiers(n, resultat);
  printlnEns(resultat);

}
