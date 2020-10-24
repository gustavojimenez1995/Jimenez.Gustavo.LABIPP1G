#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

#include "datosHarcodeo.h"
#include "notebooks.h"
#include "marcas.h"
#include "tipos.h"
#include "servicios.h"
#include "trabajos.h"
#include "validacionesHerramientas.h"
#include "cliente.h"

#define TAM 10
#define TAM_H 4





int harcodear(eMarca marcas[],eTipo tipos[],eServicio servicios[],eCliente clientes[],int tam);

char menu();

int main()
{
    eNotebook listaNotebook[TAM];
    inicializarListaNotebooks(listaNotebook,TAM);

    eTrabajo listaTrabajos[TAM];
    inicializarTrabajos(listaTrabajos,TAM);

    eMarca listaMarcas[TAM];
    inicializarMarcas(listaMarcas,TAM);

    eTipo listaTipos[TAM];
    inicializarTipos(listaTipos,TAM);

    eServicio listaServicos[TAM];
    inicializarServicios(listaServicos,TAM);

    eCliente listaClientes[TAM];
    inicializarClientes(listaClientes,TAM);


    harcodear(listaMarcas,listaTipos,listaServicos,listaClientes, TAM_H);

    listaNotebook[0]= (eNotebook)
    {
        1000,1001,"HH-QW",1001,5001,20500,0
    };
    listaNotebook[1]= (eNotebook)
    {
        1001,1002,"JJ-Q",1003,5002,30000,0
    };
    listaNotebook[2]= (eNotebook)
    {
        1002,1003,"J7-M",1002,5001,50000,0
    };
    listaNotebook[3]= (eNotebook)
    {
        1003,1004,"JMM2",1000,5000,55000,0
    };
    listaNotebook[4]= (eNotebook)
    {
        1001,1005,"JM2",1000,5002,60000,0
    };
    listaNotebook[5]= (eNotebook)
    {
        1000,1006,"JM22M2",1001,5001,58000,0
    };
    listaNotebook[6]= (eNotebook)
    {
        1002,1007,"JM22M2",1001,5002,40000,0
    };

    /*listaTrabajos [1]=(eTrabajo){1001,1001,20001,{17,10,2020}};
    listaTrabajos [2]=(eTrabajo){1002,1002,20003,{23,10,2020}};
    listaTrabajos [3]=(eTrabajo){1003,1003,20002,{23,10,2020}};*/

    char seguir = 's';
    int rtaModificacion;
    int rtaBaja;
    int rtaAltaTr;
    int rtaAltaCl;
    int rtaAltaNot;
    int idClientes=1000;
    int idNotebook=1000;
    int idTrabajos=1000;


    do
    {
        system("cls");
        switch(menu())
        {

        case 'a':
            rtaAltaNot=altaNotebooks(listaNotebook,listaMarcas,listaTipos,listaClientes,TAM,idNotebook);
            if(rtaAltaNot==0)
            {
                printf("\nAlta de notebooks Exitosa!!\n");
                idNotebook++;
            }
            else if (rtaAltaNot ==1)
            {
                printf("\nError al hacer el Alta !!\n");
            }
            else
            {
                printf("\nAlta Cancelada!!\n");
            }
            break;
        case 'b':
            rtaModificacion = modificarNotebooks(listaNotebook,listaMarcas,listaTipos,listaClientes,TAM);
            if(rtaModificacion==0)
            {
                printf("\nModificacion Exitosa!!\n");
            }
            else if (rtaModificacion ==1)
            {
                printf("\nError al modificar !!\n");
            }
            else
            {
                printf("\nModificacion Cancelada!!\n");
            }


            break;
        case 'c':
            rtaBaja=bajaNotebooks(listaNotebook,listaMarcas,listaTipos,listaClientes,TAM);
            if(rtaBaja==0)
            {
                printf("\nBaja Exitosa!!\n");
            }
            else if (rtaBaja ==1)
            {
                printf("\nError al hacer la Baja !!\n");
            }
            else
            {
                printf("\nBaja Cancelada!!\n");
            }


            break;
        case 'd':
            ordenarPersonas(listaNotebook,listaMarcas,TAM);
            if(listarNotebooks(listaNotebook,listaMarcas,listaTipos,listaClientes,TAM))
            {
                printf("\Error al listar Notebooks");
            }
            break;
        case 'e':
            if(mostrarMarcas(listaMarcas,TAM))
            {
                printf("\nError al listar Marcas");
            }
            break;
        case 'f':
            if(mostrarTipos(listaTipos,TAM))
            {
                printf("\nError al listar Tipos");
            }
            break;
        case 'g':
            if(mostrarServicios(listaServicos,TAM))
            {
                printf("\nError al listar Servicios");
            }
            break;
        case 'h':
            rtaAltaTr=altaTrabajos(listaTrabajos,TAM,idTrabajos,listaMarcas,listaTipos,listaNotebook,listaServicos,listaClientes);
            if(rtaAltaTr==0)
            {
                printf("\nAlta Exitosa!!\n");
                idTrabajos++;
            }
            else if (rtaAltaTr ==1)
            {
                printf("\nError al hacer el Alta!!\n");
            }
            else
            {
                printf("\nAlta Cancelada!!\n");
            }
            break;
        case 'i':
            if(listarTrabajos(listaNotebook,TAM,listaMarcas,listaTipos,listaServicos,listaTrabajos))
            {
                printf("\Error al listar Trabajos");
            }

            break;
        case 'j':
            rtaAltaCl=altaClientes(listaClientes,idClientes,TAM);
            if(rtaAltaCl==0)
            {
                printf("\nAlta Exitosa!!\n");
                idClientes++;
            }
            else if (rtaAltaCl ==1)
            {
                printf("\nError al hacer el Alta!!\n");
            }
            else
            {
                printf("\nAlta Cancelada!!\n");
            }

            break;
        case 'k':
            if(listarClientes(listaClientes,TAM))
            {
                printf("\Error al listar Clientes");
            }

            break;
        case 'm':
            if(listarNotbooksPorTipo(listaNotebook,listaTipos,listaMarcas,listaClientes,TAM))
            {
                printf("\Error al listar por tipo");
            }
            break;
        case 'n':
            if(listarNotbooksPorMarca(listaNotebook,listaTipos,listaMarcas,listaClientes,TAM))
            {
                printf("\nError al listar por marca");
            }
            break;
        case 'l':
             if(notebooksBarato(listaNotebook,listaMarcas,listaTipos,listaClientes,TAM))
            {
                printf("\nError al listar Notebooks baratas\n");
            }
            break;
        case 'o':
             if(listarNotebooksDecadaMarca(listaNotebook,listaMarcas,listaTipos,listaClientes,TAM))
            {
                printf("\nError al listar\n");
            }


        case 'z':
            if(confirmacion("Salida") == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("\nOpcion invalida!!!\n");

        }

        system("pause");

    }
    while( seguir == 's');


    return 0;
}


char menu()
{
    char opcion;

    printf("****Menu opcion****\n\n");
    printf(" a. ALTA NOTEBOOK \n");
    printf(" b. MODIFICAR NOTEBOOK\n");
    printf(" c. BAJA NOTEBOOK:\n");
    printf(" d. LISTAR NOTEBOOKS\n");
    printf(" e. LISTAR MARCAS\n");
    printf(" f. LISTAR TIPOS\n");
    printf(" g. LISTAR SERVICIOS\n");
    printf(" h. ALTA TRABAJO\n");
    printf(" i. LISTAR TRABAJOS\n");
    printf(" j. ALTA CLIENTE\n");
    printf(" k. LISTAR CLIENTES\n");
    printf(" m. NOTEBOOKS POR TIPO SELECCIONADO\n");
    printf(" n. NOTEBOOKS POR MARCA SELECCIONADA\n");
    printf(" l. NOTEBOOKS MAS BARATAS\n");
    printf(" o. NOTEBOOKS SEPARADAS POR MARCA");
    printf(" z. Salir\n\n");
    printf("    Ingrese Opcion : ");
    fflush(stdin);
    opcion=tolower(getchar());

    return opcion;
}


int harcodear(eMarca marcas[],eTipo tipos[],eServicio servicios[],eCliente clientes[],int tam)
{
    int error = 1;
    if(tam>0)
    {
        for(int i = 0; i <tam; i++)
        {
            marcas[i].idMarca = idMarcas[i];
            strcpy(marcas[i].desMarca,marcasNot[i]);
            marcas[i].isEmpty=0;

            tipos[i].idTipo = idTipos[i];
            strcpy(tipos[i].desTipo,tiposNot[i]);
            tipos[i].isEmpty=0;

            servicios[i].idServicio = idServicios[i];
            strcpy(servicios[i].desServicio,serviciosNot[i]);
            servicios[i].precio = precios[i];
            servicios[i].isEmpty=0;

            clientes[i].idCliente = idClientes[i];
            strcpy(clientes[i].nombre,nombresClientes[i]);
            clientes[i].sexo = sexClientes[i];
            clientes[i].isEmpty = 0;

        }
        error=0;
    }
    return error;
}





