#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *tiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
struct Producto
{
    int ProductoID;
    int cantidad;
    char *TiposProducto;
    float PrecioUnitario;
}typedef Producto;

struct Cliente
{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
}typedef Cliente;

int numAleatorios(int min, int max);
void cargarClientes(Cliente *clientes, int cantidad);
void cargarProducto(Producto *productos, int cantidad);
void mostrarClientes(Cliente *clientes, int cantidad);
void mostrarProducto(Producto *productos, int cantidad);
float costoProducto(Producto producto);
float pagoCliente(Producto *productos, int cantidad);

int main() 
{
    srand(time(NULL));
    int cantClientes, numCliente, numProducto;
    float costoProdu;
    Cliente *clientes;
    do{
        printf("\nIngrese la cantidad de clientes: ");
        scanf("%d", &cantClientes);
        if (cantClientes<0 && cantClientes>5)
        {
            printf("\nLa cantidad ingresada no es válida");
        }
        
    }while(cantClientes<0 && cantClientes>5);
    clientes = (Cliente *)malloc(cantClientes*sizeof(Cliente));
    cargarClientes(clientes, cantClientes);
    mostrarClientes(clientes, cantClientes);
    printf("\nIngrese el número de cliente sobre el que desea conocer el costo producto: ");
    scanf("%d", &numCliente);
    printf("\nIngrese el número de producto sobre el que desea conocer el costo: ");
    scanf("%d", &numProducto);
    costoProdu = costoProducto(clientes[numCliente-1].Productos[numProducto-1]);
    printf("\nEl costo del producto seleccionado es: %.2f", costoProdu);
    for(int i = 0;i<cantClientes;i++)
    {
        free((clientes+i)->Productos);
        free((clientes+i)->NombreCliente);
    }
    free(clientes);
    return 0;
}

int numAleatorios(int min, int max)
{
    int num;
    num = min + rand()%(max-min+1);
    return num;
}

void cargarClientes(Cliente *clientes, int cantidad)
{
    char *buff = (char *)malloc(sizeof(char)*100);
    for(int i = 0;i<cantidad;i++)
    {
        (clientes +i)->ClienteID = i;
        printf("\nIngrese el nombre del cliente %d: ", i + 1);
        fflush(stdin);
        gets(buff);
        (clientes + i)->NombreCliente = (char *)malloc((strlen(buff)+1)*sizeof(char));
        strcpy((clientes + i)->NombreCliente, buff);
        (clientes + i)->CantidadProductosAPedir = numAleatorios(1,5);   
        int cantProductos = (clientes + i)->CantidadProductosAPedir;
        (clientes + i)->Productos = (Producto *)malloc(cantProductos*sizeof(Producto));
        cargarProducto((clientes + i)->Productos, cantProductos);
    }
    free(buff);
}

void cargarProducto(Producto *productos, int cantidad)
{
    char *puntTipo;
    for(int i = 0;i<cantidad;i++)
    {
        (productos + i)->ProductoID = i;
        (productos + i)->cantidad = numAleatorios(1,10);
        (productos + i)->PrecioUnitario = numAleatorios(1000,10000)*0.01;
        puntTipo = tiposProductos[numAleatorios(0,4)];
        (productos + i)->TiposProducto = (char *)malloc(sizeof(char)*(strlen(puntTipo)+1));
        strcpy((productos + i)->TiposProducto, puntTipo);
    }
}

void mostrarClientes(Cliente *clientes, int cantidad)
{
    for(int i = 0;i<cantidad;i++)
    {

        printf("\n--------Cliente %d--------\n", i+1);
        printf("\nId del cliente: %d", (clientes + i)->ClienteID);
        printf("\nNombre del cliente: %s", (clientes + i)->NombreCliente);
        printf("\nCantidad de productos: %d", (clientes + i)->CantidadProductosAPedir);  
        mostrarProducto((clientes + i)->Productos, (clientes + i)->CantidadProductosAPedir); 
        printf("\nEl total a pagar por el cliente es: %.2f", pagoCliente((clientes + i)->Productos, (clientes + i)->CantidadProductosAPedir));
    }
}
void mostrarProducto(Producto *productos, int cantidad)
{
    for(int i = 0;i<cantidad;i++)
    {
        printf("\n\n--------Producto %d--------\n", i+1);
        printf("\nId del producto: %d", (productos + i)->ProductoID);
        printf("\nCantidad: %d", (productos + i)->cantidad);  
        printf("\nTipo de producto: %s", (productos + i)->TiposProducto);
        printf("\nPrecio unitario: %.2f", (productos + i)->PrecioUnitario);
    }
}
float costoProducto(Producto producto)
{
    return (producto.cantidad*producto.PrecioUnitario);
}

float pagoCliente(Producto *productos, int cantidad)
{
    float total = 0;
    for(int i = 0;i<cantidad;i++)
    {
        total = total + costoProducto(*(productos + i));
    }
    return total;
}