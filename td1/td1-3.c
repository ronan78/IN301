#include <stdio.h>

int main ()
{
	int x,r,y,resultat;
	printf("Rentre le premier chiffre: ");
	scanf("%d",&x);
	
	printf("Rentre le deuxieme chiffre: ");
	scanf("%d",&y);
	
	printf("%d * %d\n",x,y);
	r=0;
	resultat= x*y;
	while (x!=1)
	{
		if (x%2==0)
		{
			x=x/2;
			printf("= %d *",x);
			y=2*y;
			printf("%d + %d \n",y,r);
		}
		else 
		{
			x=x-1;
			printf("= %d * %d",x,y);
			r=r+y;
			printf(" + %d \n",r);
		}
	}
	printf("le resultat est %d",resultat);
	return 0;
}
