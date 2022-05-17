#include <stdio.h>

void Count(int N) //Counting form 1 to N only odd numbers
{

    if (N <= 1)
    {
        printf ("%d", N);
    } else
    {
        Count(N-1);

        if (N%2==1)
        {
            printf ("%3d", N);
        }
        
    }

}

void main()
{
    int x;

    printf("Enter N number : ");
    scanf("%d", &x);

    Count(x);
}