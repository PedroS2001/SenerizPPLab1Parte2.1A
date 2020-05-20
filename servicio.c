#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

/** \brief imprime los servicios, su id, descripcion y precio
 *
 * \param estructura servicios
 * \param tamaño de la estructura
 */

void listarServicios(eServicio* servicio, int tam)
{
    printf(" ID       DESCRIPCION    PRECIO\n");
    for(int i=0; i<tam; i++)
    {
        printf("%d %15s    %.2f\n",servicio[i].id, servicio[i].descripcion, servicio[i].precio);
    }
}

/** \brief carga la descripcion del servicio
 *
 * \param cadena en la que se va a copiar la descripcion
 * \param id que estoy buscando cargar la descripcion
 * \param array de servicios
 * \param tamaño del array
 * \return 0 si pudo cargar la descripcion y -1 si no pudo
 */

int cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tam)
{
    int retorno = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(servicios[i].id == id)
        {
            strcpy(descripcion,servicios[i].descripcion);
            retorno = 0;
        }
    }
    return retorno;
}
