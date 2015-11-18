#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>

typedef struct element Element;
struct element
{
    char val;
    struct element *suivant;
};
 
typedef Element* ListeC;

void afficherListe(ListeC liste)
{
    Element *tmp = liste;
    printf("\n");
    while(tmp != NULL)
    {
			printf("%c", tmp->val);
			tmp = tmp->suivant;
    }
    printf("\n");
}

ListeC ajout (ListeC l, char c)
{
	if (l == NULL)
	{
		Element* pElt = malloc(sizeof(Element));
		pElt->val = c;
		pElt->suivant = l;
		l = pElt;
	}
	else l->suivant = ajout(l->suivant,c);
	return l;
}

ListeC ajoutChaine(char* t, ListeC l)
{
    if (t[0] == '\0') return NULL;
    l= ajout(l,t[0]);
    l->suivant = ajoutChaine(t+1,l->suivant);
    return l;
}

void remplitMot(char** argv, int argc, char* t, ListeC* l)
{
	int i;
	if (argc != 3) exit(EXIT_FAILURE);
	for (i=0; argv[1][i] !='\0'; i++)
	{
		t[i] = argv[1][i];
	}
	*l = ajoutChaine(argv[2],*l);
}
int ordre_lexicographique(char* t, ListeC l)
{
	if (l == NULL) return !(t[0] == '\0');
	if (l->val < *t) return 1;
	else if (l->val > *t) return -1;
	else return ordre_lexicographique(t+1,l->suivant);
} 

int main( int argc, char* argv[])
{
	char* t= malloc((strlen(argv[1]+1)*sizeof(char)));
	ListeC l = NULL;
	l = ajoutChaine(argv[1], l);
	remplitMot(argv,argc,t,&l);
	printf("%d\n", ordre_lexicographique(t,l));
	
	return 0;
}
