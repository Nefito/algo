#include<stdio.h>

typedef struct
{
    int first_vertex;
    int second_vertex;
    int weight;
}rib;

int el_in_array(int arr[],int size,int element)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == element)
        {
            return 1;
        }
    }
    return 0;
}

rib min_weight(rib a[], int length)
{
    rib min;
    min = a[0];
    for(int i = 0; i < length; i++)
    {
        if(a[i].weight < min.weight)
        {
            min = a[i];
        }
    }
    return min;
}
int ver_in_array(int arr[], int size, int vertex )
{
    for(int i = 0; i<size; i++)
    {
        if(arr[i] == vertex)
        {
            return 1;
        }
    }

return 0;
}

int main()
{
    int i, num, counter = 0, ver_count = 1, a_rcount = 0;;

    printf("Enter the number of ribs for your tree: ");
    scanf("%d", &num);
    if(num > 20 || num < 0)
    {
        printf("Enter a number greater than 0 and less than 20");
        scanf("%d", &num);
    }

    rib ribs[num];
    int vertexes[2*num], ost_vertexes[11], active_vertexes[11];

    for(i = 0; i < num; i++)
    {
        printf("Enter the first vertex for rib #%d: \n", i);
        scanf("%d", &ribs[i].first_vertex);

        printf("Enter the second vertex for rib # %d \n", i);
        scanf("%d", &ribs[i].second_vertex);

        printf("Enter the weight of rib #%d:\n", i);
        scanf("%d", &ribs[i].weight);
    }
    printf("\n");

    for(i = 0; i < num; i++)
    {
        printf("Rib %d-%d has the weight of %d\n", ribs[i].first_vertex, ribs[i].second_vertex, ribs[i].weight);
    }
    printf("\n");


    for(i = 0; i < num; i++)
    {
        vertexes[i*2] = ribs[i].first_vertex;
        vertexes[i*2+1] = ribs[i].second_vertex;
    }
    printf("\n");


    for(i = 0; i < num*2; i++)
    {
        if(!el_in_array(ost_vertexes, counter, vertexes[i]))
        {
            ost_vertexes[counter] = vertexes[i];
            counter++;
        }
    }
    printf("\n");

    active_vertexes[0] = ost_vertexes[0];

    printf("Prima algorythm:\n");
    do
    {
        rib ribs_selection[11];
        int rcount = 0;

        for(i = 0; i < num; i++)
        {
            if( (ver_in_array(active_vertexes, ver_count, ribs[i].first_vertex) + ver_in_array(active_vertexes, ver_count, ribs[i].second_vertex)) % 2)
            {
                ribs_selection[rcount] = ribs[i];
                rcount++;
            }
        }
         rib min = min_weight(ribs_selection, rcount);
         a_rcount++;

         if(ver_in_array(active_vertexes, ver_count, min.first_vertex))
         {
            active_vertexes[ver_count] = min.second_vertex;
         }
         else
         {
            active_vertexes[ver_count] = min.first_vertex;
         }
         printf("%d-%d|", min.first_vertex,min.second_vertex);
         ver_count++;
    }while(ver_count != 11);
    printf("\n");

    return 0;
}
