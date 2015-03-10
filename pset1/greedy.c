#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Constant with coin values
    const int coins[4] = {25, 10, 5, 1};
    // const int coinNum = 4;
    
    // Get the cash:
    float cash;
    do 
    {
        printf("How much change in US$? ");
        cash = GetFloat();
    } while (cash < 0.0);
    
    // We will count in cents
    cash = round(cash*100);
    
    // Repeat until cash is 0:
    int num = 0; // Number of coins neededs
    int maxIndex = 0; // Maximum coin value index so far
    while(true)
    {
        if (cash == 0)
        {
            break;
        }
        
        if (cash >= coins[maxIndex])
        {
            // printf("%f, %f, %d\n", cash, cash / coins[maxIndex], (int)cash % coins[maxIndex]);
            num += cash / coins[maxIndex];
            cash = (int)cash % coins[maxIndex];
            
        } else {
            maxIndex++;
            continue;
        }
    }
    
    printf("%d\n", num);
}




