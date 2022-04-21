#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"
#include <string.h>

int main(int argc, char *argv[])
{
  // TODO: attempt to open scenario file and scan data into allocated structures
  FILE* file;
  char path[] = "./cs475-hwk7-bankers/";
  char *arg = argv[1];
  strcat(path, arg);
  printf("%s\n", path);
  file = fopen(arg, "r");
  int NRES; // number of resource types
  int NPROC; // number of processes
  if(argc == 1){ // if no file was inputted
    printf("Error: No file was inputted: ./bankers <filename>\n");
  }
  else{
    if(file != NULL){
      fscanf(file, "%d", &NRES);
      fscanf(file, "%d", &NPROC);
      int mat = malloc((NPROC*NRES)*sizeof(int));
      
    }else{ // if file does not exist
      printf("Error: File does not exist\n");
    }
  }
  // TODO: Run banker's safety algorithm

  return 0;
}