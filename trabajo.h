#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bicicleta.h"
#include "servicio.h"
#include "cliente.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int estaVacio;
}eTrabajo;

/** \brief Solicita todos los datos necesarios al usuario para agregar un nuevo trabajo y luego se los pasa a agregarTrabajo.
 *
 * \param trabajos[] eTrabajo
 * \param largoTrabajos int
 * \param bicicletas[] eBicicleta
 * \param largoBicicletas int
 * \param servicios[] eServicio
 * \param largoServicios int
 * \param trabajosRealizados int
 * \return void
 *
 */
int altaTrabajo(eTrabajo trabajos[], int largoTrabajos, eBicicleta bicicletas[], int largoBicicletas,eServicio servicios[],int largoServicios, int trabajosRealizados, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eCliente clientes[], int largoClientes);

/** \brief Inicializa el listado completo en estaVacio = true.
 *
 * \param trabajos[] eTrabajo
 * \param largo int
 * \return void
 *
 */
void inicializarTrabajos(eTrabajo trabajos[], int largo);

/** \brief agrega un trabajo al listado con los datos recibidos por parametro.
 *
 * \param trabajos[] eTrabajo
 * \param idBicicleta int
 * \param idServicio int
 * \param dia int
 * \param mes int
 * \param anio int
 * \param trabajosRealizados int
 * \return void
 *
 */
void agregarTrabajo(eTrabajo trabajos[],int idBicicleta,int  idServicio,int  dia,int  mes,int  anio, int trabajosRealizados);

/** \brief Muestra todos los trabajos que se encuntran en el listado.
 *
 * \param trabajos[] eTrabajo
 * \param largoTrabajos int
 * \param servicios[] eServicio
 * \param largoServicios int
 * \param trabajosRealizados int
 * \return void
 *
 */
void listarTrabajos(eTrabajo trabajos[], int largoTrabajos, eServicio servicios[], int largoServicios, int trabajosRealizados );

/** \brief Se pide seleccionar un trabajo y se muestran todos los realizados de ese tipo.
 *
 * \param trabajos[] eTrabajo
 * \param largoTrabajos int
 * \param servicios[] eServicio
 * \param largoServicios int
 * \param trabajosRealizados int
 * \return void
 *
 */
void mostrarTodosLosTrabajosDeUnTipo(eTrabajo trabajos[], int largoTrabajos, eServicio servicios[], int largoServicios, int trabajosRealizados );

/** \brief Se pide seleccionar una bicicleta y se muestran todos los trabajos realizados a la misma.
 *
 * \param bicicletas[] eBicicleta
 * \param largoBicicletas int
 * \param tipos[] eTipo
 * \param largoTipos int
 * \param colores[] eColor
 * \param largoColores int
 * \param servicios[] eServicio
 * \param largoServicios int
 * \param trabajos[] eTrabajo
 * \param largoTrabajos int
 * \param clientes[] eCliente
 * \param largoClientes int
 * \param trabajosRealizados int
 * \return void
 *
 */
void listarTrabajosAUnaBicicleta(eBicicleta bicicletas[],int largoBicicletas,eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eServicio servicios[], int largoServicios, eTrabajo trabajos[], int largoTrabajos, eCliente clientes[], int largoClientes, int trabajosRealizados);

/** \brief Se pide ingresar una fecha y se muestran todos los trabajos realizados en ese dia.
 *
 * \param trabajos[] eTrabajo
 * \param largoTrabajos int
 * \param servicios[] eServicio
 * \param largoServicios int
 * \param trabajosRealizados int
 * \return void
 *
 */
void mostrarTodosLosTrabajosDeUnDia(eTrabajo trabajos[], int largoTrabajos, eServicio servicios[], int largoServicios, int trabajosRealizados);
#endif // TRABAJO_H_INCLUDED
