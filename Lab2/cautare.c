#include<stdlib.h>
#include<stdio.h>

int citire(int a[],int n)
{
	FILE* f;
	int i = 0;
	{
		if ((f = fopen("nr.txt", "rt")) == NULL)
		{
			printf("fisierul nu a fost gasit");
		}
		else
		{
			while (!feof(f))
			{
				fscanf(f, "%d", &a[i]);
				i++;
			}
			fclose(f);
		}
	}
	return i;

}

int cautare_liniara(int a[], int n, int x)
{
	int i = 0;
	while (a[i] != x && i < n) i++;
	return i;
}

int tehnica_fanionului(int a[], int n, int x)
{
	int i = 0;
	a[n] = x;
	while (a[i] != x) i++;
	return i;
}

int citire1(int a[],int n)
{
	FILE* f;
	int i = 0;
	{
		if ((f = fopen("nr1.txt", "rt")) == NULL)
		{
			printf("fisierul nu a fost gasit");
		}
		else
		{
			while (!feof(f))
			{
				fscanf(f, "%d", &a[i]);
				i++;
			}
			fclose(f);
		}
	}
	return i;
}

int cautare_binara(int a[], int n, int x)
{
	int s, d, m;
	s = 0; d = n - 1;
	do
	{
		m = (s + d) / 2;
		if (x > a[m]) s = m + 1;
		else
			d = m - 1;
	} while (a[m] != x && s <= d);
	return m;
}

int cautare_binara_performanta(int a[], int n, int x)
{
	int s, d, m;
	s = 0; d = n - 1;
	do
	{
		m = (s + d) / 2;
		if (x > a[m]) s = m + 1;
		else
			d = m;
	} while (s < d);
	return d;
}

int cautare_interpolare(int a[], int n, int x)
{
	int s, d, m;
	s = 0;
	d = n - 1;
	if (x <= a[d] && x >= a[s])
		do
		{
			m = ((s + x - a[s]) / (a[d] - a[s])) * (d - s);
			if (a[x] > a[m]) s = m + 1;
			else
				d = m - 1;
		} while (a[m] != x && s < d && a[d] != a[s] && x <= a[d] && x >= a[s]);
		return m;
}

int main()
{
	int a[20], n, x;
	printf("Nr de elemente ale tabloului: ");
	scanf("%d", &n);
	citire(a, n);
	printf("Elementul pe care doriti sa il cautati: ");
	scanf("%d", &x);
	if (a[cautare_liniara(a, n, x)] < n) printf("Elementul a fost gasit la pozitia %d\n", cautare_liniara(a, n, x));
	else
		printf("Elementul nu a fost gasit\n");
	if (a[tehnica_fanionului(a, n, x)] < n) printf("Elementul a fost gasit la pozitia %d\n", tehnica_fanionului(a, n, x));
	else
		printf("Elementul nu a fost gasit\n");
	printf("Nr de elemente ale tabloului: ");
	scanf("%d", &n);
	citire1(a, n);
	printf("Elementul pe care doriti sa il cautati: ");
	scanf("%d", &x);
	if (a[cautare_binara(a, n, x)] == x) printf("Elementul a fost gasit la pozitia %d\n", cautare_binara(a, n, x));
	else
		printf("Elementul nu a fost gasit\n");
	if (a[cautare_binara_performanta(a, n, x)] == x) printf("Elementul a fost gasit la pozitia %d\n", cautare_binara_performanta(a, n, x));
	else
		printf("Elementul nu a fost gasit\n");
	if (a[cautare_interpolare(a, n, x)] == x) printf("Elementul a fost gasit la pozitia %d\n", cautare_interpolare(a, n, x));
	else
		printf("Elementul nu a fost gasit\n");
	return(0);

}