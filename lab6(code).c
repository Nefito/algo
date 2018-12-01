#include <stdio.h>
#include <math.h>

int fact(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}

int F(int k, int l)
{
    return fact(k)/(fact(l)*fact(k-l));
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void lexSwap(int len, int a[])
{
    int i, k, j, counter = 0;
    for(i = len-1; i >= 0; i--)
    {
        if(a[i] > a[i-1])
        {
            for(k = i+1; k < len; k++)
            {
                if(a[i] > a[k])
                {
                    counter++;
                }
            }

            if(counter != len - i - 1)
            {
                counter = 0;
            }
            else
            {
                break;
            }
        }
    }
    if(counter == len - i - 1)
    {
        swap(&a[i], &a[i-1]);
        for(k = i; k < len; k++)
        {
            for( j = k+1; j < len; j++)
            {
                if(a[k] > a[j])
                {
                    swap(&a[k], &a[j]);
                }
            }
        }
    }
}


int main()
{
    int len1 = 4, len2 = 5, len3 = 5, len4 = 5, len5 = 7, len6 = 8, n = 8, result = 0, m, j, i, x, y;
    int a1[] = {1, 4, 3, 2};
    int a2[] = {5, 4, 1, 2, 3};
    int a3[] = {1, 2, 4, 5, 3};
    int a4[] = {4, 5, 2, 3, 1};
    int a5[] = {6, 7, 1, 4, 2, 3, 5};
    int a6[] = {3, 1, 5, 2, 8, 7, 6, 4};

    printf("Set 1 is: \n");
    for(int k = 0; k < len1; k++)
    {
        printf(" %d ", a1[k]);
    }printf("\n");

    printf("Set 2 is: \n");
    for(int k = 0; k < len2; k++)
    {
        printf(" %d ", a2[k]);
    }printf("\n");

    printf("Set 3 is: \n");
    for(int k = 0; k < len3; k++)
    {
        printf(" %d ", a3[k]);
    }printf("\n");

    printf("Set 4 is: \n");
    for(int k = 0; k < len4; k++)
    {
        printf(" %d ", a4[k]);
    }printf("\n");

    printf("Set 5 is: \n");
    for(int k = 0; k < len5; k++)
    {
        printf(" %d ", a5[k]);
    }printf("\n");

    printf("Set 6 is: \n");
    for(int k = 0; k < len6; k++)
    {
        printf(" %d ", a6[k]);
    }printf("\n");

    lexSwap(len1, a1);
    lexSwap(len2, a2);
    lexSwap(len3, a3);
    lexSwap(len4, a4);
    lexSwap(len5, a5);
    lexSwap(len6, a6);

    printf("The next lexicographic permutation for set 1 is:\n");
    for(i = 0; i < len1; i++)
    {
        printf(" %d ", a1[i]);
    }printf("\n");

    printf("The next lexicographic permutation for set 2 is:\n");
    for(i = 0; i < len2; i++)
    {
        printf(" %d ", a2[i]);
    }printf("\n");

    printf("The next lexicographic permutation for set 3 is:\n");
    for(i = 0; i < len3; i++)
    {
        printf(" %d ", a3[i]);
    }printf("\n");

    printf("The next lexicographic permutation for set 4 is:\n");
    for(i = 0; i < len4; i++)
    {
        printf(" %d ", a4[i]);
    }printf("\n");

    printf("The next lexicographic permutation for set 5 is:\n");
    for(i = 0; i < len5; i++)
    {
        printf(" %d ", a5[i]);
    }printf("\n");

    printf("The next lexicographic permutation for set 6 is:\n");
    for(i = 0; i < len6; i++)
    {
        printf(" %d ", a6[i]);
    }printf("\n");

    //this is for the binomial theorem
    printf("Enter a value for x: \n");
    scanf("%d", &x);

    printf("Enter a value for y: \n");
    scanf("%d", &y);
    y *= -1;

    for(j = 0, m = n, i = 0; i <= n; i++, m--, j++)
    {
        result += F(n, j)*pow(x, m)*pow(y, j);
    }
    printf("(%d%d)^8 = %d\n", x, y, result);

    return 0;
}
