#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x, y, sum, point;

    for (int i = 0;; i++)
    {
        printf("Press ENTER key to throw dice\n");
        getchar();

        printf("\nNumber of throw = %d\n", i+1);

        srand(time(NULL));

        x = 1 + rand() % 6;
        printf("Die one = %d\n", x);
        y = 1 + rand() % 6;
        printf("Die two = %d\n", y);

        sum = x + y;
        printf("Sum of throw = %d\n", sum);

        if (sum == 7 || sum == 11)
        {

            if (i == 0)
            {
                printf("CONGRATULATION! YOU WIN!\n\n");
                break;
            }

        } else if (sum == 2 || sum == 3 || sum == 12)
        {

            if (i == 0)
            {
                printf("YOU LOSE!\n\n");
                break;
            }

        } else if (sum == 4 || sum == 5 || sum == 6 || sum == 8 || sum == 9 || sum == 10)
        {

            if (i == 0)
            {

                point = sum;
                printf("Your point is %d\n\n", point);

            } else if (sum == point)
            {
                
                printf("CONGRATULATION! YOU WIN!\n\n");
                break;

            }
            
        }       

    }

    printf("Game Finished!\n\n");
    return 0;
}