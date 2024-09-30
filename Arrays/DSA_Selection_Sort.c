// To implement the Selection Sort algorithm in a programming language, we need:

// An array with values to sort.
// An inner loop that goes through the array, finds the lowest value, and moves it to the front of the array. This loop must loop through one less value each time it runs.
// An outer loop that controls how many times the inner loop must run. For an array with n values, this outer loop must run n ? 1 times.

#include <stdio.h>
#include <stdlib.h> 

int main()
{
    int *arr = NULL;
    int index = 0;
    int input;
    int *temp_value = NULL;

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

    for (int j = 0; j < index - 1; j++)
    {
        for (int i = 0; i < (index - 1 - j); i++)
        {
            if (arr[i] > arr[i+1])
            {
                temp_value = &arr[i+1];
            }
        }
        if (temp_value != NULL)
        {
            *temp_value = arr[j] + *temp_value;
            arr[j] = *temp_value - arr[j];
            *temp_value = *temp_value - arr[j];
        }
                
    }

    printf("\nArray from the lowest value to the highest value: ");
    for (int i = 0; i < index - 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    
    return 0;
}


