#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//defino las constantes
#define COMA ';'

enum TIPO { NORMAL, FUEGO, AGUA, PLANTA, ELECTRICO, ROCA };

struct ataque {
	char nombre[20];
	enum TIPO tipo;
	unsigned int poder;
};

void definir_nombre(char *texto, int tope, char nombre[]){

    for(int i = 0; i < tope; i++){
        nombre[i] = texto[i];
    }
    
}

int definir_poder(char *texto, int i, int tope){

    char aux[tope-i];

    int k = 0;

    for(i; i < tope; i++){
        aux[k] = texto[i];
        k++;
    }

    int rta = atoi(aux);

    return rta;
}

enum TIPO definir_tipo(char texto){

    enum TIPO tipo = -1;

    if(texto == 'N'){
        tipo = NORMAL;
    }else if(texto == 'F'){
        tipo = FUEGO;
    }else if(texto == 'A'){
        tipo = AGUA;
    }else if(texto ==  'P'){
        tipo = PLANTA;
    }else if(texto == 'E'){
        tipo = ELECTRICO;
    }else if(texto == 'R'){
        tipo = ROCA;
    }

    return tipo;
}

struct ataque *parsear_ataque(char *texto, struct ataque *ataque){
	
    int tope = (int)strlen(texto);
    int separaciones = 0;

    for(int i = 0;i < tope && separaciones < 2; i++){

        if(texto[i] == COMA && separaciones == 0){
            definir_nombre(texto, i, ataque->nombre);
            separaciones++;
        }else if(texto[i] == COMA && separaciones == 1){

            ataque->tipo = definir_tipo(texto[i-1]);

            ataque->poder = definir_poder(texto, i+1, tope);

            separaciones++;
        }

    }

    if(strlen(ataque->nombre) < 1 || ataque->poder < 1 || ataque->tipo < 0){
        return NULL;
    }else{
        return ataque;
    }

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
