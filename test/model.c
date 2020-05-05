#include<stdlib.h>
#include <time.h>
#include<stdio.h>

void afisare (int a[], int N)
{
  int i;
  printf ("\n");
  for (i = 0; i < N; i++)
    {
      printf ("%d ", a[i]);
    }
  printf ("\n");
}


void load_tab (int a[], int N)
{
  time_t t;
  int i;
  srand ((unsigned) time (&t));
  for (i = 0; i < N; i++)
    a[i] = rand () % 100;
}


void selectie (int a[], int N)
{
  int i, j, x_min, k_min;
  for (i = 0; i < N; i++)
    {
      x_min = a[i];
      k_min = i;
      for (j = i + 1; j < N; j++)
	{
	  if (a[j] < x_min)
	    {
	      x_min = a[j];
	      k_min = j;
	    }
	}
      a[k_min] = a[i];
      a[i] = x_min;
    }
}

int main ()
{
  int N;
  int a[20];
  N = 10;
  load_tab(a,N);
  afisare(a,N);
  selectie(a,N);
  afisare(a,N);
  return 0;
}