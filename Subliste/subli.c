#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sublista
{
    char nume[20],prenume[20];
    int vechime;
    struct sublista *urm;
}sublista;

typedef struct lista
{
    char departament[20];
    struct sublista *sub;
    struct lista *urm;
}lista;

sublista *adauga_sublista(sublista *cap_sublista, char nume[], char prenume[],int vechime)
{
    sublista *q1,*q2,*aux;
    aux=(sublista*)malloc(sizeof(sublista));
    strcpy(aux->nume,nume);
    strcpy(aux->prenume,prenume);
    aux->vechime=vechime;
    for(q2=q1=cap_sublista;q1!=NULL&&strcmp(q1->nume,aux->nume)<0;q2=q1,q1=q1->urm)
    ;
    if(q1==q2)
    {
        aux->urm=cap_sublista;
        cap_sublista=aux;
    }
    else
    {
        q2->urm=aux;
        aux->urm=q1;
    }
    return cap_sublista;
}

lista *adauga_lista(lista *cap_lista,char departament[],char nume[],char prenume[],int vechime)
{
    lista *q1,*q2,*aux;
    aux=(lista*)malloc(sizeof(lista));
    strcpy(aux->departament,departament);
    for(q1=q2=cap_lista;q1!=NULL&&strcmp(q1->departament,aux->departament)<0;q2=q1,q1=q1->urm)
    ;
    if(q1!=NULL&&strcmp(q1->departament,aux->departament)==0)
    q1->sub=adauga_sublista(q1->sub,nume,prenume,vechime);
    else
    {
        if(q1==q2)
        {
            aux->urm=cap_lista;
            cap_lista=aux;
        }
        else
        {
            q2->urm=aux;
            aux->urm=q1;
        }
        aux->sub=adauga_sublista(aux->sub,nume,prenume,vechime);
    }
     
     return cap_lista;
}

lista *citire(lista *cap_lista)
{
    char nume[20],prenume[20],departament[20];
    int vechime;
    FILE *f;
    if((f=fopen("cd.txt","rt"))==0)
    {
        printf("Fisierul nu poate fi deschis pentru citire!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        while(fscanf(f,"%s%s%s%d",departament,nume,prenume,&vechime)==4)
        {
        cap_lista=adauga_lista(cap_lista,departament,nume,prenume,vechime);
        }
        fclose(f);
    }
    return cap_lista;
}

void afisare(lista *cap_lista)
{
    lista *p;
    sublista *q;
    for(p=cap_lista;p!=NULL;p=p->urm)
    {
        printf("Departamentul: %s \n",p->departament);
        for(q=p->sub;q!=NULL;q=q->urm)
        {
        printf("%s %s %d \n",q->nume,q->prenume,q->vechime);
        }
        printf("\n");
    }
}
void afisare_dep(lista *cap_lista)
{
    char dep[20];
    lista *q;
    sublista *p;
    printf("Departamentul: ");
    scanf("%s",dep);
    for(q=cap_lista;q!=NULL;q=q->urm)
    {
        if(strcmp(q->departament,dep)==0)
        for(p=q->sub;p!=NULL;p=p->urm)
        printf("%s %s %d \n",p->nume,p->prenume,p->vechime);
    }

}

void fisier(lista *cap_lista)
{
    lista *q;
    sublista *p;
    FILE *f;
    int vech;
    printf("Vechime minima: ");
    scanf("%d",&vech);
    if((f=fopen("cd1.txt","wt"))==0)
    {
        printf("Fisierul nu poate fi deschis pentru scriere!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for(q=cap_lista;q!=NULL;q=q->urm)
        {
        for(p=q->sub;p!=NULL;p=p->urm)
        if(p->vechime>vech)
        fprintf(f,"%s %s %s %d\n",q->departament,p->nume,p->prenume,p->vechime);
        }
        fclose(f);
    }
    
}

int main()
{
    lista *cap_lista=NULL;
    int opt;
    do
    {
        printf("1.Incarca datele\n");
        printf("2.Afisare\n");
        printf("3.Afisare dupa departament\n");
        printf("4.Scriere fisier\n");
        printf("0.Iesire\n");
        printf("Optiune: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 0: 
            exit(0);
            break;
            case 1:
            cap_lista=citire(cap_lista);
            break;
            case 2:
            afisare(cap_lista);
            break;
            case 3:
            afisare_dep(cap_lista);
            break;
            case 4:
            fisier(cap_lista);
            break;
            
        }
    } while (1);
    
    return 0;
}