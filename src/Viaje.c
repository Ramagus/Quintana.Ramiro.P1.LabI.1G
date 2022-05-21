#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Viaje.h"


int eViaje_inicializar(eViaje array[], int len)
{
	int retorno = -1;
	int i;

	if(array != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			array[i].isEmpty = TRUE;
		}

		retorno = 0;
	}

	return retorno;
}

int eViaje_hardcodear(eViaje array[], int len, int* id)
{
	int retorno = -1;
	int indice;
	int i;
	int cant;
	int flag = FALSE;

	eViaje auxArray[] =
	{
		{0, 3, 20003, {1, 9, 2000}, FALSE},
		{0, 3, 20001, {5, 6, 2002}, FALSE},
		{0, 1, 20002, {9, 4, 2004}, FALSE},
		{0, 1, 20000, {5, 6, 2002}, FALSE},
		{0, 2, 20001, {1, 9, 2000}, FALSE},
		{0, 2, 20003, {7, 7, 2010}, FALSE}
	};

	if(array != NULL && len > 0 && id != NULL)
	{
		cant = sizeof(auxArray) / sizeof(eViaje);

		if(cant <= len)
		{
			for(i = 0; i < cant; i++)
			{
				if(!eViaje_obtenerIndiceVacio(array, len, &indice))
				{
					array[indice] = auxArray[i];
					array[indice].id = *id;

					(*id)++;

					flag = TRUE;
				}

				else
				{
					break;
				}
			}

			if(flag)
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}


int eViaje_arrayIsEmpty(eViaje array[], int len)
{
	int retorno = -1;
	int i;

	if(array != NULL && len > 0)
	{
		retorno = 1;

		for(i = 0; i < len; i++)
		{
			if(array[i].isEmpty == FALSE)
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int eViaje_obtenerIndiceVacio(eViaje array[], int len, int* indice)
{
	int retorno = -1;
	int i;

	if(array != NULL && len > 0 && indice != NULL)
	{
		for(i = 0; i < len; i++)
		{
			if(array[i].isEmpty)
			{
				*indice = i;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int eViaje_encontrarPorId(eViaje array[], int len, int id, int* indice)
{
	int retorno = -1;
	int i;

	if(array != NULL && len > 0 && id > 0 && indice != NULL)
	{
		for(i = 0; i < len; i++)
		{
			if(!array[i].isEmpty && array[i].id == id)
			{
				*indice = i;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int eViaje_eliminar(eViaje array[], int len, int indice)
{
	int retorno = -1;

	if(array != NULL && len > 0 && indice >= 0 && indice < len && !array[indice].isEmpty)
	{
		array[indice].isEmpty = TRUE;

		retorno = 0;
	}

	return retorno;
}

int eViaje_elegirCriterioOrdenamiento(int* criterio)
{
    int retorno = -1;
	char opcion;

    if(criterio != NULL)
    {
        printf("\n");
        system("pause");
        system("cls");

        printf("\tCRITERIO DE ORDENAMIENTO\n\n");
        printf("A. ID\n");
        printf("B. Dato 1\n");
        printf("C. Dato 2\n");
        printf("D. Dato 3\n");

        if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'D', 2))
        {
            switch(opcion)
            {
                case 'A':

                    *criterio = ID;

                    break;

                case 'B':

                    *criterio = ID_MICRO;

                    break;

                case 'C':

                    *criterio = ID_DESTINO;

                    break;

                case 'D':

                    *criterio = FECHA;

                    break;
            }

            retorno = 0;
        }
    }

    return retorno;
}

int eViaje_elegirSentidoOrdenamiento(int* order)
{
    int retorno = -1;
    char option;

    if(order != NULL)
    {
		printf("\n");
		system("pause");
		system("cls");

		printf("\tSENTIDO DE ORDENAMIENTO\n\n");
		printf("A. Orden Ascendente\n");
		printf("B. Orden Descendente\n");

		if(!utn_getCaracter(&option, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'B', 2))
		{
			switch(option)
			{
				case 'A':

					*order = UP;

					break;

				case 'B':

					*order = DOWN;

					break;
			}

			retorno = 0;
		}
    }

    return retorno;
}

int eViaje_compararInt(int a, int b)
{
	int retorno = -2;

	if(a > 0 && b > 0)
	{
		if(a < b)
		{
			retorno = -1;
		}

		else if(a == b)
		{
			retorno = 0;
		}

		else
		{
			retorno = 1;
		}
	}

	return retorno;
}

int eViaje_compararFloat(float a, float b)
{
	int retorno = -2;

	if(a > 0 && b > 0)
	{
		if(a < b)
		{
			retorno = -1;
		}

		else if(a == b)
		{
			retorno = 0;
		}

		else
		{
			retorno = 1;
		}
	}

	return retorno;
}

int eViaje_compararChar(char a, char b)
{
	int retorno = -2;

	if(a != '\0' && b != '\0')
	{
		if(a < b)
		{
			retorno = -1;
		}

		else if(a == b)
		{
			retorno = 0;
		}

		else
		{
			retorno = 1;
		}
	}

	return retorno;
}

int eViaje_compararString(char* a, char* b, int length)
{
	int retorno = -2;
	int auxCmp;

	if(a != NULL && b != NULL && length > 0)
	{
		auxCmp = strncmp(a, b, length);

		if(auxCmp < 0)
		{
			retorno = -1;
		}

		else if(auxCmp == 0)
		{
			retorno = 0;
		}

		else
		{
			retorno = 1;
		}
	}

	return retorno;
}

int eViaje_swap(eViaje* a, eViaje* b)
{
	int retorno = -1;
	eViaje temp;

	if(a != NULL && b != NULL)
	{
		temp = *a;
		*a = *b;
		*b = temp;

		retorno = 0;
	}

	return retorno;
}

int eViaje_compararCriterio(eViaje* a, eViaje* b, int criterio)
{
	int retorno = -3;

	if(a != NULL && b != NULL && criterio >= 0)
	{
		switch(criterio)
		{
			case ID:

				retorno = eViaje_compararInt(a->id, b->id);

				break;

			case ID_MICRO:

				retorno = eViaje_compararInt(a->idMicro, b->idMicro);

				break;

			case ID_DESTINO:

				retorno = eViaje_compararInt(a->idDestino, b->idDestino);

				break;

			/*case FECHA:

				retorno = eViaje_compararString(a->dato3, b->dato3, MAX_STR_GEN_2);

				break;*/
		}
	}

	return retorno;
}

int eViaje_ordenar(eViaje array[], int len, int criterio1, int criterio2, int order)
{
	int retorno = -1;
	int i;
	int auxLen;
	int auxCmp;
	int flagSwap;

	if(array != NULL && len > 0 && criterio1 >= 0 && criterio2 >= 0 &&
	   criterio1 != criterio2 && (order == UP || order == DOWN))
	{
		auxLen = len;

		do
		{
			flagSwap = FALSE;

			for(i = 0; i < auxLen - 1; i++)
			{
				if(!array[i].isEmpty && !array[i + 1].isEmpty)
				{
					auxCmp = eViaje_compararCriterio(&array[i], &array[i + 1], criterio1);

				    if((auxCmp == order - !order || (!auxCmp && eViaje_compararCriterio(&array[i], &array[i + 1], criterio2) == order - !order)) &&
				       !eViaje_swap(&array[i], &array[i + 1]))
				    {
				    	flagSwap = TRUE;
				    }
				}
			}

			auxLen--;

		} while(flagSwap);

		retorno = 0;
	}

	return retorno;
}

int eViaje_encontrarFecha(eViaje array[], int len, eFecha* fecha, int* indice)
{
	int retorno = -1;
	int i;

	if(array != NULL && len > 0 && fecha != NULL &&
	   !validarFecha(fecha->dia, fecha->mes, fecha->anio) && indice != NULL)
	{
		for(i = 0; i < len; i++)
		{
			if(!array[i].isEmpty && array[i].fecha.dia == fecha->dia &&
	            array[i].fecha.mes == fecha->mes && array[i].fecha.anio == fecha->anio)
			{
				*indice = i;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
