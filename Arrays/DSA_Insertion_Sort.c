// To implement the Insertion Sort algorithm in a programming language, we need:

// An array with values to sort.
// An outer loop that picks a value to be sorted. For an array with n values, this outer loop skips the first value, and must run n?1 times.
// An inner loop that goes through the sorted part of the array, to find where to insert the value. If the value to be sorted is at index i, the sorted part of the array starts at index 0 and ends at index i?1.


#include <stdio.h>
#include <stdlib.h> 

int main()
{
    int *arr = NULL;
    int index = 0;
    int input;
    int temp_value = 0;

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

        // Add element to array
        arr[index] = input;
        index++;
    }

    printf("Input Arrays is: ");
    for (int i = 0; i < index; i++)
    {
        printf("%d, ", arr[i]);
    }

    for (int j = 1; j < index; j++)
    {
        for (int i = 0; i < j; i++)
        {
            if (arr[i] > arr[j])
            {
                temp_value = arr[j];
                for (; j > i; j--)
                {
                    arr[j] = arr[j-1];
                }
                arr[i] = temp_value;
                
                break;
            }
        }                
    }

    printf("\nArray from the lowest value to the highest value: ");
    for (int i = 0; i < index ; i++)
    {
        printf("%d, ", arr[i]);
    }
    
    return 0;
}


