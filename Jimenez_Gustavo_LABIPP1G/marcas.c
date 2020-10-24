#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

#include "marcas.h"


void mostrarMarca(eMarca marcas)
{
    printf(" %4d %10s \n",marcas.idMarca, marcas.desMarca);
}

int mostrarMarcas(eMarca marcas[], int tam)
{
    int error = 1;
    int flag=0;
    if(marcas != NULL && tam >0)
    {
        system("cls");
        printf(" ID         Marcas\n");
        printf("-------------------\n");


        for(int i = 0 ; i<tam; i++)
        {
            if(marcas[i].isEmpty == 0)
            {
                mostrarMarca(marcas[i]);
                flag=1;
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
int validarIdMarca(eMarca marcas[],int tam, int id_m)
{
    int esValido = 0;
    if(marcas != NULL && tam>0)
    {
        for(int i =0; i<tam ; i++)
        {
            if(marcas[i].idMarca == id_m)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
int obtenerDescripcionMarca(eMarca marca[], int tam, int id, char descripcion[])
{
    int error= 1;

    if(marca!=NULL && tam>0 && descripcion!=NULL)
    {

        for(int i = 0 ; i< tam; i++)
        {
            if ( marca[i].idMarca == id)
            {
                strcpy(descripcion, marca[i].desMarca);
                error=0;
                break;
            }
        }

    }

    return error;
}

int inicializarMarcas(eMarca marcas[], int tam)
{
    int error=1;
    if(marcas != NULL && tam >0)
    {
        for(int i= 0; i < tam ; i++)
        {
            marcas[i].isEmpty=1;
        }
        error= 0;
    }
    return error;
}
