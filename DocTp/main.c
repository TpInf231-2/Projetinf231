#include"fonction.h"

int main(){
    int x; 
    
    do {
        printf("\nQUE SOUHAITEZ VOUS FAIRE?\n");
        printf("1-SOMME DE DEUX MATRICES\n");
        printf("2-PRODUIT DE MATRICES\n");
        printf("3-RECHERCHE D'UN ELEMENT\n");
        printf("4-MULTIPLICATION PAR ADDITION SUCCESSIVES\n");
        printf("5-VERIFIER SI UN TABLEAU EST TRIE\n");
        printf("6-DETERMINER LA MEDIANE D'UN TABLEAU STATISTIQUE\n");
        printf("7-INVERSER L'ORDRE DES ELEMENTS D'UN TABLEAU\n");
        printf("8-EFFECTUER LE PRODUIT VECTORIEL\n");
        printf("9-EFFECTUER LE PRODUIT VECTEUR MATRICE\n");
        printf("10-QUITTER\n");
        printf("Votre choix: ");
        scanf("%d", &x);

        switch (x) {
            case 1: {
                int n, m;
                printf("Entrer les dimensions des matrices: ");
                scanf("%d %d", &n, &m);
                
                int T[n][m], T1[n][m], U[n][m];
                
                printf("Elements de la premiere matrice:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("T[%d][%d]: ", i, j);
                        scanf("%d", &T[i][j]);
                    }
                }
                printf("Premiere matrice:\n");
                afficher(n, m, T);
                
                printf("Elements de la seconde matrice:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("T1[%d][%d]: ", i, j);
                        scanf("%d", &T1[i][j]);
                    }
                }
                printf("Deuxieme matrice:\n");
                afficher(n, m, T1);
                
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        U[i][j] = T[i][j] + T1[i][j];
                    }
                }
                printf("Resultat de la somme:\n");
                afficher(n, m, U);
                break;
            }
            
            case 2: {
                int L1, C1, L2, C2;
                printf("Entrer le nombre de ligne et de colonne de la premiere matrice: ");
                scanf("%d %d", &L1, &C1);
                printf("Entrer le nombre de ligne et de colonne de la seconde matrice: ");
                scanf("%d %d", &L2, &C2);
                
                if (C1 != L2) {
                    printf("Produit impossible: nombre de colonnes de la premiere doit egaler nombre de lignes de la seconde\n");
                } else {
                    int T[L1][C1], T1[L2][C2], T2[L1][C2];
                    
                    printf("Entrer les elements de la premiere matrice:\n");
                    for(int i = 0; i < L1; i++) {
                        for(int j = 0; j < C1; j++) {
                            printf("T[%d][%d]: ", i, j);
                            scanf("%d", &T[i][j]);
                        }
                    }
                    
                    printf("Premiere Matrice:\n");
                    afficher(L1, C1, T);
                    
                    printf("Entrer les elements de la seconde matrice:\n");
                    for(int i = 0; i < L2; i++) {
                        for(int j = 0; j < C2; j++) {
                            printf("T1[%d][%d]: ", i, j);
                            scanf("%d", &T1[i][j]);
                        }
                    }
                    
                    printf("Seconde matrice:\n");
                    afficher(L2, C2, T1);
                    
                    for(int i = 0; i < L1; i++) {
                        for(int j = 0; j < C2; j++) {
                            T2[i][j] = 0;
                            for(int k = 0; k < C1; k++) {
                                T2[i][j] += T[i][k] * T1[k][j];
                            }
                        }
                    }
                    
                    printf("Resultat du produit:\n");
                    afficher(L1, C2, T2);
                }
                break;
            }
            
            case 3: {
                int n;
                printf("Entrer la taille du tableau: ");
                scanf("%d", &n);
                int T[n];
                
                printf("Elements du tableau:\n");
                for (int i = 0; i < n; i++) {
                    printf("T[%d]: ", i);
                    scanf("%d", &T[i]);
                }
                
                printf("Tableau: [ ");
                for (int i = 0; i < n; i++) {
                    printf("%d", T[i]);
                    if(i < n-1) printf(" ");
                }
                printf(" ]\n");
                
                int a;
                printf("Entrer l'element a rechercher: ");
                scanf("%d", &a);
                recherche(n, T, a);
                break;
            }
            
            case 4: {
                int n, m;
                printf("Entrer les deux nombres: ");
                scanf("%d %d", &n, &m);
                multipli(n, m);
                break;
            }
            
            case 5: {
                int n;
                printf("Entrer la taille du tableau: ");
                scanf("%d", &n);
                int A[n];
                
                printf("Remplir le tableau:\n");
                for (int i = 0; i < n; i++) {
                    printf("Element %d: ", i+1);
                    scanf("%d", &A[i]);
                }
                
                afficher2(n, A);
                check(n, A);
                break;
            }
            
            case 6: {
                int a;
                printf("Entrer la taille du tableau: ");
                scanf("%d", &a);
                int T[a];
                
                printf("Entrer les elements du tableau:\n");
                for (int i = 0; i < a; i++) {
                    printf("T[%d]: ", i);
                    scanf("%d", &T[i]);
                }
                
                mediane(a, T);
                break;
            }
            
            case 7: {
                int n;
                printf("Entrer la taille du tableau: ");
                scanf("%d", &n);
                int B[n];
                
                printf("Remplir le tableau:\n");
                for (int i = 0; i < n; i++) {
                    printf("Element %d: ", i);
                    scanf("%d", &B[i]);
                }
                
                printf("Tableau original: [ ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", B[i]);
                }
                printf("]\n");
                
                printf("Tableau inverse: ");
                inverse(n, B);
                break;
            }
            
            case 8: {
                int U[3], V[3];
                printf("Entrer les coordonnees du premier vecteur (x y z): ");
                scanf("%d %d %d", &U[0], &U[1], &U[2]);
                printf("Entrer les coordonnees du deuxieme vecteur (x y z): ");
                scanf("%d %d %d", &V[0], &V[1], &V[2]);
                produitvect(U, V);
                break;
            }
            
            case 9: {
                int n, a, m;
                printf("Entrer la taille du vecteur: ");
                scanf("%d", &n);
                printf("Entrer le nombre de ligne et de colonne de la matrice: ");
                scanf("%d %d", &a, &m);
                
                if(n != a) {
                    printf("Produit impossible: taille du vecteur doit egaler nombre de lignes de la matrice\n");
                    break;
                }
                
                int T[n], T1[a][m];
                
                printf("Entrer les coordonnees du vecteur:\n");
                for (int i = 0; i < n; i++) {
                    printf("Element %d: ", i);
                    scanf("%d", &T[i]);
                }
                
                printf("Entrer les elements de la matrice:\n");
                for (int i = 0; i < a; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("Element [%d][%d]: ", i, j);
                        scanf("%d", &T1[i][j]);
                    }
                }
                
                produit(n, a, m, T, T1);
                break;
            }
            
            case 10:
                printf("Au revoir!\n");
                break;
                
            default:
                printf("CHOIX INVALIDE\n");
                break;
        }
    } while (x != 10);
    
    return 0;
}