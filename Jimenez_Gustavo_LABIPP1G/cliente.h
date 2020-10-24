#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

struct
{
    int idCliente;
    char nombre[20];
    char sexo;
    int isEmpty;

} typedef eCliente;


#endif // CLIENTE_H_INCLUDED
/** \brief inicia todas las posiciones, isEmpty = 1
 *
 * \param eCliente clientes[] nombre de array de estructuras
 * \param tam int tamaño del array
 * \return int  1 si hay error/0 si esta bien
 *
 */
int inicializarClientes(eCliente clientes[], int tam);

/** \brief obtiene la descripcion del id
 *
 * \param eCliente clientes[] array de estructuras que se recorre
 * \param int idCliente numero entero que desea saber la decripcion
 * \param nombre[] char variable donde se guarda la descripcion
 * \param tam int tamaño del array
 * \return int 1 si hay error/0 si esta bien
 *
 */
int obtenerNombreCliente(eCliente clientes[],int idCliente, char nombre[], int tam);

/** \brief muestra los datos de una posicion dentro del array
 *
 * \param eCliente cliente nombre de array de estructuras
 * \return void
 *
 */
void mostrarCliente(eCliente cliente);
/** \brief  muestra los datos de una posicion dentro del array
 *
 * \param eCliente clientes[] nombre de array de estructuras
 * \param tam int tamaño del array
 * \return int 1 si hay error/0 si esta bien
 *
 */
int listarClientes(eCliente clientes[], int tam);

/** \brief verifica si el numero entero es parte del array de estructura
 *
 * \param eCliente clientes[] eMarca array de estructura en que se verifica
 * \param tam int tamaño del array
 * \param int id_c int  numero entero que se desea verificar
 * \return int  0 si hay error/1 si esta bien
 *
 *
 */
int validarCliente(eCliente clientes[],int tam, int id_c);


/** \brief devuelve indice vacio dentro del array
 *
 * \param eCliente clientes[] nombre de array de estructuras
 * \param tam int tamaño del array
 * \return int indice de campo libre
 *
 */
int buscarLibreClientes(eCliente clientes[], int tam);

/** \brief solicita y agrega datos en la primera posicion vacia encontrada
 *
 * \param eCliente clientes[] array de estructuras necesaria para mostrar datos
 * \param idClientes int id numero referencia
 * \return int  1 si hay error/0 si esta bien/2 si se cancela
 *
 */
int altaClientes(eCliente clientes[],int idClientes, int tam);

