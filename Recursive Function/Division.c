#include <stdio.h>

int Division(int x, int y) //Division without "/"
{

    if (x <= y)
    {
        return 1;
    } else 
    {
        return (1+Division(x-y, y));
    }
        
    
}

int main()
{
    int x, y;

    printf("Enter the base number : ");
    scanf("%d", &x);
    printf("Enter the divider number : ");
    scanf("%d", &y);

    printf("%d", Division(x, y));

    return 0;
}