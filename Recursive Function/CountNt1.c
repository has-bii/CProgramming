#include <stdio.h>

void Count(int N) //Counting form N to 2 only even numbers
{

    if (N <= 2)
    {
        printf ("%3d", N);
    } else
    {
        
        if (N%2==0)
        {
            printf ("%3d", N);
        }

        Count(N-1);
    }

}

void main()
{
    int x;

    printf("Enter N number : ");
    scanf("%d", &x);

    Count(x);
}