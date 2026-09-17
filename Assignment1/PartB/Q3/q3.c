/*
  Assignment 1 | Part B | Question 3
  Student Results Processing System
  
  Note on Ambiguity: The general assignment instructions advised focusing on 
  single-execution decision structures, but Question 3 explicitly required 
  processing N students and 5 subjects per student using repetition. Per class 
  discussion and the question's explicit requirements, nested while loops were 
  implemented to handle the multi-student and multi-subject evaluation logic.
*/
#include <stdio.h>

int main()
{
    int students, i = 1;
    printf("Enter the number of students: ");
    scanf("%d", &students);

    while (i <= students)
    {
        int sum = 0;
        int failed_subject = 0;
        int subject = 1;
        float average;

        printf("\n--- Student %d ---\n", i);
        while (subject <= 5)
        {
            int marks;
            printf("Enter marks for subject %d (out of 100): ", subject);
            scanf("%d", &marks);

            sum += marks;
            if (marks < 33)
            {
                failed_subject++;
            }
            subject++;
        }
        average = (float)sum / 5.0;
        printf("Total marks for student %d: %d\n", i, sum);
        printf("Average marks for student %d: %.2f\n", i, average);
        if (failed_subject > 0)
        {
            printf("Result: Fail Subject Deficiency (%d subject(s) below 33)\n", failed_subject);
        }
        else if (average >= 80)
        {
            printf("Result: Distinction\n");
        }
        else if (average >= 60)
        {
            printf("Result: Pass\n");
        }
        else
        {
            printf("Result: Fail\n");
        }

        i++;
    }

    return 0;
}