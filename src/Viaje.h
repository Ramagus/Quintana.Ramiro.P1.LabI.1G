#ifndef VIAJE_H_
#define VIAJE_H_

#include "Fecha.h"
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0
#define ID 0
#define ID_MICRO 1
#define ID_DESTINO 2
#define FECHA 3

typedef struct
{
	int id;
	int idMicro;
	int idDestino;
	eFecha fecha;
	int isEmpty;

} eViaje;


/** \brief Pone el estado de la bandera isEmpty en TRUE de cada viaje
 *
 * \param array[] eDestino Array de Viajes
 * \param len int Límite del array
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eViaje_inicializar(eViaje array[], int len);


/** \brief Carga algunos datos de viajes para testear
 *
 * \param array[] eDestino Array de Viajes
 * \param len int Límite del array
 * \param id int* ID del viaje a cargar
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eViaje_hardcodear(eViaje array[], int len, int* id);


/** \brief Verifica si el array de Viajes está vacío
 *
 * \param array[] eDestino Array de Viajes
 * \param len int Límite del array
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eViaje_arrayIsEmpty(eViaje array[], int len);


/** \brief Encuentra el índice del primer viaje vacío
 *
 * \param array[] eDestino Array de Viajes
 * \param len int Límite del array
 * \param indice int* Lugar donde se guardará el índice del primer viaje vacío encontrado
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eViaje_obtenerIndiceVacio(eViaje array[], int len, int* indice);


/** \brief Encuentra un viaje por ID
 *
 * \param array[] eDestino Array de Viajes
 * \param len int Límite del array
 * \param id int ID del viaje a buscar
 * \param indice int* Lugar donde se guardará el índice del viaje encontrado
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eViaje_encontrarPorId(eViaje array[], int len, int id, int* indice);


/** \brief Elimina el viaje en el índice especificado, cambiando el estado de la bandera isEmpty a TRUE
 *
 * \param array[] eDestino Array de Viajes
 * \param len int Límite del array
 * \param indice int Índice del viaje a eliminar
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eViaje_eliminar(eViaje array[], int len, int indice);


/** \brief Establece el criterio de ordenamiento elegido
 *
 * \param criterio int* Lugar donde se guardará el criterio elegido
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eViaje_elegirCriterioOrdenamiento(int* criterio);


/** \brief Establece el sentido de ordenamiento elegido
 *
 * \param order int* Lugar donde se guardará el sentido elegido
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eViaje_elegirSentidoOrdenamiento(int* order);


/** \brief Compara los valores de dos int
 *
 * \param a int Primer int
 * \param b int Segundo int
 *
 * \return int (-2) si hubo un error
 *             (-1) si el primer int es menor al segundo int
 *             ( 0) si ambos int son iguales
 *             ( 1) si el primer int es mayor al segundo int
 *
 */
int eViaje_compararInt(int a, int b);


/** \brief Compara los valores de dos float
 *
 * \param a float Primer float
 * \param b float Segundo float
 *
 * \return int (-2) si hubo un error
 *             (-1) si el primer float es menor al segundo float
 *             ( 0) si ambos float son iguales
 *             ( 1) si el primer float es mayor al segundo float
 *
 */
int eViaje_compararFloat(float a, float b);


/** \brief Compara los valores de dos char
 *
 * \param a char Primer char
 * \param b char Segundo char
 *
 * \return int (-2) si hubo un error
 *             (-1) si el primer char es menor al segundo char en su valor
 *             ( 0) si ambos char son iguales
 *             ( 1) si el primer char es mayor al segundo char en su valor
 *
 */
int eViaje_compararChar(char a, char b);


/** \brief Compara los valores de dos string
 *
 * \param a char* Primer string
 * \param b char* Segundo string
 * \param length int Longitud de String
 *
 * \return int (-2) si hubo un error
 *             (-1) si el primer string es menor al segundo string en su valor
 *             ( 0) si ambos string son iguales
 *             ( 1) si el primer string es mayor al segundo string en su valor
 *
 */
int eViaje_compararString(char* a, char* b, int length);


/** \brief Intercambia los valores de dos viajes
 *
 * \param a eViaje* Primer viaje
 * \param b eViaje* Segundo viaje
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eViaje_swap(eViaje* a, eViaje* b);


/** \brief Compara los valores de los datos de dos viajes
 *
 * \param a eViaje* Primer viaje
 * \param b eViaje* Segundo viaje
 * \param criterio int Criterio de ordenamiento
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eViaje_compararCriterio(eViaje* a, eViaje* b, int criterio);


/** \brief Ordena los viajes según los dos criterios y el sentido de ordenamiento elegidos
 *
 * \param array[] eDestino Array de Viajes
 * \param len int Límite del array
 * \param criterio1 int Primer criterio de ordenamiento
 * \param criterio2 int Segundo criterio de ordenamiento
 * \param order int Sentido de ordenamiento
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eViaje_ordenar(eViaje array[], int len, int criterio1, int criterio2, int order);


/** \brief Encuentra un viaje por fecha
 *
 * \param array[] eDestino Array de Viajes
 * \param len int Límite del array
 * \param fecha eFecha* Fecha del viaje a buscar
 * \param indice int* Lugar donde se guardará el índice del viaje encontrado
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eViaje_encontrarFecha(eViaje array[], int len, eFecha* fecha, int* indice);


#endif /* VIAJE_H_ */
