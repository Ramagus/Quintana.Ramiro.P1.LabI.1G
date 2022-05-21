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
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int cargarFecha(eFecha* unaFecha);


/** \brief Verifica si los datos de una fecha son correctos
 *
 * \param dia int Día de la fecha
 * \param mes int Mes de la fecha
 * \param anio int Año de la fecha
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int validarFecha(int dia, int mes, int anio);


/** \brief Verifica si el año de la fecha es bisiesto
 *
 * \param anio int Año de la fecha
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int esBisiesto(int anio);


/** \brief Muestra los datos de una fecha
 *
 * \param unaFecha eFecha* Puntero a una fecha
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
int mostrarFecha(eFecha* unaFecha);


#endif /* FECHA_H_ */
