#include <stdio.h>

int SumOfArray(int array[], int size)
{
    if (size == 1)
    {
        return array[size-1];
    } else
    {
        return (array[size-1] + SumOfArray(array, size-1));
    }
    
    
}

void main()
{
    int N;

    printf("Enter N number : ");
    scanf("%d", &N);

    int array[N];

    for (int i = 0; i < N; i++)
    {
        printf("Enter a number for array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    printf ("%d", SumOfArray(array, N));
}