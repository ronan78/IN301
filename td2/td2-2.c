#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Tableau {
	int taille;
	int tab[100];
};

int alea (int n)
{
	int res;
	res = rand() % n;
	return res;
	
}

typedef struct Tableau Tableau;

Tableau initialise (Tableau tableau) 
{
	int i;
	tableau.taille = 10;
	for (i=0;i<tableau.taille;i++)
	{
		tableau.tab[i] = alea(20)+1;
	}
	
	return tableau;
}

Tableau decalage(Tableau tab)
{
	tab.taille = tab.taille + 1;
    int courant=0, suivant=0, temp=0;
    int tampon=tab.tab[tab.taille-1]; 
    for (courant=0; courant < tab.taille; courant+=2) 
    {
        suivant = (courant+1) % tab.taille; 
        temp=tab.tab[suivant]; 
        
        tab.tab[suivant]=tab.tab[courant]; 
        tab.tab[courant]=tampon; 
        tampon = temp;
    }
    tab.tab[0]=0;
    return tab;
}
	
Tableau tri(Tableau tab)
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    for(i=0; i<=tab.taille ; i++)
    {
        for(j=i; j<=tab.taille; j++)
        {
            if(tab.tab[j]<tab.tab[i]){
                tmp = tab.tab[i];
                tab.tab[i] = tab.tab[j];
                tab.tab[j] = tmp;
            }
        }
    }
    return tab;
}

Tableau insertion (Tableau tab)
{
	tab.taille = tab.taille + 1;
	tab.tab[tab.taille]= alea(20) ;
	tab = tri (tab);
	return tab;
}

Tableau inverseTableau(Tableau tab)
{
	int i = 0, temp = 0;
	for (i = 0 ; i < tab.taille / 2 ; i++)
	{
		temp = tab.tab[i];
		tab.tab[i] = tab.tab[tab.taille - i - 1];
		tab.tab[tab.taille - i - 1] = temp;
	}
	return tab;
}

Tableau supprime (Tableau tab, int case_supp)
{
    int courant=0, suivant=0, temp=0;
    int tampon=tab.tab[tab.taille-1]; 
    for (courant=0; courant < case_supp; courant+=2) 
    {
        suivant = (courant+1) % tab.taille; 
        temp=tab.tab[suivant]; 
        
        tab.tab[suivant]=tab.tab[courant]; 
        tab.tab[courant]=tampon; 
        tampon = temp;
    }
	tab.taille = tab.taille - 1;
	
	return tab;
}

Tableau doublon(Tableau tab)
{
	int i;
	for (i=0;i<tab.taille-1;i++)
	{
		if (tab.tab[i] == tab.tab[i+1]) tab.tab[i] = -1; 
	}
	
	for (i=0;i<tab.taille;i++)
	{
		if (tab.tab[i] == -1) supprime(tab,i);
	}
	
	return tab;
}

int main ()
{
	srand(time(NULL));
	Tableau tab;
	tab = initialise(tab);
	int i;
	
	/*printf("taille: %d\n",tab.taille);
	
	double res;
	for (i=0;i<tab.taille;i++)
	{
		res = res*tab.tab[i];
	}
	printf("le produit des cases du tableau est: %d\n",res);
	
	int min;
	min=tab.tab[0];
	for (i=0;i<tab.taille;i++)
	{
		if (min < tab.tab[i]) min =tab.tab[i];
	}
	printf("la valeur minimale est: %d\n",min);*/
	
	
	tab = decalage(tab);
	
	tab = tri(tab);

	tab = insertion(tab);
	
	tab = inverseTableau(tab);
	
	int case_supp;
	case_supp = alea (tab.taille-1);
	tab = supprime(tab,case_supp);
	
	tab = doublon(tab);
	
	for (i=0;i<tab.taille;i++)
	{
		printf("cases %d:%d\n",i,tab.tab[i]);
	}
	
	return 0;
}
