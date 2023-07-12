#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main()
{
    int Produccion[5][12];
    int promgan = 0;
    srand (time(NULL));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            Produccion[i][j] = 10000 + rand() % 40000;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("\nValor Mes:%d Anio:%d : %d", j+1, i+1,Produccion[i][j]);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            promgan = promgan + Produccion[i][j];
        }
        printf("\nPromedio Ganancia Anio %d: %d", i+1, promgan/12);
        promgan = 0;
    }
    int max = 10000, min = 50000, aniomax, aniomin, mesmax, mesmin;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (Produccion[i][j] < min)
            {
                min = Produccion[i][j];
                aniomin = i;
                mesmin = j;
            }else if (Produccion[i][j] > max)
            {
                max = Produccion[i][j];
                aniomax = i;
                mesmax = j;
            }
            
        }
    }
    printf("\nValor maximo: %d; Anio %d y mes %d", max, aniomax, mesmax);
    printf("\nValor minimo: %d; Anio %d y mes %d", min, aniomin, mesmin);
    return 0;
}
