#include <stdio.h>

int main() {
    char str[100];  
    int i = 0;      

    
    printf("   Mixed-Case Message Converter Program\n");
    

    printf("\nEnter a sentence: ");
    scanf("%[^\n]", str); 

    
    while (str[i] != '\0') {
        
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; 
        }
        
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        
        i++;
    }

    printf("\nConverted message: %s\n", str);

   
    printf("Program ended successfully.\n");
    
    return 0;
}
