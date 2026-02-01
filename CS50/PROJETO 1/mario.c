#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int Height;

    do
    {
        Height = get_int("How tall should the blocks be?");
    }
    while (Height < 1 || Height > 8);

    for (int i = 1; i <= Height; i++)
    {
        for (int j = 0; j < Height - i; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
