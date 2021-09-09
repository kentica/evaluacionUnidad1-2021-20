#include <stdlib.h>
#include "student.h"

#define max_long 250


void feature1(FILE *fin, FILE *fout){

    char* bufer = (char *)calloc(max_long,sizeof(char));// se reservan esa cantidad de espacios para char bufer(memoria dinamica)
    fgets(bufer,max_long,fin);//que me lea hasta el salto de linea con el fgets
    fprintf(fout,"%s\n",bufer);
    free(bufer);//Libero memoria de el bufer
}
void feature2(FILE *fin,FILE *fout){

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
