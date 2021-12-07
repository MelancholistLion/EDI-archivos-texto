#include <stdio.h>
#include <stdlib.h>

#define N 5
#define nomTam 20

int main()
{
    int salon;
    printf("Cuantos alumnos son? ");
    scanf("%d",&salon);
    leeClase(salon);
    imprime(salon);
}

void leeClase(int tam)
{
    FILE *ptr;
    int i;
    float cal;
    char name[nomTam];

    ptr=fopen("cal.txt","w");

    if(ptr==NULL)
    {
        printf("Error: No existe el archivo cal.txt");
        exit(0);
    }

    for(i=0;i<tam;i++)
    {
        printf("Nombre %d: ",i);
        scanf("%s",name);
        printf("Calificacion %d: ",i);
        scanf("%f",&cal);
        fprintf(ptr,"%s %f",name,cal);
    }
    fclose(ptr);
}

void imprime(tam)
{
    FILE *ptr;
    int i;
    float acum=0,x;
    char name[nomTam];

    ptr=fopen("cal.txt","r");

if(ptr==NULL)
    {
        printf("Error: No existe el archivo cal.txt");
        exit(0);
    }

    while(!feof(ptr))
    {
        fscanf(ptr,"%s",name);
        fscanf(ptr,"%f",&x);

        acum = acum + x;
    }

    fclose(ptr);
    acum = acum / tam;
    printf("El promedio de los alumnos es de: %f",acum);
}

