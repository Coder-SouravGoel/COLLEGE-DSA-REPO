#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *address;
};

int main()
{
	int n;
	struct node *head, *current;
	struct node *newnode;

	printf("ENTER THE NUMBER OF NODE :- \n");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{

		if (i == 0)
		{

			head = (struct node *)malloc(sizeof(struct node));
			current = head;
		}
		else
		{

			current->address = (struct node *)malloc(sizeof(struct node));
			current = current->address;
		}

		printf("ENTER THE ITEM IN THE NODE :- \n");
		scanf("%d", &current->data);
	}
	current->address = NULL;

	int choice = 0;
	printf("ENTER\n1. TO INSERT THE NODE IN THE BEGINING\n2. TO INSERT THE NODE A THE END\n3. TO INSERT THE NODE AT ANY POSITION\n4. TO DELETE THE NODE IN THE BEGINING\n5. TO DELECT THE NODE AT THE END\n6. TO DELETE THE NODE AT ANY POSITION\n");
	scanf("%d", &choice);

	switch ((choice))
	{
	case 1:


		newnode = (struct node *)malloc(sizeof(struct node));

		printf("ENTER THE ELEMENT TO BE INSERTED IN THE FRONT :- \n");
		scanf("%d", &newnode->data);

		newnode->address = head;
		head = newnode;

		current = head;

		while (current != NULL)
		{

			printf("%d \n", current->data);
			current = current->address;
		}

		break;

	case 2:
		//struct node *newnode;

		newnode = (struct node *)malloc(sizeof(struct node));

		while (current->address == NULL)
		{
			current->address = newnode;

			printf("ENTER THE ELEMENT TO BE INSERTED IN THE END :- \n");
			scanf("%d", &newnode->data);
		}

		break;

	case 3:
		//struct node *newnode;

		newnode = (struct node *)malloc(sizeof(struct node));

		printf("ENTER THE ELEMENT TO BE INSERTED IN THE FRONT :- \n");
		scanf("%d", &newnode->data);

		newnode->address = head;
		head = newnode;

		current = head;

		while (current != NULL)
		{

			printf("%d \n", current->data);
			current = current->address;
		}
		break;

	case 4:
		/* code */
		break;

	case 5:
		/* code */
		break;

	case 6:
		/* code */
		break;

	default:
		break;
	}

	//struct node *newnode;

	newnode = (struct node *)malloc(sizeof(struct node));

	printf("ENTER THE ELEMENT TO BE INSERTED IN THE FRONT :- \n");
	scanf("%d", &newnode->data);

	newnode->address = head;
	head = newnode;

	current = head;

	while (current != NULL)
	{

		printf("%d \n", current->data);
		current = current->address;
	}

	return 0;
}
