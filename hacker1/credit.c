#include <stdio.h>
#include <math.h>
#include <cs50.h>

bool luhn(long long num, int len)
{
    int part = 0;
    int sum = 0;
    while(num) 
    {
        sum += num % 10;
        part = 2 * ((num / 10) % 10);
        if (part > 9) 
        {
            part = (part % 10) + 1;
        }
        sum += part;
        num = floor(num / 100.0);
    }
    return !(sum % 10);
}

void validateCard(long long num)
{
    /*
     American Express uses 15-digit numbers, starting with 34 or 37;
     MasterCard uses 16-digit numbers, start with 51, 52, 53, 54, or 55;
     Visa uses 13- and 16-digit numbers, starting with 4
     */
    // Get length:
    int length = floor(log10(num)) + 1;
    // Get first two digits:
    int firstTwo = num / pow(10, length - 2);
    
    // We don't care about perormance, so always check luhn:
    if (!luhn(num, length)) 
    {
        printf("INVALID\n");
        return;
    }
    
    // Check if AMEX
    if (length == 15 && (firstTwo == 34 || firstTwo == 37)) 
    {
        printf ("AMEX\n");
        return;
    }
    
    // Check if Mastercard
    if (length == 16 && firstTwo >= 51 && firstTwo <= 55) 
    {
        printf ("MASTERCARD\n");
        return;
    }
    
    // Check if Visa:
    if ((length == 13 || length == 16) && (firstTwo / 10 == 4)) 
    {
        printf ("VISA\n");
        return;
    }
    
    printf ("INVALID\n");
    return;
}

int main(void)
{
    // Get the credit card number:
    printf("Number: ");
    long long num = GetLongLong();
    validateCard(num);
}
