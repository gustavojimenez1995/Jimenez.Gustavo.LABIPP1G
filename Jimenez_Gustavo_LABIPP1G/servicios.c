#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

#include "servicios.h"


int inicializarServicios(eServicio servicios[], int tam)
{
    int error=1;
    if(servicios != NULL && tam >0)
    {
        for(int i= 0; i < tam ; i++)
        {
            servicios[i].isEmpty=1;
        }
        error= 0;
    }
    return error;
}

void mostrarServicio(eServicio servicio)
{
    printf(" %5d %15s  $%8.2f\n",servicio.idServicio, servicio.desServicio, servicio.precio);
}

int mostrarServicios(eServicio servicios[], int tam)
{
    int error = 1;
    int flag=0;
    if(servicios != NULL && tam >0)
    {
        system("cls");
        printf(" ID        servicios      precios \n");
        printf("-----------------------------------\n");


        for(int i = 0 ; i<tam; i++)
        {
            if(servicios[i].isEmpty == 0)
            {
                mostrarServicio(servicios[i]);
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
int validarIdServicios(eServicio servicios[],int tam, int idServicio)
{
    int esValido = 0;
    if(servicios != NULL && tam>0)
    {
        for(int i =0; i<tam ; i++)
        {
            if(servicios[i].idServicio == idServicio)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

