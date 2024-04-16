#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char *tiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
struct Producto
{
    int ProductoID;
    int cantidad;
    char *TiposProducto;
    float PrecioUnitario;
};

struct Cliente
{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
};



int main() 
{
    return 0;
}