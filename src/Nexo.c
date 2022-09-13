#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Nexo.h"


/** \brief Imprime las opciones del menú de ABM de Micros
 *
 * \param opcion int* Lugar donde se guardará la opción elegida por el usuario
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
static int mostrarMenu_ABM_eMicro(int* opcion);


/** \brief Imprime las opciones del menú de modificación de Micro
 *
 * \param opcion char* Lugar donde se guardará la opción elegida por el usuario
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
static int mostrarMenuModificacion_eMicro(char* opcion);


/** \brief Imprime las opciones del menú de ABM de Viajes
 *
 * \param opcion int* Lugar donde se guardará la opción elegida por el usuario
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
static int mostrarMenu_ABM_eViaje(int* opcion);


/** \brief Imprime las opciones del menú de modificación de Viaje
 *
 * \param opcion char* Lugar donde se guardará la opción elegida por el usuario
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
static int mostrarMenuModificacion_eViaje(char* opcion);


/** \brief Imprime las opciones del menú de Informes
 *
 * \param opcion int* Lugar donde se guardará la opción elegida por el usuario
 *
 * \return int -1 si hubo un error, 0 si está todo ok
 *
 */
static int mostrarMenuInformes(int* opcion);


int mostrarMenuPrincipal(int* opcion)
{
	int retorno = -1;

	if(opcion != NULL)
	{
		printf("\tMENU PRINCIPAL\n\n");

		printf("1 - ABM Micros\n");
		printf("2 - Listar Micros\n");
		printf("3 - Listar Empresas\n");
		printf("4 - Listar Tipos\n");
		printf("5 - Listar Destinos\n");
		printf("6 - ABM Viajes\n");
		printf("7 - Listar Viajes\n");
		printf("8 - Informes\n");
		printf("9 - Salir\n");

		if(!utn_getNumero(opcion, "\nElija una opcion: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 9, 2))
		{
			retorno = 0;
		}
	}

	return retorno;
}

static int mostrarMenu_ABM_eMicro(int* opcion)
{
	int retorno = -1;

	if(opcion != NULL)
	{
		printf("\tABM MICROS\n\n");

		printf("1 - Alta Micro\n");
		printf("2 - Modificacion Micro\n");
		printf("3 - Baja Micro\n");
		printf("4 - Salir\n");

		if(!utn_getNumero(opcion, "\nElija una opcion: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 4, 2))
		{
			retorno = 0;
		}
	}

	return retorno;
}

int ABM_eMicro(eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, int* idMicro)
{
	int retorno = -1;
	int opcion;
	int auxId;
	int indiceMicro;
	int indiceChofer;
	int indiceEmpresa;
	int indiceTipo;
	int flagExit = FALSE_MICRO;

	if(arrayMicros != NULL && lenMicros > 0 && arrayChoferes != NULL && lenChoferes > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0 && idMicro != NULL)
	{
		do
		{
			printf("\n");
			system("pause");
			system("cls");

			if(!mostrarMenu_ABM_eMicro(&opcion))
			{
				switch(opcion)
				{
					case 1:

						if(!eMicro_obtenerIndiceVacio(arrayMicros, lenMicros, &indiceMicro))
						{
							printf("\n");
							system("pause");
							system("cls");

							printf("\tALTA DE MICRO\n");

							if(!eMicro_cargarEnArray(arrayMicros, lenMicros, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos, arrayChoferes, lenChoferes, indiceMicro, idMicro))
							{
								printf("\nAlta de Micro realizada con exito\n");
							}

							else
							{
								printf("\nNo se pudo realizar el alta de Micro\n");
							}
						}

						else
						{
							printf("\nNo hay mas lugar disponible para el alta\n");
						}

						break;

					case 2:

						if(!eMicro_arrayIsEmpty(arrayMicros, lenMicros))
						{
							if(!eMicro_mostrarLista(arrayMicros, lenMicros, arrayChoferes, lenChoferes, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos) &&
							   !utn_getNumero(&auxId, "\nIngrese el ID de Micro a modificar: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 1000, 2) &&
							   !eMicro_encontrarPorId(arrayMicros, lenMicros, auxId, &indiceMicro) &&
							   !eChofer_encontrarPorId(arrayChoferes, lenChoferes, arrayMicros[indiceMicro].idChofer, &indiceChofer) &&
							   !eEmpresa_encontrarPorId(arrayEmpresas, lenEmpresas, arrayMicros[indiceMicro].idEmpresa, &indiceEmpresa) &&
							   !eTipo_encontrarPorId(arrayTipos, lenTipos, arrayMicros[indiceMicro].idTipo, &indiceTipo))
							{
								printf("\n");
								system("pause");
								system("cls");

								printf("\tMODIFICACION DE MICRO\n\n");

								printf("*----------*--------------------*--------------------*----------*--------------------*\n");
								printf("|%-10s|%-20s|%-20s|%-10s|%-20s|\n", "ID", "EMPRESA", "TIPO", "CAPACIDAD", "CHOFER");
								printf("*----------*--------------------*--------------------*----------*--------------------*\n");
								eMicro_mostrarUnMicro(&arrayMicros[indiceMicro], &arrayEmpresas[indiceEmpresa], &arrayTipos[indiceTipo], &arrayChoferes[indiceChofer]);
								printf("\n*----------*--------------------*--------------------*----------*--------------------*\n");

								if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar a este Micro? (S/N): ", "Error. Solo S o N: ") == 1 &&
								   !eMicro_modificar(arrayMicros, lenMicros, arrayTipos, lenTipos, indiceMicro))
								{
									printf("\nModificacion de Micro realizada con exito\n");
								}

								else
								{
									printf("\nNo se pudo realizar la modificacion de Micro\n");
								}
							}

							else
							{
								printf("\nError en la modificacion\n");
							}
						}

						else
						{
							printf("\nNo hay Micros para modificar\n");
						}

						break;

					case 3:

						if(!eMicro_arrayIsEmpty(arrayMicros, lenMicros))
						{
							if(!eMicro_mostrarLista(arrayMicros, lenMicros, arrayChoferes, lenChoferes, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos) &&
							   !utn_getNumero(&auxId, "\nIngrese el ID de Micro a eliminar: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 1000, 2) &&
							   !eMicro_encontrarPorId(arrayMicros, lenMicros, auxId, &indiceMicro) &&
							   !eChofer_encontrarPorId(arrayChoferes, lenChoferes, arrayMicros[indiceMicro].idChofer, &indiceChofer) &&
							   !eEmpresa_encontrarPorId(arrayEmpresas, lenEmpresas, arrayMicros[indiceMicro].idEmpresa, &indiceEmpresa) &&
							   !eTipo_encontrarPorId(arrayTipos, lenTipos, arrayMicros[indiceMicro].idTipo, &indiceTipo))
							{
								printf("\n");
								system("pause");
								system("cls");

								printf("\tBAJA DE MICRO\n\n");

								printf("*----------*--------------------*--------------------*----------*--------------------*\n");
								printf("|%-10s|%-20s|%-20s|%-10s|%-20s|\n", "ID", "EMPRESA", "TIPO", "CAPACIDAD", "CHOFER");
								printf("*----------*--------------------*--------------------*----------*--------------------*\n");
								eMicro_mostrarUnMicro(&arrayMicros[indiceMicro], &arrayEmpresas[indiceEmpresa], &arrayTipos[indiceTipo], &arrayChoferes[indiceChofer]);
								printf("\n*----------*--------------------*--------------------*----------*--------------------*\n");

								if(utn_respuestaEsAfirmativa("\nEsta seguro que desea eliminar a este Micro? (S/N): ", "Error. Solo S o N: ") == 1 &&
								   !eMicro_eliminar(arrayMicros, lenMicros, indiceMicro))
								{
									printf("\nBaja de Micro realizada con exito\n");
								}

								else
								{
									printf("\nNo se pudo realizar la baja de Micro\n");
								}
							}

							else
							{
								printf("\nError en la baja\n");
							}
						}

						else
						{
							printf("\nNo hay Micros para eliminar\n");
						}

						break;

					case 4:

						if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
						{
							printf("\nHa salido del menu de ABM Micros\n");

							flagExit = TRUE_MICRO;
						}

						break;
				}
			}

		} while(opcion != 4 || !flagExit);

		retorno = 0;
	}

	return retorno;
}

int eMicro_cargarUnMicro(eMicro* unMicro, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eChofer arrayChoferes[], int lenChoferes, int* idMicro)
{
	int retorno = -1;
	int indiceEmpresa;
	int indiceTipo;
	int indiceChofer;

	eMicro aux;

	if(unMicro != NULL && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0 && arrayChoferes != NULL && lenChoferes > 0 && idMicro != NULL &&
	   !eEmpresa_mostrarLista(arrayEmpresas, lenEmpresas) &&
	   !utn_getNumero(&aux.idEmpresa, "\nIngrese ID de Empresa: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1000, 2000, 2) &&
	   !eEmpresa_encontrarPorId(arrayEmpresas, lenEmpresas, aux.idEmpresa, &indiceEmpresa) &&
	   !eTipo_mostrarLista(arrayTipos, lenTipos) &&
	   !utn_getNumero(&aux.idTipo, "\nIngrese ID de Tipo: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 5000, 6000, 2) &&
	   !eTipo_encontrarPorId(arrayTipos, lenTipos, aux.idTipo, &indiceTipo) &&
	   !utn_getNumero(&aux.capacidad, "\nIngrese capacidad entre 1 y 50: ", "Error. Ingrese solo numeros enteros entre 1 y 50: ", 1, 50, 2) &&
	   !eChofer_mostrarLista(arrayChoferes, lenChoferes) &&
	   !utn_getNumero(&aux.idChofer, "\nIngrese ID de Chofer: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 4, 2) &&
	   !eChofer_encontrarPorId(arrayChoferes, lenChoferes, aux.idChofer, &indiceChofer))
	{
		aux.id = *idMicro;
		aux.isEmpty = FALSE_MICRO;

		*unMicro = aux;

		(*idMicro)++;

		retorno = 0;
	}

	return retorno;
}

int eMicro_cargarEnArray(eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eChofer arrayChoferes[], int lenChoferes, int indiceMicro, int* idMicro)
{
	int retorno = -1;

	if(arrayMicros != NULL && lenMicros > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0 && arrayChoferes != NULL && lenChoferes > 0 &&
	   indiceMicro >= 0 && indiceMicro < lenMicros && idMicro != NULL && arrayMicros[indiceMicro].isEmpty &&
	   !eMicro_cargarUnMicro(&arrayMicros[indiceMicro], arrayEmpresas, lenEmpresas, arrayTipos, lenTipos, arrayChoferes, lenChoferes, idMicro))
	{
		retorno = 0;
	}

	return retorno;
}

static int mostrarMenuModificacion_eMicro(char* opcion)
{
	int retorno = -1;

	if(opcion != NULL)
	{
		printf("\tMENU DE MODIFICACION DE MICROS\n\n");
		printf("A- Tipo\n");
		printf("B- Capacidad\n");
		printf("C- Salir\n");

		if(!utn_getCaracter(opcion, "\nQue desea modificar?: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'C', 2))
		{
			retorno = 0;
		}
	}

	return retorno;
}

int eMicro_modificar(eMicro arrayMicros[], int lenMicros, eTipo arrayTipos[], int lenTipos, int indiceMicro)
{
	int retorno = -1;
	char opcion;
	int auxIndice;
	int flagMod = FALSE_MICRO;
	int flagExit = FALSE_MICRO;

	int auxIdTipo;
	int auxCapacidad;

	if(arrayMicros != NULL && lenMicros > 0 && arrayTipos != NULL && lenTipos > 0 &&
	   indiceMicro >= 0 && indiceMicro < lenMicros && !arrayMicros[indiceMicro].isEmpty)
	{
		do
		{
			printf("\n");
			system("pause");
			system("cls");

			if(!mostrarMenuModificacion_eMicro(&opcion))
			{
				switch(opcion)
				{
					case 'A':

						if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el Tipo? (S/N): ", "Error. Solo S o N: ") == 1 &&
						   !eTipo_mostrarLista(arrayTipos, lenTipos) &&
						   !utn_getNumero(&auxIdTipo, "\nIngrese nuevo ID de Tipo: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 5000, 6000, 2) &&
						   !eTipo_encontrarPorId(arrayTipos, lenTipos, auxIdTipo, &auxIndice))
						{
							arrayMicros[indiceMicro].idTipo = auxIdTipo;

							flagMod = TRUE_MICRO;
						}

						break;

					case 'B':

						if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar la capacidad? (S/N): ", "Error. Solo S o N: ") == 1 &&
						   !utn_getNumero(&auxCapacidad, "\nIngrese nueva capacidad entre 1 y 50: ", "Error. Ingrese solo numeros enteros entre 1 y 50: ", 1, 50, 2))
						{
							arrayMicros[indiceMicro].capacidad = auxCapacidad;

							flagMod = TRUE_MICRO;
						}

						break;

					case 'C':

						if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
						{
							printf("\nHa salido del menu de modificacion\n");

							flagExit = TRUE_MICRO;
						}

						break;
				}
			}

		} while(opcion != 'C' || !flagExit);

		if(flagMod)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int eMicro_mostrarUnMicro(eMicro* unMicro, eEmpresa* unaEmpresa, eTipo* unTipo, eChofer* unChofer)
{
	int retorno = -1;

	if(unMicro != NULL && unaEmpresa != NULL && unTipo != NULL && unChofer != NULL)
	{
		printf("|%-10d|%-20s|%-20s|%-10d|%-20s|", unMicro->id, unaEmpresa->descripcion, unTipo->descripcion,
												  unMicro->capacidad, unChofer->nombre);

		retorno = 0;
	}

	return retorno;
}

int eMicro_mostrarLista(eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos)
{
	int retorno = -1;
	int indiceChofer;
	int indiceEmpresa;
	int indiceTipo;
	int i;

	if(arrayMicros != NULL && lenMicros > 0 && arrayChoferes != NULL && lenChoferes > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0)
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tLISTA DE MICROS\n\n");
		printf("*----------*--------------------*--------------------*----------*--------------------*\n");
		printf("|%-10s|%-20s|%-20s|%-10s|%-20s|\n", "ID", "EMPRESA", "TIPO", "CAPACIDAD", "CHOFER");
		printf("*----------*--------------------*--------------------*----------*--------------------*\n");

		for(i = 0; i < lenMicros; i++)
		{
			if(!arrayMicros[i].isEmpty &&
			   !eChofer_encontrarPorId(arrayChoferes, lenChoferes, arrayMicros[i].idChofer, &indiceChofer) &&
			   !eEmpresa_encontrarPorId(arrayEmpresas, lenEmpresas, arrayMicros[i].idEmpresa, &indiceEmpresa) &&
			   !eTipo_encontrarPorId(arrayTipos, lenTipos, arrayMicros[i].idTipo, &indiceTipo))
			{
				if(!eMicro_mostrarUnMicro(&arrayMicros[i], &arrayEmpresas[indiceEmpresa], &arrayTipos[indiceTipo], &arrayChoferes[indiceChofer]))
				{
					printf("\n");
				}

				else
				{
					break;
				}
			}
		}

		printf("*----------*--------------------*--------------------*----------*--------------------*\n");

		if(i == lenMicros)
		{
			retorno = 0;
		}
	}

	return retorno;
}

static int mostrarMenu_ABM_eViaje(int* opcion)
{
	int retorno = -1;

	if(opcion != NULL)
	{
		printf("\tABM VIAJES\n\n");

		printf("1 - Alta Viaje\n");
		printf("2 - Modificacion Viaje\n");
		printf("3 - Baja Viaje\n");
		printf("4 - Salir\n");

		if(!utn_getNumero(opcion, "\nElija una opcion: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 4, 2))
		{
			retorno = 0;
		}
	}

	return retorno;
}

int ABM_eViaje(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos, int* idViaje)
{
	int retorno = -1;
	int opcion;
	int auxId;
	int indiceViaje;
	int indiceMicro;
	int indiceEmpresa;
	int indiceTipo;
	int indiceDest;
	int flagExit = FALSE_VIAJE;

	if(arrayViajes != NULL && lenViajes > 0 && arrayMicros != NULL && lenMicros > 0 && arrayChoferes != NULL && lenChoferes > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0 && arrayDestinos != NULL && lenDestinos > 0 && idViaje != NULL)
	{
		do
		{
			printf("\n");
			system("pause");
			system("cls");

			if(!mostrarMenu_ABM_eViaje(&opcion))
			{
				switch(opcion)
				{
					case 1:

						if(!eViaje_obtenerIndiceVacio(arrayViajes, lenViajes, &indiceViaje))
						{
							printf("\n");
							system("pause");
							system("cls");

							printf("\tALTA DE VIAJE\n");

							if(!eViaje_cargarEnArray(arrayViajes, lenViajes, arrayMicros, lenMicros, arrayChoferes, lenChoferes, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos, arrayDestinos, lenDestinos, indiceViaje, idViaje))
							{
								printf("\nAlta de Viaje realizada con exito\n");
							}

							else
							{
								printf("\nNo se pudo realizar el alta de Viaje\n");
							}
						}

						else
						{
							printf("\nNo hay mas lugar disponible para el alta\n");
						}

						break;

					case 2:

						if(!eViaje_arrayIsEmpty(arrayViajes, lenViajes))
						{
							if(!eViaje_mostrarLista(arrayViajes, lenViajes, arrayMicros, lenMicros, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos, arrayDestinos, lenDestinos) &&
							   !utn_getNumero(&auxId, "\nIngrese el ID de Viaje a modificar: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 1000, 2) &&
							   !eViaje_encontrarPorId(arrayViajes, lenViajes, auxId, &indiceViaje) &&
							   !eMicro_encontrarPorId(arrayMicros, lenMicros, arrayViajes[indiceViaje].idMicro, &indiceMicro) &&
							   !eEmpresa_encontrarPorId(arrayEmpresas, lenEmpresas, arrayMicros[indiceMicro].idEmpresa, &indiceEmpresa) &&
							   !eTipo_encontrarPorId(arrayTipos, lenTipos, arrayMicros[indiceMicro].idTipo, &indiceTipo) &&
							   !eDestino_encontrarPorId(arrayDestinos, lenDestinos, arrayViajes[indiceViaje].idDestino, &indiceDest))
							{
								printf("\n");
								system("pause");
								system("cls");

								printf("\tMODIFICACION DE VIAJE\n\n");

								printf("*----------*----------------------------------------------------*--------------------*----------*\n");
								printf("|%-10s|%-52s|%-20s|%-10s|\n", "ID", "MICRO", "DESTINO", "FECHA");
								printf("|%-10c|----------------------------------------------------|%-20c|%-10c|\n", ' ', ' ', ' ');
								printf("|%-10c|%-20s|%-20s|%-10s|%-20c|%-10c|\n", ' ', "EMPRESA", "TIPO", "CAPACIDAD", ' ', ' ');
								printf("*----------*--------------------*--------------------*----------*--------------------*----------*\n");
								eViaje_mostrarUnViaje(&arrayViajes[indiceViaje], &arrayMicros[indiceMicro], &arrayEmpresas[indiceEmpresa], &arrayTipos[indiceTipo], &arrayDestinos[indiceDest]);
								printf("*----------*--------------------*--------------------*----------*--------------------*----------*\n");

								if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar a este Viaje? (S/N): ", "\nError. Solo S o N: ") == 1 &&
								   !eViaje_modificar(arrayViajes, lenViajes, arrayMicros, lenMicros, arrayChoferes, lenChoferes, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos, arrayDestinos, lenDestinos, indiceViaje))
								{
									printf("\nModificacion de Viaje realizada con exito\n");
								}

								else
								{
									printf("\nNo se pudo realizar la modificacion de Viaje\n");
								}
							}

							else
							{
								printf("\nError en la modificacion\n");
							}
						}

						else
						{
							printf("\nNo hay Viajes para modificar\n");
						}

						break;

					case 3:

						if(!eViaje_arrayIsEmpty(arrayViajes, lenViajes))
						{
							if(!eViaje_mostrarLista(arrayViajes, lenViajes, arrayMicros, lenMicros, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos, arrayDestinos, lenDestinos) &&
							   !utn_getNumero(&auxId, "\nIngrese el ID de Viaje a eliminar: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 1000, 2) &&
							   !eViaje_encontrarPorId(arrayViajes, lenViajes, auxId, &indiceViaje) &&
							   !eMicro_encontrarPorId(arrayMicros, lenMicros, arrayViajes[indiceViaje].idMicro, &indiceMicro) &&
							   !eEmpresa_encontrarPorId(arrayEmpresas, lenEmpresas, arrayMicros[indiceMicro].idEmpresa, &indiceEmpresa) &&
							   !eTipo_encontrarPorId(arrayTipos, lenTipos, arrayMicros[indiceMicro].idTipo, &indiceTipo) &&
							   !eDestino_encontrarPorId(arrayDestinos, lenDestinos, arrayViajes[indiceViaje].idDestino, &indiceDest))
							{
								printf("\n");
								system("pause");
								system("cls");

								printf("\tBAJA DE VIAJE\n\n");

								printf("*----------*----------------------------------------------------*--------------------*----------*\n");
								printf("|%-10s|%-52s|%-20s|%-10s|\n", "ID", "MICRO", "DESTINO", "FECHA");
								printf("|%-10c|----------------------------------------------------|%-20c|%-10c|\n", ' ', ' ', ' ');
								printf("|%-10c|%-20s|%-20s|%-10s|%-20c|%-10c|\n", ' ', "EMPRESA", "TIPO", "CAPACIDAD", ' ', ' ');
								printf("*----------*--------------------*--------------------*----------*--------------------*----------*\n");
								eViaje_mostrarUnViaje(&arrayViajes[indiceViaje], &arrayMicros[indiceMicro], &arrayEmpresas[indiceEmpresa], &arrayTipos[indiceTipo], &arrayDestinos[indiceDest]);
								printf("*----------*--------------------*--------------------*----------*--------------------*----------*\n");

								if(utn_respuestaEsAfirmativa("\nEsta seguro que desea eliminar a este Viaje? (S/N): ", "\nError. Solo S o N: ") == 1 &&
								   !eViaje_eliminar(arrayViajes, lenViajes, indiceViaje))
								{
									printf("\nBaja de Viaje realizada con exito\n");
								}

								else
								{
									printf("\nNo se pudo realizar la baja de Viaje\n");
								}
							}

							else
							{
								printf("\nError en la baja\n");
							}
						}

						else
						{
							printf("\nNo hay Viajes para eliminar\n");
						}

						break;

					case 4:

						if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
						{
							printf("\nHa salido del menu de ABM Viajes\n");

							flagExit = TRUE_VIAJE;
						}

						break;
				}
			}

		} while(opcion != 4 || !flagExit);

		retorno = 0;
	}

	return retorno;
}

int eViaje_cargarUnViaje(eViaje* unViaje, eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestino, int* idViaje)
{
	int retorno = -1;
	int indiceMicro;
	int indiceDest;
	eViaje aux;

	if(unViaje != NULL && arrayMicros != NULL && lenMicros > 0 && arrayChoferes != NULL && lenChoferes > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0 && arrayDestinos != NULL && lenDestino > 0 && idViaje != NULL &&
	   !eMicro_mostrarLista(arrayMicros, lenMicros, arrayChoferes, lenChoferes, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos) &&
	   !utn_getNumero(&aux.idMicro, "\nIngrese ID de Micro: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 1000, 2) &&
	   !eMicro_encontrarPorId(arrayMicros, lenMicros, aux.idMicro, &indiceMicro) &&
	   !eDestino_mostrarLista(arrayDestinos, lenDestino) &&
	   !utn_getNumero(&aux.idDestino, "\nIngrese ID de Destino: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 20000, 30000, 2) &&
	   !eDestino_encontrarPorId(arrayDestinos, lenDestino, aux.idDestino, &indiceDest) &&
	   !eFecha_cargar(&aux.fecha))
	{
		aux.id = *idViaje;
		aux.isEmpty = FALSE_VIAJE;

		*unViaje = aux;

		(*idViaje)++;

		retorno = 0;
	}

	return retorno;
}

int eViaje_cargarEnArray(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestino, int indiceViaje, int* idViaje)
{
	int retorno = -1;

	if(arrayViajes != NULL && lenViajes > 0 && arrayMicros != NULL && lenMicros > 0 && arrayChoferes != NULL && lenChoferes > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0 &&
	   arrayDestinos != NULL && lenDestino > 0 && indiceViaje >= 0 && indiceViaje < lenViajes && idViaje != NULL && arrayViajes[indiceViaje].isEmpty &&
	   !eViaje_cargarUnViaje(&arrayViajes[indiceViaje], arrayMicros, lenMicros, arrayChoferes, lenChoferes, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos, arrayDestinos, lenDestino, idViaje))
	{
		retorno = 0;
	}

	return retorno;
}

static int mostrarMenuModificacion_eViaje(char* opcion)
{
	int retorno = -1;

	if(opcion != NULL)
	{
		printf("\tMENU DE MODIFICACION DE VIAJE\n\n");
		printf("A- ID Micro\n");
		printf("B- Destino\n");
		printf("C- Fecha\n");
		printf("D- Regresar\n");

		if(!utn_getCaracter(opcion, "\nQue desea modificar?: ", "Error. Ingrese un solo caracter dentro del rango: ", 'A', 'D', 2))
		{
			retorno = 0;
		}
	}

	return retorno;
}

int eViaje_modificar(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos, int indiceViaje)
{
	int retorno = -1;
	char opcion;
	int flagMod = FALSE_VIAJE;
	int flagExit = FALSE_VIAJE;

	eViaje aux;

	if(arrayViajes != NULL && lenViajes > 0 && arrayMicros != NULL && lenMicros > 0 && arrayChoferes != NULL && lenChoferes > 0 && arrayEmpresas != NULL && lenEmpresas > 0 &&
	   arrayTipos != NULL && lenTipos > 0 && arrayDestinos != NULL && lenDestinos > 0 && indiceViaje >= 0 && indiceViaje < lenViajes && !arrayViajes[indiceViaje].isEmpty)
	{
		do
		{
			printf("\n");
			system("pause");
			system("cls");

			if(!mostrarMenuModificacion_eViaje(&opcion))
			{
				switch(opcion)
				{
					case 'A':

						if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el ID de Micro? (S/N): ", "Error. Solo S o N: ") == 1 &&
						   !eMicro_mostrarLista(arrayMicros, lenMicros, arrayChoferes, lenChoferes, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos) &&
						   !utn_getNumero(&aux.idMicro, "\nIngrese nuevo ID de Micro: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 1000, 2))
						{
							arrayViajes[indiceViaje].idMicro = aux.idMicro;

							flagMod = TRUE_VIAJE;
						}

						break;

					case 'B':

						if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar el Destino? (S/N): ", "Error. Solo S o N: ") == 1 &&
						   !eDestino_mostrarLista(arrayDestinos, lenDestinos) &&
						   !utn_getNumero(&aux.idDestino, "\nIngrese nuevo ID de Destino: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 20000, 30000, 2))
						{
							arrayViajes[indiceViaje].idDestino = aux.idDestino;

							flagMod = TRUE_VIAJE;
						}

						break;

					case 'C':

						if(utn_respuestaEsAfirmativa("\nEsta seguro que desea modificar la fecha? (S/N): ", "Error. Solo S o N: ") == 1 &&
						   !eFecha_cargar(&aux.fecha))
						{
							arrayViajes[indiceViaje].fecha = aux.fecha;

							flagMod = TRUE_VIAJE;
						}

						break;

					case 'D':

						if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
						{
							printf("\nHa salido del menu de modificacion\n");

							flagExit = TRUE_VIAJE;
						}

						break;
				}
			}

		} while(opcion != 'D' || !flagExit);

		if(flagMod)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int eViaje_mostrarUnViaje(eViaje* unViaje, eMicro* unMicro, eEmpresa* unaEmpresa, eTipo* unTipo, eDestino* unDestino)
{
	int retorno = -1;

	if(unViaje != NULL && unMicro != NULL && unaEmpresa != NULL && unTipo != NULL && unDestino != NULL)
	{
		printf("|%-10d|%-20s|%-20s|%-10d|%-20s|", unViaje->id, unaEmpresa->descripcion, unTipo->descripcion, unMicro->capacidad, unDestino->descripcion);
		eFecha_mostrar(&unViaje->fecha);
		printf("|\n");

		retorno = 0;
	}

	return retorno;
}

int eViaje_mostrarLista(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos)
{
	int retorno = -1;
	int indiceMicro;
	int indiceEmpresa;
	int indiceTipo;
	int indiceDest;
	int i;

	if(arrayViajes != NULL && lenViajes > 0 && arrayMicros != NULL && lenMicros > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0 && arrayDestinos != NULL && lenDestinos > 0)
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tLISTA DE VIAJES\n\n");

		printf("*----------*----------------------------------------------------*--------------------*----------*\n");
		printf("|%-10s|%-52s|%-20s|%-10s|\n", "ID", "MICRO", "DESTINO", "FECHA");
		printf("|%-10c|----------------------------------------------------|%-20c|%-10c|\n", ' ', ' ', ' ');
		printf("|%-10c|%-20s|%-20s|%-10s|%-20c|%-10c|\n", ' ', "EMPRESA", "TIPO", "CAPACIDAD", ' ', ' ');
		printf("*----------*--------------------*--------------------*----------*--------------------*----------*\n");

		for(i = 0; i < lenViajes; i++)
		{
			if(!arrayViajes[i].isEmpty && !eMicro_encontrarPorId(arrayMicros, lenMicros, arrayViajes[i].idMicro, &indiceMicro) &&
			   !eEmpresa_encontrarPorId(arrayEmpresas, lenEmpresas, arrayMicros[indiceMicro].idEmpresa, &indiceEmpresa) &&
			   !eTipo_encontrarPorId(arrayTipos, lenTipos, arrayMicros[indiceMicro].idTipo, &indiceTipo) &&
			   !eDestino_encontrarPorId(arrayDestinos, lenDestinos, arrayViajes[i].idDestino, &indiceDest) &&
			   eViaje_mostrarUnViaje(&arrayViajes[i], &arrayMicros[indiceMicro], &arrayEmpresas[indiceEmpresa], &arrayTipos[indiceTipo], &arrayDestinos[indiceDest]))
			{
				break;
			}
		}

		printf("*----------*--------------------*--------------------*----------*--------------------*----------*\n");

		if(i == lenViajes)
		{
			retorno = 0;
		}
	}

	return retorno;
}

static int mostrarMenuInformes(int* opcion)
{
	int retorno = -1;

	if(opcion != NULL)
	{
		printf("\tINFORMES\n\n");

		printf("1 - Mostrar micros de una empresa\n");
		printf("2 - Mostrar micros de un tipo\n");
		printf("3 - Informar Promedio de micros de tipo Vip sobre el total de micros de una empresa\n");
		printf("4 - Mostrar listado de los micros separados por empresa\n");
		printf("5 - Informar la o las empresas que pueden transportar mas pasajeros\n");
		printf("6 - Mostrar la o las empresas con menor cantidad de micros\n");
		printf("7 - Mostrar todos los viajes que hizo un micro\n");
		printf("8 - Informar la suma de los precios de todos los viajes que realizo un micro\n");
		printf("9 - Mostrar los micros que viajaron a un destino y en que fecha\n");
		printf("10 - Mostrar todos los viajes realizados en una fecha\n");
		printf("11 - Salir\n");

		if(!utn_getNumero(opcion, "\nElija una opcion: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 11, 2))
		{
			retorno = 0;
		}
	}

	return retorno;
}

int realizarInformes(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos)
{
	int retorno = -1;
	int opcion;
	int auxId;
	eFecha auxFecha;
	int indiceViaje;
	int indiceMicro;
	int indiceEmpresa;
	int indiceTipo;
	int indiceDest;
	float suma;
	int flagExit = 0;

	if(arrayViajes != NULL && lenViajes > 0 && arrayMicros != NULL && lenMicros > 0 && arrayChoferes != NULL && lenChoferes > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0 && arrayDestinos != NULL && lenDestinos > 0)
	{
		do
		{
			printf("\n");
			system("pause");
			system("cls");

			if(!mostrarMenuInformes(&opcion))
			{
				switch(opcion)
				{
					case 1:

						if(!eEmpresa_mostrarLista(arrayEmpresas, lenEmpresas) &&
						   !utn_getNumero(&auxId, "\nIngrese ID de Empresa: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1000, 2000, 2) &&
						   !eEmpresa_encontrarPorId(arrayEmpresas, lenEmpresas, auxId, &indiceEmpresa) &&
						   !mostrarMicrosXEmpresa(arrayMicros, lenMicros, arrayChoferes, lenChoferes, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos, indiceEmpresa))
						{
							printf("\nMuestra realizada correctamente\n");
						}

						else
						{
							printf("\nError en la muestra\n");
						}

						break;

					case 2:

						if(!eTipo_mostrarLista(arrayTipos, lenTipos) &&
						   !utn_getNumero(&auxId, "\nIngrese ID de Tipo: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 5000, 6000, 2) &&
						   !eTipo_encontrarPorId(arrayTipos, lenTipos, auxId, &indiceTipo) &&
						   !mostrarMicrosXTipo(arrayMicros, lenMicros, arrayChoferes, lenChoferes, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos, indiceTipo))
						{
							printf("\nMuestra realizada correctamente\n");
						}

						else
						{
							printf("\nError en la muestra\n");
						}

						break;

					case 3:

						if(!eEmpresa_mostrarLista(arrayEmpresas, lenEmpresas) &&
						   !utn_getNumero(&auxId, "\nIngrese ID de Empresa: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1000, 2000, 2) &&
						   !eEmpresa_encontrarPorId(arrayEmpresas, lenEmpresas, auxId, &indiceEmpresa) &&
						   !eTipo_encontrarPorId(arrayTipos, lenTipos, 5003, &indiceTipo) &&
						   !informarPromedioMicrosEmpresa(arrayMicros, lenMicros, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos, indiceEmpresa, indiceTipo))
						{
							printf("\nMuestra realizada correctamente\n");
						}

						else
						{
							printf("\nError en la muestra\n");
						}

						break;

					case 4:

						if(!mostrarMicrosDeEmpresas(arrayMicros, lenMicros, arrayChoferes, lenChoferes, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos))
						{
							printf("\nMuestra realizada correctamente\n");
						}

						else
						{
							printf("\nError en la muestra\n");
						}

						break;

					case 5:

						if(!mostrarEmpresaConMasPasajeros(arrayMicros, lenMicros, arrayEmpresas, lenEmpresas))
						{
							printf("\nMuestra realizada correctamente\n");
						}

						else
						{
							printf("\nError en la muestra\n");
						}

						break;

					case 6:

						if(!mostrarEmpresaConMenosMicros(arrayMicros, lenMicros, arrayEmpresas, lenEmpresas))
						{
							printf("\nMuestra realizada correctamente\n");
						}

						else
						{
							printf("\nError en la muestra\n");
						}

						break;

					case 7:

						if(!eMicro_mostrarLista(arrayMicros, lenMicros, arrayChoferes, lenChoferes, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos) &&
						   !utn_getNumero(&auxId, "\nIngrese ID de Micro: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 1000, 2) &&
						   !eMicro_encontrarPorId(arrayMicros, lenMicros, auxId, &indiceMicro) &&
						   !mostrarViajesXMicro(arrayViajes, lenViajes, arrayMicros, lenMicros, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos, arrayDestinos, lenDestinos, indiceMicro))
						{
							printf("\nMuestra realizada correctamente\n");
						}

						else
						{
							printf("\nError en la muestra\n");
						}

						break;

					case 8:

						if(!eMicro_mostrarLista(arrayMicros, lenMicros, arrayChoferes, lenChoferes, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos) &&
						   !utn_getNumero(&auxId, "\nIngrese ID de Micro: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 1, 1000, 2) &&
						   !eMicro_encontrarPorId(arrayMicros, lenMicros, auxId, &indiceMicro) &&
						   !calcularSumaPrecios(arrayViajes, lenViajes, arrayMicros, lenMicros, arrayDestinos, lenDestinos, indiceMicro, &suma))
						{
							printf("\nLa suma de los precios de todos los viajes que realizo es: $%.2f\n", suma);
						}

						else
						{
							printf("\nError en la muestra\n");
						}

						break;

					case 9:

						if(!eDestino_mostrarLista(arrayDestinos, lenDestinos) &&
						   !utn_getNumero(&auxId, "\nIngrese ID de Destino: ", "Error. Ingrese solo numeros enteros dentro del rango: ", 20000, 30000, 2) &&
						   !eDestino_encontrarPorId(arrayDestinos, lenDestinos, auxId, &indiceDest) &&
						   !mostrarMicrosXDestino(arrayViajes, lenViajes, arrayMicros, lenMicros, arrayChoferes, lenChoferes, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos, arrayDestinos, lenDestinos, indiceDest))
						{
							printf("\nMuestra realizada correctamente\n");
						}

						else
						{
							printf("\nError en la muestra\n");
						}

						break;

					case 10:

						if(!eFecha_cargar(&auxFecha) && !eViaje_encontrarFecha(arrayViajes, lenViajes, &auxFecha, &indiceViaje) &&
						   !mostrarViajesXFecha(arrayViajes, lenViajes, arrayMicros, lenMicros, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos, arrayDestinos, lenDestinos, indiceViaje))
						{
							printf("\nMuestra realizada correctamente\n");
						}

						else
						{
							printf("\nError en la muestra\n");
						}

						break;

					case 11:

						if(utn_respuestaEsAfirmativa("\nEsta seguro que desea salir del menu? (S/N): ", "Error. Solo S o N: ") == 1)
						{
							printf("\nHa salido del menu de Informes\n");

							flagExit = 1;
						}

						break;
				}
			}

		} while(opcion != 11 || !flagExit);

		retorno = 0;
	}

	return retorno;
}

int mostrarMicrosDeEmpresas(eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos)
{
	int retorno = -1;
	int i;

	if(arrayMicros != NULL && lenMicros > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0)
	{
		for(i = 0; i < lenEmpresas; i++)
		{
			mostrarMicrosXEmpresa(arrayMicros, lenMicros, arrayChoferes, lenChoferes, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos, i);
		}

		retorno = 0;
	}

	return retorno;
}

int mostrarMicrosXEmpresa(eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, int indiceEmpresa)
{
	int retorno = -1;
	int flag = 0;
	int indiceChofer;
	int indiceTipo;
	int i;

	if(arrayMicros != NULL && lenMicros > 0 && arrayChoferes != NULL && lenChoferes > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0 && indiceEmpresa >= 0 && indiceEmpresa < lenEmpresas)
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tLISTA DE MICROS POR EMPRESA\n");

		printf("\n\n\tMicros de Empresa: %s\n\n", arrayEmpresas[indiceEmpresa].descripcion);

		printf("*----------*--------------------*--------------------*----------*--------------------*\n");
		printf("|%-10s|%-20s|%-20s|%-10s|%-20s|\n", "ID", "EMPRESA", "TIPO", "CAPACIDAD", "CHOFER");
		printf("*----------*--------------------*--------------------*----------*--------------------*\n");

		for(i = 0; i < lenMicros; i++)
		{
			if(!arrayMicros[i].isEmpty && arrayMicros[i].idEmpresa == arrayEmpresas[indiceEmpresa].id &&
			   !eTipo_encontrarPorId(arrayTipos, lenTipos, arrayMicros[i].idTipo, &indiceTipo) &&
			   !eChofer_encontrarPorId(arrayChoferes, lenChoferes, arrayMicros[i].idChofer, &indiceChofer))
			{
				eMicro_mostrarUnMicro(&arrayMicros[i], &arrayEmpresas[indiceEmpresa], &arrayTipos[indiceTipo], &arrayChoferes[indiceChofer]);
				printf("\n");
				flag = 1;
			}
		}

		if(flag)
		{
			printf("*----------*--------------------*--------------------*----------*--------------------*\n");
		}

		else
		{
			printf("\n\nNo hay micros en esta empresa\n\n");
		}

		retorno = 0;
	}

	return retorno;
}

int mostrarMicrosDeTipos(eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos)
{
	int retorno = -1;
	int i;

	if(arrayMicros != NULL && lenMicros > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0)
	{
		for(i = 0; i < lenTipos; i++)
		{
			mostrarMicrosXTipo(arrayMicros, lenMicros, arrayChoferes, lenChoferes, arrayEmpresas, lenEmpresas, arrayTipos, lenTipos, i);
		}

		retorno = 0;
	}

	return retorno;
}

int mostrarMicrosXTipo(eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, int indiceTipo)
{
	int retorno = -1;
	int flag = 0;
	int indiceChofer;
	int indiceEmpresa;
	int i;

	if(arrayMicros != NULL && lenMicros > 0 && arrayChoferes != NULL && lenChoferes > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0 && indiceTipo >= 0 && indiceTipo < lenTipos)
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tLISTA DE MICROS POR TIPO\n");

		printf("\n\n\tMicros de Tipo: %s\n\n", arrayTipos[indiceTipo].descripcion);

		printf("*----------*--------------------*--------------------*----------*--------------------*\n");
		printf("|%-10s|%-20s|%-20s|%-10s|%-20s|\n", "ID", "EMPRESA", "TIPO", "CAPACIDAD", "CHOFER");
		printf("*----------*--------------------*--------------------*----------*--------------------*\n");

		for(i = 0; i < lenMicros; i++)
		{
			if(!arrayMicros[i].isEmpty && arrayMicros[i].idTipo == arrayTipos[indiceTipo].id &&
			   !eEmpresa_encontrarPorId(arrayEmpresas, lenEmpresas, arrayMicros[i].idEmpresa, &indiceEmpresa) &&
			   !eChofer_encontrarPorId(arrayChoferes, lenChoferes, arrayMicros[i].idChofer, &indiceChofer))
			{
				eMicro_mostrarUnMicro(&arrayMicros[i], &arrayEmpresas[indiceEmpresa], &arrayTipos[indiceTipo], &arrayChoferes[indiceChofer]);
				printf("\n");
				flag = 1;
			}
		}

		if(flag)
		{
			printf("*----------*--------------------*--------------------*----------*--------------------*\n");
		}

		else
		{
			printf("\n\nNo hay micros en esta empresa\n\n");
		}

		retorno = 0;
	}

	return retorno;
}

int contarCantPasajerosDeEmpresas(eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas, int contEmpresas[])
{
	int retorno = -1;
	int i;

	if(arrayMicros != NULL && lenMicros > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && contEmpresas != NULL)
	{
		for(i = 0; i < lenEmpresas; i++)
		{
			contarCantPasajerosXEmpresa(arrayMicros, lenMicros, arrayEmpresas[i].id, &contEmpresas[i]);
		}

		retorno = 0;
	}

	return retorno;
}

int contarCantPasajerosXEmpresa(eMicro arrayMicros[], int lenMicros, int idEmpresa, int* cont)
{
	int retorno = -1;
	int i;

	if(arrayMicros != NULL && lenMicros > 0 && idEmpresa > 0 && cont != NULL)
	{
		for(i = 0; i < lenMicros; i++)
		{
			if(arrayMicros[i].idEmpresa == idEmpresa)
			{
				*cont += arrayMicros[i].capacidad;
			}
		}

		retorno = 0;
	}

	return retorno;
}

int calcularMaximoDePasajerosDeEmpresas(int contEmpresas[], int lenEmpresas, int* maximo)
{
	int retorno = -1;
	int i;

	if(contEmpresas != NULL && lenEmpresas > 0 && maximo != NULL)
	{
		for(i = 0; i < lenEmpresas; i++)
		{
			if(i == 0 || contEmpresas[i] > *maximo)
			{
				*maximo = contEmpresas[i];
			}
		}

		retorno = 0;
	}

	return retorno;
}

int mostrarEmpresaConMasPasajeros(eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas)
{
	int retorno = -1;
	int contEmpresas[] = {0, 0, 0, 0};
	int maximo;
	int i;

	if(arrayMicros != NULL && lenMicros > 0 && arrayEmpresas != NULL && lenEmpresas > 0 &&
	   !contarCantPasajerosDeEmpresas(arrayMicros, lenMicros, arrayEmpresas, lenEmpresas, contEmpresas) &&
	   !calcularMaximoDePasajerosDeEmpresas(contEmpresas, lenEmpresas, &maximo))
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tEMPRESAS CON MAS PASAJEROS\n\n");

		printf("*----------*--------------------*\n");
		printf("|%-10s|%-20s|\n", "ID", "DESCRIPCION");
		printf("*----------*--------------------*\n");

		for(i = 0; i < lenEmpresas; i++)
		{
			if(contEmpresas[i] == maximo)
			{
				eEmpresa_mostrarUnaEmpresa(&arrayEmpresas[i]);
			}
		}

		printf("*----------*--------------------*\n");

		printf("\nCantidad maxima: %d\n", maximo);

		retorno = 0;
	}

	return retorno;
}

int contarCantMicrosDeEmpresas(eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas, int contEmpresas[])
{
	int retorno = -1;
	int i;

	if(arrayMicros != NULL && lenMicros > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && contEmpresas != NULL)
	{
		for(i = 0; i < lenEmpresas; i++)
		{
			contarCantMicrosXEmpresa(arrayMicros, lenMicros, arrayEmpresas[i].id, &contEmpresas[i]);
		}

		retorno = 0;
	}

	return retorno;
}

int contarCantMicrosXEmpresa(eMicro arrayMicros[], int lenMicros, int idEmpresa, int* cont)
{
	int retorno = -1;
	int i;

	if(arrayMicros != NULL && lenMicros > 0 && idEmpresa > 0 && cont != NULL)
	{
		for(i = 0; i < lenMicros; i++)
		{
			if(arrayMicros[i].idEmpresa == idEmpresa)
			{
				(*cont)++;
			}
		}

		retorno = 0;
	}

	return retorno;
}

int contarCantMicrosEmpresaTipo(eMicro arrayMicros[], int lenMicros, int idEmpresa, int idTipo, int* cont)
{
	int retorno = -1;
	int i;

	if(arrayMicros != NULL && lenMicros > 0 && idEmpresa > 0 && idTipo > 0 && cont != NULL)
	{
		for(i = 0; i < lenMicros; i++)
		{
			if(arrayMicros[i].idEmpresa == idEmpresa && arrayMicros[i].idTipo == idTipo)
			{
				(*cont)++;
			}
		}

		retorno = 0;
	}

	return retorno;
}

int informarPromedioMicrosEmpresa(eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, int indiceEmpresa, int indiceTipo)
{
	int retorno = -1;
	int cantMicrosTipo = 0;
	int cantMicrosTotal = 0;
	float promedio;

	if(arrayMicros != NULL && lenMicros > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0 &&
	   indiceEmpresa >= 0 && indiceEmpresa < lenEmpresas && indiceTipo >= 0 && indiceTipo < lenTipos &&
	   !contarCantMicrosEmpresaTipo(arrayMicros, lenMicros, arrayEmpresas[indiceEmpresa].id, arrayTipos[indiceTipo].id, &cantMicrosTipo) &&
	   !contarCantMicrosXEmpresa(arrayMicros, lenMicros, arrayEmpresas[indiceEmpresa].id, &cantMicrosTotal))
	{
		promedio = (float) cantMicrosTipo / cantMicrosTotal;

		printf("\nEmpresa: %s\n\n", arrayEmpresas[indiceEmpresa].descripcion);

		printf("--> Cantidad de Micros de Tipo %s: %d\n\n", arrayTipos[indiceTipo].descripcion, cantMicrosTipo);
		printf("--> Cantidad de Micros Totales: %d\n\n", cantMicrosTotal);

		printf("El promedio de Cantidad de Tipo sobre Cantidad Total es: %g\n", promedio);

		retorno = 0;
	}

	return retorno;
}

int calcularMinimoDeMicrosDeEmpresas(int contEmpresas[], int lenEmpresas, int* minimo)
{
	int retorno = -1;
	int i;

	if(contEmpresas != NULL && lenEmpresas > 0 && minimo != NULL)
	{
		for(i = 0; i < lenEmpresas; i++)
		{
			if(i == 0 || contEmpresas[i] < *minimo)
			{
				*minimo = contEmpresas[i];
			}
		}

		retorno = 0;
	}

	return retorno;
}

int mostrarEmpresaConMenosMicros(eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas)
{
	int retorno = -1;
	int contEmpresas[] = {0, 0, 0, 0};
	int minimo;
	int i;

	if(arrayMicros != NULL && lenMicros > 0 && arrayEmpresas != NULL && lenEmpresas > 0 &&
	   !contarCantMicrosDeEmpresas(arrayMicros, lenMicros, arrayEmpresas, lenEmpresas, contEmpresas) &&
	   !calcularMinimoDeMicrosDeEmpresas(contEmpresas, lenEmpresas, &minimo))
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tEMPRESAS CON MENOS MICROS\n\n");

		printf("*----------*--------------------*\n");
		printf("|%-10s|%-20s|\n", "ID", "DESCRIPCION");
		printf("*----------*--------------------*\n");

		for(i = 0; i < lenEmpresas; i++)
		{
			if(contEmpresas[i] == minimo)
			{
				eEmpresa_mostrarUnaEmpresa(&arrayEmpresas[i]);
			}
		}

		printf("*----------*--------------------*\n");

		printf("\nCantidad minima: %d\n", minimo);

		retorno = 0;
	}

	return retorno;
}

int mostrarViajesXMicro(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos, int indiceMicro)
{
	int retorno = -1;
	int flag = 0;
	int indiceEmpresa;
	int indiceTipo;
	int indiceDest;
	int i;

	if(arrayViajes != NULL && lenViajes > 0 && arrayMicros != NULL && lenMicros > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0 && arrayDestinos != NULL && lenDestinos > 0 && indiceMicro >= 0 && indiceMicro < lenMicros &&
	   !eEmpresa_encontrarPorId(arrayEmpresas, lenEmpresas, arrayMicros[indiceMicro].idEmpresa, &indiceEmpresa) &&
	   !eTipo_encontrarPorId(arrayTipos, lenTipos, arrayMicros[indiceMicro].idTipo, &indiceTipo))
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tLISTA DE VIAJES POR MICRO\n");

		printf("\n\n\tViajes de Micro con Empresa %s, de Tipo: %s y con capacidad %d\n\n", arrayEmpresas[indiceEmpresa].descripcion, arrayTipos[indiceTipo].descripcion, arrayMicros[indiceMicro].capacidad);

		printf("*----------*----------------------------------------------------*--------------------*----------*\n");
		printf("|%-10s|%-52s|%-20s|%-10s|\n", "ID", "MICRO", "DESTINO", "FECHA");
		printf("|%-10c|----------------------------------------------------|%-20c|%-10c|\n", ' ', ' ', ' ');
		printf("|%-10c|%-20s|%-20s|%-10s|%-20c|%-10c|\n", ' ', "EMPRESA", "TIPO", "CAPACIDAD", ' ', ' ');
		printf("*----------*--------------------*--------------------*----------*--------------------*----------*\n");

		for(i = 0; i < lenViajes; i++)
		{
			if(!arrayViajes[i].isEmpty && arrayViajes[i].idMicro == arrayMicros[indiceMicro].id &&
			   !eDestino_encontrarPorId(arrayDestinos, lenDestinos, arrayViajes[i].idDestino, &indiceDest))
			{
				eViaje_mostrarUnViaje(&arrayViajes[i], &arrayMicros[indiceMicro], &arrayEmpresas[indiceEmpresa], &arrayTipos[indiceTipo], &arrayDestinos[indiceDest]);
				flag = 1;
			}
		}

		if(flag)
		{
			printf("*----------*--------------------*--------------------*----------*--------------------*----------*\n");
		}

		else
		{
			printf("\n\nNo hay viajes de este micro\n\n");
		}

		retorno = 0;
	}

	return retorno;
}

int calcularSumaPrecios(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eDestino arrayDestinos[], int lenDestinos, int indiceMicro, float* acum)
{
	int retorno = -1;
	int indiceDest;
	int i;

	if(arrayViajes != NULL && lenViajes > 0 && arrayMicros != NULL && lenMicros > 0 && arrayDestinos != NULL && lenDestinos > 0 && indiceMicro >= 0 && indiceMicro < lenMicros && acum != NULL)
	{
		*acum = 0;

		for(i = 0; i < lenViajes; i++)
		{
			if(!arrayViajes[i].isEmpty && arrayViajes[i].idMicro == arrayMicros[indiceMicro].id &&
			   !eDestino_encontrarPorId(arrayDestinos, lenDestinos, arrayViajes[i].idDestino, &indiceDest))
			{
				*acum += arrayDestinos[indiceDest].precio;
			}
		}

		if(*acum > 0)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int mostrarMicrosXDestino(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos, int indiceDest)
{
	int retorno = -1;
	int flag = 0;
	int indiceMicro;
	int indiceChofer;
	int indiceEmpresa;
	int indiceTipo;
	int i;

	if(arrayViajes != NULL && lenViajes > 0 && arrayMicros != NULL && lenMicros > 0 && arrayChoferes != NULL && lenChoferes > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0 && arrayDestinos != NULL && lenDestinos > 0 && indiceDest >= 0 && indiceDest < lenDestinos)
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tLISTA DE MICROS POR DESTINO\n");

		printf("\n\n\tMicros con Destino a %s\n\n", arrayDestinos[indiceDest].descripcion);

		printf("*----------*--------------------*--------------------*----------*--------------------*----------*\n");
		printf("|%-10s|%-20s|%-20s|%-10s|%-20s|%-10s|\n", "ID", "EMPRESA", "TIPO", "CAPACIDAD", "CHOFER", "FECHA");
		printf("*----------*--------------------*--------------------*----------*--------------------*----------*\n");

		for(i = 0; i < lenViajes; i++)
		{
			if(!arrayViajes[i].isEmpty && arrayViajes[i].idDestino == arrayDestinos[indiceDest].id &&
			   !eMicro_encontrarPorId(arrayMicros, lenMicros, arrayViajes[i].idMicro, &indiceMicro) &&
			   !eEmpresa_encontrarPorId(arrayEmpresas, lenEmpresas, arrayMicros[indiceMicro].idEmpresa, &indiceEmpresa) &&
			   !eTipo_encontrarPorId(arrayTipos, lenTipos, arrayMicros[indiceMicro].idTipo, &indiceTipo) &&
			   !eChofer_encontrarPorId(arrayChoferes, lenChoferes, arrayMicros[i].idChofer, &indiceChofer))
			{
				eMicro_mostrarUnMicro(&arrayMicros[indiceMicro], &arrayEmpresas[indiceEmpresa], &arrayTipos[indiceTipo], &arrayChoferes[indiceChofer]);
				eFecha_mostrar(&arrayViajes[i].fecha);
				printf("|\n");
				flag = 1;
			}
		}

		if(flag)
		{
			printf("*----------*--------------------*--------------------*----------*--------------------*----------*\n");
		}

		else
		{
			printf("\n\nNo hay micros hacia ese destino\n\n");
		}

		retorno = 0;
	}

	return retorno;
}

int mostrarViajesXFecha(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos, int indiceViaje)
{
	int retorno = -1;
	int flag = 0;
	int indiceMicro;
	int indiceEmpresa;
	int indiceTipo;
	int indiceDest;
	int i;

	if(arrayViajes != NULL && lenViajes > 0 && arrayMicros != NULL && lenMicros > 0 && arrayEmpresas != NULL && lenEmpresas > 0 && arrayTipos != NULL && lenTipos > 0 && arrayDestinos != NULL && lenDestinos > 0 && indiceViaje >= 0 && indiceViaje < lenViajes)
	{
		printf("\n");
		system("pause");
		system("cls");

		printf("\tLISTA DE VIAJES POR FECHA\n");

		printf("\n\n\tViajes realizados en la fecha ");
		eFecha_mostrar(&arrayViajes[indiceViaje].fecha);
		printf("\n\n");

		printf("*----------*----------------------------------------------------*--------------------*----------*\n");
		printf("|%-10s|%-52s|%-20s|%-10s|\n", "ID", "MICRO", "DESTINO", "FECHA");
		printf("|%-10c|----------------------------------------------------|%-20c|%-10c|\n", ' ', ' ', ' ');
		printf("|%-10c|%-20s|%-20s|%-10s|%-20c|%-10c|\n", ' ', "EMPRESA", "TIPO", "CAPACIDAD", ' ', ' ');
		printf("*----------*--------------------*--------------------*----------*--------------------*----------*\n");

		for(i = 0; i < lenViajes; i++)
		{
			if(!arrayViajes[i].isEmpty &&
			   arrayViajes[i].fecha.dia == arrayViajes[indiceViaje].fecha.dia &&
			   arrayViajes[i].fecha.mes == arrayViajes[indiceViaje].fecha.mes &&
			   arrayViajes[i].fecha.anio == arrayViajes[indiceViaje].fecha.anio &&
			   !eMicro_encontrarPorId(arrayMicros, lenMicros, arrayViajes[i].idMicro, &indiceMicro) &&
			   !eEmpresa_encontrarPorId(arrayEmpresas, lenEmpresas, arrayMicros[indiceMicro].idEmpresa, &indiceEmpresa) &&
			   !eTipo_encontrarPorId(arrayTipos, lenTipos, arrayMicros[indiceMicro].idTipo, &indiceTipo) &&
			   !eDestino_encontrarPorId(arrayDestinos, lenDestinos, arrayViajes[i].idDestino, &indiceDest))
			{
				eViaje_mostrarUnViaje(&arrayViajes[indiceViaje], &arrayMicros[indiceMicro], &arrayEmpresas[indiceEmpresa], &arrayTipos[indiceTipo], &arrayDestinos[indiceDest]);
				flag = 1;
			}
		}

		if(flag)
		{
			printf("*----------*----------------------------------------------------*--------------------*----------*\n");
		}

		else
		{
			printf("\n\nNo hay viajes realizados en esa fecha\n\n");
		}

		retorno = 0;
	}

	return retorno;
}
