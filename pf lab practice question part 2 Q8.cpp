#include <stdio.h>

int main() {
    char str[100];   

    
    printf("     Non-Alphabetic Character Collector\n");
   

    printf("\nEnter a mix of alphabets, numbers, or symbols:\n");
    printf("(Program will store only NON-ALPHABETIC characters)\n\n");

    
    scanf("%[^A-Za-z]", str);

   
    printf("The non-alphabetic characters you entered are:\n");
    printf("%s\n", str);
   
    printf("Program ended successfully.\n");

    return 0;
}
