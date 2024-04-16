#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **nombres =(char **)malloc(5*sizeof(char *));
    char *buff = (char *)malloc(sizeof(char)*100);
    for(int i = 0;i<5;i++)
    {
        printf("Ingrese el nombre %d: ", i+1);
        gets(buff);
        nombres[i] =(char *) malloc((strlen(buff)+1)*sizeof(char));
        strcpy(nombres[i], buff);
    }
    for(int j=0;j<5;j++)
    { 
        puts(nombres[j]);
    }
    free(buff);
    for (int k = 0; k < 5; k++)
    {
       free(nombres[k]);
    }
    free(nombres);
    
}