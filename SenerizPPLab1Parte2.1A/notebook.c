#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebook.h"
#include "servicio.h"
#include "tipo.h"
#include "marca.h"
#include "trabajo.h"
#include "utn.h"
#include "cliente.h"

/** \brief Imprime una notebook mostrando todos los datos de la estructura
 *
 * \param estructura notebook
 * \param estructura de marca
 * \param estructura de tipo
 */

int imprimirNotebook(eNotebook notebook, eMarca* marca, eTipo* tipo, eCliente* cliente)
{
    int retorno = -1;
    char descTipo[20];
    char descMarca[20];
    char nombreCliente[20];
    cargarDescripcionMarca(descMarca, notebook.idMarca,marca,4);
    cargarDescripcionTipo(descTipo, notebook.idTipo, tipo,4);
    cargarNombreCliente(nombreCliente, notebook.idCliente, cliente,5);

    if(notebook.isEmpty == 0)
    {
        printf("%2d  %10s    %10s  %10s    %10s    %.2f\n", notebook.id, notebook.modelo, nombreCliente , descMarca, descTipo, notebook.precio);
        retorno = 0;
    }

    return retorno;
}

/** \brief imprime todas las notebooks cargadas con sus datos
 *
 * \param la estructura de notebooks
 * \param la estructura de marca
 * \param la estructura de tipos
 *
 */

void imprimirNotebooks(eNotebook* notebook, int tam, eMarca* marca, eTipo* tipo, eCliente* cliente)
{
    int i;

    printf("ID      MODELO    NOMBRECLIENTE   MARCA        TIPO      PRECIO\n");
    for(i=0; i<tam; i++)
    {
        imprimirNotebook(notebook[i], marca, tipo, cliente);
    }
}

/** \brief inicializa todas las notebooks como vacias
 *
 * \param la estructura de notebooks
 * \param el tamaño de la estructura
 */

void inicializarNotebooks(eNotebook* notebook, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        notebook[i].isEmpty = 1;
    }
}

/** \brief Carga y da de alta una notebook con los parametros recibidos
 *
 * \param estructura de notebook en la que voy a cargar los datos
 * \param Auxiliar de notebook del que voy a recibir los datos
 * \param el id que va a tener la notebook
 */

void altaNotebook(eNotebook* notebookNueva, eNotebook datosNotebook, int id)
{
    notebookNueva[id-1] = datosNotebook;
    notebookNueva[id-1].id = id;
    notebookNueva[id-1].isEmpty = 0;
}

/** \brief da de baja una notebook que ya estaba cargada
 *
 * \param estructura de notebooks
 * \param tamaño de la estructura de notebooks
 * \param estructura de marcas
 * \param estructura de tipos
 * \param cantidad de notebooks cargadas
 * \return
 *
 */

void bajaNotebook(eNotebook* notebook, int tam, eMarca* marca, eTipo* tipo, int idNotebook, eCliente* cliente)
{
    int idABorrar;
    char confirma;
    system("cls");
    printf("***BAJA NOTEBOOK***\n\n");

    imprimirNotebooks(notebook,tam,marca,tipo, cliente);
    utn_getNumero(&idABorrar,"Ingrese el id de la notebook a dar de baja: ", "No existe notebook con ese id. Reingrese\n", 1, idNotebook-1, 2);

    if(imprimirNotebook(notebook[idABorrar-1],marca,tipo,cliente)==0)
    {
        printf("Esta seguro que quiere dar de baja esta notebook? <s o n> ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma == 's')
        {
            notebook[idABorrar-1].isEmpty = 1;
            printf("Notebook eliminada\n");
        }
        else
        {
            printf("Se ha cancelado la baja\n");
        }
    }
    else
    {
        printf("\nEsa notebook ya fue eliminada\n\n");
    }
}

/** \brief modifica algun campo de una notebook ya cargada
 *
 * \param estructura de notebooks
 * \param tamaño de la estructura de notebooks
 * \param estructura de tipos
 * \param estructura de marcas
 * \param cantidad de notebooks cargadas
 *
 */

void modificarNotebook(eNotebook* notebook, int tam, eTipo* tipo, eMarca* marca, int idNotebook, eCliente* cliente)
{
    int id;
    int modifica;
    float nuevoPrecio;
    int nuevoTipo;
    system("cls");
    printf("***MODIFICAR NOTEBOOK***\n\n");

    imprimirNotebooks(notebook,tam,marca,tipo,cliente);

    if(utn_getNumero(&id,"Ingrese el id de la notebook a modificar: ", "No existe notebook con ese id. Reingrese\n", 1, idNotebook-1, 2) != -1)
    {
        if(notebook[id-1].isEmpty == 0)
        {
            imprimirNotebook(notebook[id-1],marca,tipo,cliente);
            printf("Que desea modificar de esta notebook? \n");
            utn_getNumero(&modifica,"1)Precio\n2)Tipo\n3)Cancelar ","Error\n",1,3,2 );
            if(modifica == 1)
            {
                utn_getNumeroFlotante(&nuevoPrecio,"Ingrese nuevo precio: ", "Error\n", 1, 99999.9,2);
                notebook[id-1].precio = nuevoPrecio;
                printf("\n");
            }
            else if(modifica==2)
            {
                listarTipos(tipo,4);
                utn_getNumero(&nuevoTipo,"Ingrese el id del nuevo tipo: ", "Error\n",5000,5003,2);
                notebook[id-1].idTipo = nuevoTipo;
                printf("\n");
            }
            else if(modifica==3)
            {
                printf("Se cancelo la modificacion\n");
            }
        }
        else
        {
            printf("Esa notebook fue eliminada \n");
        }
    }
}

/** \brief ordena las notebooks por marca y por precio
 *
 * \param estructura de notebooks
 * \param tamaño de la estructura
 * \param estructura de marcas
 */

void ordenarNotebooksPorMarcaYPrecio(eNotebook* notebook, int len, eMarca* marca)
{
    eNotebook auxiliar;
    int i;
    int j;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(notebook[i].isEmpty == 0 && notebook[j].isEmpty == 0)
            {
                if(notebook[i].idMarca > notebook[j].idMarca)
                {
                    auxiliar = notebook[i];
                    notebook[i] = notebook[j];
                    notebook[j] = auxiliar;
                }
                else if(notebook[i].idMarca == notebook[j].idMarca && notebook[i].precio > notebook[j].precio)
                {
                    auxiliar = notebook[i];
                    notebook[i] = notebook[j];
                    notebook[j] = auxiliar;
                }
            }
        }
    }
}


/** \brief Ordena las notebooks por ID de forma ascendente
 *
 * \param la estructura de notebooks
 * \param el tamaño de la estructura
 * \return el array de marcas
 */


void ordenarXID(eNotebook* notebook,int len, eMarca* marca)
{
    eNotebook auxiliar;
    int i;
    int j;

    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(notebook[i].isEmpty == 0 && notebook[j].isEmpty == 0)
            {
                if(notebook[i].id > notebook[j].id)
                {
                    auxiliar = notebook[i];
                    notebook[i] = notebook[j];
                    notebook[j] = auxiliar;
                }
            }
        }
    }
}

int cargarModeloNotebook(char descripcion[], int id, eNotebook notebook[], int tam)
{
    int retorno = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(notebook[i].id == id)
        {
            strcpy(descripcion, notebook[i].modelo);
            retorno = 0;
        }
    }
    return retorno;
}
