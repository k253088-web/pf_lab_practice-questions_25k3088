#include <stdio.h>

int main() {
    int arr[10];   
    int i, j;      
    int current;   

   
    printf("    Duplicate Remover - Data Management Tool\n");
    

    
    printf("\nEnter 10 integer IDs:\n");
    for (i = 0; i < 10; i++) {
        printf("ID %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    /
    for (i = 0; i < 10; i++) {
        current = arr[i];
        if (current == -1)  
            continue;

        
        j = i + 1;
        while (j < 10) {
            if (arr[j] == current) {
                arr[j] = -1; 
            }
            j++;
        }
    }

   
    printf("\nUpdated Array (duplicates replaced with -1):\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

   
    printf("Program ended successfully.\n");
    

    return 0;
}
