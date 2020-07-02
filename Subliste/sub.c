#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sublista
{
    char nume[20],prenume[20];
    int nota;
    struct sublista *urm;
}sublista;

typedef struct student
{
    char disciplina[20];
    struct sublista *sub;
    struct student *urm;
}student;


sublista *adauga_sublista(sublista *cap_sublista,char nume[],char prenume[],int nota)
{
    sublista *q1,*q2,*aux;
    aux=(sublista*)malloc(sizeof(sublista));
    strcpy(aux->nume,nume);
    strcpy(aux->prenume,prenume);
    aux->nota=nota;
    for(q1=q2=cap_sublista;q1!=NULL&&q1->nota>nota;q2=q1,q1=q1->urm);
    if(q2==q1)
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

student *adauga_student(student *cap_lista,char nume[],char prenume[],int nota, char disciplina[])
{
    student *q1,*q2,*aux;
    aux=(student*)malloc(sizeof(student));
    strcpy(aux->disciplina,disciplina);
    aux->sub=NULL;
    for(q1=q2=cap_lista;q1!=NULL&&strcmp(q1->disciplina,aux->disciplina)>0;q2=q1,q1=q1->urm)
    ;
   if(q1!=NULL&&strcmp(q1->disciplina,aux->disciplina)==0)
    q1->sub=adauga_sublista(q1->sub,nume,prenume,nota);
    else
    {
       if(q2==q1)
        {
            aux->urm=cap_lista;
            cap_lista=aux;
        }
        else
        {
            q2->urm=aux;
            aux->urm=q1;
        }
        aux->sub=adauga_sublista(aux->sub,nume,prenume,nota);
    }
        return cap_lista;
}

student *citire(student *cap_lista)
{
    FILE *f;
    char disciplina[20],nume[20],prenume[20];
    int nota;
    if((f=fopen("sublista.txt","rt"))==0)
    {
        printf("Fisierul nu poate fi deschis pentru citire!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        while(fscanf(f,"%s%s%d%s",nume,prenume,&nota,disciplina)==4)
    {
        cap_lista=adauga_student(cap_lista,nume,prenume,nota,disciplina);
    }
    fclose(f);
    }
    return cap_lista;
}

void afisare(student *cap_lista)
{
    student *p;
    sublista *q;
    for(p=cap_lista;p!=NULL;p=p->urm)
    {
    printf("Disciplina: %s\n",p->disciplina);
    for(q=p->sub;q!=NULL;q=q->urm)
    {
        printf("Nume: %s Prenume: %s Nota: %d\n",q->nume,q->prenume,q->nota);
    }
    printf("\n");
    }
}

void afisare_nota(student *cap_lista)
{
    student *q;
    sublista *q1;
    int nota_min;
    printf("Care este nota minima? ");
    scanf("%d",&nota_min);
    for(q=cap_lista;q!=NULL;q=q->urm)
    {
        for(q1=q->sub;q1!=NULL;q1=q1->urm)
        if(q1->nota>nota_min)
        printf("\nStudentul: %s are nota mai mare decat nota minima\n",q1->nume);
    }
}

sublista *stergere_sublista(sublista *cap_sublista,char numele[])
{
    sublista *q1,*q2;
    for(q1=q2=cap_sublista;q1!=NULL&&strcmp(q1->nume,numele);q2=q1,q1=q1->urm)
    ;
    if(q1!=NULL&&(strcmp(q1->nume,numele)==0))
    {
    if(q1==q2)
    cap_sublista=cap_sublista->urm;
    else
    {
        q2->urm=q1->urm;
        free(q1);
    }
    }
    return cap_sublista;
}

student *delete_sl(student *cap_lista, char nume[])
{
    student *s;
    for(s=cap_lista;s!=NULL;s=s->urm)
    {
        s->sub= stergere_sublista(s->sub, nume);
    }
    return cap_lista;
}

student *stergere_student(student *cap_lista,char numele[])
{
    student *q1,*q2;
    for(q1=q2=cap_lista;q1!=NULL&&strcmp(q1->disciplina,numele);q2=q1,q1=q1->urm)
    ;
    if(q1!=NULL&&strcmp(q1->disciplina,numele)==0)
    {
        if(q1==q2)
        cap_lista=cap_lista->urm;
        else
        {
            q2->urm=q1->urm;
            free(q1);
        }
        
    }  
    return cap_lista;

}

void fisier(student *cap_lista)
{
    student *q; sublista *p;
    FILE *f;
    char discip[20];
    printf("Disciplina: ");
    scanf("%s",discip);
    if((f=fopen("sub.txt","wt"))==0)
    {
        printf("Fisierul nu poate fi deschis pentru scriere!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for(q=cap_lista;q!=NULL;q=q->urm)
        {
        if(strcmp(q->disciplina,discip)==0)
        for(p=q->sub;p!=NULL;p=p->urm)
        fprintf(f,"%s %s %d %s",p->nume,p->prenume,p->nota,discip);
        }
        fclose(f);
    }
    
}

int main()
{
    student *cap_lista=NULL;
    char numele[20],discip[20];
    int opt;
    do
    {
       printf("1.Incarcare date in lista\n");
       printf("2.Afisare date\n");
       printf("3.Afisare dupa nota\n");
       printf("4.Stergere dupa nume\n");
       printf("5.Stergere disciplina intreaga\n");
       printf("6.Scriere in fisier\n");
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
           afisare_nota(cap_lista);
           break;
           case 4:
           printf("Numele persoanei pe care doriti sa o stergeti: ");
           scanf("%s",numele);
           cap_lista=delete_sl(cap_lista,numele);
           afisare(cap_lista);
           break;
           case 5:
           printf("Disciplina pe care doriti sa o stergeti: ");
           scanf("%s",discip);
           cap_lista=stergere_student(cap_lista,discip);
           afisare(cap_lista);
           break;
           case 6:
           fisier(cap_lista);
       }

    } while (1);
    
    return 0;
}