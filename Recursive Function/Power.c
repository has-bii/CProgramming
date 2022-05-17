#include <stdio.h>

int Power(int x, int y)
{
    if (y == 1)
    {
        return x;
    } else
    {
        return (x*Power(x, y-1));
    }
    
}

int main()
{
    int x, y;

    printf("Enter base number : ");
    scanf("%d", &x);
    printf("Enter power number : ");
    scanf("%d", &y);

    printf("%d", Power(x, y));

    return 0;
}