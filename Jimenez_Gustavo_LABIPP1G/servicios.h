#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

struct
{
    int idServicio;
    char desServicio[20];
    float precio;
    int isEmpty;

} typedef eServicio;


#endif // SERVICIOS_H_INCLUDED

/** \brief  inicia todas las posiciones, isEmpty = 1
 *
 * \param servicios[] eServicio nombre de array de estructuras
 * \param tam int tamaño del array
 * \return int 1 si hay error/0 si esta bien
 *
 */
int inicializarServicios(eServicio servicios[], int tam);

/** \brief muestra los datos de una posicion dentro del array
 *
 * \param servicio eServicio nombre de array de estructuras
 * \return void
 *
 */
void mostrarServicio(eServicio servicio);

/** \brief Imprime los datos que contiene el array de forma encolumnada
 *
 * \param servicios[] eServicio nombre de array de estructuras
 * \param tam int tamaño del array
 * \return int 1 si hay error/0 si esta bien
 *
 */
int mostrarServicios(eServicio servicios[], int tam);

/** \brief berifica si el entero es parte del array de estructura
 *
 * \param servicios[] eServicio nombre de array de estructuras
 * \param tam int tamaño del array
 * \param idServicio int entero que desea validar
 * \return int  0 si hay error/1 si esta bien
 */
int validarIdServicios(eServicio servicios[],int tam , int idServicio);
