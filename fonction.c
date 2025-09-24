#include<stdio.h>
#include"fonction.h"

// fonction d'affichage matrice
void afficher(int n, int m, int T[n][m]){
    for(int i = 0; i < n; i++){
        printf(" [");
        for(int j = 0; j < m; j++){
            printf("%d", T[i][j]);
            if(j < m-1) printf(" ");
        }
        printf("]");
        if(i < n-1) printf(" ");
        printf("\n");
    }
}

// fonction de sommatrice (identique à afficher)
void afficher1(int n, int m, int T[n][m]){
    afficher(n, m, T);
}

// fonction de recherche
void recherche(int n, int T[], int b){
    int trouve = 0;
    for (int i = 0; i < n; i++) {
        if (T[i] == b) {
            printf("Recherche terminee\n");
            printf("Trouve a la position %d\n", i+1);
            trouve = 1;
            break; // Arrêter après avoir trouvé la première occurrence
        }
    }
    if (!trouve) {
        printf("Element introuvable\n");
    }
}

// fonction de multiplication
void multipli(int a, int b){
    int resultat = 0;
    int d = a;
    
    for (int i = 0; i < b; i++) {
        resultat += a;
        printf("%dième tour : %d\n", i+1, resultat);
    }
    printf("%d * %d = %d\n", d, b, resultat);
}

// fonction de verification
void check(int n, int T[]){
    int trie = 1;
    for (int i = 0; i < n-1; i++) {
        if (T[i] > T[i+1]) {
            printf("Tableau non trie\n");
            trie = 0;
            break;
        }
    }
    if (trie) {
        printf("Tableau trie\n");
    }
}

void afficher2(int n, int T[]){
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d", T[i]);
        if(i < n-1) printf(" ");
    }
    printf(" ]\n"); 
}

// fonction de la mediane
void mediane(int n,int T[]){
    int minindex,temp;
for (int i = 0; i < n-1; i++){
    minindex=i;
    for(int j=i+1; j<n;j++){
        if(T[j]<T[minindex]){
         minindex=j;
        }
    }
    temp=T[minindex];
    T[minindex]=T[i];
    T[i]=temp;
}
printf("[");
for (int i = 0; i < n; i++)
{
    printf("%d",T[i]);
    if(i<n-1) printf(" ");
}
printf("]");
if (n%2 == 1)
{
    printf("\n");
    printf("tableau impaire\n");
    printf("Mediane %d:",T[n/2]);
}else{
    printf("\nTableau paire\n");
    double media=(T[n/2]+T[n/2-1])/2.0;
    printf("Mediane %f",media);
}

}

// fonction d'inversion
void inverse(int n, int T[]){
    printf("[ ");
    for (int i = n-1; i >= 0; i--) {
        printf("%d", T[i]);
        if(i > 0) printf(" ");
    }
    printf(" ]\n");
}

// fonction du produit vectoriel
void produitvect(int U[3], int V[3]){
    int T[3];
    T[0] = U[1]*V[2] - U[2]*V[1];
    T[1] = U[2]*V[0] - U[0]*V[2];
    T[2] = U[0]*V[1] - U[1]*V[0];
    printf("Produit vectoriel: [%d, %d, %d]\n", T[0], T[1], T[2]);
}

// fonction du produit vecteur matrice 
void produit(int n, int a, int m, int T[], int T1[a][m]){
    int A[m];
    
    // Initialiser le résultat à 0
    for (int j = 0; j < m; j++) {
        A[j] = 0;
    }
    
    // Vérifier la compatibilité des dimensions
    if (n != a) {
        printf("Dimensions incompatibles: taille du vecteur (%d) != lignes de la matrice (%d)\n", n, a);
        return;
    }
    
    // Calcul du produit
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            A[j] += T[i] * T1[i][j];
        }
    }
    
    printf("Resultat: [");
    for (int j = 0; j < m; j++) {
        printf("%d", A[j]);
        if (j < m-1) printf(" ");
    }
    printf("]\n");
}