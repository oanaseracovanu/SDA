#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max 20
typedef struct magazie 
{
    char nume[max];
    int cod,categorie;
    float cantitate,pret;
    struct magazie *urm;
}mag;

typedef mag A,B,M;

A *adaugare_magazieA(A *magazieA_cap, char *nume, int cod, int categorie, float cantitate, float pret)
{
	A *q1, *q2, *aux;
	aux = (A *)malloc(sizeof(A));
	strcpy(aux->nume, nume);
	aux->cantitate = cantitate;
	aux->cod = cod;
    aux->categorie=categorie;
    aux->cantitate=cantitate;
    aux->pret=pret;
	aux->urm = NULL;
	for (q1 = q2 = magazieA_cap; q1 != NULL && strcmp(q1->nume, aux->nume) < 0; q2 = q1, q1 = q1->urm);
	if (q1 == q2)
	{
		aux->urm = magazieA_cap;
		magazieA_cap = aux;
	}
	else
	{
		q2->urm = aux;
		aux->urm = q1;
	}
	return magazieA_cap;
}

B *adaugare_magazieB(B *magazieB_cap, char *nume, int cod, int categorie, float cantitate, float pret)
{
	B *q1, *q2, *aux;
	aux = (B *)malloc(sizeof(B));
	strcpy(aux->nume, nume);
	aux->cantitate = cantitate;
	aux->cod = cod;
    aux->categorie=categorie;
    aux->cantitate=cantitate;
    aux->pret=pret;
	aux->urm = NULL;
	for (q1 = q2 = magazieB_cap; q1 != NULL && strcmp(q1->nume, aux->nume) < 0; q2 = q1, q1 = q1->urm);
	if (q1 == q2)
	{
		aux->urm = magazieB_cap;
		magazieB_cap = aux;
	}
	else
	{
		q2->urm = aux;
		aux->urm = q1;
	}
	return magazieB_cap;
}

M *adaugare_magazieM(M *magazieM_cap, char *nume, int cod, int categorie, float cantitate, float pret)
{
	M *q1, *q2, *aux;
	aux = (M *)malloc(sizeof(M));
	strcpy(aux->nume, nume);
	aux->cantitate = cantitate;
	aux->cod = cod;
    aux->categorie=categorie;
    aux->cantitate=cantitate;
    aux->pret=pret;
	aux->urm = NULL;
	for (q1 = q2 = magazieM_cap; q1 != NULL && strcmp(q1->nume, aux->nume) < 0; q2 = q1, q1 = q1->urm);
	if (q1 == q2)
	{
		aux->urm = magazieM_cap;
		magazieM_cap = aux;
	}
	else
	{
		q2->urm = aux;
		aux->urm = q1;
	}
	return magazieM_cap;
}

A *citire_magazieA(A *magazieA_cap)
{
	FILE *f = NULL;
	char nume[max];
	int cod, categorie;
    float cantitate,pret;
	if ((f = fopen("magazie.txt", "rt")) == NULL)
	{
		printf("Eroare la citirea fisierului\n ");
	}
	else
	{
		while (fscanf(f, "%s %d %d %f %f", nume, &cod, &categorie,&cantitate,&pret)==5)
		{
			if(categorie==1)
			magazieA_cap = adaugare_magazieA(magazieA_cap, nume, cod,categorie,cantitate,pret);
		}
		fclose(f);
	}
	return magazieA_cap;
}

B *citire_magazieB(B *magazieB_cap)
{
	FILE *f = NULL;
	char nume[max];
	int cod, categorie;
    float cantitate,pret;
	if ((f = fopen("magazie.txt", "rt")) == NULL)
	{
		printf("Eroare la citirea fisierului\n ");
	}
	else
	{
		while (fscanf(f, "%s %d %d %f %f", nume, &cod, &categorie,&cantitate,&pret)==5)
		{
			if(categorie==2)
			magazieB_cap = adaugare_magazieB(magazieB_cap, nume, cod,categorie,cantitate,pret);
		}
		fclose(f);
	}
	return magazieB_cap;
}

M *citire_magazieM(M *magazieM_cap)
{
	FILE *f = NULL;
	char nume[max];
	int cod, categorie;
    float cantitate,pret;
	if ((f = fopen("magazie.txt", "rt")) == NULL)
	{
		printf("Eroare la citirea fisierului\n ");
	}
	else
	{
			while(fscanf(f, "%s %d %d %f %f", nume, &cod, &categorie,&cantitate,&pret)==5)
			{
			if(categorie==3)
			magazieM_cap = adaugare_magazieM(magazieM_cap, nume, cod,categorie,cantitate,pret);
			}
		
		fclose(f);
	}
	return magazieM_cap;
}

void afisare(A *magazieA_cap,B *magazieB_cap,M *magazieM_cap,int a)
{
	A *q1; B *q2; M *q3;
	switch(a)
	{
		case 1:
		printf("\nMateriale in magazia A: \n");
		for (q1 = magazieA_cap; q1 != NULL; q1 = q1->urm)
		printf("%s %2d %2d %2f %2f\n", q1->nume, q1->cod, q1->categorie,q1->cantitate,q1->pret);
		break;
		case 2:
		printf("\nMateriale in magazia B: \n");
		for(q2=magazieB_cap;q2 != NULL; q2 = q2->urm)
		printf("%s %2d %2d %2f %2f\n", q2->nume, q2->cod, q2->categorie,q2->cantitate,q2->pret);
		break;
		case 3:
		printf("\nMateriale in magazia M: \n");
		for(q3=magazieM_cap;q3 != NULL; q3 = q3->urm)
		printf("%s %2d %2d %2f %2f\n", q3->nume, q3->cod, q3->categorie,q3->cantitate,q3->pret);
		break;
	}
	
}

void cautare(A *magazieA_cap,B *magazieB_cap,M *magazieM_cap)
{
	A *q1; B *q2; M *q3;
	char denumire[20];
	printf("Materialul pe care doriti sa il cautati: ");
	scanf("%s",denumire);
		for(q1=magazieA_cap;q1!=NULL;q1=q1->urm)
		if(strcmp(q1->nume,denumire)==0) 
		{
		printf("Materialul se afla in magazia A\n");
		printf("\n%s %2d %2d %2f %2f\n", q1->nume, q1->cod, q1->categorie,q1->cantitate,q1->pret);
		}
		for(q2=magazieB_cap;q2!=NULL;q2=q2->urm)
		if(strcmp(q2->nume,denumire)==0)
		{
		printf("Materialul se afla in magazia B\n");
		printf("\n%s %2d %2d %2f %2f\n", q2->nume, q2->cod, q2->categorie,q2->cantitate,q2->pret);
		}
		for(q3=magazieM_cap;q3!=NULL;q3=q3->urm)
		if(strcmp(q3->nume,denumire)==0)
		{
		printf("Materialul se afla in magazia M\n");
		printf("\n%s %2d %2d %2f %2f\n", q3->nume, q3->cod, q3->categorie,q3->cantitate,q3->pret);
		}
	

}

void valoare(A *magazieA_cap, B *magazieB_cap, M *magazieM_cap)
{
	A *q1; B *q2; M *q3;
	float s1=0,s2=0,s3=0;
	for(q1=magazieA_cap;q1!=NULL;q1=q1->urm)
	s1=s1+q1->pret*q1->cantitate;
	for(q2=magazieB_cap;q2!=NULL;q2=q2->urm)
	s2=s2+q2->pret*q2->cantitate;
	for(q3=magazieM_cap;q3!=NULL;q3=q3->urm)
	s3=s3+q3->pret*q3->cantitate;
	printf("Valoarea totala a materialelor este: %f\n",s1+s2+s3);
}

A *stergere_magazieA(A *magazieA_cap,char *denumire)
{
	A *q1, *q2;

	for (q1 = q2 = magazieA_cap; q1 != NULL; q2 = q1, q1 = q1->urm)
	if (q1 != NULL && (strcmp(q1->nume, denumire) == 0))
	{
		if (q1 == q2)
		{
			magazieA_cap = magazieA_cap->urm;
		}
		else
		{
			q2->urm = q1->urm;
			free(q1);
		}
	}
    return magazieA_cap;
}
		
B *stergere_magazieB(B*magazieB_cap,char *denumire)
{
    B *q3,*q4;
	for (q3 = q4 = magazieB_cap; q3 != NULL; q4 = q3, q3 = q3->urm)
	if (q3 != NULL && (strcmp(q3->nume, denumire) == 0))
	{
		if (q3 == q4)
		{
			magazieB_cap = magazieB_cap->urm;
		}
		else
		{
			q4->urm = q3->urm;
			free(q3);
		}
	}
    return magazieB_cap;
}

M *stergere_magazieM(M *magazieM_cap,char *denumire)
{
    M *q5,*q6;
	for (q5 = q6 = magazieM_cap; q5 != NULL; q6 = q5, q5 = q5->urm)
	if (q5 != NULL && (strcmp(q5->nume, denumire) == 0))
	{
		if (q5 == q6)
		{
			magazieM_cap = magazieM_cap->urm;
		}
		else
		{
			q6->urm = q5->urm;
			free(q5);
		}
	}
    return magazieM_cap;
}

void mutare(A *magazieA_cap, B *magazieB_cap, M *magazieM_cap)
{
    A *q1; B *q2; M *q3;
    char denumire[20];
    int a;
    printf("Materialul pe care doriti sa il mutati: ");
	scanf("%s",denumire); 
	printf("Magazia in care doriti sa il mutati: 1-A 2-B 3-M ");
	scanf("%d",&a);
    for(q1=magazieA_cap;q1!=NULL;q1=q1->urm)
    if(strcmp(q1->nume,denumire)==0)
	{
	    if(a==2)
		{
		magazieB_cap=adaugare_magazieB(magazieB_cap,q1->nume,q1->cod,q1->categorie,q1->cantitate,q1->pret);
        magazieA_cap=stergere_magazieA(magazieA_cap,q1->nume);
		}
		if(a==3)
		{
		magazieM_cap=adaugare_magazieM(magazieM_cap,q1->nume,q1->cod,q1->categorie,q1->cantitate,q1->pret);
        magazieA_cap=stergere_magazieA(magazieA_cap,q1->nume);
		}
		}
    for(q2=magazieB_cap;q2!=NULL;q2=q2->urm)
	{
			if(strcmp(q2->nume,denumire)==0)
			{
				if(a==1)
				{	
				magazieA_cap=adaugare_magazieA(magazieA_cap,q2->nume,q2->cod,q2->categorie,q2->cantitate,q2->pret);
                magazieB_cap=stergere_magazieB(magazieB_cap,q2->nume);
				}
				if(a==3)
				{
				magazieM_cap=adaugare_magazieM(magazieM_cap,q2->nume,q2->cod,q2->categorie,q2->cantitate,q2->pret);
                magazieB_cap=stergere_magazieB(magazieB_cap,q2->nume);
				}
			}
		}
        for(q3=magazieM_cap;q3!=NULL;q3=q3->urm)
		{
			if(strcmp(q3->nume,denumire)==0)
			{
				if(a==1)
				{
				magazieA_cap=adaugare_magazieA(magazieA_cap,q3->nume,q3->cod,q3->categorie,q3->cantitate,q3->pret);
                magazieM_cap=stergere_magazieM(magazieM_cap,q3->nume);
				}
				if(a==2)
				{
				magazieB_cap=adaugare_magazieB(magazieB_cap,q3->nume,q3->cod,q3->categorie,q3->cantitate,q3->pret);
                magazieM_cap=stergere_magazieM(magazieM_cap,q3->nume);
				}		
			}
		}
}

void introducere(A *magazieA_cap,B *magazieB_cap,M *magazieM_cap)
{
	char nume[max];
    int cod,categorie;
    float cantitate,pret;
	printf("Denumire material: ");
	scanf("%s",nume);
	printf("Cod material: ");
	scanf("%d",&cod);
	printf("Categorie material: ");
	scanf("%d",&categorie);
	printf("Cantitatea: ");
	scanf("%f",&cantitate);
	printf("Pretul materialului: ");
	scanf("%f",&pret);
	if(categorie==1)
	magazieA_cap=adaugare_magazieA(magazieA_cap,nume,cod,categorie,cantitate,pret);
	if(categorie==2)
	magazieB_cap=adaugare_magazieB(magazieB_cap,nume,cod,categorie,cantitate,pret);
	if(categorie==3)
	magazieM_cap=adaugare_magazieM(magazieM_cap,nume,cod,categorie,cantitate,pret);

}

void stergere_cantitate(A *magazieA_cap)
{
	A *q1;
	int cantitate_minima;
	printf("Cantitatea minima: ");
	scanf("%d",&cantitate_minima);
	for (q1 = magazieA_cap; q1 != NULL; q1 = q1->urm)
	if ( (q1->cantitate < cantitate_minima))
	{
		magazieA_cap=stergere_magazieA(magazieA_cap,q1->nume);
	}
}

void actualizare(A *magazieA_cap,B *magazieB_cap,M *magazieM_cap)
{
	A *q1; B *q2; M *q3;
 		FILE *f=NULL;
		if ((f = fopen("magazieA_actualizat.txt", "wt")) == NULL)
	{
		printf("Eroare la citirea fisierului\n ");
	}
	else
	{
		for(q1=magazieA_cap;q1!=NULL;q1=q1->urm)
		fprintf(f, "%s %d %d %f %f\n", q1->nume, q1->cod, q1->categorie,q1->cantitate,q1->pret);
		fclose(f);
	}
		FILE *g=NULL;
		if ((g = fopen("magazieB_actualizat.txt", "wt")) == NULL)
	{
		printf("Eroare la citirea fisierului\n ");
	}
	else
	{
		for(q2=magazieB_cap;q2!=NULL;q2=q2->urm)
		fprintf(g, "%s %d %d %f %f\n", q2->nume, q2->cod, q2->categorie,q2->cantitate,q2->pret);
		fclose(g);
	}
		FILE *h=NULL;
		if ((h = fopen("magazieM_actualizat.txt", "wt")) == NULL)
	{
		printf("Eroare la citirea fisierului\n ");
	}
	else
	{
		for(q3=magazieM_cap;q3!=NULL;q3=q3->urm)
		fprintf(g, "%s %d %d %f %f\n", q3->nume, q3->cod, q3->categorie,q3->cantitate,q3->pret);
		fclose(g);
	}

}

int main()
{
	A *magazieA=NULL; B *magazieB=NULL; M *magazieM=NULL;
	int optiune,a;
	char denumire[20];
	do
	{
		printf("\n1.Citire date\n");
		printf("2.Afisare materiale in ordine crescatoare dintr-o magazie citita de la tastatura\n");
		printf("3.Cautare material\n");
		printf("4.Valoarea totala a materialelor aflate in magaziile intreprinderii\n");
		printf("5.Stergere material\n");
		printf("6.Mutare material dintr-o magazie in alta\n");
		printf("7.Introducere material de la tastatura\n");
		printf("8.Stergerea tuturor materialelor cu cantitate prea mica\n");
		printf("9.Materialele care se afla acum in fiecare magazie\n");
		printf("10.Parasire program\n");
		printf("Optiunea dumneavoastra: ");
		scanf("%d",&optiune);
		switch(optiune)
		{
			case 1:
			magazieA=citire_magazieA(magazieA);
			magazieB=citire_magazieB(magazieB);
			magazieM=citire_magazieM(magazieM);
			break;
			case 2:
			printf("Magazia din care doriti sa afisati: 1-A 2-B 3-M ");
			scanf("%d",&a);
			afisare(magazieA,magazieB,magazieM,a);
			break;
			case 3:
			cautare(magazieA,magazieB,magazieM);
			break;
			case 4:
			valoare(magazieA,magazieB,magazieM);
			break;
			case 5:
			printf("Materialul pe care doriti sa il stergeti: ");
			scanf("%s",denumire);
			magazieA=stergere_magazieA(magazieA,denumire);
            magazieB=stergere_magazieB(magazieB,denumire);
            magazieM=stergere_magazieM(magazieM,denumire);
			break;
            case 6:
            mutare(magazieA,magazieB,magazieM);
            break;
			case 7:
			introducere(magazieA,magazieB,magazieM);
			break;
            case 8:
            stergere_cantitate(magazieA);
            break;
			case 9:
			actualizare(magazieA,magazieB,magazieM);
			break;
			case 10:
			exit(0);
			break;
			default:
			printf("Optiunea nu exista!\n");
		}
	} while (1);
	return 0;
}