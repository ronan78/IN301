#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>

int estInt (char* t)
{
	int i=0;
	while (t[i] != '\0')
	{
		if (!isdigit(t[i])) return 0;
		i++;
	}
	if (i == 0) return 0;
	return 1;
}

int somme (char **argv, int argc)
{
	int i;
	double somme = 0;
	for (i=1; i<argc ; i++)
	{
		if (!estInt (argv[i]))
		{
			printf("ERREUR\n");
			exit(EXIT_FAILURE);
		}
		somme += atof(argv[i]);
	}
	return somme;
}

int main( int argc, char** argv)
{
	int compteur;
	compteur = somme(argv, argc);
	printf("%d\n", compteur);
	return 0;
}
