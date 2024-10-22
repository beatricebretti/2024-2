typedef struct {
    char id[6];
    char tipo;
    int hora_llegada;
    int hora_salida;
} Vehiculo;

/* void mostrarMensajeLlegada(Vehiculo *vehiculo)
 * mostrar mensaje cuando llega un vehiculo
 * Parametros: Vehiculo *vehiculo, int tiempo_actual
 */
void mostrarMensajeLlegada(Vehiculo *vehiculo, int tiempo_actual);

/* void mostrarMensajeCarga(Vehiculo *vehiculo, int tiempo_actual)
 * mostrar mensaje cuando se carga un vehiculo
 * Parametros: Vehiculo *vehiculo, int tiempo_actual
 */
void mostrarMensajeCarga(Vehiculo *vehiculo, int tiempo_actual);

/* void mostrarMensajeZarpe(char ribera_origen, int tiempo_actual)
 * mostrar mensaje de zarpe del ferry
 * parametros: char ribera_origen, int tiempo_actual
 */
void mostrarMensajeZarpe(char ribera_origen, int tiempo_actual);

/* void mostrarMensajeLlegadaFerry(char ribera_destino, int tiempo_actual)
 * mostrar mensaje de llegada del ferry a la otra ribera
 * parametros: char ribera_destino, int tiempo_actual
 */
void mostrarMensajeLlegadaFerry(char ribera_destino, int tiempo_actual);

/* void mostrarMensajeDescarga(Vehiculo *vehiculo, int tiempo_actual)
 * mostrar mensaje cuando se descarga un vehiculo
 * Parametros: Vehiculo *vehiculo, int tiempo_actual
 */
void mostrarMensajeDescarga(Vehiculo *vehiculo, int tiempo_actual);

/* void mostrarCantidadVehiculosRibera(char ribera, int cantidad)
 * muestra cantidad total de vehiculos esperando en la fila
 * Parametros: char ribera, int cantidad
 */
void mostrarCantidadVehiculosRibera(char ribera, int cantidad);

/* void convertirTiempo(int minutos, char *resultado)
 * convierte tiempo al formatpo requerido
 * Parametros: int minutos, char *resultado
 */
void convertirTiempo(int minutos, char *resultado);
