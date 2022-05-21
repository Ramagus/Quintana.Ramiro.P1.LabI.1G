#ifndef NEXO_H_
#define NEXO_H_


#include "Destino.h"
#include "Empresa.h"
#include "Micro.h"
#include "Chofer.h"
#include "Tipo.h"
#include "Viaje.h"


/** \brief Imprime las opciones del men� principal
 *
 * \param opcion int* Lugar donde se guardar� la opci�n elegida por el usuario
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int mostrarMenuPrincipal(int* opcion);


/** \brief Realiza la gesti�n del ABM de Micros
 *
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayChoferes[] eChofer Array de Choferes
 * \param lenChoferes int L�mite del Array de Choferes
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 * \param idMicro int* ID del micro a cargar en el Alta
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int ABM_eMicro(eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, int* idMicro);


/** \brief Carga los datos de un micro
 *
 * \param unMicro eMicro* Micro a ser cargado
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 * \param idMicro int* ID del micro a cargar
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int eMicro_cargarUnMicro(eMicro* unMicro, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, int* idMicro);


/** \brief Carga un micro en el �ndice especificado
 *
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 * \param indiceMicro int �ndice del micro a ser cargado
 * \param idMicro int* ID del micro a cargar
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int eMicro_cargarEnArray(eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, int indiceMicro, int* idMicro);


/** \brief Modifica el micro en el �ndice especificado, cambiando el dato seleccionado por el usuario
 *
 * \param arrayMicros[] eDestino Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 * \param indiceMicro int �ndice del micro a modificar
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int eMicro_modificar(eMicro arrayMicros[], int lenMicros, eTipo arrayTipos[], int lenTipos, int indiceMicro);


/** \brief Imprime los datos de un micro con todos sus datos asociados
 *
 * \param unMicro eMicro* Puntero a un micro
 * \param unaEmpresa eEmpresa* Puntero a la empresa relacionada
 * \param unTipo eTipo* Puntero al tipo relacionado
 * \param unChofer eChofer* Puntero al chofer relacionado
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int eMicro_mostrarUnMicro(eMicro* unMicro, eEmpresa* unaEmpresa, eTipo* unTipo, eChofer* unChofer);


/** \brief Imprime la lista de micros con todos sus datos asociados
 *
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayChoferes[] eChofer Array de Choferes
 * \param lenChoferes int L�mite del Array de Choferes
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int eMicro_mostrarLista(eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos);


/** \brief Realiza la gesti�n del ABM de Viajes
 *
 * \param arrayViajes[] eViaje Array de Viajes
 * \param lenViajes int L�mite del Array de Viajes
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayChoferes[] eChofer Array de Choferes
 * \param lenChoferes int L�mite del Array de Choferes
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 * \param arrayDestinos[] eDestino Array de Destinos
 * \param lenDestinos int L�mite del Array de Destinos
 * \param idViaje int* ID del viaje a cargar en el Alta
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int ABM_eViaje(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos, int* idViaje);


/** \brief Carga los datos de un viaje
 *
 * \param unViaje eViaje* Viaje a ser cargado
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayChoferes[] eChofer Array de Choferes
 * \param lenChoferes int L�mite del Array de Choferes
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 * \param arrayDestinos[] eDestino Array de Destinos
 * \param lenDestinos int L�mite del Array de Destinos
 * \param idViaje int* ID del viaje a cargar
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int eViaje_cargarUnViaje(eViaje* unViaje, eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos, int* idViaje);


/** \brief Carga un viaje en el �ndice especificado
 *
 * \param arrayViajes[] eViaje Array de Viajes
 * \param lenViajes int L�mite del Array de Viajes
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayChoferes[] eChofer Array de Choferes
 * \param lenChoferes int L�mite del Array de Choferes
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 * \param arrayDestinos[] eDestino Array de Destinos
 * \param lenDestinos int L�mite del Array de Destinos
 * \param indiceViaje int �ndice del viaje a ser cargado
 * \param idViaje int* ID del viaje a cargar
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int eViaje_cargarEnArray(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos, int indiceViaje, int* idViaje);


/** \brief Modifica el viaje en el �ndice especificado, cambiando el dato seleccionado por el usuario
 *
 * \param arrayViajes[] eDestino Array de Viajes
 * \param lenViajes int L�mite del Array de Viajes
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayChoferes[] eChofer Array de Choferes
 * \param lenChoferes int L�mite del Array de Choferes
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 * \param arrayDestinos[] eDestino Array de Destinos
 * \param lenDestinos int L�mite del Array de Destinos
 * \param indiceViaje int �ndice del viaje a modificar
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int eViaje_modificar(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos, int indiceViaje);


/** \brief Imprime los datos de un viaje con todos sus datos asociados
 *
 * \param unViaje eViaje* Puntero a un viaje
 * \param unMicro eMicro* Puntero al micro relacionado
 * \param unaEmpresa eEmpresa* Puntero a la empresa relacionada
 * \param unTipo eTipo* Puntero al tipo relacionado
 * \param unDestino eDestino* Puntero al destino relacionado
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int eViaje_mostrarUnViaje(eViaje* unViaje, eMicro* unMicro, eEmpresa* unaEmpresa, eTipo* unTipo, eDestino* unDestino);


/** \brief Imprime la lista de viajes con todos sus datos asociados
 *
 * \param arrayViajes[] eViaje Array de Viajes
 * \param lenViajes int L�mite del Array de Viajes
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 * \param arrayDestinos[] eDestino Array de Destinos
 * \param lenDestinos int L�mite del Array de Destinos
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int eViaje_mostrarLista(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos);


/** \brief Gestiona los Informes
 *
 * \param arrayViajes[] eViaje Array de Viajes
 * \param lenViajes int L�mite del Array de Viajes
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayChoferes[] eChofer Array de Choferes
 * \param lenChoferes int L�mite del Array de Choferes
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 * \param arrayDestinos[] eDestino Array de Destinos
 * \param lenDestinos int L�mite del Array de Destinos
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int realizarInformes(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos);


/** \brief Muestra los micros de todas las empresas
 *
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayChoferes[] eChofer Array de Choferes
 * \param lenChoferes int L�mite del Array de Choferes
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int mostrarMicrosDeEmpresas(eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos);


/** \brief Muestra los micros de una empresa
 *
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayChoferes[] eChofer Array de Choferes
 * \param lenChoferes int L�mite del Array de Choferes
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 * \param indiceEmpresa int �ndice de la empresa
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int mostrarMicrosXEmpresa(eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, int indiceEmpresa);


/** \brief Muestra los micros de todos los tipos
 *
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayChoferes[] eChofer Array de Choferes
 * \param lenChoferes int L�mite del Array de Choferes
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int mostrarMicrosDeTipos(eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos);


/** \brief Muestra los micros de un tipo
 *
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayChoferes[] eChofer Array de Choferes
 * \param lenChoferes int L�mite del Array de Choferes
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param indiceTipo int �ndice del tipo
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int mostrarMicrosXTipo(eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, int indiceTipo);


/** \brief Cuenta la cantidad de pasajeros de cada empresa
 *
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param contEmpresas[] int Acumuladores de pasajeros de cada empresa
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int contarCantPasajerosDeEmpresas(eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas, int contEmpresas[]);


/** \brief Cuenta la cantidad de pasajeros de una empresa
 *
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param idEmpresa int ID de la empresa a contar
 * \param cont int* Acumulador de pasajeros de la empresa
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int contarCantPasajerosXEmpresa(eMicro arrayMicros[], int lenMicros, int idEmpresa, int* cont);


/** \brief Calcula la mayor cantidad de pasajeros de las empresas
 *
 * \param contEmpresas[] int Contadores de cada empresa
 * \param lenEmpresas int L�mite del Array de Contadores de Empresas
 * \param minimo int* Lugar donde se guardar� el m�nimo contador
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int calcularMaximoDeMicrosDeEmpresas(int contEmpresas[], int lenEmpresas, int* minimo);


/** \brief Muestra las empresas con mayor cantidad de pasajeros
 *
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int mostrarEmpresaConMasPasajeros(eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas);


/** \brief Cuenta la cantidad de micros de cada empresa
 *
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param contEmpresas[] int Contadores de micros de cada empresa
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int contarCantMicrosDeEmpresas(eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas, int contEmpresas[]);


/** \brief Cuenta la cantidad de micros de una empresa
 *
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param idEmpresa int ID de la empresa a contar
 * \param cont int* Contador de micros de la empresa
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int contarCantMicrosXEmpresa(eMicro arrayMicros[], int lenMicros, int idEmpresa, int* cont);


/** \brief Calcula la menor cantidad de micros de las empresas
 *
 * \param contEmpresas[] int Contadores de micros de cada empresa
 * \param lenEmpresas int L�mite del Array de Contadores de Empresas
 * \param minimo int* Lugar donde se guardar� el m�nimo contador
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int calcularMinimoDeMicrosDeEmpresas(int contEmpresas[], int lenEmpresas, int* minimo);


/** \brief Muestra las empresas con menor cantidad de micros
 *
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int mostrarEmpresaConMenosMicros(eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas);


/** \brief Muestra los viajes que realiz� un micro
 *
 * \param arrayViajes[] eViaje Array de Viajes
 * \param lenViajes int L�mite del Array de Viajes
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 * \param arrayDestinos[] eDestino Array de Destinos
 * \param lenDestinos int L�mite del Array de Destinos
 * \param indiceMicro int �ndice del micro
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int mostrarViajesXMicro(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos, int indiceMicro);


/** \brief Calcula la suma de precios de un micro de cada viaje que realiz�
 *
 * \param arrayViajes[] eViaje Array de Viajes
 * \param lenViajes int L�mite del Array de Viajes
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayDestinos[] eDestino Array de Destinos
 * \param lenDestinos int L�mite del Array de Destinos
 * \param indiceMicro int �ndice del micro
 * \param acum float* Lugar donde se acumula la suma de precios
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int calcularSumaPrecios(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eDestino arrayDestinos[], int lenDestinos, int indiceMicro, float* acum);


/** \brief Muestra los micros de un destino
 *
 * \param arrayViajes[] eViaje Array de Viajes
 * \param lenViajes int L�mite del Array de Viajes
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayChoferes[] eChofer Array de Choferes
 * \param lenChoferes int L�mite del Array de Choferes
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 * \param arrayDestinos[] eDestino Array de Destinos
 * \param lenDestinos int L�mite del Array de Destinos
 * \param indiceDest int �ndice del destino
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int mostrarMicrosXDestino(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eChofer arrayChoferes[], int lenChoferes, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos, int indiceDest);


/** \brief Muestra los viajes que se realizaron en una fecha
 *
 * \param arrayViajes[] eViaje Array de Viajes
 * \param lenViajes int L�mite del Array de Viajes
 * \param arrayMicros[] eMicro Array de Micros
 * \param lenMicros int L�mite del Array de Micros
 * \param arrayChoferes[] eChofer Array de Choferes
 * \param lenChoferes int L�mite del Array de Choferes
 * \param arrayEmpresas[] eEmpresa Array de Empresas
 * \param lenEmpresas int L�mite del Array de Empresas
 * \param arrayTipos[] eTipo Array de Tipos
 * \param lenTipos int L�mite del Array de Tipos
 * \param arrayDestinos[] eDestino Array de Destinos
 * \param lenDestinos int L�mite del Array de Destinos
 * \param indiceViaje int �ndice del viaje
 *
 * \return int -1 si hubo un error, 0 si est� todo ok
 *
 */
int mostrarViajesXFecha(eViaje arrayViajes[], int lenViajes, eMicro arrayMicros[], int lenMicros, eEmpresa arrayEmpresas[], int lenEmpresas, eTipo arrayTipos[], int lenTipos, eDestino arrayDestinos[], int lenDestinos, int indiceViaje);


#endif /* NEXO_H_ */
