#include <stdio.h>
#include <stdlib.h>
//TEMA:1.FUNCTIE CARE PRIMESTE UN VECTOR SI DIMENSIUNEA SA, NUMERIC, SI INLOCUIESTE CU -1 VALOAREA MINIMA DIN VECTOR, ORI DE CATE ORI APARE.
//2. FUNCTIE CU VECTOR SI DIMENSIUNEA SA SI ELIMINA VALOAREA MAXIMA, INDIFERENT DE CATE ORI APARE.
//3. FUNCTIE CARE PRIMESTE VECTOR SI DIMENSIUNEA SA SI ELIMINA VALORILE CARE SE REPETA, PASTRAND-O DOAR PE PRIMA, FARA VECTOR DE FRECVENTA.
//+ CALCULAT ORDINUL DE COMPLEXITATE PT FIECARE DINTRE ELE.
// DE FACUT CU ALOCARE DINAMICA!!! FARA REALLOC.

void minim(int w[], int n)//complexitate O(n)
{
    int i, min = w[0];
    for (i = 0; i < n; i++)
    {
        if (w[i] < min)
            min = w[i];
    }
    for (i = 0; i < n; i++)
    {
        if (min == w[i])
            w[i] = -1;
    }

}

void maxim(int w[], int* n)//complexitate O(n*n)
{
    int i, max = w[0];
    for (i = 0; i < *n; i++)
    {
        if (max < w[i])
            max = w[i];
    }
    for (i = 0; i < *n; i++)
    {
        if (w[i] == max)
        {
            for (int j = i; j < *n; j++)
                w[j] = w[j + 1];
            (*n)--;
            i--;
        }

    }
}
void repetare(int w[], int* n) //complexitate O(n*n*n)
{
    int i, j;

    for (i = 0; i < *n; i++) {
        for (j = i + 1; j < *n; ) {
            if (w[i] == w[j]) {
                for (int p = j; p < *n - 1; p++) {
                    w[p] = w[p + 1];
                }
                (*n)--;
            }
            else {
                j++;
            }
        }
    }
}




int main() {
    int i, min = 0, n = 8;
    int* dv = (int*)malloc(n * sizeof(int));

    if (dv == NULL) {
        printf("Alocare esuata.\n");
        return 1;
    }
    int v[] = { 5, 6, 0, 8, 7, 9, 0, 21 };
    for (i = 0; i < n; ++i) {
        dv[i] = v[i];
    }
    minim(dv, &n);
    printf("%d \n", n);
    printf("Continut nou al vectorului dinamic: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", dv[i]);
    }
    printf("\n");

    free(dv);
    return 0;
}
