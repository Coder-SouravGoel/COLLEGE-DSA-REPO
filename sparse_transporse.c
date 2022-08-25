#include <stdio.h>
#include <stdlib.h>
int main(){

    int n;
    scanf("%d",&n);

    int ** arr = (int **)malloc(n * sizeof(int *));

    for (int i=0; i<n; i++){
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int c=0; 

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (arr[i][j] != 0){
                c++;
            }
        }
    }    
    c++;
    int ** sparse = (int **)malloc(c * sizeof(int *));

    for(int i=0; i<c; i++){
        sparse[i] = (int *)malloc(3 * sizeof(int));
    }

    sparse[0][0] = n;
    sparse[0][1] = n;
    sparse[0][2] = c - 1;

    int k=1;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (arr[i][j] != 0){
            sparse[k][0] = i;
            sparse[k][1] = j;
            sparse[k][2] = arr[i][j];
            k++;
            }
        }
    }

/*     printf("ORIGINAL SPARSE MATRIX :- \n");

    for(int i=0; i<c; i++){
        for(int j=0; j<3; j++){

            printf("%d ",sparse[i][j]);
        }
        printf("\n");
    } */

    k=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (arr[i][j] != 0){
            sparse[k][0] = j;
            sparse[k][1] = i;
            sparse[k][2] = arr[i][j];
            k++;
            }
        }
    }



/*     printf("SPARSE MATRIX AFTER TRANSPOSE :- \n");

    for(int i=0; i<c; i++){
        for(int j=0; j<3; j++){
            printf("%d ",sparse[i][j]);
        }
        printf("\n");
    } */


    int temp;


    for(int i=1; i<c-1; i++){
        for(int j=1; j<c-i; j++){
            if((sparse[j][0]*n+sparse[j][1])>(sparse[j+1][0]*n+sparse[j+1][1])){
                temp=sparse[j][0];
                sparse[j][0]=sparse[j+1][0];
                sparse[j+1][0]=temp;
                temp=sparse[j][1];
                sparse[j][1]=sparse[j+1][1];
                sparse[j+1][1]=temp;
                temp=sparse[j][2];
                sparse[j][2]=sparse[j+1][2];
                sparse[j+1][2]=temp;
            }
        }
        printf("\n");

    }
    for(int i=0; i<c; i++){
        for(int j=0; j<3; j++){
            printf("%d ",sparse[i][j]);
        }
        printf("\n");
    }

    return 0;
}
