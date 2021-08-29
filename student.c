#include <stdlib.h>
#include "student.h"
#include <string.h>

void feature1(FILE *fin, FILE *fout){
    char buffer[128];
    char *status = NULL;
    int cont= 0; 
    do{
        status = fgets(buffer,sizeof(buffer),fin);
        cont++;
        if(status != NULL){
        fputs(buffer, fout);
        }               
    }
    while (cont<=0);
    printf("\n");   
}

void feature2(FILE *fin, FILE *fout) {
    
    char buffer[128];
    char *status = NULL;

    status = fgets(buffer, sizeof(buffer), fin);
    if (status != NULL) {
        for (int i = sizeof(buffer) - 2; i >= 0; i--) {
            fprintf(fout, "%c", buffer[i]);
        }
    }
    printf("\n");
}

void feature3(FILE *fin, FILE *fout)
{
    int contador = 0;
    char buffer[10];
    int resultado = 0, valoractual = 0;
    char *estado = NULL;
    estado = fgets(buffer, sizeof(buffer), fin);
    if (estado != NULL)
    {
        for (contador = 0; contador <= sizeof(buffer); contador++)
        {   fscanf(fin , "%d",&valoractual);
            resultado = resultado + valoractual; 
        }
     }
    
    fprintf(fout, "%d", resultado);
}
