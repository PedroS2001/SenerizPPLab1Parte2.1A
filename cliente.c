#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

int cargarNombreCliente(char nombre[], int id, eCliente* cliente, int tam)
{
    int retorno = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(cliente[i].id == id)
        {
            strcpy(nombre,cliente[i].nombre);
            retorno = 0;
        }
    }
    return retorno;
}
