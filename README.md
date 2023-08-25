<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# TP0

## Repositorio de Santiago Henseler - 110732 - shenseler@fi.uba.ar

##  Enunciado

El propósito de este TP es que practiquen la metodología de entrega que será utilizada a lo largo del cuatrimestre. También debería servira para que se saquen todas las dudas acerca de cómo compilar y ejecutar programas en **C**.

En esta oportunidad el objetivo del trabajo es lograr parsear un string y llenar una estructura basándose en el mismo.  Se brinda un archivo `tp0.c` que contiene el código base de la aplicación. Se debe completar la función `parsear_ataque` que es la encargada de justamente realizar el parseo. Dicha función recibe un string que representa un ataque de un Pokemon dividido en 3 partes separadas por '`;`'. Por ejemplo `Lanzallamas;F;4` representa un ataque con nombre `Lanzallamas`, del tipo `F` (fuego) y poder de ataque 4. La función entonces debe determinar si las 3 partes están presentes en el string. En caso de no estarlo (o en el caso de que el formato sea inválido, por ejemplo que el poder de ataque no sea un número), se debe retornar NULL. En caso de que los datos sean correctos, se deben completar los datos de la estructura pasada mediante puntero y devolver el puntero.

### Tipos de ataque
La segunda parte del string contiene un caracter que debe ser convertido a un tipo de ataque según la siguiente tabla:

| Caracter  | Tipo |
| --- | --- |
| N  | NORMAL |
| F  | FUEGO |
| A  | AGUA  |
| P  | PLANTA |
| E  | ELECTRICO |
| R  | ROCA |
