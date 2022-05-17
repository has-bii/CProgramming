#include <stdio.h>

int Division(int x, int y) //Multiplication without "*"
{

    if (y <= 2)
    {
        return x+x;
    } else 
    {

        return (x+Division(x, y-1));
    }
        
    
}

int main()
{
    int x, y;

    printf("Enter the base number : ");
    scanf("%d", &x);
    printf("Enter the multipler number : ");
    scanf("%d", &y);

    printf("%d", Division(x, y));

    return 0;
}