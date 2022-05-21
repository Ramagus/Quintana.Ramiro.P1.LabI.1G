#ifndef EMPRESA_H_
#define EMPRESA_H_

#define EMPRESA_DESC_LEN 20
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0
#define ID 0
#define DESC 1

typedef struct
{
	int id;
	char descripcion[EMPRESA_DESC_LEN];

} eEmpresa;


/** \brief Carga algunos datos de empresas para testear
 *
 * \param array[] eDestino Array de Empresas
 * \param len int Límite del array
 * \param id int* ID de la empresa a cargar
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eEmpresa_hardcodear(eEmpresa array[], int len, int* id);


/** \brief Encuentra una empresa por ID
 *
 * \param array[] eDestino Array de Empresas
 * \param len int Límite del array
 * \param id int ID de la empresa a buscar
 * \param indice int* Lugar donde se guardará el índice de la empresa encontrado
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eEmpresa_encontrarPorId(eEmpresa array[], int len, int id, int* indice);


/** \brief Establece el criterio de ordenamiento elegido
 *
 * \param criterio int* Lugar donde se guardará el criterio elegido
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eEmpresa_elegirCriterioOrdenamiento(int* criterio);


/** \brief Establece el sentido de ordenamiento elegido
 *
 * \param order int* Lugar donde se guardará el sentido elegido
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eEmpresa_elegirSentidoOrdenamiento(int* order);


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
int eEmpresa_compararInt(int a, int b);


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
int eEmpresa_compararFloat(float a, float b);


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
int eEmpresa_compararChar(char a, char b);


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
int eEmpresa_compararString(char* a, char* b, int length);


/** \brief Intercambia los valores de dos empresas
 *
 * \param a eEmpresa* Primera empresa
 * \param b eEmpresa* Segunda empresa
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eEmpresa_swap(eEmpresa* a, eEmpresa* b);


/** \brief Compara los valores de los datos de dos empresas
 *
 * \param a eEmpresa* Primera empresa
 * \param b eEmpresa* Segunda empresa
 * \param criterio int Criterio de ordenamiento
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eEmpresa_compararCriterio(eEmpresa* a, eEmpresa* b, int criterio);


/** \brief Ordena las empresas según los dos criterios y el sentido de ordenamiento elegidos
 *
 * \param array[] eDestino Array de Empresas
 * \param len int Límite del array
 * \param criterio1 int Primer criterio de ordenamiento
 * \param criterio2 int Segundo criterio de ordenamiento
 * \param order int Sentido de ordenamiento
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eEmpresa_ordenar(eEmpresa array[], int len, int criterio1, int criterio2, int order);


/** \brief Imprime los datos de una empresa
 *
 * \param unaEmpresa eEmpresa* Puntero a una empresa
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eEmpresa_mostrarUnaEmpresa(eEmpresa* unaEmpresa);


/** \brief Imprime la lista de empresas
 *
 * \param array[] eDestino Array de Empresas
 * \param len int Límite del array
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eEmpresa_mostrarLista(eEmpresa array[], int len);


#endif /* EMPRESA_H_ */
