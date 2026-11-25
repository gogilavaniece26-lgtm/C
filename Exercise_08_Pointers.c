#include <stdio.h>
#include <stdlib.h>

/* Call by Value */
int addByValue(int a, int b)
{
    int res;
    res = a + b;
    return res;
}

/* Call by Reference */
void swapByReference(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b, res;
    int *ptr;
    int *arr;
    int n, i, sum;

    printf("Enter the first number: ");
    if (scanf("%d", &a) != 1)
        return 1;

    printf("Enter the second number: ");
    if (scanf("%d", &b) != 1)
        return 1;

    /* Pointer Demonstration */
    ptr = &a;
    printf("\nPointer Demonstration:\n");
    printf("Value of a = %d\n", *ptr);
    printf("Address of a = %p\n", (void *)ptr);

    /* Call by Value */
    res = addByValue(a, b);
    printf("\nCall by Value:\n");
    printf("Sum = %d\n", res);

    /* Call by Reference */
    swapByReference(&a, &b);
    printf("\nCall by Reference:\n");
    printf("After swapping, first number = %d\n", a);
    printf("After swapping, second number = %d\n", b);

    /* Dynamic Memory Allocation */
    printf("\nDynamic Memory Allocation\n");
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    arr = (int *)malloc((size_t)n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    printf("Sum of dynamically allocated array = %d\n", sum);

    free(arr);
    return 0;
}
