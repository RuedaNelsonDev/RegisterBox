#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define O 162 //Constante en la que se guarda un número que en ascii es una letra



int cantidadVentas = 0;
int cantidadProducos = 3;



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
    do
    {
        scanf("%i", &opcion);
        if(opcion==1||opcion==2)
        {
            if(opcion==1)
            {
                cantidadVentas = cantidadVentas ++;
                newVenta[cantidadVentas].idVenta = cantidadVentas;
                printf("Venta registrada exitosamente\n\n");
            }
            else
            {
                printf("Venta cancelada exitosamente\n\n");
            }


        }
        else
        {
            printf("Oprima una opci%cn valida\n\n", O);
        }
    }
    while(opcion!=1 &&opcion!=2);

    printf("Si desea registrar una venta oprime 1, e lo contrario oprima cualquier tecla para ir al menu principal\n");
    scanf("%i",&opcion);
    limpiarConsola();
    if(opcion==1)
    {
        registerVenta();
    }
    else
    {
        main();
    }



}


void limpiarConsola()
{
    system("cls");
}


void registrarNewProducto()
{
    limpiarConsola();
    int id= cantidadProducos + 1;
    int opcion;
    newProduct[id].idInvProducto = id;

    printf("Ingrese nombre del nuevo producto\n");
    scanf("%s", &newProduct[id].nombreInvProducto);
    fflush(stdin);

    printf("Indica el precio del producto por unidad\n");
    scanf("%i", &newProduct[id].precioInvProducto);
    fflush(stdin);


    printf("Indica la cantidad de unidades existentes del producto\n");
    scanf("%i", &newProduct[id].cantidadInvProducto);
    limpiarConsola();

    printf("Resumen del registro\nId del producto: %i\nNombre del producto: %s\nPrecio de producto por unidad: %i\nCantidad de producto: %i\n", newProduct[id].idInvProducto, newProduct[id].nombreInvProducto,
           newProduct[id].precioInvProducto, newProduct[id].cantidadInvProducto);

    printf("Desea guardar el producto %s? para confirmar oprima 1 de lo contrario oprima 2\n",newProduct[id].nombreInvProducto);


    do
    {
scanf("%i", &opcion);
        if(opcion==1 || opcion==2)
        {
            if(opcion==1)
            {
                printf("Registro exitoso\n\n");

            }
            if(opcion==2)
            {
                printf("Registro cancelado\n\n");

            }
        }
        else
        {
            printf("Oprima una opci%cn valida\n\n", O);
        }
        }while(opcion!=1&&opcion!=2);

        printf("Si desea registrar un nuevo producto oprima 1, de lo contrario oprima cualquier tecla para ir al menu principal\n");
        scanf("%i",&opcion);
        limpiarConsola();
        if(opcion==1)
        {
            registrarNewProducto();
            }
            else
            {
                main();
            }

    }




    void inventario()
    {
        int opcionInventario;

        printf("1.Crear producto"
               "\n2.Listar productos"
               "\n3.Regresar\n");

        scanf("%i", &opcionInventario);

        switch (opcionInventario)
        {
        case 1:
            registrarNewProducto();
            break;
        case 2:

            break;
//    case 3:





        }

    }
    void listVentas()
    {

    }
    void salir()
    {

    }
    void swichtMenuInicio(int opcionSeleccionada)
    {
        limpiarConsola();
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
