#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

#include "cliente.h"
#include "validacionesHerramientas.h"

int inicializarClientes(eCliente clientes[], int tam)
{
    int error=1;
    if(clientes != NULL && tam >0)
    {
        for(int i= 0; i < tam ; i++)
        {
            clientes[i].isEmpty=1;
        }
        error= 0;
    }
    return error;
}

int obtenerNombreCliente(eCliente clientes[],int idCliente, char nombre[], int tam)
{
    int error= 1;

    if(clientes!=NULL && tam>0 && nombre!=NULL)
    {

        for(int i = 0 ; i< tam; i++)
        {
            if ( clientes[i].idCliente == idCliente)
            {
                strcpy(nombre, clientes[i].nombre);
                error=0;
                break;
            }
        }

    }

    return error;
}

void mostrarCliente(eCliente cliente)
{
    printf(" %4d %10s \n",cliente.idCliente, cliente.nombre);
}

int listarClientes(eCliente clientes[], int tam)
{
    int error = 1;
    int flag=0;
    if(clientes != NULL && tam >0)
    {
        system("cls");
        printf(" ID         Cliente\n");
        printf("-------------------\n");


        for(int i = 0 ; i<tam; i++)
        {
            if(clientes[i].isEmpty == 0)
            {
                mostrarCliente(clientes[i]);
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
int validarCliente(eCliente clientes[],int tam, int id_c)
{
    int esValido = 0;
    if(clientes != NULL && tam>0)
    {
        for(int i =0; i<tam ; i++)
        {
            if(clientes[i].idCliente == id_c)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

int altaClientes(eCliente clientes[],int idClientes, int tam)
{
    int error=1 ;
    int indice;
    eCliente auxCliente;

    if ( clientes != NULL  && tam>0 && idClientes>=1000)
    {
        system("cls");
        printf(" *** Alta de Cliente*** \n\n");
        indice = buscarLibreClientes(clientes,tam);
        if(indice == -1)
        {
            printf("El sistema esta lleno\n");
        }
        else
        {
            auxCliente.idCliente = idClientes;
            auxCliente.isEmpty = 0;

            antiOverflow(auxCliente.nombre,20,"Nombre");

            if(confirmacion("Alta")=='s')
            {
                clientes[indice] = auxCliente;
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

int buscarLibreClientes(eCliente clientes[], int tam)
{
    int indice= -1;
    for(int i = 0; i < tam; i++)
    {
        if(clientes[i].isEmpty == 1)
        {
            indice = i ;
            break;
        }
    }
    return indice;
}
