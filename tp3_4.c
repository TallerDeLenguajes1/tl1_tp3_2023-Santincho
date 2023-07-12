#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
} typedef Producto;
struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
} typedef Cliente;

void cargarCliente(Cliente *cliente, int cantClientes);
void mostrarCliente(Cliente *cliente, int cantClientes);

int main()
{
    srand(time(NULL));
    Cliente *cliente;
    int cantClientes;

    printf("Ingrese la cantidad de clientes visitados: \t");
    scanf("%d",&cantClientes);

    fflush(stdin);
    while (cantClientes > 5)
    {
        printf("Cantidad incorrecta, por favor intente nuevamente\n\r");
        scanf("%d",&cantClientes);
    }

    cliente = (Cliente*) malloc(sizeof(Cliente)*cantClientes);

    cargarCliente(cliente,cantClientes);
    mostrarCliente(cliente,cantClientes);

    for (int k = 0; k < cantClientes; k++)
    {
        free(cliente[k].NombreCliente);
    }
    
    return 0;
}

void cargarCliente(Cliente *cliente,int cantClientes)
{
    int random;
    char *aux;
    aux=(char*) malloc(sizeof(char)*50);
    for (int i = 0; i < cantClientes; i++)
    {
        cliente[i].ClienteID=i+1;
        printf("Ingrese el nombre del cliente: \t");
        gets(aux);
        fflush(stdin);
        cliente[i].NombreCliente=(char*) malloc((strlen(aux)+1) * sizeof(char));
        strcpy(cliente[i].NombreCliente,aux);

        cliente[i].CantidadProductosAPedir=1+rand()%5;
        cliente[i].Productos=(Producto*) malloc(sizeof(Producto)*cliente[i].CantidadProductosAPedir);
        
        for (int j = 0; j < cliente[i].CantidadProductosAPedir; j++)
        {
            random=rand()%5;
            cliente[i].Productos[j].ProductoID = j;            
            cliente[i].Productos[j].TipoProducto = (char*) malloc((strlen(TiposProductos[random])+1)*sizeof(char));
            cliente[i].Productos[j].TipoProducto = TiposProductos[random];
            cliente[i].Productos[j].PrecioUnitario = 10 + rand()%91;
            cliente[i].Productos[j].Cantidad = 1 + rand()%10;
        }
    }
    free(aux);
    
}

void mostrarCliente(Cliente *cliente, int cantClientes)
{
    int total;
    for (int i = 0; i < cantClientes; i++)
    {
        total = 0;
        printf("\nCliente %d\n\r",cliente[i].ClienteID);
        printf("Nombre: %s\n\r",cliente[i].NombreCliente);
        printf("Cantidad de productos a pedir: %d\n\r",cliente[i].CantidadProductosAPedir);
        printf("----- Productos ------ \n\r");
        for (int j = 0; j < cliente[i].CantidadProductosAPedir; j++)
        {
            printf("Id del producto %d:\n\r",cliente[i].Productos[j].ProductoID);
            printf("\tTipo de producto %s\n\r",cliente[i].Productos[j].TipoProducto);
            printf("\tCantidad: %d\n\r",cliente[i].Productos[j].Cantidad);
            printf("\tPrecio Unitario: %2f\n\r",cliente[i].Productos[j].PrecioUnitario);
            total += cliente[i].Productos[j].PrecioUnitario + cliente[i].Productos[j].Cantidad;
        }
        printf("Total a pagar: %d", total);
    }
}