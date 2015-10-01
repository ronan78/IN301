#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//fonction factorielle
int factorielle(int x){
  int res,i;
  res=1;
  i=1;
  if(x == 0) return 0;
  while(x >= 1){
	res = res * i;
	i++;
	printf("\n%d\n",res);
	x = x-1;
	printf("%d\n",x);
  }
  return res;
}

//fonction somme
int somme(int x){
  int res = 0;
  int i = 0;
  while(i <= x){
    i++;       //incrementation 
    res += i-1; //fin de boucle 
  }
  return res;
}

//fonction maximum
int maximum(int x, int y){
  if(y > x)
    return y;
  else 
    return x;
}

//fonction principale
int main(){
  int a, b;

  srand(time(NULL));
  a =3; //rand() % 8 + 2;
  b = factorielle(a);
  printf("\nFactorielle de %d vaut %d\n\n", a, b);
  
  a = rand() % 100;
  b = somme(a);
  printf("\nLa somme des entiers de 1 a %d vaut %d\n\n", a, b);

  a = rand() % 100;
  b = rand() % 100;
  printf("\nLe maximum entre %d et %d vaut %d\n\n", a, b, maximum(a,b));
  
  return 0;
}
