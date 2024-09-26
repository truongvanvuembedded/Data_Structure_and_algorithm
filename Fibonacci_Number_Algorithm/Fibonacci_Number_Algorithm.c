#include <stdio.h>

#define USING_LOOP_METHOD   0

// Using Recursion to find Fiboracci number
#if !USING_LOOP_METHOD
// void Recursion_Funtion(int u4_a, int u4_b, int u4_d)
// {
//     u4_b += u4_a;
//     u4_a = u4_b - u4_a;
    
//     printf("%d, ",u4_b);
//     if (u4_d > 0)
//     { 
//         u4_d--;
//         Recursion_Funtion(u4_a, u4_b, u4_d);
//     }
// }

int Recursion_method(int u4_d)
{
    if (u4_d <= 1)
        return u4_d;
    else
        return (Recursion_method(u4_d - 1)  + Recursion_method(u4_d - 2));
}
#endif

int main()
{
    
    int u4_a = (int)0;
    int u4_b = (int)1;
    int u4_d = (int)0;

    printf("Please, Type number to Calculate Fiboracci number: ");
    scanf("%d",&u4_d);
    printf("The Fiboracci number: %d, %d, ",u4_a,u4_b);

#if USING_LOOP_METHOD
    for (; u4_d > 0; u4_d--)
    {
        u4_b += u4_a;
        u4_a = u4_b - u4_a;
        printf("%d, ", u4_b);
    }
#else
    //Recursion_Funtion(u4_a,u4_b,u4_d);
    u4_d = Recursion_method(u4_d);
    printf("%d, ", u4_d);
#endif    

    return 0;
}