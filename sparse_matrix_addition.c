#include <stdio.h>
#include <stdlib.h>

int main()
{

    /*     int n;
        scanf("%d",&n); */

    /*     int **sparse_1 = (int **)malloc((n+1) * sizeof(int *));

        for (int i = 0; i < 3; i++)
        {
            sparse_1[i] = (int *)malloc(n * sizeof(int));
        } */

    /*     for (int i=0; i<n+1; i++){
            for(int j=0; j<3; j++){
                scanf("%d ",&sparse_1[i][j]);
                printf("%d is i \n%d is j\n\n",i,j);
            }
        } */

    /*     for (int i=0; i<n+1; i++){
            for(int j=0; j<3; j++){
                printf("%d ",sparse_1[i][j]);
            }
        } */

    /*  int **sparse_2 = (int **)malloc((n+1) * sizeof(int *));

     for (int i = 0; i < 3; i++)
     {
         sparse_2[i] = (int *)malloc(n * sizeof(int));
     }


     for (int i=0; i<n+1; i++){
         for(int j=0; j<3; j++){
             scanf("%d ",&sparse_2[i][j]);
         }
     }

     for (int i=0; i<n+1; i++){
         for(int j=0; j<3; j++){
             printf("%d ",sparse_1[i][j]);
         }
     }

     for (int i=0; i<n+1; i++){
         for(int j=0; j<3; j++){
             printf("%d ",sparse_2[i][j]);
         }
     }
  */

    int sparse_1[4][3] = {{3, 3, 2}, {0, 1, 2}, {2, 0, 6}, {0, 2, 9}};
    int sparse_2[4][3] = {{3, 3, 2}, {0, 1, 2}, {1, 1, 3}, {1, 2, 6}};
    int sparse_3[4][3] = {{3, 3, 2}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    int apos = 0, bpos = 0, k = 0;

    while (apos < 4 && bpos < 4)
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

    while (apos < 4)
    {

        sparse_3[k][0] = sparse_1[apos][0];
        sparse_3[k][1] = sparse_1[apos][1];
        sparse_3[k][2] = sparse_1[apos++][2];

        k++;
        apos++;
    }

    while (bpos < 4)
    {

        sparse_3[k][0] = sparse_2[bpos][0];
        sparse_3[k][1] = sparse_2[bpos][1];
        sparse_3[k][2] = sparse_2[bpos++][2];

        k++;
        bpos++;
    }

     for(int i=0; i<12; i++){
        for(int j=0; j<3; j++){
            printf("%d ", sparse_3[i][j]);
        }
        printf("\n");
    }
    /*
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    } */

    return 0;
}