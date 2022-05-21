#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Fecha.h"


int cargarFecha(eFecha* unaFecha)
{
	int retorno = -1;

	eFecha aux;

	if(unaFecha != NULL)
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tFECHA\n");

		if(!utn_getNumero(&aux.dia, "\nIngrese dia de la fecha entre 1 y 31: ", "Error. Ingrese solo numeros enteros entre 1 y 31: ", 1, 31, 2) &&
		   !utn_getNumero(&aux.mes, "\nIngrese mes de la fecha entre 1 y 12: ", "Error. Ingrese solo numeros enteros entre 1 y 12: ", 1, 12, 2) &&
		   !utn_getNumero(&aux.anio, "\nIngrese anio de la fecha entre 2000 y 2030: ", "Error. Ingrese solo numeros enteros entre 2000 y 2030: ", 2000, 2030, 2) &&
		   !validarFecha(aux.dia, aux.mes, aux.anio))
		{
			*unaFecha = aux;
			retorno = 0;
		}
	}

	return retorno;
}

int validarFecha(int dia, int mes, int anio)
{
	int retorno = -1;
	int diaMaximo;

	if(dia >= 1 && mes >= 1 && mes <= 12 && anio >= 1)
	{
		switch(mes)
		{
			case 4:
			case 6:
			case 9:
			case 11:

				diaMaximo = 30;

				break;

			case 2:

				if(esBisiesto(anio))
				{
					diaMaximo = 29;
				}

				else
				{
					diaMaximo = 28;
				}

				break;

			default:

				diaMaximo = 31;
		}

		if(dia <= diaMaximo)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int esBisiesto(int anio)
{
	int retorno = -1;

	if(anio >= 1)
	{
		retorno = 0;

		if(anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0))
		{
			retorno = 1;
		}
	}

	return retorno;
}

int mostrarFecha(eFecha* unaFecha)
{
	int retorno = -1;

	if(unaFecha != NULL)
	{
		printf("%02d/%02d/%d", unaFecha->dia, unaFecha->mes, unaFecha->anio);

		retorno = 0;
	}

	return retorno;
}
