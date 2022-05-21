#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Micro.h"


int eMicro_inicializar(eMicro array[], int len)
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

int eMicro_hardcodear(eMicro array[], int len, int* id)
{
	int retorno = -1;
	int indice;
	int i;
	int cant;
	int flag = FALSE;

	eMicro auxArray[] =
	{
		{0, 1000, 5000, 50, 1, FALSE},
		{0, 1003, 5002, 30, 1, FALSE},
		{0, 1000, 5001, 40, 2, FALSE},
		{0, 1003, 5003, 30, 2, FALSE},
		{0, 1002, 5000, 50, 3, FALSE},
		{0, 1001, 5002, 10, 3, FALSE},
		{0, 1000, 5003, 20, 4, FALSE},
		{0, 1003, 5000, 50, 4, FALSE},
	};

	if(array != NULL && len > 0 && id != NULL)
	{
		cant = sizeof(auxArray) / sizeof(eMicro);

		if(cant <= len)
		{
			for(i = 0; i < cant; i++)
			{
				if(!eMicro_obtenerIndiceVacio(array, len, &indice))
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

int eMicro_arrayIsEmpty(eMicro array[], int len)
{
	int retorno = -1;
	int i;

	if(array != NULL && len > 0)
	{
		retorno = 1;

		for(i = 0; i < len; i++)
		{
			if(!array[i].isEmpty)
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int eMicro_obtenerIndiceVacio(eMicro array[], int len, int* indice)
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

int eMicro_encontrarPorId(eMicro array[], int len, int id, int* indice)
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

int eMicro_eliminar(eMicro array[], int len, int indice)
{
	int retorno = -1;

	if(array != NULL && len > 0 && indice >= 0 && indice < len && !array[indice].isEmpty)
	{
		array[indice].isEmpty = TRUE;

		retorno = 0;
	}

	return retorno;
}

int eMicro_elegirCriterioOrdenamiento(int* criterio)
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
        printf("B. Empresa\n");
        printf("C. Tipo\n");
        printf("D. Capacidad\n");

        if(!utn_getCaracter(&opcion, "\nElija una opcion: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'D', 2))
        {
            switch(opcion)
            {
                case 'A':

                    *criterio = ID;

                    break;

                case 'B':

                    *criterio = EMPRESA;

                    break;

                case 'C':

                    *criterio = TIPO;

                    break;

                case 'D':

                	*criterio = CAPACIDAD;

                	break;
            }

            retorno = 0;
        }
    }

    return retorno;
}

int eMicro_elegirSentidoOrdenamiento(int* order)
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

int eMicro_compararInt(int a, int b)
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

int eMicro_compararFloat(float a, float b)
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

int eMicro_compararChar(char a, char b)
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

int eMicro_compararString(char* a, char* b, int length)
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

int eMicro_swap(eMicro* a, eMicro* b)
{
	int retorno = -1;
	eMicro temp;

	if(a != NULL && b != NULL)
	{
		temp = *a;
		*a = *b;
		*b = temp;

		retorno = 0;
	}

	return retorno;
}

int eMicro_compararCriterio(eMicro* a, eMicro* b, int criterio)
{
	int retorno = -3;

	if(a != NULL && b != NULL && criterio >= 0)
	{
		switch(criterio)
		{
			case ID:

				retorno = eMicro_compararInt(a->idEmpresa, b->idEmpresa);

				break;

			case EMPRESA:

				retorno = eMicro_compararInt(a->idEmpresa, b->idEmpresa);

				break;

			case TIPO:

				retorno = eMicro_compararInt(a->idTipo, b->idTipo);

				break;

			case CAPACIDAD:

				retorno = eMicro_compararInt(a->capacidad, b->capacidad);

				break;
		}
	}

	return retorno;
}

int eMicro_ordenar(eMicro array[], int len, int criterio1, int criterio2, int order)
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
					auxCmp = eMicro_compararCriterio(&array[i], &array[i + 1], criterio1);

					if((auxCmp == order - !order || (!auxCmp && eMicro_compararCriterio(&array[i], &array[i + 1], criterio2) == order - !order)) &&
					   !eMicro_swap(&array[i], &array[i + 1]))
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
