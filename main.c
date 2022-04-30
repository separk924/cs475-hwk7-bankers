#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"
#include <string.h>

int main(int argc, char *argv[])
{
  // TODO: attempt to open scenario file and scan data into allocated structures
  int *available;
  int **max;
  int **alloc;
  FILE* file;
  if(argc == 1){ // if no file was inputted
    printf("Usage: ./bankers <scenario file>\n");
  }else{
    char *arg = argv[1];
    file = fopen(arg, "r");
    int NRES; // number of resource types
    int NPROC; // number of processes
      if(file != NULL){
        fscanf(file, "%d", &NRES);
        m = NRES;
        fscanf(file, "%d", &NPROC);
        n = NPROC;
        
        /*  allocate space for available vector  */
        int i,j;
        available = malloc((NRES)*sizeof(int));
        /*  allocate space for max matrix  */
        max = (int**)malloc((NPROC)*sizeof(int*));
        for (int i = 0; i < NPROC; i++)
        {
          max[i] = (int*)malloc(NRES*sizeof(int));
        }
        /*  allocate space for alloc matrix  */
        alloc = (int**)malloc((NPROC)*sizeof(int*));
        for (int i = 0; i < NPROC; i++)
        {
          alloc[i] = (int*)malloc(NRES*sizeof(int));
        }
        /*  get available vector */
        for(i=0;i<NRES;i++)
        {
          fscanf(file, "%d", &available[i]);
        }
        /*  get max matrix */
        for(i=0;i<NPROC;i++){
          for(j=0;j<NRES;j++){
            fscanf(file, "%d", &max[i][j]);
          }
        }
        /*  get alloc matrix */
        for(i=0;i<NPROC;i++){
          for(j=0;j<NRES;j++){
            fscanf(file, "%d", &alloc[i][j]);
          }
        }

        /** check if safe **/
        isSafe(available, max, alloc);

      }else{ // if file does not exist
        printf("Error: File does not exist\n");
      }
  }
  // TODO: Run banker's safety algorithm
  free(available);
  for (int i = 0; i < m; i++)
  {
    free(max[i]);
    free(alloc[i]);
  }
  return 0;
}