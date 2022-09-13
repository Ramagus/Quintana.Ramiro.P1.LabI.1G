#ifndef CHOFER_H_
#define CHOFER_H_

#define NOMBRE_LEN_CHOFER 20

typedef struct
{
	int id;
	char nombre[NOMBRE_LEN_CHOFER];
	char sexo;

} eChofer;


/** \brief Carga algunos datos de choferes para testear
 *
 * \param array[] eDestino Array de Choferes
 * \param len int Límite del array
 * \param id int* ID del chofer a cargar
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eChofer_hardcodear(eChofer array[], int len, int* id);


/** \brief Encuentra un chofer por ID
 *
 * \param array[] eDestino Array de Choferes
 * \param len int Límite del array
 * \param id int ID del chofer a buscar
 * \param indice int* Lugar donde se guardará el índice del destino encontrado
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eChofer_encontrarPorId(eChofer array[], int len, int id, int* indice);


/** \brief Imprime los datos de un chofer
 *
 * \param unChofer eChofer* Puntero a un chofer
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eChofer_mostrarUnChofer(eChofer* unChofer);


/** \brief Imprime la lista de choferes
 *
 * \param array[] eDestino Array de Choferes
 * \param len int Límite del array
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int eChofer_mostrarLista(eChofer array[], int len);


#endif /* CHOFER_H_ */
