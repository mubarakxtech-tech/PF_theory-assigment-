#include <stdio.h>

int main()
{
    int quantity, price_per_item;
    float discount_per, tax_per, sub_total, discounted_amount, final_bill;

    printf("Enter the quantity of items purchased: ");
    scanf("%d", &quantity);
    printf("Enter the price per item: ");
    scanf("%d", &price_per_item);
    printf("Enter the discount percentage: ");
    scanf("%f", &discount_per);
    printf("Enter the tax percentage: ");
    scanf("%f", &tax_per);
    if ((quantity <= 0 || price_per_item <= 0) || (discount_per < 0 || tax_per < 0) || (discount_per >= 100 || tax_per >= 100))
    {
        printf("Error: Invalid input values entered.\n");
        return 1; 
    }
    sub_total = quantity * price_per_item;
    discounted_amount = sub_total - (sub_total * (discount_per / 100.0));
    final_bill = discounted_amount + (discounted_amount * (tax_per / 100.0));

    printf("Subtotal: %.2f\n", sub_total);
    printf("Discounted Amount: %.2f\n", discounted_amount);
    printf("Final Bill: %.2f\n", final_bill);

    return 0;
}