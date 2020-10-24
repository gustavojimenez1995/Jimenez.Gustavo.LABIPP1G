#ifndef NOTEBOOKS_H_INCLUDED
#define NOTEBOOKS_H_INCLUDED


#include "marcas.h"
#include "tipos.h"
#include "cliente.h"

struct
{
    int idClienteNot;
    int idNotebook;
    char modeloNotebook[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;

} typedef eNotebook;

#endif // NOTEBOOKS_H_INCLUDED


int altaNotebooks(eNotebook notebooks[], eMarca marca[],eTipo tipos[],eCliente cliente[], int tam,int idNotebook);

/** \brief modifica los datos de un campo especifico del array
 *
 * \param notebooks[] eNotebook array de estructura necesario
 * \param marcas[] eMarca array de estructuras necesaria para mostrar datos
 * \param tipos[] eTipo array de estructuras necesaria para mostrar datos
 * \param clientes[] eCliente array de estructura necesario para mostrar datos
 * \param tam int tamaño del array
 * \return int 1 si hay error/0 si esta bien/2 si se cancela
 *
 */
int modificarNotebooks(eNotebook notebooks[], eMarca marcas[], eTipo tipos[],eCliente clientes[], int tam);

/** \brief Elimina de manera lógica los datos de un campo especifico del array
 *
 * \param notebooks[] eNotebook array de estructura necesario
 * \param marcas[] eMarca array de estructura necesario para mostrar datos
 * \param tipos[] eTipo array de estructura necesario para mostrar datos
 * \param tam int tamaño del array
 * \return int 1 si hay error/0 si esta bien/2 si se cancela
 *
 */
int bajaNotebooks(eNotebook notebooks[], eMarca marcas[], eTipo tipos[],eCliente clientes[], int tam);

/** \brief Imprime los datos que contiene el array de forma encolumnada
 *
 * \param notebooks[] eNotebook array de estructura necesario para mostrar datos
 * \param marcas[] eMarca array de estructura necesario para mostrar datos
 * \param tipos[] eTipo array de estructura necesario para mostrar datos
 * \param clientes[] eCliente array de estructura necesario para mostrar datos
 * \param tam int tamaño del array
 * \return int 1 si hay error/0 si esta bien
 *
 */
int listarNotebooks(eNotebook notebooks[], eMarca marcas[], eTipo tipos[],eCliente clientes[], int tam);

/** \brief muestra los datos de una posicion dentro del array
 *
 * \param notebooks eNotebook array de estructura necesario para mostrar datos
 * \param marcas[] eMarca array de estructura necesario para mostrar datos
 * \param tipos[] eTipo aarray de estructura necesario para mostrar datos
 * \param tam int tamaño del array
 * \return void
 *
 */
void mostrarNotebooks(eNotebook notebooks, eMarca marcas[], eTipo tipos[],eCliente clientes[], int tam);

/** \brief ordenada por marca y precio y de forma encolumnada los datos

 *
 * \param notebooks[] eNotebook array de estructura que se ordena
 * \param marca[] eMarca array de estructura necesario para mostrar datos
 * \param tam int tamaño del array
 * \return int 1 si hay error/0 si esta bien
 *
 */
int ordenarPersonas(eNotebook notebooks[],eMarca marca[], int tam);

/** \brief berifica si el numero entero es parte del array de estructura
 *
 * \param notebooks[] eNotebook array de estructura en que se verifica
 * \param idNotebook int numero entero que se desea verificar
 * \param tam int tamaño del array
 * \return int 0 si hay error/1 si esta bien
 *
 */
int validarIdNotebook(eNotebook notebooks[], int idNotebook,int tam);

/** \brief devuelve indice vacio dentro del array
 *
 * \param notebooks[] eNotebook nombre de array de estructuras
 * \param tam int tamaño del array
 * \return int indice de campo libre
 *
 */
int buscarLibreNotebooks(eNotebook notebooks[], int tam);

/** \brief inicia todas las posiciones, isEmpty = 1
 *
 * \param notebooks[] eNotebook nombre de array de estructuras
 * \param tam int tamaño del array
 * \return int 1 si hay error/0 si esta bien
 *
 */
int inicializarListaNotebooks(eNotebook notebooks[], int tam);

/** \brief devuelve indice vacio dentro del array/ Alta de trabajo
 *
 * \param notebooks[] eNotebook nombre de array de estructuras que se recorre
 * \param tam int tamaño del array
 * \return int indice de campo libre
 *
 */
int idLibreNetbooks(eNotebook notebooks[], int tam);

/** \brief busca y devuelve indice
 *
 * \param notebooks[] eNotebook nombre de array de estructuras que se recorre
 * \param idNotIngresado id del indice a buscar
 * \param tam int tamaño del array
 * \return int indice del array
 *
 */
int buscarNotebooks(eNotebook notebooks[], int idNotIngresado, int tam);

/** \brief
 *
 * \param notebooks[] eNotebook
 * \param marcas[] eMarca
 * \param tipos[] eTipo
 * \param clientes[] eCliente
 * \param tam int
 * \return int
 *
 */

/** \brief Imprime los datos de cada marca
 *
 * \param notebooks[] eNotebook array de estructura necesario para mostrar datos
 * \param marcas[] eMarca array de estructura necesario para mostrar datos
 * \param tipos[] eTipo array de estructura necesario para mostrar datos
 * \param clientes[] eCliente array de estructura necesario para mostrar datos
 * \param tam int tamaño del array
 * \return int 1 si hay error/0 si esta bien
 *
 */
int listarNotebooksDecadaMarca(eNotebook notebooks[],eMarca marcas[],eTipo tipos[],eCliente clientes[], int tam);

/** \brief Imprime los datos de notebooks mas barato
 *
 * \param notebooks[] eNotebook array de estructura necesario para mostrar datos
 * \param marcas[] eMarca array de estructura necesario para mostrar datos
 * \param tipos[] eTipo array de estructura necesario para mostrar datos
 * \param clientes[] eCliente array de estructura necesario para mostrar datos
 * \param tam int tamaño del array
 * \return int 1 si hay error/0 si esta bien
 *
 */
int notebooksBarato(eNotebook notebooks[],eMarca marcas[],eTipo tipos[],eCliente cliente[], int tam);

/** \brief Imprime los datos de notbooks por tipo
 *
 * \param notebooks[] eNotebook array de estructura necesario para mostrar datos
 * \param marcas[] eMarca array de estructura necesario para mostrar datos
 * \param tipos[] eTipo array de estructura necesario para mostrar datos
 * \param clientes[] eCliente array de estructura necesario para mostrar datos
 * \param tam int tamaño del array
 * \return int 1 si hay error/0 si esta bien
 *
 */
int listarNotbooksPorTipo(eNotebook notbooks[],eTipo tipos[],eMarca marcas[],eCliente clientes[],int tam);

/** \brief Imprime los datos de notebooks por marca
 *
 * \param notebooks[] eNotebook array de estructura necesario para mostrar datos
 * \param marcas[] eMarca array de estructura necesario para mostrar datos
 * \param tipos[] eTipo array de estructura necesario para mostrar datos
 * \param clientes[] eCliente array de estructura necesario para mostrar datos
 * \param tam int tamaño del array
 * \return int 1 si hay error/0 si esta bien
 *
 */
int listarNotbooksPorMarca(eNotebook notbooks[],eTipo tipos[],eMarca marcas[],eCliente clientes[],int tam);

/** \brief eNotebook solicita y agrega datos en la primera posicion vacia encontrada
 *
 * \param notebooks[] array de estructuras necesaria para mostrar datos
 * \param marca[] eMarca array de estructuras necesaria para mostrar datos
 * \param tipos[] eTipo  array de estructuras necesaria para mostrar datos
 * \param tam int  tamaño de array
 * \param idNotebook int id numero referencia
 * \return int  1 si hay error/0 si esta bien/2 si se cancela
 *
 */




