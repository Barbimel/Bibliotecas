//IFNDEF_______________________________________________________________________________________________________________________________

//ESTRUCTURAS__________________________________________________________________________________________________________________________

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int socioId;
    char apellido[31];
    char nombre[31];
    char sexo;
    char telefono[16];
    char eMail[31];
    eFecha asociado;

    int state;

}eSocios;

typedef struct
{
    int prestamoId;
    int libroId;
    int socioId;
    eFecha prestamo;

    int state;

}ePrestamos;

typedef struct
{
    int codigoLibro;
    char titulo[51];
    int codigoAutor;
    int state;

}eLibros;

typedef struct
{
    int codigoAutor;
    char apellido[31];
    char nombre[31];
    int state;

}eAutores;

//PROTOTIPOS___________________________________________________________________________________________________________________________
/** \brief recorre un vector estructura y setea los campos "state" en 0.
 * \param array[]: es el vector estructura a recorrer.
 * \param size: es el tamaño del vector antes recibido.
 * \return void. */

 void iniciarSocios(eSocios array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre un vector en busca de un registro, partiendo de su ID.
 * \param array: es el vector en el que busca el registro.
 * \param size: es el tamaño del vector a recorrer.
 * \param id: Nro. de legajo a buscar en el vector.
 * \return devuelve la ubicacion del registro, si no lo encuentra devuelve -1. */

int buscarSocio(eSocios array[], int size, int id);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre y ordena de forma ascendente la lista de registros activos.
 * \param array: es el vector a ordenar.
 * \param size: es el tamaño del vector antes recibido.
 * \return void. */

void ordenarSocios(eSocios array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre un vector e imprime una registro activo.
 * \param array: es el vector en el que busca el registro.
 * \param size: es el tamaño del vector a recorrer.
 * \return void. */

void mostrarSocio(eSocios array[], int size, int id);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre un vector e imprime una lista de los registros activos.
 * \param array: es el vector en el que busca los registros.
 * \param size: es el tamaño del vector a recorrer.
 * \return void. */

void mostrarSocios(eSocios array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief recorre un vector buscando espacio disponible para un nuevo registro.
 * \param array: es el vector en el que busca espacio.
 * \param size: es el tamaño del vector a recorrer.
 * \return devuelve 0 cuando encuentra un espacio libre, si no lo hay retorna -1. */

int sociosLibres(eSocios array[],int size);
//_____________________________________________________________________________________________________________________________________

/** \brief gestiona el alta de un nuevo registro.
 * \param array: es el vector donde almacenaremos la informacion del nuevo registro.
 * \param size: es el tamaño vector antes recibido.
 * \return void. */

void altaSocio(eSocios array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief gestiona la modificacion de un registro activo.
 * \param array: es el vector que recorre en busca del registro a modificar.
 * \param size: es el tamaño del vector a recorrer.
 * \return void. */

void modificarSocio(eSocios array[], int size);
//_____________________________________________________________________________________________________________________________________

/** \brief gestiona la baja de un registro activo.
 * \param array: es el vector en el que busca el registro.
 * \param size: es el tamaño del vector antes recibido.
 * \return void. */

void bajaSocio(eSocios array[],int size);
//_____________________________________________________________________________________________________________________________________


