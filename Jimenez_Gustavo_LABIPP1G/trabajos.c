#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

#include "trabajos.h"
#include "notebooks.h"
#include "servicios.h"
#include "validacionesHerramientas.h"
#include "cliente.h"


int inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    int error=1;
    if(trabajos != NULL && tam >0)
    {
        for(int i= 0; i < tam ; i++)
        {
            trabajos[i].isEmpty=1;
        }
        error= 0;
    }
    return error;
}

int altaTrabajos(eTrabajo trabajos[], int tam,int idTrabajo, eMarca marcas[],eTipo tipos[],eNotebook notebooks[],eServicio servicios[],eCliente clientes[])
{
    int error=1 ;
    int indice;
    eTrabajo auxTrabajo;

    if ( trabajos != NULL && marcas != NULL && tipos != NULL && servicios != NULL  && tam>0 && idTrabajo>=1000)
    {
        system("cls");
        printf(" *** Alta de Trabajos *** \n\n");
        indice = buscarLibreTrabajos(trabajos,tam);
        if(indice == -1)
        {
            printf("El sistema esta lleno\n");
        }
        else
        {
            auxTrabajo.idTrabajo = idTrabajo;
            auxTrabajo.isEmpty = 0;

            listarNotebooks(notebooks,marcas,tipos,clientes,tam);
            printf("Ingrese ID de Notebook : ");
            scanf("%d",&auxTrabajo.idNotebook);

            while(validarIdNotebook(notebooks,auxTrabajo.idNotebook,tam)==0)
            {
                printf("Id invalido. reingrese : ");
                scanf("%d", &auxTrabajo.idNotebook);
            }
            printf("%d",auxTrabajo.idNotebook);
            system("pause");
            mostrarServicios(servicios,tam);
            printf("Ingrese ID de servicio: ");
            scanf("%d",&auxTrabajo.idServicio);

            while(validarIdServicios(servicios,tam,auxTrabajo.idServicio)==0)
            {
                printf("Id invalido. reingrese : ");
                scanf("%d", &auxTrabajo.idServicio);
            }

            printf("%d",auxTrabajo.idServicio);
            system("pause");

            printf("Ingrese Fecha nacimiento dd/mm/aaaa : ");
            scanf("%d/%d/%d",&auxTrabajo.fecNac.dia,&auxTrabajo.fecNac.mes,&auxTrabajo.fecNac.anio);


            if(confirmacion("Alta")=='s')
            {
                trabajos[indice] = auxTrabajo;
                error = 0;
            }
            else
            {
                error = 2;
            }


        }
    }
    return error;
}

int buscarLibreTrabajos(eTrabajo trabajos[], int tam)
{
    int indice= -1;
    for(int i = 0; i < tam; i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            indice = i ;
            break;
        }
    }
    return indice;
}

int listarTrabajos(eNotebook notebooks[], int tam, eMarca marcas[], eTipo tipos[],eServicio servicios[],eTrabajo trabajos[])
{
    int error = 1;
    int flag = 0;
    if(trabajos != NULL && marcas != NULL && tipos != NULL && tam >0)
    {
        system("cls");
        printf(" trabajo                 Notebooks                             Servicio            Fecha\n");
        printf("--------   ------------------------------------------     ---------------------- -----------\n");
        printf("   ID          Modelo      Marca       Tipo    Precio        servicios  precios   dd/mm/aaaa \n\n");

        for(int i = 0 ; i<tam; i++)
        {
            if(trabajos[i].isEmpty == 0)
            {
                mostrarTrabajos(notebooks[i],tam,marcas,tipos,trabajos[i],servicios[i]);
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



void mostrarTrabajos(eNotebook notebooks, int tam, eMarca marcas[], eTipo tipos[], eTrabajo trabajos, eServicio servicios)
{
    char descMarca[20];
    char descTipo[20];

    if(!obtenerDescripcionMarca(marcas,tam,notebooks.idMarca,descMarca) && !obtenerDescripcionTipo(tipos,tam,notebooks.idTipo,descTipo))
    {
        printf("  %4d%15s  %8s  %10s  $%06.2f %15s  $%04.2f   %02d/%02d/%d\n",
               trabajos.idTrabajo,
               notebooks.modeloNotebook,
               descMarca,
               descTipo,
               notebooks.precio,
               servicios.desServicio,
               servicios.precio,
               trabajos.fecNac.dia,
               trabajos.fecNac.mes,
               trabajos.fecNac.anio);

    }
    else
    {
        printf("error al obtener descripcion \n ");
    }

}
//aca
/*int informeTotalaPagar()
{
    int error=1;
    auxTrabajo;
    system("cls");
    printf("Total a pagar \n\n");


    return error;
}


int validarTrabajo(eTrabajo trabajos[],int tam, int id_t)
{
    int esValido = 0;
    if(trabajos != NULL && tam>0)
    {
        for(int i =0; i<tam ; i++)
        {
            if(trabajos[i].idTrabajo == id_t)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}*/
