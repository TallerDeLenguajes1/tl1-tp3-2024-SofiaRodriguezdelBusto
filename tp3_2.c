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
    int max = 0, min= 60000;
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<M;j++)
        {
            if(Matriz[i][j]>= max)
            {
                max = Matriz[i][j];
            }else{
                if(Matriz[i][j]<min)
                {
                    min = Matriz[i][j];
                }
            }
        }
    }
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