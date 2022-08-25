#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, n1;

    printf("ENTER THE NUMBER OF ROWS OF THE SPARSE MATRIX :- ");
    scanf("%d", &n);

    printf("ENTER THE NUMBER OF ROWS OF THE SPARSE MATRIX :- ");
    scanf("%d", &n1);

    int **sparse_1 = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < 3; i++)
    {
        sparse_1[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            scanf("%d ",&sparse_1[i][j]);
        }
    }

    int **sparse_2 = (int **)malloc(n1 * sizeof(int *));

    for (int i = 0; i < 3; i++)
    {
        sparse_2[i] = (int *)malloc(n1 * sizeof(int));
    }

    for (int i=0; i<n1; i++){
        for(int j=0; j<3; j++){
            scanf("%d ",&sparse_2[i][j]);
        }
    }

    int **sparse_3 = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < 3; i++)
    {
        sparse_3[i] = (int *)malloc(n * sizeof(int));
    }

    int apos = 0, bpos = 0, k = 0;

    while (apos < n && bpos < n)
    {

        // CHECKING IF B'S SPARSE MATRIX'S ROW AND COLUMN IS SMALLER THEN A'S

        if (sparse_1[apos][0] < sparse_2[bpos][0] || sparse_1[apos][0] == sparse_2[bpos][0] && sparse_1[apos][1] < sparse_2[bpos][1])
        {

            // INSERT VALUES INTO A NEW MATRIX

            sparse_3[k][0] = sparse_2[bpos][0];
            sparse_3[k][1] = sparse_2[bpos][1];
            sparse_3[k][2] = sparse_2[bpos][2];

            k++;
            bpos++;
        }

        // CHECKING IF B'S SPARSE MATRIX'S ROW AND COLUMN IS SAMLLER THEN B'S

        else if (sparse_1[apos][0] > sparse_2[bpos][0] || sparse_1[apos][0] == sparse_2[bpos][0] && sparse_1[apos][1] > sparse_2[bpos][1])
        {

            sparse_3[k][0] = sparse_1[apos][0];
            sparse_3[k][1] = sparse_1[apos][1];
            sparse_3[k][2] = sparse_1[apos][2];

            k++;
            apos++;
        }

        else
        {

            // add the values as row and col is same
            int addedval = sparse_1[apos][2] +
                           sparse_2[bpos][2];

            if (addedval != 0)
            {
                sparse_3[k][0] = sparse_1[apos][0];
                sparse_3[k][1] = sparse_1[apos][1];
                sparse_3[k][2] = addedval;

                k++;
                // then insert
                apos++;
                bpos++;
            }
        }
    }

    while (apos < n)
    {

        sparse_3[k][0] = sparse_1[apos][0];
        sparse_3[k][1] = sparse_1[apos][1];
        sparse_3[k][2] = sparse_1[apos++][2];

        k++;
    }

    while (bpos < n1)
    {

        sparse_3[k][0] = sparse_2[bpos][0];
        sparse_3[k][1] = sparse_2[bpos][1];
        sparse_3[k][2] = sparse_2[bpos++][2];

        k++;
    }

    for (int i=0; i<k; i++){
        for(int j=0; j<3; j++){
            printf("%d ",sparse_3[i][k]);
        }
        printf("\n");
    }

    return 0;
}