#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

#include "validacionesHerramientas.h"
#include "marcas.h"
#include "notebooks.h"
#include "tipos.h"
#include "cliente.h"

int altaNotebooks(eNotebook notebooks[], eMarca marca[],eTipo tipos[],eCliente cliente[], int tam,int idNotebook)
{
    int error=1 ;
    int indice;
    eNotebook auxiliarNotebook;

    if ( notebooks != NULL && marca != NULL && tipos != NULL && tam>0 && idNotebook>=1000)
    {
        system("cls");
        printf(" *** Alta de Notebooks *** \n\n");
        indice = buscarLibreNotebooks(notebooks,tam);
        if(indice == -1)
        {
            printf("El sistema esta lleno\n");
        }
        else
        {
            auxiliarNotebook.idNotebook = idNotebook;
            auxiliarNotebook.isEmpty = 0;

            listarClientes(cliente,tam);
            printf("Ingrese cliente : ");
            scanf("%d",&auxiliarNotebook.idClienteNot);
            while(validarCliente(cliente,tam,auxiliarNotebook.idClienteNot)==0)
            {
                printf("Id invalido. reingrese : ");
                scanf("%d", &auxiliarNotebook.idClienteNot);
            }



            antiOverflow(auxiliarNotebook.modeloNotebook,20,"modelo");

            system("cls");
            mostrarMarcas(marca,tam);
            printf("Ingrese Marca : ");
            scanf("%d",&auxiliarNotebook.idMarca);

            while(validarIdMarca(marca,tam,auxiliarNotebook.idMarca)==0)
            {
                printf("Id invalido. reingrese : ");
                scanf("%d", &auxiliarNotebook.idMarca);
            }

            system("cls");
            mostrarTipos(tipos,tam);
            printf("Ingrese tipo : ");
            scanf("%d",&auxiliarNotebook.idTipo);

            while(validarIdtipo(tipos,tam,auxiliarNotebook.idTipo)==0)
            {
                printf("Id invalido. reingrese : ");
                scanf("%d", &auxiliarNotebook.idTipo);
            }

            system("cls");
            printf("Ingrese Precio : ");
            scanf("%f",&auxiliarNotebook.precio);


            if(confirmacion("Alta")=='s')
            {
                notebooks[indice] = auxiliarNotebook;
                error= 0;
            }
            else
            {
                error=2;
            }


        }
    }
    return error;
}

int modificarNotebooks(eNotebook notebooks[], eMarca marcas[], eTipo tipos[],eCliente clientes[], int tam)
{
    int error = 1;
    int idNoteobok;
    int indice;
    char opcion;
    eNotebook auxnotebooks;

    if(notebooks != NULL && marcas != NULL && tipos != NULL && tam>0)
    {
        listarNotebooks(notebooks,marcas,tipos,clientes,tam);
        printf("ingrese ID : ");
        scanf("%d", &idNoteobok);

        indice = buscarNotebooks(notebooks,idNoteobok,tam);
        if(indice == -1)
        {
            printf("no existe ese ID");
        }
        else
        {
            system("cls");
            printf("********** Modificar datos **********\n\n");
            printf("\n");
            printf(" ID   Modelo      Marca      Tipo    Precio\n");
            printf("--------------------------------------------\n");
            mostrarNotebooks(notebooks[indice],marcas,tipos,clientes,tam);
            printf("a. Modificar Tipo \n");
            printf("b. Modificar Marca \n");
            printf("   Ingrese opcion : ");
            fflush(stdin);
            opcion = tolower(opcion);
            scanf("%c",&opcion);
            switch(opcion)
            {
            case 'a':
                system("cls");
                printf("********** Modificar datos **********\n\n");
                mostrarTipos(tipos,tam);
                printf("\n\n");
                printf("Ingrese Id de tipo : ");
                scanf("%d",&auxnotebooks.idTipo);

                if(!validarIdtipo(tipos,tam,auxnotebooks.idTipo))
                {
                    printf("Id invalido. \n");
                    error=1;
                }
                else if(confirmacion("modificacion")== 's')
                {
                    notebooks[indice].idTipo = auxnotebooks.idTipo;
                    mostrarNotebooks(notebooks[indice],marcas,tipos,clientes,tam);
                    error= 0;
                }
                else
                {
                    error=2;
                }


                break;
            case 'b':
                system("cls");
                printf("********** Modificar datos **********\n\n");
                mostrarMarcas(marcas,tam);
                printf("\n\n");
                printf("Ingrese Id de Marca : ");
                scanf("%d",&auxnotebooks.idMarca);

                if(!validarIdMarca(marcas,tam,auxnotebooks.idMarca))
                {
                    printf("Id invalido. ");
                    error=1;
                }
                else if(confirmacion("modificacion")== 's')
                {
                    notebooks[indice].idMarca = auxnotebooks.idMarca;
                    mostrarNotebooks(notebooks[indice],marcas,tipos,clientes,tam);
                    printf("\n\n");
                    error= 0;
                }
                else
                {
                    error=2;
                }

                break;
            default:
                printf("\nOpcion invalida\n");
                break;

            }
        }
    }
    return error;
}
int bajaNotebooks(eNotebook notebooks[], eMarca marcas[], eTipo tipos[],eCliente clientes[], int tam)
{
    int error = 1;
    int idNotebooks;
    int indice;
    if(notebooks != NULL && marcas != NULL &&  tipos != NULL &&  tam>0)
    {
        system("cls");
        printf("  *** baja de Notebooks*** \n\n");
        listarNotebooks(notebooks,marcas,tipos,clientes,tam);
        printf("ingrese id:");
        scanf("%d", &idNotebooks);

        indice = buscarNotebooks(notebooks,idNotebooks,tam);
        if(indice == -1)
        {
            printf("no existe ese ID");
        }
        else
        {
            mostrarNotebooks(notebooks[indice],marcas,tipos,clientes,tam);
            if(confirmacion("borrado")== 's')
            {
                notebooks[indice].isEmpty =1;
                error= 0;
            }
            else
            {
                error= 2;
            }
        }
    }
    return error;
}
int listarNotebooks(eNotebook notebooks[], eMarca marcas[], eTipo tipos[],eCliente clientes[], int tam)
{
    int error = 1;
    int flag = 0;
    if(notebooks != NULL && marcas != NULL && tipos != NULL && tam >0)
    {
        system("cls");
        printf(" ID  NombreCliente   Modelo        Marca        Tipo      Precio\n");
        printf("-----------------------------------------------------------------\n");


        for(int i = 0 ; i<tam; i++)
        {
            if(notebooks[i].isEmpty == 0)
            {
                mostrarNotebooks(notebooks[i],marcas,tipos,clientes,tam);
                flag= 1;
            }
        }

        if(flag==0)
        {
            printf(" No Hay datos que mostrar \n");
        }
        printf("\n\n");
        error= 0;
    }
    return error;
}
void mostrarNotebooks(eNotebook notebooks, eMarca marcas[], eTipo tipos[],eCliente clientes[], int tam)
{
    char descMarca[20];
    char descTipo[20];
    char nombreCliente[20];

    if(!obtenerDescripcionMarca(marcas,tam,notebooks.idMarca,descMarca) && !obtenerDescripcionTipo(tipos,tam,notebooks.idTipo,descTipo) &&!obtenerNombreCliente(clientes,notebooks.idClienteNot,nombreCliente,tam))
    {
        printf(" %d %10s %10s %10s %10s $ %.2f \n",
               notebooks.idNotebook,
               nombreCliente,
               notebooks.modeloNotebook,
               descMarca,
               descTipo,
               notebooks.precio);

    }
    else
    {
        printf("error al obtener descripcion \n\n");
    }

}
int ordenarPersonas(eNotebook notebooks[],eMarca marca[], int tam)
{
    int error = 1;
    eNotebook auxNotebooks;
    char desMarcaI[20];
    char desMarcaJ[20];

    if(notebooks != NULL && tam>0 )
    {
        for( int i = 0; i < tam-1; i++)
        {
            for( int j= i+1; j< tam ; j++)
            {
                obtenerDescripcionMarca(marca,tam,notebooks[i].idMarca,desMarcaI);
                obtenerDescripcionMarca(marca,tam,notebooks[j].idMarca,desMarcaJ);

                if((strcmp(desMarcaI,desMarcaJ)>0) || (notebooks[i].idMarca== notebooks[j].idMarca && notebooks[i].precio > notebooks[j].precio))
                {
                    auxNotebooks = notebooks[i];
                    notebooks[i]= notebooks[j];
                    notebooks[j]= auxNotebooks;

                }
                /*if(notebooks[i].idMarca== notebooks[j].idMarca && notebooks[i].precio > notebooks[j].precio)
                {
                    auxNotebooks = notebooks[i];
                    notebooks[i]= notebooks[j];
                    notebooks[j]= auxNotebooks;

                }*/


                error= 0;
            }
        }
    }
    return error;
}
int validarIdNotebook(eNotebook notebooks[], int idNotebook,int tam)
{
    int esValido = 0;
    if(notebooks != NULL && tam>0)
    {
        for(int i =0; i<tam ; i++)
        {
            if(notebooks[i].idNotebook == idNotebook)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
int buscarLibreNotebooks(eNotebook notebooks[], int tam)
{
    int indice= -1;
    for(int i = 0; i < tam; i++)
    {
        if(notebooks[i].isEmpty == 1)
        {
            indice = i ;
            break;
        }
    }
    return indice;
}
int inicializarListaNotebooks(eNotebook notebooks[], int tam)
{
    int error=1;
    if(notebooks != NULL && tam >0)
    {
        for(int i= 0; i < tam ; i++)
        {
            notebooks[i].isEmpty=1;
        }
        error= 0;
    }
    return error;
}
int idLibreNetbooks(eNotebook notebooks[], int tam)
{
    int indice= -1;
    for(int i = 0; i < tam; i++)
    {
        if(notebooks[i].isEmpty == 1)
        {
            indice = i ;
            break;
        }
    }
    return indice;
}
int buscarNotebooks(eNotebook notebooks[], int idNotIngresado, int tam)
{
    int indice= -1;
    for(int i = 0; i < tam; i++)
    {
        if(notebooks[i].idNotebook == idNotIngresado && notebooks[i].isEmpty == 0)
        {
            indice = i ;
            break;
        }
    }
    return indice;
}

int listarNotbooksPorTipo(eNotebook notbooks[],eTipo tipos[],eMarca marcas[],eCliente clientes[],int tam)
{
    int error = 1;
    int idTipo;
    char tipo[20];
    int flag = 0;
    if(notbooks != NULL && tam > 0 && tipos != NULL && marcas != NULL && clientes != NULL)
    {
        system("cls");
        printf(" ***Tipos*** \n\n");
        mostrarTipos(tipos,tam);
        printf("ingrese id Tipo: ");
        scanf("%d", &idTipo);
        while( validarIdtipo(tipos,tam,idTipo)==0)
        {
            printf("Id invalido. reingrese : ");
            scanf("%d", &idTipo);
        }
        obtenerDescripcionTipo(tipos,tam,idTipo,tipo);
        printf("Notebooks de tipo %s :\n \n", tipo);
        printf(" ID  NombreCliente   Modelo        Marca        Tipo      Precio\n");
        printf("-----------------------------------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
            if(tipos[i].isEmpty == 0 && notbooks[i].idTipo == idTipo)
            {
                mostrarNotebooks(notbooks[i],marcas,tipos,clientes,tam);
                flag=1;
            }
        }
        if (flag == 0)
        {
            printf("no hay notbooks con ese tipo : %s \n\n", tipo);
        }
        error=0;

    }
    return error;
}

int listarNotbooksPorMarca(eNotebook notbooks[],eTipo tipos[],eMarca marcas[],eCliente clientes[],int tam)
{
    int error = 1;
    int idMarca;
    char marca[20];
    int flag = 0;
    if(notbooks != NULL && tam > 0 && tipos != NULL && marcas != NULL && clientes != NULL)
    {
        system("cls");
        printf(" ***Marcas*** \n\n");
        mostrarMarcas(marcas,tam);
        printf("ingrese id marca: ");
        scanf("%d", &idMarca);
        while( validarIdMarca(marcas,tam,idMarca)==0)
        {
            printf("Id invalido. reingrese : ");
            scanf("%d", &idMarca);
        }
        obtenerDescripcionMarca(marcas,tam,idMarca,marca);
        printf("Notebooks de marca %s :\n \n", marca);
        printf(" ID  NombreCliente   Modelo        Marca        Tipo      Precio\n");
        printf("-----------------------------------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
            if(marcas[i].isEmpty == 0 && marcas[i].idMarca == idMarca)
            {
                mostrarNotebooks(notbooks[i],marcas,tipos,clientes,tam);
                flag=1;
            }
        }
        if (flag == 0)
        {
            printf("no hay notbooks con esa marca : %s \n\n", marca);
        }
        error=0;

    }
    return error;
}

int notebooksBarato(eNotebook notebooks[],eMarca marcas[],eTipo tipos[],eCliente clientes[], int tam)
{
    int error = 1;
    int precioMenor;
    int flag = 0;

    if(notebooks != NULL && tam > 0 )
    {
        system("cls");
        printf(" ***  Notebooks baratos *** \n\n");
        printf(" ID  NombreCliente   Modelo        Marca        Tipo      Precio\n");
        printf("-----------------------------------------------------------------\n");

        for(int i = 0; i <tam; i ++)
        {
            if ((notebooks[i].isEmpty==0) && (notebooks[i].precio< precioMenor || flag ==0))
            {
                precioMenor = notebooks[i].precio;
                flag =1;
            }
        }

        for(int i = 0; i <tam; i ++)
        {
            if (notebooks[i].precio== precioMenor)
            {
                mostrarNotebooks(notebooks[i],marcas,tipos,clientes,tam);
            }
        }
        printf("\n\n");

        error = 0;

    }
    return error;
}
int listarNotebooksDecadaMarca(eNotebook notebooks[],eMarca marcas[],eTipo tipos[],eCliente clientes[], int tam)
{
    int error = 1;
    char marca[20];
    int flag = 0;
    if(notebooks != NULL && tam > 0 && marcas != NULL &&  tipos != NULL && clientes != NULL && tam > 0)
    {
        system("cls");
        printf(" *** Listado de cada Marca*** \n");
        for( int d = 0 ; d<tam; d++)
        {
            flag=0;

            obtenerDescripcionMarca(marcas,tam,marcas[d].idMarca,marca);
            printf("Marca : %s\n",marca);

            for(int i = 0; i < tam; i++)
            {
                if(notebooks[i].isEmpty == 0 && notebooks[i].idMarca == marcas[d].idMarca)
                {
                    mostrarNotebooks(notebooks[i],marcas,tipos,clientes,tam);
                    flag=1;
                }
            }
            if (flag == 0)
            {
                printf("no hay Notebooks con esta marca %s \n\n", marca);
            }


        }
        error=0;

    }
    return error;
}
/*int notebooksporMarcaTipo(eNotebook notebooks[],eMarca marcas[],eTipo tipos[],eCliente clientes[],int tam)
{
    int idMarca;
    int idTipo;
    int error=1;
    int flagM=0;
    int flagT=0;
    int canMarca=0;
    char canTipo=0;
    if(notebooks != NULL && tam > 0 && marcas != NULL &&  tipos != NULL && clientes != NULL && tam > 0)
    {
        mostrarMarcas(marcas,tam);
        printf("Ingrese Marca : ");
        scanf("%d",&idMarca);

        while(validarIdMarca(marcas,tam,idMarca)==0)
        {
            printf("Id invalido. reingrese : ");
            scanf("%d", &idMarca);
        }

        mostrarTipos(tipos,tam);
        printf("Ingrese tipo : ");
        scanf("%d",&idTipo);

        while(validarIdtipo(tipos,tam,idTipo)==0)
        {
            printf("Id invalido. reingrese : ");
            scanf("%d", &idTipo);
        }

        system("cls");
        printf("****notebooks por Tipo y marca****\n\n");

        for(int i= 0; i<tam; i++)
        {
            if( notebooks[i].idMarca==idMarca)
            {
                canMarca++;

            }
        }
        printf("cantidad de marcas %d",marca);

        obtenerDescripcionTipo(tipos,tam,idTipo,tipo);
        printf("****%s****\n\n",tipo);
        for(int i= 0; i<tam; i++)
        {
            if(notebooks[i].idTipo==idTipo)
            {
                canTipo++;

            }
        }
        printf("cantidad de tipos %d",tipos);


    }


    return error;
}*/


