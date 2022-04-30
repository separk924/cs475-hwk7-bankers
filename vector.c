#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// TODO - Define vector and matrix operations
int *clone(int *the_vect){
    // clone vectors/matrices
    int i;
    int *vect = malloc((m)*sizeof(int));
    for(i=0;i<m;i++){
        vect[i] = the_vect[i];
    }
    return vect;
}

void add(int *vect1, int *vect2){
    // add 2 vectors/matrices
    for (int i = 0; i < m; i++)
    {
        vect1[i] += vect2[i];
    }
}

void printMat(int *mat){
    // print contents of vectors/matrices
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){;
            printf("%d ", mat[i*m+j]);
        }printf("\n");
    }
}