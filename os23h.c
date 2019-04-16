#include <stdio.h>
#include <stdlib.h>
int main()
{
    int Maximum[10][10], need[10][10], allocation[10][10], available[10], completed[10], safeState[10];
    int p, r, i, j, process, count;
    count = 0;

    printf("Enter the no of processes : ");
    scanf("%d", &p);

    for(i = 0; i< p; i++)
    completed[i] = 0;

    printf("\n\nEnter the no of resources : ");
    scanf("%d", &r);

    printf("\n\nEnter the Max values for each process : ");
    for(i = 0; i < p; i++)
    {
        printf("\nFor process %d : ", i + 1);
        for(j = 0; j < r; j++)
            scanf("%d", &Maximum[i][j]);
    }

    printf("\n\nEnter the allocation for each process : ");
    for(i = 0; i < p; i++)
    {
        printf("\nFor process %d : ",i + 1);
        for(j = 0; j < r; j++)
            scanf("%d", &allocation[i][j]);
    }

    printf("\n\nEnter the Available Resources : ");
    for(i = 0; i < r; i++)
        scanf("%d", &available[i]);

    for(i = 0; i < p; i++)

        for(j = 0; j < r; j++)
            need[i][j] = Maximum[i][j] - allocation[i][j];

        do
        {
            printf("\n Max values:\tAllocation values:\n");

            for(i = 0; i < p; i++)
            {
                for( j = 0; j < r; j++)
                    printf("%d ", Maximum[i][j]);
                printf("\t\t");
                for( j = 0; j < r; j++)
                    printf("%d ", allocation[i][j]);
                printf("\n");
            }

            process = -1;

            for(i = 0; i < p; i++)
            {
                if(completed[i] == 0)//if not completed
                {
                    process = i ;
                    for(j = 0; j < r; j++)
                    {
                        if(available[j] < need[i][j])
                        {
                            process = -1;
                            break;
                        }
                    }
                }
                if(process != -1)
                    break;
    }

}


