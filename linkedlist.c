#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *address;
};

int main() {
	int n;
	printf("ENTER THE NUMBER OF NODES :- \n");
	scanf("%d",&n);

	struct node *head, *current;

	for (int i=0; i<n; i++){
		if (i==0){
			head = (struct node*)malloc(sizeof(struct node));
			current = head;
		}
		else{
			
		}
		printf("ENTER THE DATA IN THE NODE :- \n");
		scanf("%d", current -> data);
	}	
	return 0;
}

