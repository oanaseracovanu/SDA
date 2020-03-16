#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum
{
    medii, superioare, doctorat
}studii;

typedef enum
{
    economic, tehnic
}profil;

typedef struct 
{
    float medie_bac, medie_liceu;
}basic;

typedef union
{
    basic info;
    float nota_licenta, nota_doctorat;
}note;

typedef struct persoana
{
    char nume[20],prenume[20];
    int salariu,zi,luna,an;
    note nota;
    studii tip;
}pers;

pers tab[20];

int citire(pers tab[], int j)
{
    FILE *f;
    int i=0;
    if ((f = fopen("date.txt", "rt")) == NULL) 
    {
        printf("Fisierul nu a fost gasit");
    } 
    else 
    {
        while (i<j) 
        {
            fscanf(f, "%s %s %d %d %d %d %d", tab[i].nume, tab[i].prenume, &tab[i].zi, &tab[i].luna,
            &tab[i].an, &tab[i].salariu, &tab[i].tip);
            if(tab[i].tip==0) fscanf(f,"%f %f ", &tab[i].nota.info.medie_bac,&tab[i].nota.info.medie_liceu);
            if(tab[i].tip==1) fscanf(f,"%f ",&tab[i].nota.nota_licenta);
            if(tab[i].tip==2) fscanf(f,"%f ",&tab[i].nota.nota_doctorat);
            i++;
        }
        fclose(f);
    }
    return i;
}

void afisare(pers tab[], int j)
{
    int i=0;
    while(i<j)
    {
        printf("Nume: %s\n Prenume : %s\n Data nastere: %d %d %d\n Salariu: %d\n Tipul studiilor: %d\n",
        tab[i].nume, tab[i].prenume, tab[i].zi, tab[i].luna, tab[i].an, tab[i].salariu, tab[i].tip );
        if(tab[i].tip==0) printf("Medie bac: %f\n Medie liceu: %f\n ", 
                                tab[i].nota.info.medie_bac, tab[i].nota.info.medie_liceu);
        if(tab[i].tip==1) printf("Nota de la licenta: %f\n ",tab[i].nota.nota_licenta);
        if(tab[i].tip==2) printf("Nota de la doctorat: %f\n ",tab[i].nota.nota_doctorat);
        i++;
    }
}

void cautare(pers tab[], int j,char nume_cautare[])
{
    int i=0;
    while(i<j)
    {
        if(strcmp(tab[i].nume,nume_cautare)==0)
        {
        printf("Nume: %s\n Prenume : %s\n Data nastere: %d %d %d\n Salariu: %d\n Tipul studiilor: %d\n",
        tab[i].nume, tab[i].prenume, tab[i].zi, tab[i].luna, tab[i].an, tab[i].salariu, tab[i].tip );
        if(tab[i].tip==0) printf("Medie bac: %f\n Medie liceu: %f\n ", 
                                tab[i].nota.info.medie_bac, tab[i].nota.info.medie_liceu);
        if(tab[i].tip==1) printf("Nota de la licenta: %f\n ",tab[i].nota.nota_licenta);
        if(tab[i].tip==2) printf("Nota de la doctorat: %f\n ",tab[i].nota.nota_doctorat);
        }
        i++;
    }
}

void numar_salariu(pers tab[], int j)
{
    int i=0,nr=0,varsta,tip_studii;
    float sal=0;
    printf("Anul corespunzator limitei superioare de varsta: ");
    scanf("%d",&varsta);
    printf("Tipul de studii: 0- medii 1- superioare 2- doctorat: ");
    scanf("%d",&tip_studii);
    while(i<j)
    {
        if(tab[i].an<varsta&&tab[i].tip==tip_studii)
        {
            nr=nr+1;
            sal=sal+tab[i].salariu;
        }
        i++;
    }
    printf("Numarul de persoane care respecta conditiile: %d\n Salariul mediu al acestora: %f\n ",nr,sal/nr);
}
void stergere_persoana(pers tab[],int *j)
{
	int i=0,k=0,m;
    char nume_sterge[20];
    pers aux[20];
    printf("Persoana pe care doriti sa o stergeti: ");
    scanf("%s",nume_sterge);
	for(i=0;i<=(*j-k);i++)
		if (strcmp(tab[i].nume,nume_sterge)==0)
		{
				k++;
				for (m = i+1; m < (*j - k); m++)
                {
					*(aux+m) = *(tab + m);
                    tab[i]=tab[*j-k];
                    *(tab+m)=*(aux+m);
                }
				i--;
		
		}
	*j = *j - k;
}

int main()
{
    int j,opt;
    char nume_cautare[20];
    do
    {
        printf("1.Citire\n");
        printf("2.Afisare\n");
        printf("3.Cautare dupa nume\n");
        printf("4.Numarul si salariul mediu\n");
        printf("5.Stergere\n");
        printf("0.Iesire\n");
        printf("Optiunea dumneavoastra este: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1: 
            printf("Cate persoane doriti sa cititi? ");
            scanf("%d",&j);
            citire(tab,j);
            break;
            case 2: 
            afisare(tab,j);
            break;
            case 3:
            printf("Numele pe care doriti sa il cautati: ");
            scanf("%s",nume_cautare);
            cautare(tab,j,nume_cautare);
            break;
            case 4:
            numar_salariu(tab,j);
            break;
            case 5:
            stergere_persoana(tab,&j);
            break;
            default: 
            printf("Optiunea nu exista!");
            break;
        }
    }while(1);
    
    return 0;
}