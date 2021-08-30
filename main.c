#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int *create_array(int);
char *create_String(int);
void destroy_array(int *);
void destroy_String(char *);

int main(int argc, char *argv[]){

    FILE *inFile = fopen("./fin", "r");
    FILE *inFileOut = fopen("./fout", "a+");
    char *auxop = create_String(10);
    char **op = &auxop;
    int *auxparr = create_array(20);
    int **parr = &auxparr;
    int *length;

    if(inFile == NULL){
        perror("Open File fin Fails :");
        return(EXIT_FAILURE);
    }
    if(inFileOut == NULL){
        perror("Open File fout fails: ");
        return(EXIT_FAILURE);
    }
    for(int i=0;i<8;i++){
        if(i ==1 ) feature1(inFile,inFileOut);
        if(i ==2 ) feature2(inFile,inFileOut);
        if(i ==3 ) feature3(inFile,inFileOut);
<<<<<<< HEAD
        //if(i ==4 ) feature4(inFile, parr, length, op);                
        //if(i == 7) feature7(inFileOut,&pobj);
=======
>>>>>>> main
    }
        destroy_array(auxparr);
    destroy_String(auxop);
    
    fclose(inFile);
    fclose(inFileOut);
    
    return EXIT_SUCCESS;
}

int *create_array(int size){
    return (int * ) malloc(size * sizeof(int));
}

char *create_String(int size) {
    return (char * ) malloc(size  * sizeof(char));
}

void destroy_array(int *this){
    free(this);
}

void destroy_String(char *this){
    free(this);
}