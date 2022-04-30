#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h" 

// TODO - Safety Algorithm goes here
void isSafe(int *available, int **max, int **alloc)
{
    /*  clone available vector */
    int *work = malloc(m*sizeof(int));
    work = clone(available);

    /*  subtract allocated resources from the total work vector */
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            work[j] -= alloc[i][j];
        }
    }
    
    /*  allocate space for finish array */
    int *finish = malloc(n*sizeof(int));
    int j, i;
    /*  allocate space for the array of finished threads */
    int *num = malloc(n*sizeof(int));
    int ind = 0;

    /*  allocate space for need matrix */
    int **need = (int**)malloc((n)*sizeof(int*));
    for (i = 0; i < n; i++){
        need[i] = (int*)malloc(m*sizeof(int));
    }
    /*  calculate for need matrix */
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        } 
    }
    
    /*  initialize finish array with zeros  */
    for(i=0;i<n;i++){
        finish[i] = 0;
    }
    /*  BANKER'S ALGORITHM  */
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if(finish[j] == 0){
                int flag = 0;
                for (int k = 0; k < m; k++){
                    if(need[j][k] > work[k]){ // if there are not enough resources available yet
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){ // if there are enough resources
                    // add the thread into the finished threads array
                    num[ind++] = j; 
                    // add the allocated resources into the work vector
                    add(work, alloc[j]); 
                    // indicate that thread is completed in finish array
                    finish[j] = 1;
                }
                
            }
        }
        
    }
    /*  allocate space for the array of unfinished threads */
    int *incomplete = malloc(n*sizeof(int));
    int length = 0;
    /*  The array of incomplete threads */
    for (i = 0; i < n; i++){
        if(finish[i]==0){
            incomplete[length++] = i;
        }
    }
    
    
    int flag = 1;
    for (int i = 0; i < n; i++){
        if(finish[i]==0){
            flag = 0;
            printf("Unsafe: ");
            for (j = 0; j < length; j++){
                printf("T%d ", incomplete[j]);
            }printf("can't finish\n");
            break;
        }
    }
    
    if(flag == 1){
        printf("Safe:   ");
        for (i = 0; i < n-1; i++){
            printf("T%d, ", num[i]);
        }
        printf("T%d\n", num[n-1]);
    }
    free(work);
    free(finish);
    free(num);
    free(incomplete);
    free(need);
}