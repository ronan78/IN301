#include <stdio.h>

int main ()
{
	int i,s,m,h;
	printf("Entre le nombre de secondes: ");
	scanf("%d",&i);
	if (i>59)
	{
		m=i/60;
		s=i-m*60;
		if (m>59)
		{
			h=m/60;
			m=m-h*60;
		}
	}
	printf("%d secondes correspond à ",i);
	
	if (h>=1) 
	{
		if (h==1) printf("%d heure ",h);
		else printf("%d heures",h);
	}
	
	if (m==1) printf("%d minute ",m);
	else printf("%d minutes ",m);
	
	printf("%d secondes ",s);
	
	return 0;
}
