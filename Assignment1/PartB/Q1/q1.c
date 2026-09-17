/*
  Assignment 1 | Part B | Question 1
  Hotel Booking System
  
  Note on Ambiguity: The general assignment instructions advised focusing on 
  single-execution decision structures, but Question 1 explicitly required 
  processing N guests and calculating total hotel revenue. Per class discussion 
  and the question's explicit requirements, a while loop was implemented to 
  handle multiple guests.
*/
#include <stdio.h>
int main() {
    int guests, season, room_type, nights_stay;
    int count = 1;
    float rate = 0, total_cost, discount, discounted_total;
    float hotel_total_revenue = 0;

    printf("Enter the number of guests: ");
    scanf("%d", &guests);

    while (count <= guests) {
        printf("\nGuest %d Booking \n", count);
        printf("Enter season (1 for peak, 2 for off-peak): ");
        scanf("%d", &season);
        
        printf("Enter room type (1 for standard, 2 for deluxe, 3 for suite): ");
        scanf("%d", &room_type);
        
        printf("Enter number of nights stay: ");
        scanf("%d", &nights_stay);
        if (season == 1) {
            if (room_type == 1) rate = 5000;
            else if (room_type == 2) rate = 8000;
            else if (room_type == 3) rate = 12000;
        } else if (season == 2) {
            if (room_type == 1) rate = 3000;
            else if (room_type == 2) rate = 5000;
            else if (room_type == 3) rate = 8000;
        }

        total_cost = rate * nights_stay;
        if (nights_stay > 7) {
            discount = total_cost * 0.15;
            discounted_total = total_cost - discount;
        } else {
            discount = 0;
            discounted_total = total_cost;
        }

        hotel_total_revenue += discounted_total;

        printf("Final price for Guest %d: Rs. %.2f\n", count, discounted_total);
        printf("Discount applied: Rs. %.2f\n", discount);

        count++;
    }

    printf("\n=====\n");
    printf("Hotel's Total Revenue: Rs. %.2f\n", hotel_total_revenue);
    printf("=======\n");

    return 0;
}