#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

/** \brief imprime los tipos con sus id y descripcion
 *
 * \param estructura de tipos
 * \param tamaño de la estructura
 */

void listarTipos(eTipo* tipo, int tam)
{
    int i;
    printf("ID   TIPO\n");
    for(i=0;i<tam;i++)
    {
        printf("%d   %s\n",tipo[i].id, tipo[i].descripcion);
    }
}

/** \brief carga la descripcion del tipo
 *
 * \param cadena en la que se va a copiar la descripcion
 * \param id que estoy buscando cargar la descripcion
 * \param array de tipos
 * \param tamaño del array
 * \return 0 si pudo cargar la descripcion y -1 si no pudo
 */

int cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tam)
{
    int retorno = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(tipos[i].id == id)
        {
            strcpy(descripcion,tipos[i].descripcion);
            retorno = 0;
        }
    }
    return retorno;
}
