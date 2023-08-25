#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 20

void Imprime(int A[N]);
void Genera (int A[N]);
void Burbuja(int A[N]);
void Seleccion(int A[N]);
void Insercion(int A[N]);
void QuickSort(int A[N], int inicio, int fin);

int main()
{

    int A[N];

    Genera(A);
    //Imprime(A);

    time_t t1=0, t2=0, tf=0;
    time(&t1);
    t1=time(NULL);

    Burbuja(A);
    //Insercion(A);
    //Seleccion(A);
    //QuickSort(A, 0, N-1);

    t2=time(NULL);
    time(&t2);
    tf=t2-t1;
    printf("Duracion de la funcion:%f ", difftime(t2,t1));
    //printf("\n");
    //Imprime(A);

}

void Genera (int A[N])
{
    int c;
    for (c=0;c<N;c++)
    {
        A[c]=rand()%21;
    }

}

void Burbuja(int A[N])
{
    int i, v, p;

    for(p=1;p<N;p++)
    {
        for (i=0; i<N-p; i++)
        {
            if (A[i]>A[i+1])
            {
                v=A[i+1];
                A[i+1]=A[i];
                A[i]=v;
            }
        }
    }
}

void Seleccion(int A[N])
{
    int i, v, p, max;


    for(p=0;p<N-1;p++)
    {
        max=0;
        for (i=0; i<N-p; i++)
        {
            if (A[max]<A[i])
            {
                max=i;
            }
        }
        v=A[max];
        A[max]=A[N-p-1];
        A[N-p-1]=v;
    }

}


void Insercion(int A[N])
{
    int v, p;
    for (p=1;p<N;p++)
    {
        for(p; p>0 && A[p]<A[p-1];p--)
        {
            v=A[p];
            A[p]=A[p-1];
            A[p-1]=v;
        }
    }
}


void QuickSort(int A[N], int ini, int fin)
{
    int izq, der, p, aux;
    bool band;

    izq=ini;
    der=fin;
    p=ini;
    band=1;

    while (band)
    {
        band=0;
        while (A[p]<=A[der] && p!=der)
        {
            der--;
        }

        if (p!=der)
        {
            aux=A[p];
            A[p]=A[der];
            A[der]=aux;
            p=der;

            while (A[p]>=A[izq] && p!=izq)
            {
                izq++;
            }
            if(p!=izq)
            {
                aux=A[p];
                A[p]=A[izq];
                A[izq]=aux;
                p=izq;
                band=1;
            }

        }


    }

    if (p-1 > ini)
    {
        QuickSort(A, ini, p-1);
    }

    if(fin>p+1)
    {
        QuickSort(A, p+1, fin);
    }


}

void Imprime(int A[N])
{
    int c;
    for(c=0;c<N;c++)
    {
        printf("%d ", A[c]);
    }

}
