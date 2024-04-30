#include <stdio.h>
#include <stdlib.h>

int policeThief(char arr[], int n, int k) {
    int i = 0, l = 0, r = 0, res = 0;
    int thi[n], pol[n]; // Usamos arreglos de tamaño n para almacenar los índices
    int thiSize = 0, polSize = 0;

    // Almacenamos los índices en los arreglos
    for (i = 0; i < n; i++) {
        if (arr[i] == 'P')
            pol[polSize++] = i;
        else if (arr[i] == 'T')
            thi[thiSize++] = i;
    }

    // Seguimos los índices mínimos actuales de ladrones (thi[l]) y policías (pol[r])
    while (l < thiSize && r < polSize) {
        // Puede ser atrapado
        if (abs(thi[l] - pol[r]) <= k) {
            res++;
            l++;
            r++;
        }
        // Incrementamos el índice mínimo
        else if (thi[l] < pol[r])
            l++;
        else
            r++;
    }

    return res;
}

int main() {
	
	// caso 1
    char arr1[] = {'P', 'T', 'T', 'T', 'T', 'P', 'T', 'P', 'T', 'P'};
    int k = 2;
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("Maximo de ladrones atrapados: %d\n", policeThief(arr1, n, k));

	// caso 2
    /*char arr2[] = {'T', 'T', 'P', 'T', 'T', 'P', 'T', 'T', 'P', 'P'};
    int k = 1; 
    int n = sizeof(arr2) / sizeof(arr2[0]);
    printf("Maximo de ladrones atrapados: %d\n", policeThief(arr2, n, k));*/
    
	// caso 3
    /*char arr3[] = {'P', 'T', 'P', 'T', 'P', 'T', 'P', 'T', 'P', 'T'};
    int k = 3;
    int n = sizeof(arr3) / sizeof(arr3[0]);
    printf("Maximo de ladrones atrapados: %d\n", policeThief(arr3, n, k));*/

    return 0;
}
