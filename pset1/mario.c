#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get user input:
    int height;
    do
    {
        printf ("Height: ");
        height = GetInt();
    } while (height < 0 || height > 23);

    // Loop through rows:
    for (int row = 1; row <= height; row++)
    {
        // For row n < height, draw height-n blanks and n #'s:
        // Format: blank #'s space #'s
        for (int j = 0, blanks = height - row; j < blanks; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < row; j++)
        {
            printf("#");
        }
        /*
        printf("  ");
        for (int j = 0; j < row; j++)
        {
            printf("#");
        }
        */
        
        printf("#\n");
    }
    return 0;
}

