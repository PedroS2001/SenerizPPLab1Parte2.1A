#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fecha.h"
#include "marca.h"
#include "tipo.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"
#include "utn.h"
#include "cliente.h"
#include "datawarehouse.h"
#include "informes.h"

#define TAMNOTE 20
#define TTRABAJO 20
#define CANTHARD 15
#define TAMCLIENTE 5

char menu();
int menuInformes();

void hardcodearTrabajos(eTrabajo* trabajos, int tam);
int hardcodearNotebooks(eNotebook* notebook, int cant);



int main()
{
    eNotebook notebook[TAMNOTE];
    eTrabajo trabajo[TTRABAJO];
    eMarca hMarcas[] = {{1000,"Compaq"},{1001,"Asus"},{1002,"Acer"},{1003,"HP"} };
    eTipo hTipos[] = {{5000,"Gamer"},{5001,"Disenio"},{5002,"Ultrabook"},{5003,"Normalita"} };
    eServicio hServicios[] = {{20000,"Bateria",250},{20001,"Antivirus",300},{20002,"Actualizacion",400},{20003,"Fuente",600}};
    eCliente cliente[TAMCLIENTE] = {{1,"Pedro",'m'},{2,"Juanita",'f'},{3,"Maria",'f'}, {4,"Jose",'m'},{5,"Noelia",'f'} };

    eNotebook auxNotebook;
    eTrabajo auxTrabajo;

    int flagAltas = 0;
    char rtamenu;
    int rtainformes;
    int idNotebook = 1;
    int idTrabajo = 1;
    int ayudanteEntero;

    inicializarTrabajos(trabajo,TTRABAJO);
    inicializarNotebooks(notebook,TAMNOTE);

    hardcodearNotebooks(notebook,CANTHARD);
    flagAltas = 1;
    idNotebook += CANTHARD;
    hardcodearTrabajos(trabajo,5);
    idTrabajo+=5;


    do
    {
        rtamenu = menu();
        switch(rtamenu)
        {
        case 'a':
            if(idNotebook <= TAMNOTE)
            {
                system("cls");
                printf("***ALTA NOTEBOOK***\n\n");
                printf("ID %d\n",idNotebook);
                if(utn_getNombre(auxNotebook.modelo,20,"Ingrese modelo de la notebook: ","Error",2) == -1)
                {
                    printf("ALTA INTERRUMPIDA\n");
                    printf("\nError al ingresar el modelo\n\n");
                    break;
                }
                if(utn_getNumero(&auxNotebook.idCliente, "Ingrese el ID del cliente: ", "Ese cliente no esta registrado\n\n",1,5,2 ) == -1)
                {
                    printf("ALTA INTERRUMPIDA\n");
                    printf("\nError al ingresar el id del cliente\n\n");
                }

                listarMarcas(hMarcas,4);
                if(utn_getNumero(&auxNotebook.idMarca,"Ingrese el id de la marca de la notebook: ","Error\n",1000,1003,2) == -1)
                {
                    printf("ALTA INTERRUMPIDA\n");
                    printf("\nError al ingresar la marca\n\n");
                    break;
                }

                listarTipos(hTipos,4);
                if(utn_getNumero(&auxNotebook.idTipo,"Ingrese el id del tipo de la notebook: ","Error\n",5000,5003,2) == -1)
                {
                    printf("ALTA INTERRUMPIDA\n");
                    printf("\nError al ingresar el tipo\n\n");
                    break;
                }

                if(utn_getNumeroFlotante(&auxNotebook.precio,"Ingrese precio de la notebook: ","Error\n",1,99999.9,2 ) == -1)
                {
                    printf("ALTA INTERRUMPIDA\n");
                    printf("\nError al ingresar el precio\n\n");
                    break;
                }
                altaNotebook(notebook, auxNotebook, idNotebook);

                idNotebook++;
                flagAltas = 1;
                printf("\nSE DIO DE ALTA UNA NOTEBOOK\n\n");
            }
            else
            {
                printf("\nNO HAY LUGAR DISPONIBLE\n\n");
            }
            break;
        case 'b':
            if(flagAltas)
            {
                modificarNotebook(notebook,TAMNOTE,hTipos,hMarcas,idNotebook,cliente);
            }
            else
            {
                printf("Primero hay que dar una notebook de alta\n");
            }
            break;
        case 'c':
            if(flagAltas)
            {
                bajaNotebook(notebook,TAMNOTE,hMarcas,hTipos, idNotebook,cliente);
            }
            else
            {
                printf("Primero hay que dar una notebook de alta\n");
            }
            break;
        case 'd':
            system("cls");
            printf("***NOTEBOOKS***\n");
            if(flagAltas)
            {
                ordenarNotebooksPorMarcaYPrecio(notebook,TAMNOTE,hMarcas);
                imprimirNotebooks(notebook, TAMNOTE, hMarcas, hTipos, cliente );
                ordenarXID(notebook,TAMNOTE,hMarcas);
            }
            else
            {
                printf("Primero hay que dar una notebook de alta\n");
            }
            break;
        case 'e':
            system("cls");
            printf("***MARCAS***\n");
            listarMarcas(hMarcas,4);
            break;
        case 'f':
            system("cls");
            printf("***TIPOS***\n");
            listarTipos(hTipos,4);
            break;
        case 'g':
            system("cls");
            printf("***SERVICIOS***\n");
            listarServicios(hServicios,4);
            break;
        case 'h':
            system("cls");
            printf("***ALTA TRABAJO***\n");
            printf("%d\n\n",idTrabajo);
            imprimirNotebooks(notebook,TAMNOTE,hMarcas,hTipos,cliente);
            if(utn_getNumero(&auxTrabajo.idNotebook,"Ingrese el id de la notebook ", "Error\n", 1,idNotebook-1,2) == -1)
            {
                printf("ERROR AL CARGAR EL ID\n");
                break;
            }

            listarServicios(hServicios,4);
            if(utn_getNumero(&auxTrabajo.idServicio, "Ingrese el id del servicio ", "Error\n",20000,20003,2) == -1)
            {
                printf("ERROR AL CARGAR EL SERVICIO\n");
                break;

            }

            if(utn_getNumero(&auxTrabajo.fecha.dia,"Ingrese el dia: ", "Dia invalido\n",1,31,2) == -1)
            {
                printf("ERROR AL CARGAR EL DIA\n");
                break;

            }

            if(utn_getNumero(&auxTrabajo.fecha.mes,"Ingrese el mes: ", "Mes invalido\n",1,12,2)== -1)
            {
                printf("ERROR AL CARGAR EL MES\n");
                break;

            }

            if(utn_getNumero(&auxTrabajo.fecha.anio,"Ingrese el anio: ", "Anio invalido. Los registros van desde 2010 a 2020\n",2010,2020,2)== -1)
            {
                printf("ERROR AL CARGAR EL ANIO\n");
                break;

            }

            altaTrabajo(trabajo,auxTrabajo,idTrabajo);
            idTrabajo++;

            break;
        case 'i':
            if(idTrabajo > 1)
            {
                system("cls");
                printf("***TRABAJOS***\n\n");
                listarTrabajos(trabajo,TTRABAJO,hServicios,4, notebook, TAMNOTE);
            }
            else
            {
                printf("\nPRIMERO DEBE DAR DE ALTA ALGUN TRABAJO\n\n");
            }
            break;
        case 'j':
            rtainformes = menuInformes();
            switch(rtainformes)
            {
            case 1:
                listarTipos(hTipos,4);
                utn_getNumero(&ayudanteEntero,"Ingrese el ID del tipo que desea informar: ","ERROR\n\n",5000,5003,2);
                informarNotebooksDeUnTipo(notebook,TAMNOTE,hTipos,hMarcas,ayudanteEntero,cliente);
                break;
            case 2:
                listarMarcas(hMarcas,4);
                utn_getNumero(&ayudanteEntero,"Ingrese el ID de la marca que desea informar: ", "ERROR\n\n",1000,1003,2);
                informarNotebooksDeUnaMarca(notebook,TAMNOTE,hMarcas,hTipos,ayudanteEntero,cliente);
                break;
            case 3:
                informarNotebookMasBarata(notebook,TAMNOTE,hTipos,hMarcas,cliente);
                break;
            case 4:
                informarNotebooksXMarca(notebook,TAMNOTE,hMarcas,hTipos,cliente);
                break;
            case 5:
                informarNotebooksTipoYMarca(notebook,TAMNOTE,hTipos,hMarcas,cliente);
                break;
            case 6:
                informarLaMarcaMasElegida(notebook,TAMNOTE,hTipos,hMarcas,cliente);
                break;
            case 7:
                informarTrabajosSobreNotebook(notebook,TAMNOTE,idNotebook-1,trabajo,TTRABAJO,hMarcas,hTipos,hServicios,cliente);
                break;
            case 8:
                sumaServicesNotebook(notebook,TAMNOTE,idNotebook-1,trabajo,TTRABAJO,hServicios,hTipos,hMarcas,cliente);
                break;
            case 9:
                notebooksUnServicio(notebook,idNotebook-1,hMarcas,hTipos,cliente,hServicios,trabajo,TTRABAJO);
                break;
            }

            break;
        case 'k':
            printf("Saliendo\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(rtamenu != 'k');



    return 0;
}

char menu()
{
    char respuesta;

    printf("****MENU****\n\n");
    printf("a)ALTA NOTEBOOK\n");
    printf("b)MODIFICAR NOTEBOOK\n");
    printf("c)BAJA NOTEBOOK\n");
    printf("d)LISTAR NOTEBOOKS POR MARCA Y PRECIO\n");
    printf("e)LISTAR MARCAS\n");
    printf("f)LISTAR TIPOS\n");
    printf("g)LISTAR SERVICIOS\n");
    printf("h)ALTA TRABAJO\n");
    printf("i)LISTAR TRABAJOS\n");
    printf("j)MENU DE INFORMES\n");
    printf("k)SALIR\n");
    utn_getCaracter(&respuesta,"Que desea hacer? ","Error. Asegurese que la letra este en minusculas\n",'a','k',2);

    return respuesta;
}

int menuInformes()
{
    int opcion;

    system("cls");

    printf("*** MENU DE INFORMES ***\n\n");
    printf("1) Informar las notebooks de un tipo \n");
    printf("2) Informar las notebooks de una marca \n");
    printf("3) Informar la/s notebook/s mas barata/s \n");
    printf("4) Informar las notebooks separadas por marca \n");
    printf("5) Elegir Tipo y Marca y contar cuantas notebooks hay de ese tipo y marca \n");
    printf("6) Informar la marca mas elegida \n");
    printf("7) Informar Trabajos sobre una notebook \n");
    printf("8) Informar la suma de los importes de los services sobre una notebook \n");
    printf("9) Pedir un servicio y mostrar las notebooks a las que se realizó ese servicio y la fecha  \n");


    printf("11) Salir\n\n");
    utn_getNumero(&opcion,"Seleccione una opcion: ", "ERROR\n\n",1,11,2);

    return opcion;
}


void hardcodearTrabajos(eTrabajo* trabajos, int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        trabajos[i].id = hTrabajoId[i];
        trabajos[i].idNotebook = hTrabajoIdNotebook[i];
        trabajos[i].idServicio = hTrabajoIdServicio[i];
        trabajos[i].fecha.dia = hTrabajoDias[i];
        trabajos[i].fecha.mes = hTrabajoMeses[i];
        trabajos[i].fecha.anio = hTrabajoAnios[i];
        trabajos[i].isEmpty = 0;
    }
}

/** \brief hardcodea una cantidad X de notebooks
 *
 * \param estructura de notebooks
 * \param cantidad que quiero hardcodear
 * \return
 *
 */

int hardcodearNotebooks(eNotebook* notebook, int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        notebook[i].id = hardodeIds[i];
        strcpy(notebook[i].modelo, hardcodeModelos[i]);
        notebook[i].idMarca = hardcodeIdMarca[i];
        notebook[i].idTipo = hardcodeIdTipo[i];
        notebook[i].precio = hardcodePrecios[i];
        notebook[i].idCliente = hardcodeIdClientes[i];
        notebook[i].isEmpty = 0;
    }
    return 0;
}

