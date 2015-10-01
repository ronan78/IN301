#include <stdio.h>

int main ()
{
	int n,m,i,d1,d2;
	printf("Rentré votre premier nombre: ");
	scanf("%d",&n);
	printf("\nRentré votre deuxieme nombre: ");
	scanf("%d",&m);
	
	for (i=1;i<=n;i++)
	{
		if (n%i == 0) d1 = d1 +i;
	}
	for (i=1;i<=m;i++)
	{
		if (m%i == 0) d2 = d2 + i;
	}

	if (d1 == d2) printf("\n%d et %d sont des nombres amis",n,m);
	else printf("\n%d et %d ne sont pas des nombres amis",n,m);
	
	return 0;
}
