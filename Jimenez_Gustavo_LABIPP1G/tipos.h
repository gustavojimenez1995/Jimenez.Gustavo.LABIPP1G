#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

struct
{
    int idTipo;
    char desTipo[20];
    int isEmpty;

} typedef eTipo;


#endif // TIPOS_H_INCLUDED


/** \brief  verifica si el numero entero es parte del array de estructura
 *
 * \param tipos[] eTipo array de estructura en que se verifica
 * \param tam int tamaño de array
 * \param id_t int numero entero que se desea verificar
 * \return int  0 si hay error/1 si esta bien
 *
 */
int validarIdtipo(eTipo tipos[],int tam , int id_t);

/** \brief obtiene la descripcion del id
 *
 * \param tipo[] eTipo array de estructuras que se recorre
 * \param tam int tamaño del array
 * \param id int numero entero que desea saber la decripcion
 * \param descripcion[] char variable donde se guarda la descripcion
 * \return int 1 si hay error/0 si esta bien
 *
 */
int obtenerDescripcionTipo(eTipo tipo[], int tam, int id, char descripcion[]);

/** \brief inicia todas las posiciones, isEmpty = 1
 *
 * \param tipos[] eTipo eMarca nombre de array de estructuras
 * \param tam int  tamaño del array
 * \return int  1 si hay error/0 si esta bien
 *
 */
int inicializarTipos(eTipo tipos[], int tam);

/** \brief   muestra los datos de una posicion dentro del array
 *
 * \param tipos eTipo eMarca nombre de array de estructuras
 * \return void
 *
 */
void mostrarTipo(eTipo tipos);

/** \brief  muestra los datos de una posicion dentro del array
 *
 * \param tipos[] eTipo
 * \param tam int nombre de array de estructuras
 * \return int 1 si hay error/0 si esta bien
 *
 */
int mostrarTipos(eTipo tipos[], int tam);
