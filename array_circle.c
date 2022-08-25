#include <stdio.h>
#include <stdlib.h>

void circle(int **arr, int n){

	int temp = 0, temp1 = n-1;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
		if ((i == temp && j == temp1) || (i == temp1 && j == temp)){
				if (i%2 == 0)
				{
					printf("%d ",2*arr[i][j]);
					//temp++;
					//temp1--;
				}
				else{

					printf("%d",(-2)*arr[i][j]);
					//temp++;
					//temp1--;

				}
			}
		else{
			printf(" ");
		}
		}
		temp++;
		temp1++;
		printf("\n");
	}

}

int main()
{
	int n;

	printf("ENTER THE SIZE OF THE 2D MATRIX :- \n");
	scanf("%d",&n);

	int** arr = (int**)malloc(n * sizeof(int*));
	for (int i=0; i<n; i++){

		arr[i] = (int*)malloc(n*sizeof(int));
}

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++){
			scanf("%d",&arr[i][j]);

			}

	}

	circle(arr, n);

	return 0;

}
