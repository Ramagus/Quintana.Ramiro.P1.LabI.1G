#ifndef FECHA_H_
#define FECHA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;

} eFecha;


/** \brief Carga los datos de una fecha
 *
 * \param unaFecha eFecha* Puntero a una fecha
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int cargarFecha(eFecha* unaFecha);


/** \brief Verifica si los datos de una fecha son correctos
 *
 * \param dia int D�a de la fecha
 * \param mes int Mes de la fecha
 * \param anio int A�o de la fecha
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int validarFecha(int dia, int mes, int anio);


/** \brief Verifica si el a�o de la fecha es bisiesto
 *
 * \param anio int A�o de la fecha
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int esBisiesto(int anio);


/** \brief Muestra los datos de una fecha
 *
 * \param unaFecha eFecha* Puntero a una fecha
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int mostrarFecha(eFecha* unaFecha);


#endif /* FECHA_H_ */
