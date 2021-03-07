#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;


#endif // TIPO_H_INCLUDED
void listarTipos(eTipo* tipo, int tam);
int cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tam);
