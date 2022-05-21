#ifndef MICRO_H_
#define MICRO_H_


#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0
#define ID 0
#define EMPRESA 1
#define TIPO 2
#define CAPACIDAD 3

typedef struct
{
	int id;
	int idEmpresa;
	int idTipo;
	int capacidad;
	int idChofer;
	int isEmpty;

} eMicro;


/** \brief Pone el estado de la bandera isEmpty en TRUE de cada micro
 *
 * \param array[] eDestino Array de Micros
 * \param len int Límite del array
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eMicro_inicializar(eMicro array[], int len);


/** \brief Carga algunos datos de micros para testear
 *
 * \param array[] eDestino Array de Micros
 * \param len int Límite del array
 * \param id int* ID del micro a cargar
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eMicro_hardcodear(eMicro array[], int len, int* id);


/** \brief Verifica si el array de Micros está vacío
 *
 * \param array[] eDestino Array de Micros
 * \param len int Límite del array
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eMicro_arrayIsEmpty(eMicro array[], int len);


/** \brief Encuentra el índice del primer micro vacío
 *
 * \param array[] eDestino Array de Micros
 * \param len int Límite del array
 * \param indice int* Lugar donde se guardará el índice del primer micro vacío encontrado
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eMicro_obtenerIndiceVacio(eMicro array[], int len, int* indice);


/** \brief Encuentra un micro por ID
 *
 * \param array[] eDestino Array de Micros
 * \param len int Límite del array
 * \param id int ID del micro a buscar
 * \param indice int* Lugar donde se guardará el índice del micro encontrado
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eMicro_encontrarPorId(eMicro array[], int len, int id, int* indice);


/** \brief Elimina el micro en el índice especificado, cambiando el estado de la bandera isEmpty a TRUE
 *
 * \param array[] eDestino Array de Micros
 * \param len int Límite del array
 * \param indice int Índice del micro a eliminar
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eMicro_eliminar(eMicro array[], int len, int indice);


/** \brief Establece el criterio de ordenamiento elegido
 *
 * \param criterio int* Lugar donde se guardará el criterio elegido
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eMicro_elegirCriterioOrdenamiento(int* criterio);


/** \brief Establece el sentido de ordenamiento elegido
 *
 * \param order int* Lugar donde se guardará el sentido elegido
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eMicro_elegirSentidoOrdenamiento(int* order);


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
int eMicro_compararInt(int a, int b);


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
int eMicro_compararFloat(float a, float b);


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
int eMicro_compararChar(char a, char b);


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
int eMicro_compararString(char* a, char* b, int length);


/** \brief Intercambia los valores de dos micros
 *
 * \param a eMicro* Primer micro
 * \param b eMicro* Segundo micro
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eMicro_swap(eMicro* a, eMicro* b);


/** \brief Compara los valores de los datos de dos micros
 *
 * \param a eMicro* Primer micro
 * \param b eMicro* Segundo micro
 * \param criterio int Criterio de ordenamiento
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eMicro_compararCriterio(eMicro* a, eMicro* b, int criterio);


/** \brief Ordena los micros según los dos criterios y el sentido de ordenamiento elegidos
 *
 * \param array[] eDestino Array de Micros
 * \param len int Límite del array
 * \param criterio1 int Primer criterio de ordenamiento
 * \param criterio2 int Segundo criterio de ordenamiento
 * \param order int Sentido de ordenamiento
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eMicro_ordenar(eMicro array[], int len, int criterio1, int criterio2, int order);


#endif /* MICRO_H_ */
