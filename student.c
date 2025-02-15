#include <stdlib.h>
#include "student.h"
#include <string.h>

#define max_long 250


void feature1(FILE *fin, FILE *fout){

    char* bufer = (char *)calloc(max_long,sizeof(char));// se reservan esa cantidad de espacios para char bufer(memoria dinamica)
    fgets(bufer,max_long,fin);//que me lea hasta el salto de linea con el fgets
    fprintf(fout,"%s",bufer);
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
    fprintf(fout,"%s\n",bufer2);
    free(bufer2);
    free(temp);
}
void feature3(FILE *fin, FILE *fout){
    char* bufer = (char *)calloc(max_long,sizeof(char));
    short* numeros = (short *) calloc(max_long,sizeof(short));
    char* temp = (char *)calloc(4,sizeof(char));
    char *bash;
    fgets(bufer,max_long,fin);
    short i=0;
    int sum = 0;
    temp = strtok(bufer, " ");
    while(temp != NULL){
        numeros[i] = strtol(temp,&bash,10);
        sum = sum + numeros[i];
        temp = strtok(NULL, " ");
        i++;        
    }
    fprintf(fout,"%d\n",sum);
    free(bufer);    
    free(temp);
    free(numeros);
    //El bash no se libera. ya que se este no tiene memoria reservada
}
void feature4(FILE *fin, int **parr, int *length, char **op){
    char* bufer = (char *)calloc(max_long,sizeof(char));
    char* temp = (char *)calloc(4,sizeof(char));
    *parr = (int *)calloc(max_long,sizeof(int));
    char *bash = (char *)calloc(4,sizeof(char));
    *op = (char *)calloc(4,sizeof(char));
    *length = 0;
    int i=0;
    fgets(bufer,max_long,fin);
    temp = strtok(bufer, " ");
    while(temp != NULL){
        (*parr)[i] = strtol(temp,&bash,10);
        temp = strtok(NULL, " ");
        i++;        
    }
    strncpy(*op,bash,3);
    *length = i;
    free(bufer);
    free(temp);
    //El par aunque usa calloc no se limpia puesto que se se usa en el feature 5
    //por que la direccion de memoria se encuentra en el main.

}
void feature5(FILE *fout, int *parr, int length, char *op){//Condiciones para cada caso posible.
    if(strcmp(op,"avg")==0){
        int sum = 0;
        for(short i = 0;i < length -1;i++){
            sum = sum + parr[i];
        }
        //printf("%d\n",sum);
        //printf("%d\n",length);
        fprintf(fout,"%d\n",(sum/(length-1)));        
    }
    else if(strcmp(op,"max")==0){
        int max = -1000;
        for(short i=0; i< length - 1;i++){
            if(parr[i] > max){
                max = parr[i];
            }
        }
        fprintf(fout,"%d\n",max);        
    }
    else if(strcmp(op,"min")==0){
        int min = 1000;
        for(short i=0; i< length - 1;i++){
            if(parr[i] < min){
                min = parr[i];
            }
        }
        fprintf(fout,"%d\n",min);        
    }
    else{
        fprintf(fout,"Operacion No reconocida.");//caso base
    }
    free(parr);
    free(op);
}
void feature6(FILE *fin, struct Obj_t *pobj){
        char* bufer = (char *)calloc(max_long,sizeof(char));
        char* nombre = (char *)calloc(max_long,sizeof(char));
        int id = 0;
        pobj->nombre = (char *)calloc(max_long,sizeof(char));
        char* bash;
        fgets(bufer,max_long,fin);
        nombre = strtok(bufer,",");
        id = strtol(strtok(NULL,","),&bash,10);//el 10 es la base a la que se convierte
        strcpy(pobj -> nombre,nombre);
        pobj->cedula = id;//soy rebelde y le pongo id a mi cedula no lo cambio en el .h por que se que tiene automatizada la revision.
        free(bufer);

}
void feature7(FILE *fout, struct Obj_t *pobj){

    fprintf(fout,"%d,%s\n",pobj->cedula,pobj->nombre);

}
void feature8(FILE *fin, struct _courseInfo_t **pobj,int *length){
    char* bufer = (char *)calloc(max_long,sizeof(char));
    int N=0, j=0;
    char *bash;
    char *bash2;
    fgets(bufer,max_long,fin);
    N = strtol(bufer,&bash,10);
    struct _courseInfo_t *parr = (struct _courseInfo_t *)calloc(N,sizeof(struct _courseInfo_t));
    printf("Porfavor,ingresar la Informacion de el orden Curso,Creditos,Nota\n");
    for(short i=0; i<N; i++){
        j=0;
        printf("Cuso %d: ",i+1);
        fgets(bufer,max_long,stdin);
        bash = strtok(bufer,",");
        while(bash!=NULL){
            if(j==0){
                strcpy(parr[i].name,bash);
            }else if(j==1){
                parr[i].credits = strtol(bash,&bash2,10);
            }
            else if(j==2){
                parr[i].grade= strtof(bash,&bash2);
            }
            j++;
            bash = strtok(NULL,",");
        }
    }
    *pobj = parr;
    *length = N;
    free(bufer);
    fclose(fin);//ya se deja de leer la info de el fin asi que se puede cerrar
}
void feature9(FILE *fout, struct _courseInfo_t *pobj,int length){
    char* bufer = (char*)calloc(10,sizeof(char));
    float calificacion = 0, creditos = 0;
    float promedio = 0.0f;
    for(short i=0;i<length;i++){
        calificacion = calificacion + pobj[i].grade*pobj[i].credits;
        creditos = creditos + pobj[i].credits;        
    }
    promedio = calificacion/creditos;
    printf("Desea guardar la info? (s) o (n) \n");
    fgets(bufer,10,stdin);
    char *tk = strtok(bufer,"\n");
    if(strcmp(tk,"s")==0 || strcmp(tk,"S")==0){
        for(short i=0;i<length;i++){
            fprintf(fout,"%s,%d,%f\n",pobj[i].name,pobj[i].credits,pobj[i].grade);            
        }
        fprintf(fout,"promedio acumulado: %f",promedio);        
    }
    else{
        fprintf(fout,"Promedio acumulado: %f",promedio);
    }
    free(bufer);
    free(pobj);
    fclose(fout);
}
