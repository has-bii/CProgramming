#include <stdio.h>

int FirstDigit(int x)
{

    if (x < 10)
    {
        return x;
    } else
    {
        return (FirstDigit(x/10));
    }

}

void main()
{
    int x;

    printf("Enter the number : ");
    scanf("%d", &x);

    printf("%d", FirstDigit(x));
}