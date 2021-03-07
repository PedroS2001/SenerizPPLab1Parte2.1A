#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED
#include "marca.h"
#include "tipo.h"
#include "cliente.h"


typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int idCliente;
    int isEmpty;
}eNotebook;

#endif // NOTEBOOK_H_INCLUDED

void inicializarNotebooks(eNotebook* notebook, int tam);
int imprimirNotebook(eNotebook notebook, eMarca* marca, eTipo* tipo, eCliente* cliente);
void imprimirNotebooks(eNotebook* notebook, int tam,eMarca* marca, eTipo* tipo, eCliente* cliente);
void ordenarNotebooksPorMarcaYPrecio(eNotebook* notebook,int len,eMarca* marca);
void ordenarXID(eNotebook* notebook,int len, eMarca* marca);

void altaNotebook(eNotebook* notebookNueva, eNotebook datosNotebook, int id);
void modificarNotebook(eNotebook* notebook, int tam, eTipo* tipo, eMarca* marca, int idNotebook, eCliente* cliente);
void bajaNotebook(eNotebook* notebook, int tam, eMarca* marca, eTipo* tipo, int idNotebook, eCliente* cliente);


int cargarModeloNotebook(char descripcion[], int id, eNotebook notebook[], int tam);

