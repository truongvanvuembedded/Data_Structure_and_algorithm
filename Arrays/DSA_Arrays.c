#include <stdio.h>
#include <stdlib.h> 

int main()
{
    int *arr = NULL;
    int index = 0;
    int input;
    int output;

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

    output = arr[0];
    for (int i = 0; i < index; i++)
    {
        if (output > arr[i])
        {
            output = arr[i];
        }
    }
    
    printf("\nLowest value of array is: %d", output);
    return 0;
}