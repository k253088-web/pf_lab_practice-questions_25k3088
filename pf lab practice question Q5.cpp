#include <stdio.h>


int areLayersSame(int a[3][3], int b[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] != b[i][j])
                return 0; 
        }
    }
    return 1; 
}

int main() {
    int arr[3][3][3]; )
    int i, j, k;

    
    printf("      3󫢫 MATRIX LAYER SIMILARITY CHECK       \n");
    
    printf("\nEnter elements for the 3󫢫 matrix:\n");
    for (i = 0; i < 3; i++) {
        printf("\n--- Enter elements for Layer %d ---\n", i + 1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("Element[%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    printf("                DISPLAYING LAYERS              \n");
    
    for (i = 0; i < 3; i++) {
        printf("\nLayer %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("%4d", arr[i][j][k]);
            }
            printf("\n");
        }
    }

   
   
    printf("             LAYER SIMILARITY REPORT            \n");
   
    if (areLayersSame(arr[0], arr[1]))
        printf("Layer 1 and Layer 2 are IDENTICAL.\n");
    else
        printf("Layer 1 and Layer 2 are DIFFERENT.\n");

    /
    if (areLayersSame(arr[0], arr[2]))
        printf("Layer 1 and Layer 3 are IDENTICAL.\n");
    else
        printf("Layer 1 and Layer 3 are DIFFERENT.\n");

    
    if (areLayersSame(arr[1], arr[2]))
        printf("Layer 2 and Layer 3 are IDENTICAL.\n");
    else
        printf("Layer 2 and Layer 3 are DIFFERENT.\n");

  
    printf("          END OF SIMILARITY ANALYSIS           \n");
   
    return 0;
}
