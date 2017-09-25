/*********** Librerias utilizadas **************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
/***********************************************/
struct token{
	int posi;
	char c_lex[20];
	char d_lex[20];
};

typedef struct token token_t;
token_t tabla[50];
/***********************************************/

void limpiarTabla()
{
	int i;
	tabla[0].posi = 0;
	for(i=1;i<50;i++)
	{
		tabla[i].posi = -1;
	}
}

int verUltimo()
{
	int i;
	for(i=1;i<50;i++)
	{
		if(tabla[i].posi == -1)
		{
			break;
		}
	}	
	return i;
}
int buscar(char const *lexema)
{
	int i = 0;
	while (tabla[i].posi != -1)
	{
		/*strcmp*/
		if(strcmp(tabla[i].c_lex,lexema) == 0)
		{
			return tabla[i].posi;
			break;
		}
		i++;
	}	
	return 0;
}

void insertarLexemas(char const *c_lex_ac,char const *d_lex_ac)
{
	int ultimo = verUltimo();
	strcpy(tabla[ultimo].c_lex, c_lex_ac);
	strcpy(tabla[ultimo].d_lex, d_lex_ac);
	tabla[ultimo].posi = (int) verUltimo();
}

void minuscula(char *texto)
{
	unsigned int idx;
	for(idx=0;idx<strlen(texto);idx++)
		texto[idx]=tolower(texto[idx]);
}

void mayuscula(char *texto)
{
	unsigned int idx;
	for(idx=0;idx<strlen(texto);idx++)
		texto[idx]=toupper(texto[idx]);
}

void cargarLexemas()
{
	insertarLexemas("[","L_CORCHETE");
	insertarLexemas("]","R_CORCHETE");
	insertarLexemas("{","L_LLAVE");
	insertarLexemas("}","R_LLAVE");
	insertarLexemas(",","COMA");
	insertarLexemas(":","DOS_PUNTOS");
	insertarLexemas("string","STRING");
	insertarLexemas("number","NUMBER");
	insertarLexemas("true","PR_TRUE");
	insertarLexemas("false","PR_FALSE");
	insertarLexemas("null","PR_NULL");
	insertarLexemas("eof","EOF");
}

/*
LEXEMA 		COMPONENTE 		LÉXICO Expresión Regular
	[ 		L_CORCHETE 		[
	]		R_CORCHETE		]
	{ 		L_LLAVE 		{
	} 		R_LLAVE 		}
    , 		COMA 			,
	: 		DOS_PUNTOS 		:
	string 	LITERAL_CADENA 	" .* "
	number 	LITERAL_NUM 	[0-9]+(\.[0-9]+)?((e|E)(+|-)?[0-9]+)?
	true 	PR_TRUE 		true | TRUE
	false 	PR_FALSE 		false | FALSE
	null 	PR_NULL 		null | NULL
	eof 	EOF 			match con el fin de archivo
*/

/************* Definiciones ********************/

/***********************************************/
