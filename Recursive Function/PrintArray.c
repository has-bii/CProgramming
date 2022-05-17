#include <stdio.h>

void PrintArray(int array[], int size)
{
    if (size == 1)
    {
        printf("%d", array[size-1]);
    } else
    {
        PrintArray(array, size-1);
        
        printf("%3d", array[size-1]);
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

    PrintArray(array, N);
}