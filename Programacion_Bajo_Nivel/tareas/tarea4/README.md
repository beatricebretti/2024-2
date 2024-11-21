# Tarea 4
Beatrice Valdés 

## Descripción
- Implementación de una librería compartida en c++ que usa la _criba de eratostenes_ para contar los números primos menores o iguales a un numero dado. 

- Ademas incluye un programa principal en c++ y un script en python que consume esta librería.

## Estructura del proyecto
- `criba.h` y `criba.cpp`: implementación de la función `criba` para contar números primos
- `main.cpp`: programa principal que utiliza la librería
- `criba.i`: archivo de interfaz para generar el binding con python
- `Makefile`: archivo para compilar y generar la librería y el ejecutable
- `script.py`: script en python para usar la librería compartida.

## Requisitos
- Python 3.x y SWIG instalado.

## Pasos de ejecución (en orden)
1. Compilacion y ejecución en c++
```
make run
```
2. Compilación de librería para python
```
make python
```
3. Ejecución del script de python
```
python3 script.py
```

## Consideraciones
- Asegúrate de que la librería `libcriba.so` esté generada correctamente y esté en el directorio adecuado. Si no está presente, ejecuta:
```
make lib
```
- El make python genera el `criba_wrap.cxx` si no se genera ejecuta:
```
make wrap
```
- Si opython no puede encontrar `_libcriba.so` puedes añadir el directorio actual a la variable de entorno PYTHONPATH:
```
export PYTHONPATH=$PYTHONPATH:$(pwd)
python3 script.py
```