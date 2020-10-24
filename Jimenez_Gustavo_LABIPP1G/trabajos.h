#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

#include "marcas.h"
#include "tipos.h"
#include "servicios.h"
#include "notebooks.h"

struct
{
    int dia;
    int mes;
    int anio;
} typedef eFecha;

struct
{
    int idTrabajo;
    int idNotebook;
    int idServicio;
    eFecha fecNac;
    int isEmpty;

} typedef eTrabajo;

#endif // TRABAJOS_H_INCLUDED

/** \brief inicia todas las posiciones, isEmpty = 1
 *
 * \param trabajos[] eTrabajo nombre de array de estructuras
 * \param tam int tamaño de array
 * \return int 1 si hay error/0 si esta bien
 *
 */
int inicializarTrabajos(eTrabajo trabajos[], int tam);

/** \brief devuelve indice vacio dentro del array,
 *
 * \param trabajos[] eTrabajo nombre de array de estructuras
 * \param tam int tamaño de array
 * \return int indice de campo libre
 *
 */
int buscarLibreTrabajos(eTrabajo trabajos[], int tam);

/** \brief solicita y agrega datos en la primera posicion vacia encontrada
 *
 * \param trabajos[] eTrabajo nombrel de array de estructuras
 * \param tam int   tamaño de array
 * \param idTrabajo int id numero referencia,
 * \param marcas[] eMarca array de estructuras necesaria para mostrar datos
 * \param tipos[] eTipo array de estructuras necesaria para mostrar datos
 * \param notebooks[] eNotebook array de estructuras necesaria para mostrar datos
 * \param servicios[] eServicio array de estructuras necesaria para mostrar datos
 * \return int 1 si hay error/0 si esta bien/2 si se cancela
 *
 */
int altaTrabajos(eTrabajo trabajos[], int tam,int idTrabajo, eMarca marcas[],eTipo tipos[],eNotebook notebooks[],eServicio servicios[],eCliente clientes[]);

/** \brief Imprime los datos que contiene el array de forma encolumnada
 *
 * \param notebooks[] eNotebook array necesario para mostrar dato
 * \param tam int tamaño de array
 * \param marcas[] eMarca array necesario para mostrar dato
 * \param tipos[] eTipo array necesario para mostrar dato
 * \param servicios[] eServicio array necesario para mostrar dato
 * \param trabajos[] eTrabajo array necesario para mostrar dato
 * \return int
 *
 */
int listarTrabajos(eNotebook notebooks[], int tam, eMarca marcas[], eTipo tipos[],eServicio servicios[],eTrabajo trabajos[]);

/** \brief muestra los datos de una posicion dentro del array
 *
 * \param notebooks eNotebook posicion del que se desea saber los datos
 * \param tam int tamaño de array
 * \param marcas[] eMarca  array necesario para mostrar datos
 * \param tipos[] eTipo array necesario para mostrar datos
 * \param trabajos eTrabajo array necesario para mostrar datos
 * \param servicios eServicio array necesario para mostrar datos
 * \return void
 *
 */
void mostrarTrabajos(eNotebook notebooks, int tam, eMarca marcas[], eTipo tipos[], eTrabajo trabajos,eServicio servicios);
