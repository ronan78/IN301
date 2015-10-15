#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
typedef struct element Element;
struct element
{
    int val;
    struct element *suivant;
};
 
typedef Element* List;

int alea (int n)
{
	int res;
	res = rand() % n;
	return res;
	
}

void afficherListe(List liste)
{
    Element *tmp = liste;
    while(tmp != NULL)
    {
        printf("[%d]\n ", tmp->val);
        tmp = tmp->suivant;
    }
}

void libere(List l)
{ 
	if(l != NULL)
	{ 
		libere(l->suivant); 
		free(l); 
	} 
}

List ajouterEnTete(List liste, int valeur)
{
    Element* nouvelElement = malloc(sizeof(Element));
    nouvelElement->val = valeur;
    nouvelElement->suivant = liste;

    return nouvelElement;
}

List ajouterEnFin(List liste, int valeur)
{
    Element* nouvelElement = malloc(sizeof(Element));
    nouvelElement->val = valeur;
    nouvelElement->suivant = NULL;
 
    if(liste == NULL)
    {
        return nouvelElement;
    }
    else
    {
        Element* temp=liste;
        while(temp->suivant != NULL)
        {
            temp = temp->suivant;
        }
        temp->suivant = nouvelElement;
        return liste;
    }
}

List ajoutcontenu(List liste)
{
	int n;
	n = alea (50);
	while (n != 0)
	{
		liste = ajouterEnFin(liste,n);
		n = alea (50);
	}
	return liste;
}

void trier(List la)
{
   List temp, temp1, temp3;
   int min;
   for(temp=la ; temp!=NULL ; temp=temp->suivant)
   {
     temp3=temp;
     min=temp->val;
     for(temp1=temp->suivant ; temp1!=NULL ; temp1=temp1->suivant)
     {
        if(min > temp1->val)
        {
           temp3=temp1; 
           min=temp3->val;
        }
     }
     temp3->val=temp->val;
     temp->val=min;
   }
}

void compte_elements(List liste)
{
	 Element* temp=liste;
	 int n;
     while(temp->suivant != NULL)
     {         
		temp = temp->suivant;
		n++;
     }
     printf("Le nombre d'éléments est: %d",n);
}

List rechercherElement(List liste, int valeur)
{
    Element *tmp=liste;
    while(tmp != NULL)
    {
        if(tmp->val == valeur)
        {
            return tmp;
        }
        tmp = tmp->suivant;
    }
    return NULL;
}

List supprimerElementEnTete(List liste)
{
    if(liste != NULL)
    {
        Element* aRenvoyer = liste->suivant;
        free(liste);
        return aRenvoyer;
    }
    else
    {
        return NULL;
    }
}

List concatenation (List l1, List l2)
{
	if (l1 == NULL) return l2;
	else l1->suivant = concatenation(l1->suivant,l2);
	return l1;
}

int main ()
{
	srand(time(NULL));
	List liste1 = NULL;
	List liste2 = NULL;
	
	/*liste = ajouterEnTete(liste,5);
	liste = ajouterEnFin(liste,12);
	liste = ajoutcontenu(liste);
	trier(liste);
	liste = supprimerElementEnTete(liste);
	liste = rechercherElement(liste,5);
	printf("\nL'adresse de l'element recherché est %p\n",liste);*/
	
	liste1 = ajoutcontenu(liste1);
	trier(liste1);
	liste2= ajoutcontenu(liste2);
	trier(liste2);
	liste1 = concatenation(liste1,liste2);
	
	afficherListe (liste1);
	//compte_elements(liste);
	
	libere(liste1);
	libere(liste2);
	
	return 0;
}
