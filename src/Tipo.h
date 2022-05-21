#ifndef TIPO_H_
#define TIPO_H_

#define TIPO_DESC_LEN 20
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0
#define ID 0
#define DESC 1

typedef struct
{
	int id;
	char descripcion[TIPO_DESC_LEN];

} eTipo;


/** \brief Carga algunos datos de tipos para testear
 *
 * \param array[] eTipo Array de Tipos
 * \param len int Límite del array
 * \param id int* ID del tipo a cargar
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eTipo_hardcodear(eTipo array[], int len, int* id);


/** \brief Encuentra un tipo por ID
 *
 * \param array[] eDestino Array de Tipos
 * \param len int Límite del array
 * \param id int ID del tipo a buscar
 * \param indice int* Lugar donde se guardará el índice del tipo encontrado
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eTipo_encontrarPorId(eTipo array[], int len, int id, int* indice);


/** \brief Establece el criterio de ordenamiento elegido
 *
 * \param criterio int* Lugar donde se guardará el criterio elegido
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eTipo_elegirCriterioOrdenamiento(int* criterio);


/** \brief Establece el sentido de ordenamiento elegido
 *
 * \param order int* Lugar donde se guardará el sentido elegido
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eTipo_elegirSentidoOrdenamiento(int* order);


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
int eTipo_compararInt(int a, int b);


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
int eTipo_compararFloat(float a, float b);


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
int eTipo_compararChar(char a, char b);


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
int eTipo_compararString(char* a, char* b, int length);


/** \brief Intercambia los valores de dos tipos
 *
 * \param a eTipo* Primer tipo
 * \param b eTipo* Segundo tipo
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eTipo_swap(eTipo* a, eTipo* b);


/** \brief Compara los valores de los datos de dos tipos
 *
 * \param a eTipo* Primer tipo
 * \param b eTipo* Segundo tipo
 * \param criterio int Criterio de ordenamiento
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eTipo_compararCriterio(eTipo* a, eTipo* b, int criterio);


/** \brief Ordena los tipos según los dos criterios y el sentido de ordenamiento elegidos
 *
 * \param array[] eDestino Array de Tipos
 * \param len int Límite del array
 * \param criterio1 int Primer criterio de ordenamiento
 * \param criterio2 int Segundo criterio de ordenamiento
 * \param order int Sentido de ordenamiento
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eTipo_ordenar(eTipo array[], int len, int criterio1, int criterio2, int order);


/** \brief Imprime los datos de un tipo
 *
 * \param unTipo eTipo* Puntero a un tipo
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eTipo_mostrarUnTipo(eTipo* unTipo);


/** \brief Imprime la lista de tipos
 *
 * \param array[] eDestino Array de Tipos
 * \param len int Límite del array
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eTipo_mostrarLista(eTipo array[], int len);


#endif /* TIPO_H_ */
