#include <stdio.h>
#include <stdlib.h> 

int main()
{
    int *arr = NULL;
    int index = 0;
    int input;
    int value_1;
    int value_2;

    printf("\nType the element number of array");
    printf("\nType negative number to end array");
    while (1)
    {
        printf("\nType number: ");
        scanf("%d", &input);
        if (input < 0)
        {
            break;
        }

        int *temp = realloc(arr, (index + 1) * sizeof(int));
        if (temp == NULL) {
            printf("\nError re-allocate memory\n");
            free(arr);
            return 1;
        }
        arr = temp;

        // Th?m ph?n t? v?o m?ng
        arr[index] = input;
        index++;
    }


    for (int j = 0; j < index; j++)
    {
        for (int i = 0; i < index - j; i++)
        {
            if (arr[i] > arr[i+1])
            {
                arr[i] = arr[i] + arr[i+1];
                arr[i+1] = arr[i] - arr[i+1];
                arr[i] = arr[i] - arr[i+1];
            }
        }
    }  

    printf("\nArray from the lowest value to the highest value: ");
    for (int i = 0; i < index; i++)
    {
        printf("%d, ", arr[i]);
    }
    
    return 0;
}