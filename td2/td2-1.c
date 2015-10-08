#include <stdio.h>

/*void affichage ()
{
	printf("char : %d octets\n", sizeof(char));
	printf("int : %d octets\n", sizeof(int));
	printf("double : %d octets\n", sizeof(double));
	printf("char*: %d octets\n", sizeof(char*));
	printf("void : %d octets\n", sizeof(void));
	printf("int : %d octets\n", sizeof(int*));
	printf("double* : %d octets\n", sizeof(double*));
	printf("int** : %d octets\n", sizeof(int**));
	printf("int[10] : %d octets\n", sizeof(int[10]));
	printf("char[7][3] : %d octets\n", sizeof(char[7][3]));
	//printf("int[] : %d octets\n", sizeof(int[]));
}*/

void echange(int *x, int *y)
{ 
	int z = *y; 
	*y = *x; 
	*x = z; 
}

void reinitPointeur(int **p)
{
	*p = NULL;
}

int main ()
{
	int a;
	a = 1;
	int *p = &a;
	reinitPointeur(&p);
	printf("l’adresse de p est %p\n", p);
	
	return 0;
}
