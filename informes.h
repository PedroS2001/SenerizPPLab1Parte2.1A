#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "fecha.h"
#include "marca.h"
#include "tipo.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"
#include "utn.h"
#include "cliente.h"

#endif // INFORMES_H_INCLUDED

void sumaServicesNotebook(eNotebook* notebook,int tamnot,int cantnot, eTrabajo* trabajos, int tamtrab, eServicio* servicios, eTipo* tipos, eMarca* marcas, eCliente* cliente);

void informarNotebooksDeUnTipo(eNotebook* notebook, int tamnot, eTipo* tipos, eMarca* marcas, int tipoID, eCliente* cliente);
void informarNotebooksDeUnaMarca(eNotebook* notebook, int tamnot, eMarca* marca, eTipo* tipo, int idMarcaBuscar, eCliente* cliente);
void informarNotebookMasBarata(eNotebook* notebook,int tamnot,eTipo* tipos, eMarca* marcas, eCliente* clientes);
void informarNotebooksXMarca(eNotebook* notebook, int tamnot, eMarca* marcas, eTipo* tipos, eCliente* cliente);
void informarNotebooksTipoYMarca(eNotebook* notebook, int tamnot, eTipo* tipos, eMarca* marcas, eCliente* cliente);
void informarLaMarcaMasElegida(eNotebook* notebook, int tamnot, eTipo* tipos, eMarca* marcas, eCliente* cliente);

void informarTrabajosSobreNotebook(eNotebook* notebook,int tamnot, int cantnot, eTrabajo* trabajo,int tamtrab, eMarca* marca, eTipo* tipo, eServicio* servicios, eCliente* cliente);

