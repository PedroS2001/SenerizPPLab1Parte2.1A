#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eMarca;

#endif // MARCA_H_INCLUDED

void listarMarcas(eMarca* marca, int tam);
int cargarDescripcionMarca(char descripcion[], int id, eMarca marcas[], int tam);
