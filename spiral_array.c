//1. Write a C program to display the elements of first outer circle of a 2-D array by
//multiplying with 2, display the elements of second outer circle of a 2-D array by
//multiplying with -2, display the elements of third outer circle of a 2-D array by
//multiplying with 2, and so on.


#include<stdio.h>
#include<stdlib.h>

int main(){

int n_094 ;
scanf("%d",&n_094);

int **arr = (int**)malloc(n_094*sizeof(int*));

for(int i_094=0; i_094<n_094; i_094++){
	arr[i_094] = (int*)malloc(n_094*sizeof(int));
}

for(int i_094=0; i_094<n_094; i_094++){
	for(int j=0; j<n_094; j++){
		scanf("%d",&arr[i_094][j]);
}
}

int t = n_094*n_094;
int ctr = 0;
int min_r=0, min_c=0, max_r=n_094-1, max_c=n_094-1, mul=1;

while(ctr < t){
		if(min_r%2 == 0){
			mul =  2;
}
		else{
			mul = -2;
}
	//left wall
		for(int i_094=min_r; i_094<=max_r; i_094++){
			printf("%d ",mul*arr[i_094][min_c]);
			ctr++;
}
	min_c++;
	//bottom wall
		for(int i_094=min_c; i_094<=max_c; i_094++){
			printf("%d ",mul*arr[max_r][i_094]);
			ctr++;
}
	max_r--;
	//right wall
		for(int i_094=max_r; i_094>=min_r; i_094--){
			printf("%d ",mul*arr[i_094][max_c]);
			ctr++;
}
	max_c--;
	//top wall
		for(int i_094=max_c; i_094>=min_c; i_094--){
			printf("%d ",mul*arr[min_r][i_094]);
			ctr++;
}
	min_r++;
}

/*for(int i=0; i<n; i++){
	for(int j=0; j<n; j++){
		printf("%d ",arr[i][j]);
}
printf("\n");
}*/
return 0;
}
