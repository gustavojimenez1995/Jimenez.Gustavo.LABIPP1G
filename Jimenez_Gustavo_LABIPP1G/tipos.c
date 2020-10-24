#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

#include "tipos.h"

void mostrarTipo(eTipo tipos)
{
    printf(" %4d %10s \n",tipos.idTipo, tipos.desTipo);
}

int mostrarTipos(eTipo tipos[], int tam)
{
    int error = 1;
    int flag=0;
    if(tipos != NULL && tam >0)
    {
        system("cls");
        printf(" ID         Tipos\n");
        printf("------------------\n");


        for(int i = 0 ; i<tam; i++)
        {
            if(tipos[i].isEmpty==0)
            {
                mostrarTipo(tipos[i]);
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

int validarIdtipo(eTipo tipos[],int tam, int id_t)
{
    int esValido = 0;
    if(tipos != NULL && tam>0)
    {
        for(int i =0; i<tam ; i++)
        {
            if(tipos[i].idTipo == id_t)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}
int obtenerDescripcionTipo(eTipo tipo[], int tam, int id, char descripcion[])
{
    int error= 1;

    if(tipo!=NULL && tam>0 && descripcion!=NULL)
    {

        for(int i = 0 ; i< tam; i++)
        {
            if ( tipo[i].idTipo == id)
            {
                strcpy(descripcion, tipo[i].desTipo);
                error=0;
                break;
            }
        }

    }

    return error;
}
int inicializarTipos(eTipo tipos[], int tam)
{
    int error=1;
    if(tipos != NULL && tam >0)
    {
        for(int i= 0; i < tam ; i++)
        {
            tipos[i].isEmpty=1;
        }
        error= 0;
    }
    return error;
}

