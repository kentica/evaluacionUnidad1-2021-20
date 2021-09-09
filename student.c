#include <stdlib.h>
#include "student.h"
#include <string.h>

#define max_long 250


void feature1(FILE *fin, FILE *fout){

    char* bufer = (char *)calloc(max_long,sizeof(char));// se reservan esa cantidad de espacios para char bufer(memoria dinamica)
    fgets(bufer,max_long,fin);//que me lea hasta el salto de linea con el fgets
    fprintf(fout,"%s\n",bufer);
    free(bufer);//Libero memoria de el bufer
}
void feature2(FILE *fin, FILE *fout){
    char* bufer = (char *)calloc(max_long,sizeof(char));
    fgets(bufer,max_long,fin);
    char* temp = (char *)calloc(1,sizeof(char));    
    char* bufer2 = strtok(bufer,"\n");
    int lon = strlen(bufer2);
    for(int i=0;i<(lon/2);i++){//ciclo para Leer al reves el texto siendo el indice i
        *temp = bufer2[i];
        bufer2[i] = bufer2[lon - i - 1];
        bufer2[lon-i - 1 ] = *temp;
    }
    fprintf(fout,"%s",bufer2);
    free(bufer2);
    free(temp);
}
void feature3(FILE *fin, FILE *fout){

}
void feature4(FILE *fin, int **parr, int *length, char **op){

}
void feature5(FILE *fout, int *parr, int length, char *op){

}
void feature6(FILE *fin, struct Obj_t *pobj){

}
void feature7(FILE *fout, struct Obj_t *pobj){

}
void feature8(FILE *fin, struct _courseInfo_t **pobj,int *length){

}
void feature9(FILE *fout, struct _courseInfo_t *pobj,int length){

}
