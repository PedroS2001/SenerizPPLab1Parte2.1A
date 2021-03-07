#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    float precio;

}eServicio;

#endif // SERVICIO_H_INCLUDED

void listarServicios(eServicio* servicio, int tam);
int cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tam);

