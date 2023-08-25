#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum TIPO { NORMAL, FUEGO, AGUA, PLANTA, ELECTRICO, ROCA };

struct ataque {
	char nombre[20];
	enum TIPO tipo;
	unsigned int poder;
};

struct ataque *parsear_ataque(char *texto, struct ataque *ataque)
{
	//completar esta función según lo pedido en el enunciado

	return NULL;
}

int main()
{
	struct ataque un_ataque;
	int errores = 0;

	if (parsear_ataque("", &un_ataque) != NULL) {
		printf("Se espera que no se pueda parsear un string vacío D:\n");
		errores++;
	} else
		printf("Parseo de un string vacío 👍\n");

	if (parsear_ataque("Rayo;E;", &un_ataque) != NULL) {
		printf("Se espera que no se pueda parsear un string incorrecto D:\n");
		errores++;
	} else
		printf("Parseo de un string incorrecto 👍\n");


	if (parsear_ataque("Rayo;E;5", &un_ataque) == NULL) {
		printf("Se espera que se pueda parsear un string correcto D:\n");
		errores++;
	} else if (strcmp(un_ataque.nombre, "Rayo") == 0 &&
		 un_ataque.tipo == ELECTRICO && un_ataque.poder == 5) {
		printf("Parseo de un string correcto 👍\n");
	} else {
		printf("Se parseó el string pero los valores son incorrectos 🤔\n");
		errores++;
	}

	return errores;
}
