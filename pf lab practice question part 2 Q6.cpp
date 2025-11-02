#include <stdio.h>

int main() {
    char str[100];      
    int i = 0;          
    int vowels = 0;      
    int consonants = 0;  

   
    printf("   Vowel and Consonant Counter Program\n");
    

    printf("\nEnter a word: ");
    scanf("%[^\n]", str);  

    
    while (str[i] != '\0') {
        char ch = str[i]; 

        
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowels++;
        }
        
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            consonants++;
        }

        i++;
    }

    printf("\nNumber of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

   
    printf("Program ended successfully.\n");
   
    return 0;
}

