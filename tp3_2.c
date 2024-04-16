#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 12
void cargarMatriz(int Matriz[N][M]);
void mostrarMatriz(int Matriz[N][M]);
int numAleatorios(int min, int max);
void gananciaAnual(int Matriz[N][M]);
void MaxyMin(int Matriz[N][M]);

int main()
{
    srand(time(NULL));
    int produccion[N][M];
    cargarMatriz(produccion);
    mostrarMatriz(produccion);
    gananciaAnual(produccion);
    MaxyMin(produccion);
    return 0;
}
int numAleatorios(int min, int max)
{
    int num;
    num = min + rand()%(max-min+1);
    return num;
}
void cargarMatriz(int Matriz[N][M])
{

    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<M;j++)
        {
            Matriz[i][j] = numAleatorios(10000,50000);
        }
    }
}

void mostrarMatriz(int Matriz[N][M])
{
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<M;j++)
        {
            printf(" %d ", Matriz[i][j]);
        }
        printf("\n");
    }
}
void gananciaAnual(int Matriz[N][M])
{
    float promedio;
    for(int i = 0;i<N;i++)
    {
        promedio = 0;
        for(int j = 0;j<M;j++)
        {
            promedio = promedio + Matriz[i][j];
        }
        promedio = promedio/M;
        printf("\nGanancias promedio del año %d: %.2f", i+1, promedio);
    }
}
void MaxyMin(int Matriz[N][M])
{   
    //Si considero solo el ultimo año y mes donde hubo un max o min puedo usar estas variables aux
    //int mesMin, anioMin, mesMax, anioMax; 
    int max = 0, min= 60000;
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<M;j++)
        {
            if(Matriz[i][j]>= max)
            {
                max = Matriz[i][j];
                /*Variables que uso si considero el último año donde se produjo un min o max
                anioMax = i + 1;
                mesMax = j + 1;
                */
            }else{
                if(Matriz[i][j]<min)
                {
                    min = Matriz[i][j];
                    /*Variables que uso si considero el último año donde se produjo un min o max
                    anioMin = i + 1;
                    mesMin = j + 1;
                    */
                }
            }
        }
    }
    //Respuestas en caso de considerar solo el último año donde se produjo un min o max
    //printf("\nEl maximo es %d y ocurrió en el anio %d y mes %d", max, anioMax, mesMax);
    //printf("\nEl minimo es %d y ocurrió en el anio %d y mes %d", min, anioMin, mesMin);  
    /*Considero que puede haber mas de un año y mes donde ocurra un mínimo o máximo entonces recorro
    la matriz nuevamente para mostrar los casos donde los valores coincidan con el max o min y muestro
    los años y dias*/
    printf("\nEl mínimo valor de producción es: %d y ocurrió en ", min);
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<M;j++)
        {
            if(Matriz[i][j] == min)
            {
               printf("\nAnio: %d y mes: %d", i+1, j+1);
            }
        }
    }
    printf("\nEl máximo valor de producción es: %d y ocurrió en ", max);
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<M;j++)
        {
            if(Matriz[i][j] == max)
            {
               printf("\nAnio: %d y mes: %d", i+1, j+1);
            }
        }
    }
}