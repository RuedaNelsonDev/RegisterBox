#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define O 162 //Constante en la que se guarda un número que en ascii es una letra



int cantidadVentas = 0;
int cantidadProductos = 3;



struct
{
    int idInvProducto;
    char nombreInvProducto[40];
    int precioInvProducto;
    int cantidadInvProducto;

} productos, newProduct[100];

void datosQuemados()
{
    newProduct[0].idInvProducto = 1;
    memcpy(newProduct[0].nombreInvProducto,"Carne de vaca muerta :V", 6 );
    newProduct[0].precioInvProducto = 14000;
    newProduct[0].cantidadInvProducto = 50;


    newProduct[1].idInvProducto = 2;
    memcpy(newProduct[1].nombreInvProducto,"Leche", 6 );
    newProduct[1].precioInvProducto = 3000;
    newProduct[1].cantidadInvProducto = 50;


    newProduct[2].idInvProducto = 3;
    memcpy(newProduct[2].nombreInvProducto,"Arroz", 6 );
    newProduct[2].precioInvProducto = 5000;
    newProduct[2].cantidadInvProducto = 100;
}


struct
{
    int idVenta;
    char nombreCliente[40];
    int idProducto;
    int cantidad;
    int valorTotal;

} venta, newVenta[100]
;



void registerVenta()
{

    printf("Entro a la opci%cn 1 \n", O);

    printf("Id del PRODUCTO: ");
    scanf("%i",&newVenta[cantidadVentas].idProducto);

    fflush(stdin);

    printf("\nNombre del CLIENTE: ");
    gets(newVenta[cantidadVentas].nombreCliente);




    printf("\nCANTIDAD a comprar: ");
    scanf("%i",&newVenta[cantidadVentas].cantidad);

    newVenta[cantidadVentas].valorTotal =  newVenta[cantidadVentas].cantidad * newProduct[newVenta[cantidadVentas].idProducto -1 ].precioInvProducto;



    printf("\nResumen de la compra"
           "\nID VENTA: %i\nCliente: %s\nProducto: %s\nCantidad: %i\nTotal: %i\n\nSi desea confirmar la compra, oprime 1 de lo contrario marque 2\n",
           newVenta[cantidadVentas].idVenta+1, newVenta[cantidadVentas].nombreCliente, newProduct[newVenta[cantidadVentas].idProducto -1].nombreInvProducto, newVenta[cantidadVentas].cantidad, newVenta[cantidadVentas].valorTotal);
    int opcion;
    do{
        scanf("%i", &opcion);
    if(opcion==1||opcion==2)
    {
        if(opcion==1)
        {
            cantidadVentas = cantidadVentas ++;
            newVenta[cantidadVentas].idVenta = cantidadVentas;
            printf("Venta registrada exitosamente");
        }
        else
        {
            printf("Venta cancelada exitosamente");
        }

    }
    else
    {
        printf("Oprima una opci%cn valida\n", O);
    }
    }while(opcion!=1 &&opcion!=2);



}









void inventario()
{
    printf("Entro a la opci%cn 2 ", O);


    int opcionInventario;

    printf("1.Crear producto"
           "\n2.Listar productos"
           "\n3.Regresar");

    scanf("%i", &opcionInventario);

    switch (opcionInventario)
    {
    case 1:
       // registrarNewProducto();
        break;
    case 2:

        break;
//    case 3:





    }

}
void listVentas()
{
    printf("Entro a la opci%cn 3 ", O);

}
void salir()
{
    printf("Entro a la opci%cn 4 ", O);

}
void swichtMenuInicio(int opcionSeleccionada)
{
    system("cls");
    switch (opcionSeleccionada)
    {
    case 1:
        registerVenta();
        break;
    case 2:
        inventario();
        break;
    case 3:
        listVentas();
        break;
    case 4:
        salir();
        break;
    }

}

int main(void)
{
    int opcionMenu1;

    datosQuemados();

    printf("Bienvenido,"
           "\npara continuear elige una de las siguientes acciones"
           "\nMenu"
           "\n1.Registrar Venta"
           "\n2.Inventario"
           "\n3.Lstar Ventas"
           "\n4.Salir\n");
    scanf("%i", &opcionMenu1);

    swichtMenuInicio(opcionMenu1);


    getch();
    return EXIT_SUCCESS;
}
