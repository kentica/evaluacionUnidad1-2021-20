#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[]){

    FILE *inFile = fopen("./fin","r");
    FILE *inFileOut = fopen("./fout","a+");
    if(inFile == NULL){
        perror("Open File fin Fails :");
        return(EXIT_FAILURE);
    }
    if(inFileOut == NULL){
        perror("Open File fout fails: ");
        return(EXIT_FAILURE);
    }
<<<<<<< HEAD
    for(int i=0;i<8;i++){
        if(i ==1 ) feature1(inFile,inFileOut);
        if(i ==2 ) feature2(inFile,inFileOut);
=======
    for(int i=0;i<6;i++){
        if(i ==1 ) feature1(inFile,inFileOut);
>>>>>>> main
    }
    
    fclose(inFile);
    fclose(inFileOut);
}

