#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define O 162 //Constante en la que se guarda un número que en ascii es una letra

#define VALUE_SIZE 256
#define FLOAT_POINT '.'



int cantidadVentas = 0;
int cantidadProducos = 3;
int opcionMenus;

int numberValidate(char number[]) {
    int i = 0, x = 0;

    for (i = 0; i < VALUE_SIZE; i++) {   /* If it sure that "number" come whitout spaces, use srtlen(number) instead VALUE_SIZE. */

        if (number[i] == FLOAT_POINT)
            x++;

        if (!isdigit(number[i]) && number[i] != FLOAT_POINT && number[i] != '\0')
            return 3;   /* Not a valid number. */
    }

    if (x == 0){
            printf("Es entero");
         return 1;   /* Integer number. */
    }


    if (x == 1)
        return 2;   /* Float number. */

    if (x > 1)
        return 3;   /* Not a valid number. */
}


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
    memcpy(newProduct[0].nombreInvProducto,"Carne de res", 40 );
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

int checkNumber ()
{
}

void registerVenta()
{
    fflush(stdin);
    printf("\nNombre del CLIENTE: ");
    gets(newVenta[cantidadVentas].nombreCliente);
    fflush(stdin);
    int opcion;
    fflush(stdin);
    int numeroRetorno;
    char valorIngreso[VALUE_SIZE] ;

    do
    {

        printf("\nId del PRODUCTO: ");

        scanf("%i",&valorIngreso);

        numeroRetorno = numberValidate(valorIngreso);

        if(numeroRetorno==1)
        {
            strcpy(newVenta[cantidadVentas].idProducto, valorIngreso);
            fflush(stdin);

            printf("\nCANTIDAD a comprar: ");
            scanf("%i",&newVenta[cantidadVentas].cantidad);

            newVenta[cantidadVentas].valorTotal =  newVenta[cantidadVentas].cantidad * newProduct[newVenta[cantidadVentas].idProducto -1 ].precioInvProducto;



            printf("\nResumen de la compra"
                   "\nCliente: %s\nID del Producto: %i\nProducto: %s\nCantidad: %i\nTotal: %i\n\nSi desea confirmar la compra, oprime 1 de lo contrario marque 2\n",
                   newVenta[cantidadVentas].nombreCliente,newVenta[cantidadVentas].idVenta+1,  newProduct[newVenta[cantidadVentas].idProducto -1].nombreInvProducto,
                   newVenta[cantidadVentas].cantidad, newVenta[cantidadVentas].valorTotal);
            int resta = newVenta[cantidadVentas].cantidad;
            do
            {

                scanf("%i", &opcion);

                if(opcion==1||opcion==2)
                {
                    if(opcion==1)
                    {

                        newVenta[cantidadVentas].idVenta = cantidadVentas+1;

                        printf("Cantidad existente: %d\n",  newProduct[newVenta[cantidadVentas].idProducto].cantidadInvProducto);

                        printf("Cantidad a restar %i\n",newVenta[cantidadVentas].cantidad);

                        printf("Resta: %i", resta);

                        newProduct[newVenta[cantidadVentas].idProducto].cantidadInvProducto= newProduct[newVenta[cantidadVentas].idProducto].cantidadInvProducto - newVenta[cantidadVentas].cantidad;


                        printf("Cantidad existente: %i",  newProduct[newVenta[cantidadVentas].idProducto].cantidadInvProducto);
                        printf("Venta registrada exitosamente\n\n");
                        cantidadVentas++;
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

            printf("Si desea registrar una venta oprime 1, de lo contrario oprima cualquier tecla para ir al menu principal\n");
            scanf("%i",&opcion);
        }
    }
    while(opcion==1);


    limpiarConsola();


    main();


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
                cantidadProducos++;

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
    }
    while(opcion!=1&&opcion!=2);

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

void listarProductosInventario()
{
    limpiarConsola();
    int opcion;
    printf("Listado de pructos existentes\n");
    for(int i = 0; i<cantidadProducos; i++)
    {

        printf("Id del producto: %i\nNombre del producto: %s\nPrecio de producto por unidad: %i\nCantidad de producto: %i\n\n\n", newProduct[i].idInvProducto,
               newProduct[i].nombreInvProducto,newProduct[i].precioInvProducto, newProduct[i].cantidadInvProducto);
    }
    printf("Para volver al menu principal oprima 1\n");
    do
    {
        scanf("%i",&opcion);

    }
    while(opcion!=1);

    main();

}


void inventario()
{
    menus("1.Crear producto"
          "\n2.Listar productos"
          "\n3.Regresar\n");

    scanf("%i", &opcionMenus);

    switch (opcionMenus)
    {
    case 1:
        registrarNewProducto();
        break;
    case 2:
        listarProductosInventario();
        break;
    case 3:
        main();
        break;
    }

}
void listVentas()
{
    limpiarConsola();
    int opcion;
    printf("Listado de ventas efectuadas\n");
    for(int i = 0; i<cantidadVentas; i++)
    {

        printf("\nID Venta: %i\nCliente: %s\nProducto: %s\nCantidad: %i\nTotal: %i\n",
               newVenta[i].idVenta, newVenta[i].nombreCliente, newProduct[newVenta[i].idProducto -1].nombreInvProducto,
               newVenta[i].cantidad, newVenta[i].valorTotal);
    }
    printf("Para volver al menu principal oprima 1\n");
    do
    {
        scanf("%i",&opcion);

    }
    while(opcion!=1);

    main();
}

int swichtMenuInicio(int opcionSeleccionada)
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
        exit(0);
        break;
    }

}

int menus(char stringMenu[200])
{
    printf("%s", stringMenu);
    scanf("%i", &opcionMenus);
}

int main(void)
{
    limpiarConsola();

    datosQuemados();
    menus("Bienvenido,"
          "\npara continuar elige una de las siguientes acciones"
          "\nMenu Principal\n"
          "\n1.Registrar Venta"
          "\n2.Inventario"
          "\n3.Listar Ventas"
          "\n4.Salir\n");


    swichtMenuInicio(opcionMenus);
}


