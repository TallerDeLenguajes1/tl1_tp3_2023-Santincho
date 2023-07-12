#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main()
{
    int cant;
    scanf("%d", &cant);
    char *aux;
    char *Nom[cant];
    aux = (char*) malloc(sizeof(char) * 50);
    for (int i = 0; i < cant; i++)
    {
        gets(aux);
        Nom[i] = (char*) malloc(sizeof(char) * (strlen(aux) + 1));
        strcpy(Nom[i], aux);
    }
    for (int i = 0; i < cant; i++)
    {
        puts(Nom[i]);
    }
    for (int i = 0; i < cant; i++)
    {
        free(Nom[i]);
    }
    free(aux);
    return 0;
}