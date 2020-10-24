#ifndef MARCAS_H_INCLUDED
#define MARCAS_H_INCLUDED

struct
{
    int idMarca;
    char desMarca[20];
    int isEmpty;

} typedef eMarca;

#endif // MARCAS_H_INCLUDED


/** \brief verifica si el numero entero es parte del array de estructura
 *
 * \param marcas[] eMarca array de estructura en que se verifica
 * \param tam int tamaño del array
 * \param id_m int  numero entero que se desea verificar
 * \return int  0 si hay error/1 si esta bien
 *
 *
 */
int validarIdMarca(eMarca marcas[],int tam , int id_m);

/** \brief obtiene la descripcion del id
 *
 * \param marca[] eMarca array de estructuras que se recorre
 * \param tam int tamaño del array
 * \param id int id numero entero que desea saber la decripcion
 * \param descripcion[] char variable donde se guarda la descripcion
 * \return int  1 si hay error/0 si esta bien
 *
 */
int obtenerDescripcionMarca(eMarca marca[], int tam, int id, char descripcion[]);

/** \brief inicia todas las posiciones, isEmpty = 1
 *
 * \param marcas[] eMarca nombre de array de estructuras
 * \param tam int tamaño del array
 * \return int  1 si hay error/0 si esta bien
 *
 */
int inicializarMarcas(eMarca marcas[], int tam);



/** \brief muestra los datos de una posicion dentro del array
 *
 * \param marcas eMarca nombre de array de estructuras
 * \return void
 *
 */
void mostrarMarca(eMarca marcas);
/** \brief  muestra los datos de una posicion dentro del array
 *
 * \param marcas[] eMarca
 * \param tam int nombre de array de estructuras
 * \return int 1 si hay error/0 si esta bien
 *
 */
int mostrarMarcas(eMarca marcas[], int tam);
