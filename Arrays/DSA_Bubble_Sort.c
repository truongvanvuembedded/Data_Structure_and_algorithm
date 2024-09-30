// How it works:

// Go through the array, one value at a time.
// For each value, compare the value with the next value.
// If the value is higher than the next one, swap the values so that the highest value comes last.
// Go through the array as many times as there are values in the array.

// To implement the Bubble Sort algorithm in a programming language, we need:

// An array with values to sort.
// An inner loop that goes through the array and swaps values if the first value is higher than the next value. This loop must loop through one less value each time it runs.
// An outer loop that controls how many times the inner loop must run. For an array with n values, this outer loop must run n-1 times.

#include <stdio.h>
#include <stdlib.h> 

int main()
{
    int *arr = NULL;
    int index = 0;
    int input;

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
    

    // Outer loop that controls how many times the inner loop must run.
    // Why (j < index - 1?)
    // Because each loop -> the lagest value is pull to last position 
    // So, for 5 index in arrays -> Loop need 4 loop 
    for (int j = 0; j < index - 1; j++)
    {
        // Inner loop that control how many element of array is loop.
        // Why (i < index - j - 1) 
        // Because -1. Same the outer loop
        // -j Because. After each loop, the lagest value is moved to right position. 
        // So, don't need check it
        for (int i = 0; i < index - j - 1; i++)
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