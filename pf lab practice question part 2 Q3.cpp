#include <stdio.h>

int main() {
    int marks;                    
    int pass[10], fail[10];        
    int passCount = 0, failCount = 0; 
    float passSum = 0, failSum = 0;   

   
    printf("   Quiz Marks Storage for Section BDS-1A\n");
    

    printf("\nEnter marks of students (0–10). Enter -1 to stop:\n");

   
    for (int i = 0; i < 10; i++) {
        printf("Enter marks for student %d: ", i + 1);
        scanf("%d", &marks);

        if (marks == -1) {
            break; 
        }

        
        if (marks >= 5 && marks <= 10) {
            pass[passCount] = marks;
            passSum += marks;
            passCount++;
        }

        
        else if (marks >= 0 && marks < 5) {
            fail[failCount] = marks;
            failSum += marks;
            failCount++;
        }

        
        else {
            printf("Invalid marks! Please enter between 0–10.\n");
            i--; 
        }
    }

   
    printf("Marks of Passed Students (>=5):\n");
    if (passCount == 0)
        printf("No pass marks recorded.\n");
    else {
        for (int i = 0; i < passCount; i++)
            printf("%d ", pass[i]);
        printf("\nAverage of Pass Marks: %.2f\n", passSum / passCount);
    }

    printf("\nMarks of Failed Students (<5):\n");
    if (failCount == 0)
        printf("No fail marks recorded.\n");
    else {
        for (int i = 0; i < failCount; i++)
            printf("%d ", fail[i]);
        printf("\nAverage of Fail Marks: %.2f\n", failSum / failCount);
    }

   
    printf("Program Ended.\n");
   

    return 0;
}
