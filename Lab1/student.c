#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


typedef struct student
{
	char nume[20];
	char prenume[20];
	float nota;
}stud;

int citire(stud st[])
{
	int nr = -1;
	FILE* f;
	if ((f = fopen("stud.txt", "rt")) == NULL)
		printf("Fisierul nu poate fi deschis!\n");
	else
	{
		while (!feof(f))
		{
			nr++;
			fscanf(f, "%s%s%f", st[nr].nume, st[nr].prenume, &st[nr].nota);

		}
		fclose(f);
	}

	return nr;
}

void afisare(stud st[], int n)
{
	int i;
	for (i = 0; i <=n; i++)
		printf("%s %s %f\n", st[i].nume, st[i].prenume, st[i].nota);
}

void scriere(stud st[], int n)
{
	int i;
	FILE* f;
	if ((f = fopen("stud1.txt", "wt")) == NULL)
	printf("Fisierul nu poate fi deschis!");
	else
	{
		for (i = 0; i <= n; i++)
		{
			if (st[i].nota > 9)
				fprintf(f," % s % s % f\n", st[i].nume, st[i].prenume, st[i].nota);
		}
		fclose(f);
	}
}

int main()
{
	int n;
	stud student[20];
	n=citire(student);
	afisare(student, n);
	scriere(student, n);
	return 0;

}