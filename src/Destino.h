#ifndef DESTINO_H_
#define DESTINO_H_

#define DESC_LEN_DEST 25
#define TRUE_DEST 1
#define FALSE_DEST 0
#define UP_DEST 1
#define DOWN_DEST 0
#define ID_DEST 0
#define DESC_DEST 1
#define PRECIO_DEST 2

typedef struct
{
	int id;
	char descripcion[DESC_LEN_DEST];
	float precio;

} eDestino;


/** \brief Carga algunos datos de destinos para testear
 *
 * \param array[] eDestino Array de Destinos
 * \param len int Límite del array
 * \param id int* ID del destino a cargar
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eDestino_hardcodear(eDestino array[], int len, int* id);


/** \brief Encuentra un destino por ID
 *
 * \param array[] eDestino Array de Destinos
 * \param len int Límite del array
 * \param id int ID del destino a buscar
 * \param indice int* Lugar donde se guardará el índice del destino encontrado
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eDestino_encontrarPorId(eDestino array[], int len, int id, int* indice);


/** \brief Establece el criterio de ordenamiento elegido
 *
 * \param criterio int* Lugar donde se guardará el criterio elegido
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eDestino_elegirCriterioOrdenamiento(int* criterio);


/** \brief Establece el sentido de ordenamiento elegido
 *
 * \param order int* Lugar donde se guardará el sentido elegido
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eDestino_elegirSentidoOrdenamiento(int* order);


/** \brief Compara los valores de dos int
 *
 * \param a int Primer int
 * \param b int Segundo int
 *
 * \return int (-2) si hubo un error en los parámetros
 *             (-1) si el primer int es menor al segundo int
 *             ( 0) si ambos int son iguales
 *             ( 1) si el primer int es mayor al segundo int
 *
 */
int eDestino_compararInt(int a, int b);


/** \brief Compara los valores de dos float
 *
 * \param a float Primer float
 * \param b float Segundo float
 *
 * \return int (-2) si hubo un error en los parámetros
 *             (-1) si el primer float es menor al segundo float
 *             ( 0) si ambos float son iguales
 *             ( 1) si el primer float es mayor al segundo float
 *
 */
int eDestino_compararFloat(float a, float b);


/** \brief Compara los valores de dos char
 *
 * \param a char Primer char
 * \param b char Segundo char
 *
 * \return int (-2) si hubo un error en los parámetros
 *             (-1) si el primer char es menor al segundo char en su valor
 *             ( 0) si ambos char son iguales
 *             ( 1) si el primer char es mayor al segundo char en su valor
 *
 */
int eDestino_compararChar(char a, char b);


/** \brief Compara los valores de dos string
 *
 * \param a char* Primer string
 * \param b char* Segundo string
 * \param length int Longitud de String
 *
 * \return int (-2) si hubo un error en los parámetros
 *             (-1) si el primer string es menor al segundo string en su valor
 *             ( 0) si ambos string son iguales
 *             ( 1) si el primer string es mayor al segundo string en su valor
 *
 */
int eDestino_compararString(char* a, char* b, int length);


/** \brief Intercambia los valores de dos destinos
 *
 * \param a eDestino* Primer destino
 * \param b eDestino* Segundo destino
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eDestino_swap(eDestino* a, eDestino* b);


/** \brief Compara los valores de los datos de dos destinos
 *
 * \param a eDestino* Primer destino
 * \param b eDestino* Segundo destino
 * \param criterio int Criterio de ordenamiento
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eDestino_compararCriterio(eDestino* a, eDestino* b, int criterio);


/** \brief Ordena los destinos según los dos criterios y el sentido de ordenamiento elegidos
 *
 * \param array[] eDestino Array de Destinos
 * \param len int Límite del array
 * \param criterio1 int Primer criterio de ordenamiento
 * \param criterio2 int Segundo criterio de ordenamiento
 * \param order int Sentido de ordenamiento
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eDestino_ordenar(eDestino array[], int len, int criterio1, int criterio2, int order);


/** \brief Imprime los datos de un destino
 *
 * \param unDestino eDestino* Puntero a un destino
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eDestino_mostrarUnDestino(eDestino* unDestino);


/** \brief Imprime la lista de destinos
 *
 * \param array[] eDestino Array de Destinos
 * \param len int Límite del array
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eDestino_mostrarLista(eDestino array[], int len);


#endif /* DESTINO_H_ */
