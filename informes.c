#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"

void sumaServicesNotebook(eNotebook* notebook,int tamnot,int cantnot, eTrabajo* trabajos, int tamtrab, eServicio* servicios, eTipo* tipos, eMarca* marcas, eCliente* cliente)
{
    float total = 0;
    int idNotebook;
    int i;
    int idTr;
    int j;

    imprimirNotebooks(notebook,tamnot,marcas,tipos,cliente);
    utn_getNumero(&idNotebook,"Ingrese el ID de la notebook: ","ERROR\n\n",1,cantnot,2);

    for(i=0;i<cantnot;i++)
    {
        if(notebook[idNotebook].isEmpty == 0)
        {
            if(trabajos[i].idNotebook == idNotebook)
            {
                imprimirNotebook(notebook[idNotebook-1],marcas,tipos,cliente);
                idTr = trabajos[i].idServicio;
                for(j=0;j<4;j++)
                {
                    if(idTr == servicios[j].id)
                    {
                        total += servicios[j].precio;
                    }
                }
            }
        }
    }

    printf("\nEL TOTAL DE LOS SERVICES HECHOS A ESA NOTEBOOK ES DE %.2f\n\n",total);
}

void informarNotebooksDeUnTipo(eNotebook* notebook, int tamnot, eTipo* tipos, eMarca* marcas, int tipoID, eCliente* cliente)
{
    int i;

    printf("\nLas notebooks que tenemos de ese tipo son: \n");
    printf("ID      MODELO    NOMBRECLIENTE   MARCA        TIPO      PRECIO\n");

    for(i=0;i<tamnot;i++)
    {
        if(notebook[i].isEmpty == 0 && notebook[i].idTipo == tipoID)
        {
            imprimirNotebook(notebook[i],marcas,tipos, cliente);
        }
    }
}

void informarNotebooksDeUnaMarca(eNotebook* notebook, int tamnot, eMarca* marca, eTipo* tipo, int idMarcaBuscar, eCliente* cliente)
{
    printf("\nLas notebooks que tenemos de esa marca son: \n");
    printf("ID      MODELO    NOMBRECLIENTE    MARCA        TIPO      PRECIO\n");
    int i;
    for(i=0;i<tamnot;i++)
    {
        if(notebook[i].idMarca == idMarcaBuscar)
        {
            imprimirNotebook(notebook[i],marca,tipo,cliente);
        }
    }
}

void informarNotebookMasBarata(eNotebook* notebook,int tamnot,eTipo* tipos, eMarca* marcas,eCliente* clientes)
{
    eNotebook aux;
    int i;
    int j;
    int flag = 0;

    for(i=0;i<tamnot;i++)
    {
        for(j=i+1;j<tamnot;j++)
        {
            if(notebook[i].isEmpty == 0 && notebook[j].isEmpty == 0 &&  (notebook[i].precio < notebook[j].precio || flag == 0))
            {
                aux = notebook[i];
                flag = 1;
            }
        }
    }
    printf("LA NOTEBOOK MAS BARATA ES: \n");
    printf("ID      MODELO    NOMBRECLIENTE    MARCA        TIPO      PRECIO\n");
    imprimirNotebook(aux, marcas, tipos, clientes);
}


void informarNotebooksXMarca(eNotebook* notebook, int tamnot, eMarca* marcas, eTipo* tipos, eCliente* cliente)
{
    int i;
    int j;
    system("cls");

    for(i=0; i<4; i++)  //Array de marcas
    {
        printf("\n_______________ MARCA: %s_______________\n",marcas[i].descripcion);
        printf("ID      MODELO    NOMBRECLIENTE    MARCA        TIPO      PRECIO\n");
        for(j=0; j<tamnot; j++) //array de notebooks
        {
            if(notebook[j].idMarca == 1000+i && notebook[j].isEmpty == 0)    //si el id de la notebbok concuerda con el id de tipos de esta pasada imprime todas las que tengan ese tipo
            {
                imprimirNotebook(notebook[j],marcas,tipos,cliente);
            }
        }
    }
}


void informarNotebooksTipoYMarca(eNotebook* notebook, int tamnot, eTipo* tipos, eMarca* marcas, eCliente* cliente)
{
    int eligeMarca;
    int eligeTipo;
    int contador = 0;
    int i;

    system("cls");

    listarMarcas(marcas,4);
    utn_getNumero(&eligeMarca,"Ingrese el ID de la marca: ", "ERROR\n\n",1000,1003,2 );

    listarTipos(tipos,4);
    utn_getNumero(&eligeTipo,"Ingrese el ID del Tipo: ", "ERROR\n\n",5000,5003,2 );


    for(i=0; i<tamnot; i++)
    {
        if(notebook[i].idMarca == eligeMarca && notebook[i].idTipo == eligeTipo && notebook[i].isEmpty == 0)
        {
            contador++;
        }
    }

    printf("\n la cantidad de notebooks que hay de esa marca y ese tipo son %d\n",contador);

}

void informarLaMarcaMasElegida(eNotebook* notebook, int tamnot, eTipo* tipos, eMarca* marcas, eCliente* cliente)
{
    int i;
    int j;
    int contador[4];
    int maximo;
    int flag = 0;
    char descripcion[20];


    for(i=0; i<4; i++) //ARRAY DE MARCAS
    {
        printf("MARCA %s\n", marcas[i].descripcion);
        for(j=0; j<tamnot; j++)
        {
            if(notebook[j].idMarca == marcas[i].id && notebook[j].isEmpty == 0)
            {
                contador[i]++;
            }
        }
    }

    for(i=0;i<4;i++)
    {
        for(j=i+1; j<4; j++)
        {
            if( contador[i] > contador[j] || flag == 0)
            {
                maximo = i;
                flag = 1;
            }
        }
    }
    cargarDescripcionMarca(descripcion, marcas[maximo].id, marcas, 4);
    printf("LA MARCA QUE MAS SE VENDE ES %s\n",descripcion);

}


void informarTrabajosSobreNotebook(eNotebook* notebook,int tamnot, int cantnot, eTrabajo* trabajo,int tamtrab, eMarca* marca, eTipo* tipo, eServicio* servicios, eCliente* cliente)
{
    int idNotebook;
    int i;
    system("cls");
    int flag = 0;

    imprimirNotebooks(notebook,tamnot,marca,tipo,cliente);
    utn_getNumero(&idNotebook,"Ingrese el ID de la notebook: ","ERROR\n\n",1,cantnot,2);
    printf("\nIDNOTEBOOK     MODELO         SERVICIO       FECHA\n");

    for(i=0;i<tamnot;i++)
    {
        if(notebook[idNotebook].isEmpty == 0)
        {
            if(trabajo[i].idNotebook == idNotebook)
            {
                listarUnTrabajo(trabajo[i],tamtrab,servicios,4,notebook,tamnot);
                flag = 1;
            }
        }
    }
    if(flag==0)
    {
        printf("\nNO HAY TRABAJOS SOBRE ESA NOTEBOOK\n\n");
    }
}



