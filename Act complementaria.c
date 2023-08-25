#include <stdio.h>
#include <stdbool.h>

#define N 20

void Bubble(int A[N]);
void Baraja(int A[N]);
void Selecc(int A[N]);
void QS(int A[N], int inicio, int fin, int *nc, int *ni);
void Print(int A[N]);
int Cambia(int *a, int *b);

int main()
{
    int peor[20] = {98, 87, 84, 77, 72, 70, 68, 66, 64, 62, 59, 57, 53, 51, 42, 37, 32, 24, 15, 4};
    int mejor[20] = {2, 5, 7, 15, 18, 25, 29, 30, 34, 38, 44, 51, 52, 60, 65, 69, 77, 80, 92, 96};
    int inicio=0, fin=N, nc=0, ni=0;
    Print(peor);
    printf("\n");
    Bubble(peor);
    //Baraja(peor);
    //Selecc(peor);
    //QS(peor, inicio, fin, &nc, &ni);
    //printf("Num intercambios:%d\tNum comparaciones:%d\n", ni, nc);
    Print(peor);

}

void Bubble(int A[N])
{
    int i, v, p, ni=0, nc=0;

    for(p=1;p<N;p++)
    {
        for (i=0; i<N-p; i++)
        {
            if (A[i]>A[i+1])
            {
                nc++;
                ni+=Cambia(&A[i+1], &A[i]);

            }
        }
    }
    printf("Num intercambios:%d\tNum comparaciones:%d\n", ni, nc);
}

void Selecc(int A[N])
{
    int i, v, p, max, ni=0, nc=0;


    for(p=0;p<N-1;p++)
    {
        max=0;
        for (i=0; i<N-p; i++)
        {
            if (A[max]<A[i])
            {
                max=i;
                nc++;
            }
        }
        ni+=Cambia(&A[max], &A[N-p-1]);
    }
    printf("Num intercambios:%d\tNum comparaciones:%d\n", ni, nc);

}


void Baraja(int A[N])
{
    int v, p, ni=0, nc=0;
    for (p=1;p<N;p++)
    {
        for(p; p>0 && A[p]<A[p-1];p--)
        {
            ni+=Cambia(&A[p], &A[p-1]);
        }
    }
    printf("Num intercambios:%d\tNum comparaciones:%d\n", ni, nc);
}


void QS(int A[N], int ini, int fin, int *nc, int *ni)
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
            *ni+=Cambia(&A[p], &A[der]);
            p=der;

            while (A[p]>=A[izq] && p!=izq)
            {
                izq++;
            }
            if(p!=izq)
            {
                *ni+=Cambia(&A[p], &A[izq]);
                p=izq;
                band=1;
                (*nc)++;
            }
            (*nc)++;

        }


    }

    if (p-1 > ini)
    {
        QS(A, ini, p-1, nc, ni);
        (*nc)++;
    }

    if(fin>p+1)
    {
        QS(A, p+1, fin, nc, ni);
        (*nc)++;
    }

}

int Cambia(int *a, int *b)
{
    int x, i=0;
    x=*a;
    *a=*b;
    *b=x;
    i++;
    return (i);
}

void Print(int A[N])
{
    int c;
    for(c=0;c<N;c++)
    {
        printf("%d ", A[c]);
    }

}
