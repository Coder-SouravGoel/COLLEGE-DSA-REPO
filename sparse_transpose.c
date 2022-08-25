#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;

    printf("ENTER THE NUMBER OF ROWS OF THE SPARSE MATRIX :- ");
    scanf("%d", &n);

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

    int temp;
    for (int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            temp = sparse_1[i][j];
            sparse_1[i][j] = sparse_1[j][i];
            sparse_1[j][i] = temp;
        }
        
    }


    for (int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            printf("%d ",sparse_1[i][j]);
        }
        printf("\n");
    }
    return 0;
}