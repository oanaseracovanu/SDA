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

void insertie (int a[], int N)
{
  int i, j, x;
  for (i = 1; i < N; i++)
    {
      j = i - 1;
      x = a[i];
      while (j >= 0 && x <= a[j])
	{
	  a[j + 1] = a[j];
	  j--;
	}
      a[j + 1] = x;
    }
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

void selectie_perf (int a[], int N)
{
  int i, j, k_min, x;
  for (i = 0; i < N; i++)
    {
      k_min = i;
      for (j = i + 1; j < N; j++)
	{
	  if (a[j] < a[k_min])
	    {
	      k_min = j;
	    }
	}
      x = a[i];
      a[i] = a[k_min];
      a[k_min] = x;
    }
}

void amestecare (int a[], int N)
{
  int i, j, s, d, x, k;
  s = 1;
  d = N - 1;
  k = N - 1;
  do
    {
      for (i = d; i >= s; i--)
	if (a[i - 1] > a[i])
	  {
	    x = a[i - 1];
	    a[i - 1] = a[i];
	    a[i] = x;
	    k = i;
	  }
      s = k + 1;
      for (i = s; i <= d; i++)
	if (a[i - 1] > a[i])
	  {
	    x = a[i - 1];
	    a[i - 1] = a[i];
	    a[i] = x;
	    k = i;
	  }
      d = k - 1;

    }
  while (s <= d);
}

void insertie_binara (int a[], int N)
{
  int i, j, x, s, d, aux, m;
  for (i = 1; i < N; i++)
    {
      aux = a[i];
      s = 0;
      d = i - 1;
      while (s <= d)
	{
	  m = (s + s) / 2;
	  if (aux < a[m])
	    d = m - 1;
	  else
	    s = m + 1;
	}
      for (j = i - 1; j >= s; j--)
	a[j + 1] = a[j];

      a[s] = aux;


    }

}
void deplasare(int a[],int s, int d)
{
    int i,j ,x,bul;
    i=s;
    j=2*i;
    x=a[i];
    bul=0;
    while(j<=d && bul==0)
    {
        if(j<d)
        {
            if(a[j]<a[j+1])
                j=j+1;
        }
        if(x<a[j])
        {
            a[i]=a[j];
            i=j;
            j=2*i;
            
        }
        else
            bul=1;
    }
    a[i]=x;
}
void sort_heap(int a[],int N)
{
    int i,j,aux,s,d;
    s=N/2+1;
    d=N;
    while(s>1){
        s--;
        deplasare(a,s,N);
    }
    while(d>1){
        aux=a[1];
        a[1]=a[d];
        a[d]=aux;
        d--;
        deplasare(a,1,d);
    }
    
}
int biti(int x,int k,int j)
{
    return (x>>k)& (~(~0<<j));
}
void radix_interschimbare(int a[],int s,int d,int b)
{
    int i,j,aux;
    if(d>s && b>=0)
    {
        i=s;
        j=d;
        do{
            
            while (biti(a[i],b,1)==0 && i<j) i++;
            while (biti(a[j],b,1)==1 && i<j) j--;
            aux=a[i];
            a[i]=a[j];
            a[j]=aux;
            
        }while(i!=j);
        if(biti(a[d],b,1)==0) j++;
        radix_interschimbare(a,s,j-1,b-1);
        radix_interschimbare(a,j,d,b-1);
        
    }
    
}
    
    

void sort_Shell(int a[], int N)
{
   int h[3]={3,2,1};
   int aux;
   int i,j,k,w;
   for(w=0;w<3;w++)
   {
        k=h[w];
        for(i=k;i<N;i++)
        {
            aux=a[i];
            j=i-k;
            while (j>=0&&aux<a[j])
            {
                a[j+k]=a[j];
                j=j-k;
            }
            a[j+k]=aux;
        }
   }
   
}

void sort_Quick(int a[],int st, int dr)
{
    int i,j,aux,x;
    i=st;
    j=dr;
    x=a[(st+dr)/2];
    do
    {
        while(a[i]<x) i=i+1;
        while (a[j]>x) j=j-1;
        if(i<=j)
        {
            aux=a[i];
            a[i]=a[j];
            a[j]=aux;
            i=i+1;
            j=j-1;
        }
        
    }while(i<=j);
    if(st<j)
        sort_Quick(a,st,j);
    if(dr>i)
        sort_Quick(a,i,dr);
}

void  Radix_Direct(int a[],int N)
{
	int b=8*sizeof(int);
	int m=4;
	int i,j,k,Trecere;
	int M=16;
	int Numar[16];
	int t[50];
	for(Trecere=0;Trecere<=b/m-1;Trecere++)
    {
	    for (i=0;i<M;i++)
	        Numar[i]=0;
		for (j=0;j<N;j++)
        {
			k=biti(a[j],Trecere*m,m);
			Numar[k]++;
		}
		for(j=1;j<M;j++)
			Numar[j]=Numar[j-1]+Numar[j];

	    for(i=N-1;i>=0;i--)
        {
		    k=biti(a[i],Trecere*m,m);
		    t[Numar[k]-1]=a[i];
	    	Numar[k]--;
    	}
	    for(i=0;i<N;i++)
	       a[i]=t[i];
	}
}
	
int main ()
{
  int N;
  int op;
  int a[20];
  N = 10;

  do
    {
      printf ("1. Insertie\n");
      printf ("2. Selectie\n");
      printf ("3. Selectie performanta\n");
      printf ("4. Amestecare\n");
      printf ("5. Insertie Binara\n");
      printf("6. ShellSort\n");
      printf("7. HeapSort\n");
      printf("8. QuickSort\n");
      printf("9. RadixDirect\n");
      printf("10. RadixInterschimbare\n");
      printf("0. Exit\n");
      printf("Introduceți optiunea:" );
      scanf("%d",&op);
     switch (op)
	{
	case 1:
	  load_tab (a, N);
	  afisare (a, N);
	  insertie (a, N);
	  afisare (a, N);
	  break;
	case 2:
	  load_tab (a, N);
	  afisare (a, N);
	  selectie (a, N);
	  afisare (a, N);
	  break;
	case 3:
	  load_tab (a, N);
	  afisare (a, N);
	  selectie_perf (a, N);
	  afisare (a, N);
	  break;
	case 4:
	  load_tab (a, N);
	  afisare (a, N);
	  amestecare (a, N);
	  afisare (a, N);
	  break;
	case 5:
	  load_tab (a, N);
	  afisare (a, N);
	  insertie_binara (a, N);
	  afisare (a, N);
	  break;
      case 6:
      load_tab(a,N);
      afisare(a,N);
      sort_Shell(a,N);
      afisare(a,N);
      break;
      case 7:
      load_tab(a,N);
      afisare(a,N);
      sort_heap(a,N-1);
      afisare(a,N);
      break;
      case 8:
      load_tab(a,N);
      afisare(a,N);
      sort_Quick(a,0,N-1);
      afisare(a,N);
      break;
      case 9:
      load_tab(a,N);
      afisare(a,N);
      radix_interschimbare(a,0,N-1,4*sizeof(int));
      afisare(a,N);
      break;
      case 10: 
      load_tab(a,N);
      afisare(a,N);
      Radix_Direct(a,N);
      afisare(a,N);
      break;
      case 0:
      exit(0);
      break;
	}
    }
  while (1);
  return 0;
}

        