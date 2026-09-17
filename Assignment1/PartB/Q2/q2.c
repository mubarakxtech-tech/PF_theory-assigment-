/*
  Assignment 1 | Part B | Question 2
  Elevator Control System
  
  Note on Ambiguity: While the scenario mentions receiving a "list of floor requests" 
  (which could imply an array or string input), the assignment constraints prioritize 
  sequential decision-making structures. Therefore, an iterative loop is used to 
  process each floor request sequentially one at a time, updating the elevator's 
  current floor dynamically per iteration.
*/
#include<stdio.h>
int main()
{
    int current_floor = 0, requested_floor,i;
    printf("Enter the number of floor requests: ");
    scanf("%d", &i);
    while(i--)
    {
        printf("Enter requested floor: ");
        scanf("%d", &requested_floor);
        if(requested_floor > current_floor)
        {
            printf("Elevator moving up from floor %d to floor %d\n", current_floor, requested_floor);
        }
        else if(requested_floor < current_floor)
        {
            printf("Elevator moving down from floor %d to floor %d\n", current_floor, requested_floor);
        }
        else
        {
            printf("Elevator is already on floor %d\n door opening...", current_floor);
        }
        current_floor = requested_floor;
    }
    
    return 0;
}