#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cantNombres;
    printf("\nIngrese la cantidad de nombres que va a ingresar: ");
    scanf("%d", &cantNombres);
    char **nombres =(char **)malloc(cantNombres*sizeof(char *));
    char *buff = (char *)malloc(sizeof(char)*100);
    for(int i = 0;i<cantNombres;i++)
    {
        printf("Ingrese el nombre %d: ", i+1);
        fflush(stdin);
        gets(buff);
        nombres[i] = (char *) malloc((strlen(buff)+1)*sizeof(char));
        strcpy(nombres[i], buff);
    }
    for(int j=0;j<cantNombres;j++)
    { 
        puts(nombres[j]);
    }
    free(buff);
    for (int k = 0; k < cantNombres; k++)
    {
       free(nombres[k]);
    }
    free(nombres);
    
}