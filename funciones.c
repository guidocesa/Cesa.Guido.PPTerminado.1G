#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "funciones.h"
#include "cliente.h"

int confirmarSalida()
{
    int retorno = 0;
    system("cls");
    printf("Seguro que desea salir del programa? \n 1 : Si \n 0 : No  \n\n Sus cambios o bicicletas no seran guardados. \n");
    fflush(stdin);
    scanf("%i", &retorno);
    return retorno;
}

int mostrarOpcionesYObtenerSeleccion()
{
    int seleccion;
    int seleccionEsCorrecta = 0;

    while(!seleccionEsCorrecta)
    {

        system("cls");
        printf("Por favor seleccione una opcion y presione la tecla enter: \n\n");
        printf("1 - Dar de ALTA una bicicleta.\n");
        printf("2 - Modificar datos de una bicicleta. \n");
        printf("3 - Dar de BAJA una bicicleta. \n");
        printf("4 - Dar de ALTA un trabajo realizado.\n");
        printf("5 - Mostrar menu de informes.\n");
        printf("0 - Salir de la base de datos. \n");

        fflush(stdin);

        scanf("%i" , &seleccion );

        if(seleccion < 6 && seleccion > -1)
        {
            seleccionEsCorrecta = 1;
        }
    }

    return seleccion;
}

int mostrarMenuDeInformes()
{
    int seleccion;
    int seleccionEsCorrecta = 0;

    while(!seleccionEsCorrecta)
    {

        system("cls");
        printf("Por favor seleccione una opcion y presione la tecla enter: \n\n");
        printf("1 - Ver todas las bicicletas. \n");
        printf("2 - Ver todas los tipos de bicicletas. \n");
        printf("3 - Ver todas los colores de bicicletas. \n");
        printf("4 - Ver todas los servicios para bicicletas. \n");
        printf("5 - Ver todos los trabajos realizados.\n");
        printf("6 - Ver todos los trabajos realizados a una bicicleta en particular.\n");
        printf("7 - Ver las bicicletas ordenadas por tipo.\n");
        printf("8 - Ver todas las bicicletas de un tipo seleccionado. \n");
        printf("9 - Ver todas las biciicletas de un color seleccionado. \n");
        printf("10 - Ver la/las bicicletas con el rodado mas chico. \n");
        printf("11 - Buscar bicicletas de un color y tipo en particular. \n");
        printf("12 - Ver el color mas elegido por los clientes. \n");
        printf("13 - Elegir un trabajo y mostrar todas las bicicletas a las que fue realizado. \n");
        printf("14 - Mostrar todos los trabajos realizados en una fecha en particular. \n");
        printf("0 - Volver al menu anterior. \n");

        fflush(stdin);

        scanf("%i" , &seleccion );

        if(seleccion < 15 && seleccion > -1)
        {
            seleccionEsCorrecta = 1;
        }
    }

    return seleccion;
}

void menuDeInformes(eBicicleta bicicletas[], int largoBicicletas, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eServicio servicios[], int largoServicios , eTrabajo trabajos[], int largoTrabajos, eCliente clientes[], int largoClientes, int trabajosRealizados)
{
    int seleccion;
    do
    {
        seleccion = mostrarMenuDeInformes();
        switch(seleccion)
        {
        case 1:
            system("cls");
            if(bicicletas[0].estaVacio)
            {
                alertarListadoVacio();
            }
            else
            {
                listarBicicletas(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
                system("pause");
            }
            break;
        case 2:
            system("cls");
            listarTipos(tipos, largoTipos);
            system("pause");
            break;
        case 3:
            system("cls");
            listarColores(colores, largoColores);
            system("pause");
            break;
        case 4:
            system("cls");
            listarServicios(servicios, largoServicios);
            system("pause");
            break;
        case 5:
            if(trabajosRealizados == 0)
            {
                alertarListadoVacio();
            }
            else
            {
                listarTrabajos(trabajos, largoTrabajos, servicios, largoServicios, trabajosRealizados);
            }
            break;
        case 6:
            if(trabajosRealizados == 0 || bicicletas[0].estaVacio)
            {
                alertarListadoVacio();
            }
            else
            {
                listarTrabajosAUnaBicicleta(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, servicios, largoServicios, trabajos, largoTrabajos, clientes, largoClientes, trabajosRealizados);
            }
            break;
        case 7:
            system("cls");
            if(bicicletas[0].estaVacio)
            {
                alertarListadoVacio();
            }
            else
            {
                listarBicicletas(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
                system("pause");
            }
            break;
        case 8:
            system("cls");
            listarBicicletasDeUnTipo(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            system("pause");
            break;
        case 9:
            system("cls");
            listarBicicletasPorColor(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            system("pause");
            break;
        case 10:
            system("cls");
            listarBicicletasDeMenorRodado(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            system("pause");
            break;
        case 11:
            system("cls");
            buscarBicicletasDeTipoYColorSeleccionado(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            system("pause");
            break;
        case 12:
            system("cls");
            mostarColorPreferidoPorLosClientes(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            system("pause");
            break;
            break;
        case 13:
            if(trabajosRealizados == 0)
            {
                alertarListadoVacio();
            }
            else
            {
                mostrarTodosLosTrabajosDeUnTipo(trabajos, largoTrabajos, servicios, largoServicios, trabajosRealizados);
            }
            break;
        case 14:
            if(trabajosRealizados == 0)
            {
                alertarListadoVacio();
            }
            else
            {
                mostrarTodosLosTrabajosDeUnDia(trabajos, largoTrabajos, servicios, largoServicios, trabajosRealizados);
            }
            break;
        }
        fflush(stdin);
    }while(seleccion !=0);
}

void formatearString(char marca[])
{
    int i = 0;
    while (marca[i])
    {
        marca[i] = tolower(marca[i]);
        i++;
    }
    marca[0] = toupper(marca[0]);
}

void harcodearCuatroBicis(eBicicleta bicicletas[])
{
    bicicletas[0].estaVacio = 0;
    bicicletas[1].estaVacio = 0;
    bicicletas[2].estaVacio = 0;
    bicicletas[3].estaVacio = 0;

    bicicletas[0].id = 0;
    bicicletas[1].id = 1;
    bicicletas[2].id = 2;
    bicicletas[3].id = 3;

    bicicletas[0].idCliente = 6001;
    bicicletas[1].idCliente = 6002;
    bicicletas[2].idCliente = 6003;
    bicicletas[3].idCliente = 6002;

    bicicletas[0].idColor = 5001;
    bicicletas[1].idColor = 5002;
    bicicletas[2].idColor = 5003;
    bicicletas[3].idColor = 5000;

    bicicletas[0].idTipo = 1001;
    bicicletas[1].idTipo = 1001;
    bicicletas[2].idTipo = 1003;
    bicicletas[3].idTipo = 1002;

    strcpy(bicicletas[0].marca, "Haro");
    strcpy(bicicletas[1].marca , "Top");
    strcpy(bicicletas[2].marca , "Vairo");
    strcpy(bicicletas[3].marca , "Sars");

    bicicletas[0].rodado = 20.00;
    bicicletas[1].rodado = 27.50;
    bicicletas[2].rodado = 20.00;
    bicicletas[3].rodado = 26.00;
}

void alertarListadoVacio()
{
    system("cls");
    printf("El listado esta vacio, primero debe hacer un alta.\n\n");
    system("pause");
}

int menuPrincipal(eBicicleta bicicletas[], int largoBicicletas, eTipo tipos[], int largoTipos, eColor colores[], int largoColores, eServicio servicios[], int largoServicios , eTrabajo trabajos[], int largoTrabajos, eCliente clientes[], int largoClientes)
{
    int trabajosRealizados = 0;
    int* pIdAcumulativo = (int*) malloc(sizeof(int));
    *pIdAcumulativo = 0;
    int programaTerminado = 0;
    int opcionSeleccionada;
    harcodearCuatroBicis(bicicletas);
    *pIdAcumulativo = 4;
    while(!programaTerminado)
    {
        opcionSeleccionada = mostrarOpcionesYObtenerSeleccion();
        switch(opcionSeleccionada)
        {
        case 1:
            solicitarDatosYAgregarBicicletaOrdenada(bicicletas, largoBicicletas,pIdAcumulativo, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            break;
        case 2:
            if(bicicletas[0].estaVacio)
            {
                alertarListadoVacio();
            }
            else
            {
                modificarBicicleta(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            }
            break;
        case 3:
            if(bicicletas[0].estaVacio)
            {
                alertarListadoVacio();
            }
            else
            {
                darDeBajaBicicleta(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, clientes, largoClientes);
            }
            break;
        case 4:
            if(altaTrabajo(trabajos, largoTrabajos, bicicletas, largoBicicletas, servicios, largoServicios, trabajosRealizados,tipos, largoTipos, colores, largoColores, clientes, largoClientes))
            {
                trabajosRealizados ++;
            }
            break;
        case 5:
            menuDeInformes(bicicletas, largoBicicletas, tipos, largoTipos, colores, largoColores, servicios, largoServicios, trabajos, largoTrabajos, clientes, largoClientes, trabajosRealizados);
        case 0:
            programaTerminado =  confirmarSalida();
            break;
        }
    }

    return 0;

}

void hardcodearDatos(eTipo tipos[], int largoTipos, eColor colores[], int  largoColores,eServicio servicios[], int largoServicios, eCliente clientes[], int largoClientes)
{
    strcpy(tipos[0].descripcion , "Rutera");
    tipos[0].id = 1000;
    strcpy(tipos[1].descripcion , "Carrera");
    tipos[1].id = 1001;
    strcpy(tipos[2].descripcion , "Mountain");
    tipos[2].id = 1002;
    strcpy(tipos[3].descripcion , "BMX");
    tipos[3].id = 1003;

    strcpy(colores[0].nombreColor , "Gris");
    colores[0].id = 5000;
    strcpy(colores[1].nombreColor , "Negro");
    colores[1].id = 5001;
    strcpy(colores[2].nombreColor , "Blanco");
    colores[2].id =5002;
    strcpy(colores[3].nombreColor , "Azul");
    colores[3].id =5003;
    strcpy(colores[4].nombreColor , "Rojo");
    colores[4].id =5004;

    strcpy(servicios[0].descripcion , "Limpieza");
    servicios[0].precio = 250;
    servicios[0].id = 20000;
    strcpy(servicios[1].descripcion , "Parche");
    servicios[1].precio = 300;
    servicios[1].id = 20001;
    strcpy(servicios[2].descripcion , "Centrado");
    servicios[2].precio = 400;
    servicios[2].id = 20002;
    strcpy(servicios[3].descripcion , "Cadena");
    servicios[3].precio = 350;
    servicios[3].id = 20003;

    clientes[0].id = 6000;
    strcpy(clientes[0].nombre, "Juan");
    clientes[0].sexo = 'm';
    clientes[1].id = 6001;
    strcpy(clientes[1].nombre, "Lucas");
    clientes[1].sexo = 'm';
    clientes[2].id = 6002;
    strcpy(clientes[2].nombre, "Marcela");
    clientes[2].sexo = 'f';
    clientes[3].id = 6003;
    strcpy(clientes[3].nombre, "Rodrigo");
    clientes[3].sexo = 'm';
    clientes[4].id = 6004;
    strcpy(clientes[4].nombre, "Lucila");
    clientes[4].sexo = 'f';
}
