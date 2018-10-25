#include <stdio.h>
#include <math.h>

int main()
{
    int length, i, k, count;
    count = 0;
    char U[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    char arr1[30];
    int arr2[30];
    char bool[30];

    printf("Enter the length of the array: ");
    scanf("%d", &length);

    while (length > 29 || length < 0)
    {
        printf("enter a valid length: ");
        scanf("%d", &length);
    }
    printf("Enter %d elemements of the array:\n", length);
    for (i = 0; i < length; i++)
    {
        printf("Enter the element %d for the array: ", i);
        scanf("%s", &arr1[i]);

        while( arr1[i] < 'a' || arr1[i] > 'z')
        {
            printf("Enter a lowercase character: ");
            scanf("%s", &arr1[i]);
        }

    }

    printf("Your array is:{ ");
    for(i = 0; i < length; i++)
    {
        printf(" %c ", arr1[i]);
    }
    printf(" }\n");

    printf("The complement for you array is:\n { ");
    for(i = 0; i < 26; i++)
    {
        count = 0;
        for(k = 0; k < length; k++)
        {
            if(U[i] != arr1[k])
            {
                count++;
            }
        }
        if ( count == length)
        {
            printf(" 1 ");
        }
        else
        {
            printf(" 0 ");
        }
    }
    printf(" }\n");

    printf("The Boolean is %0.lf\n", pow(2 , length));
    return 0;
}
