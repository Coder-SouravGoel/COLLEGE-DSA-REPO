#include <stdio.h>
#include <stdlib.h>
void tuple(int** arr, int n, int m, int** arr1, int count ){
    int c=1;
    arr1[0][0]=n;
    arr1[0][1]=m;
    arr1[0][2]=--count;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!=0){
                arr1[c][0]=i;
                arr1[c][1]=j;
                arr1[c][2]=arr[i][j];
                c++;
            }
        }
    }
}
int add (int **arr,int count,int **arr1,int count1, int** addition){
    int apos=1,bpos=1;
    int k=1;
    while(apos<count&&bpos<count1){
        if(arr[apos][0]>arr1[bpos][0]||arr[apos][0]==arr1[bpos][0]&&arr[apos][1]>arr1[bpos][1]){
            addition[k][0]=arr1[bpos][0];
            addition[k][1]=arr1[bpos][1];
            addition[k][2]=arr1[bpos][2];
            k++;
            bpos++;
        }
        else if(arr[apos][0]<arr1[bpos][0]||arr[apos][0]==arr1[bpos][0]&&arr[apos][1]<arr1[bpos][1]){
            addition[k][0]=arr[apos][0];
            addition[k][1]=arr[apos][1];
            addition[k][2]=arr[apos][2];
            k++;
            apos++;
        }
        else{
            addition[k][0]=arr[apos][0];
            addition[k][1]=arr[apos][1];
            addition[k][2]=arr[apos][2]+arr1[bpos][2];
            k++;
            apos++;
            bpos++;
        }
    }
    while(apos<count){
            addition[k][0]=arr[apos][0];
            addition[k][1]=arr[apos][1];
            addition[k][2]=arr[apos][2];
            k++;
            apos++;
        }
        while(bpos<count1){
            addition[k][0]=arr[apos][0];
            addition[k][1]=arr[apos][1];
            addition[k][2]=arr[apos][2];
            k++;
            apos++;
        }
        addition[0][0]=k-1;
        addition[0][1]=3; 
        addition[0][2]=k-1;
        return k;
}
int main(){
    int n=0;
    printf("Enter the number of rows in matrix: ");
    scanf("%d", &n);

    int m=0;
    printf("Enter the number of columns in matrix: ");
    scanf("%d", &m);

    int count=0;
    int** arr=(int**) malloc(n * sizeof(int*));
    printf("Enter the elements of matrix 1\n");
    for(int i=0;i<n;i++){
        arr[i]=(int*) malloc(m * sizeof(int));
        for(int j=0;j<m;j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]!=0){
                count++;
            }
        }
    }
    count++;

    int** output=(int**) malloc(count * sizeof(int*));
    for(int i=0;i<count;i++){
        output[i]=(int*) malloc(3 * sizeof(int));
    }

    tuple(arr, n, m, output, count);

    int count1=0;
    int** arr1=(int**) malloc(n * sizeof(int*));
    printf("Enter the elements of matrix 2\n");
    for(int i=0;i<n;i++){
        arr1[i]=(int*) malloc(m * sizeof(int));
        for(int j=0;j<m;j++){
            scanf("%d", &arr1[i][j]);
            if(arr1[i][j]!=0){
                count1++;
            }
        }
    }
    count1++;

    int** output1=(int**) malloc(count1 * sizeof(int*));
    for(int i=0;i<count1;i++){
        output1[i]=(int*) malloc(3 * sizeof(int));
    }

    tuple(arr1, n, m, output1, count1);

    int** addition=(int**) malloc((count+count1) * sizeof(int*));
    for(int i=0;i<(count+count1);i++){
            addition[i]=(int*) malloc(3 * sizeof(int));
    }

    int answer=add(output, count, output1, count1, addition);
    printf("tuple 1\n");
    for(int i=0;i<answer;i++){
        for(int j=0;j<3;j++){
            printf("%d ", addition[i][j]);
        }
        printf("\n");
    }
    return 0;
}