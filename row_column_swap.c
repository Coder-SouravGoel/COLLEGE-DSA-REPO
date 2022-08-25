//2. Write a C program to swap all the elements in the 0th column with all the corresponding
//elements in the last column, and 1st column with the last but one column of a 2-D array.
//The same swapping process will be followed to rows also. At the end display the 2-D
//array in a tabular form.

#include<stdio.h>
#include<stdlib.h>

int swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(){

int n ;
scanf("%d",&n);

int **arr = (int**)malloc(n*sizeof(int*));

for(int i=0; i<n; i++){
	arr[i] = (int*)malloc(n*sizeof(int));
}

for(int i=0; i<n; i++){
	for(int j=0; j<n; j++){
		scanf("%d",&arr[i][j]);
}
}

int min_r=0, min_c=0, max_r=n-1, max_c=n-1;
//FOR COLUMN SWAPPING

while(max_c > min_c){
	for(int i=min_r; i<=max_r; i++){
		swap(&arr[i][min_c], &arr[i][max_c]);
}
min_c++;
max_c--;
}

//FOR ROW SWAPPING
min_r=0; min_c=0; max_r=n-1; max_c=n-1;


while(max_r > min_r){
	for(int i=min_c; i<=max_c; i++){
		swap(&arr[min_r][i], &arr[max_r][i]);
}
min_r++;
max_r--;
}

for(int i=0; i<n; i++){
	for(int j=0; j<n; j++){
		printf("%d ",arr[i][j]);
}
	printf("\n");
}

return 0;
}
