#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "notebook.h"
#include "servicio.h"
#include "utn.h"

/** \brief da de alta un trabajo con los datos ya obtenidos
 *
 * \param estructura de trabajos en la que voy a cargar los datos
 * \param auxiliar de trabajo en el que tengo los datos
 * \param  id que va a recibir el trabajo
 */

void altaTrabajo(eTrabajo* trabajo, eTrabajo auxTrabajo, int id)
{
    trabajo[id-1] = auxTrabajo;
    trabajo[id-1].id = id;
    trabajo[id-1].isEmpty = 0;
}

void listarUnTrabajo(eTrabajo trabajo, int tam, eServicio servicios[], int tamser, eNotebook notebook[], int tamnot)
{
    int idnot;
    char nombreServicio[20];
    char modeloNotebook[20];

    if(trabajo.isEmpty == 0)
    {
        idnot = trabajo.idNotebook;
        cargarDescripcionServicio(nombreServicio, trabajo.idServicio, servicios, tamser);
        cargarModeloNotebook(modeloNotebook, notebook[idnot-1].id, notebook, tamnot);
        printf("  %d  %15s  %15s     %02d/%02d/%04d\n",trabajo.idNotebook, modeloNotebook, nombreServicio, trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);
    }

}


/** \brief imprime los trabajos dados de alta con el id de la notebook, el servicio y la fecha
 *
 * \param estructura de trabajos
 * \param tamaño de la estructura de trabajos
 * \param estructura de servicios
 * \param cantidad de servicios
 * \param estructura de notebooks
 * \param cantidad de notebooks
 */

void listarTrabajos(eTrabajo* trabajo, int tam, eServicio servicios[], int tamser, eNotebook notebook[], int tamnot)
{
    int i;

    printf("IDNOTEBOOK     MODELO         SERVICIO       FECHA\n");

    for(i=0; i<tam; i++)
    {
        listarUnTrabajo(trabajo[i],tam,servicios,tamser,notebook,tamnot);
    }
}

/** \brief inicializa todos los trabajos como vacios
 *
 * \param estructura de trabajos
 * \param tamaño de la estructura
 *
 */

void inicializarTrabajos(eTrabajo* trabajo, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        trabajo[i].isEmpty = 1;
    }
}
