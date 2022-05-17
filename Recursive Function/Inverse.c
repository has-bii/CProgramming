#include <stdio.h>

int y, z;  

int inverse(int x) //Inverse number
{  
    if (x <= 9)
    {
       return z = z*10 + x;
    } else
    {

        y = x%10;

        if (z == 0)
        {
            z = y;
        } else
        {
            z = z*10 + y;
        }        

        return (inverse(x/10));
    }
    
}

void main()
{
    int x;

    printf("Enter N number : ");
    scanf("%d", &x);

    printf("%d", inverse(x));
}