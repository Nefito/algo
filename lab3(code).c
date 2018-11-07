#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int i, k, m, c1, c2, c3, c4, c5, c6, counter, len, set1[20], set2[20];
    len = 20, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, counter = 0;
    int ratio[len][len];

    printf("Enter the size of sets A and B: ");
    scanf("%d", &len);
    //here I check the proper input of the size of sets A and B

    if(len > 15 || len < 0)
    {
        do
        {
            printf("Enter a valid length: ");
            scanf("%d", &len);
        }while(len > 15 || len < 0);
    }

    printf("Enter %d elements for set A\n", len);
    for( i = 0; i < len; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &set1[i]);

        if(isalpha(set1[i]))
        {
            printf("Enter a valid number: ");
            scanf("%d", &set1[i]);
        }
    }

    printf("Enter %d elements for the set\n", len);
    for( i = 0; i < len; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &set2[i]);

        while(isalpha(set2[i]))
        {
            printf("Enter a valid number! \n");
            scanf("%d", &set2[i]);
        }
    }

    printf("Set A is:\n{");
    for(i = 0; i < len; i++)
    {
        printf(" %d ", set1[i]);
    }

    printf("}\nSet B is:\n{");
    for(i = 0; i < len; i++)
    {
        printf(" %d ", set2[i]);
    }
    printf("}\n");

    //here we create our matrix
    printf("Your matrix is:\n");
    for( i = 0; i < len; i++)
    {
        for( k = 0; k < len; k++)
        {
            if ( set1[i] < set2[k]*3)
            {
                ratio[i][k] = 1;
                counter++;
            }
            else
            {
                ratio[i][k] = 0;
            }
            printf(" %d ", ratio[i][k]);
        }
        printf("\n");
    }

    //and this mumbo-jumbo is for cheking the type of our matrix
    for(i = 0; i < len; i++)
    {
        if(ratio[i][i] == 1)
        {
            c1++;
        }
        else if(ratio[i][i] == 0)
        {
            c2++;
        }

        for(k = 0; k < len; k++)
        {

            if(ratio[i][k] == ratio[k][i])
            {
                c3++;
            }
            else if(ratio[i][k] != ratio[k][i])
            {
                c4++;
            }
        }
    }

 //here I check if the matrix is transitive or antitransitive
    for( i = 0; i < len; i++)
    {
        for(k = 0; k < len; k++)
        {
            for(m = 0; m < len; m++)
            {
                if(ratio[i][k] == 1 && ratio[k][m] == 1 && ratio[i][k] == 1)
                {
                    c5++;
                }
                else if(ratio [i][k] == 1 && ratio[k][m] == 1 && ratio[i][k] == 0)
                {
                    c6++;
                }
            }
        }
    }

 // i'm cheking if the following matrix is reflexive or antireflexive
    if(c1 == len)
    {
        printf("Your matrix is reflexive\n");
    }
    else if(c2 == len)
    {
        printf("Your matrix is antireflexive\n");
    }
    else if(c1 != len  && c2 != len)
    {
        printf("Your matrix is not reflexive nor antireflexive\n");
    }

 //here i'm checking if it's symmetrical or antisymmetrical
    if(c3 == len*len)
    {
        printf("Your matrix is symmetrical\n");
    }
    else if(c4 == len*len)
    {
        printf("Your matrix is asymmetrical\n");
    }
    else if(c3 != len*len && c4 != len*len)
    {
        printf("Your matrix is not symmetrical nor antisymmetrical\n");
    }

        //and here if it's transitive or antitransitive
    if(counter == len*len)
    {
        printf("Your matrix is transitive\n");
    }
    else if(counter == 0)
    {
        printf("Your matrix is antitransitive\n");
    }
    else if(counter > 0 && counter < len*len)
    {
        printf("Your matrix is not transitive nor antitransitive\n");
    }

    return 0;
}
