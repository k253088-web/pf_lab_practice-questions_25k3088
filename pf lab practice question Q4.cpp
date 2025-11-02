#include <stdio.h>

int main() {
    int arr[3][3][3];  
    int i, j, k;
    int layerSum, totalSum = 0;
    float totalElements = 27;  

   
    printf("        3󫢫 MATRIX (3D ARRAY) ANALYSIS       \n");
   

    
    printf("\nEnter 27 elements for the 3D array:\n");
    for (i = 0; i < 3; i++) {
        printf("\n--- Enter elements for Layer %d ---\n", i + 1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("Element[%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    
    
    printf("            LAYER-WISE ANALYSIS                \n");
    

    for (i = 0; i < 3; i++) {
        layerSum = 0;
        printf("\nLayer %d:\n", i + 1);

        
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("%4d", arr[i][j][k]);
                layerSum += arr[i][j][k];
            }
            printf("\n");
        }

        printf("? Sum of Layer %d = %d\n", i + 1, layerSum);
        totalSum += layerSum;
    }

    
    float average = totalSum / totalElements;

    
    printf("Total Sum of all elements     = %d\n", totalSum);
    printf("Average of all elements       = %.2f\n", average);

    
    int max = arr[0][0][0];
    int min = arr[0][0][0];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                if (arr[i][j][k] > max)
                    max = arr[i][j][k];
                if (arr[i][j][k] < min)
                    min = arr[i][j][k];
            }
        }
    }

    printf("Maximum element in array      = %d\n", max);
    printf("Minimum element in array      = %d\n", min);

   
    printf("     End of 3D Matrix Analysis Program         \n");
    
    return 0;
}
