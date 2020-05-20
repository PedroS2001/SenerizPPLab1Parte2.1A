#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"

/** \brief Imprime el id y la descripcion de las marcas ya hardcodeadas
 *
 * \param la estructura de marcas
 * \param el tamaño de la estructura
 */

void listarMarcas(eMarca* marca, int tam)
{
    int i;
    printf("ID   MARCA\n");
    for(i=0;i<tam;i++)
    {
        printf("%d   %s\n", marca[i].id, marca[i].descripcion);
    }
}

/** \brief carga la descripcion de marca donde encuentre el idMarca
 *
 * \param cadena en la que se va a copiar la descripcion
 * \param id que estoy buscando cargar la descripcion
 * \param array de marcas
 * \param tamaño del array
 * \return 0 si pudo cargar la marca y -1 si no pudo
 *
 */

int cargarDescripcionMarca(char descripcion[], int id, eMarca marcas[], int tam)
{
    int retorno = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(marcas[i].id == id)
        {
            strcpy(descripcion,marcas[i].descripcion);
            retorno = 0;
        }
    }
    return retorno;
}
