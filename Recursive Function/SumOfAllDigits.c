#include <stdio.h>

int y, z;  

int SumOfAllDigits(int x) //Sum of all digits
{  
    if (x <= 9)
    {
       return x;
    } else
    {
        return (x%10 + SumOfAllDigits(x/10));
    }
}

void main()
{
    int x;

    printf("Enter N number : ");
    scanf("%d", &x);

    printf("%d", SumOfAllDigits(x));
}