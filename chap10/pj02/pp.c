#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void addq(struct node **head, struct node **tail, int data){
	struct node *newNode=(struct node *)malloc(sizeof(struct node));
	if(newNode==NULL){
		perror("malloc");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;
	
	if(*tail==NULL){
		*head = newNode;
		*tail = newNode;
	}else{
		(*tail)->next = newNode;
		*tail=newNode;
	}
}
int delete(struct node **head, struct node **tail) {
	if(*head == NULL) {
		printf("err\n");
		return -1;
	}
	struct node *temp = *head;
	int deleteData = temp->data;
	*head = temp->next;

	if(*head == NULL) {
		*tail = NULL;
	}

	free(temp);
	return deleteData;
}

void printQueue(struct node *head){
	if(head==NULL) {
		printf("err\n");
		return;
	}
	while (head != NULL) {
		printf("%d\n", head -> data);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	struct node *head = NULL;
	struct node *tail = NULL;

	int input;
	while(1) {
		if(scanf("%d", &input) != 1) {
			printQueue(head);
			while(getchar() != '\n');
		} else {
			if(input == -1){
				break;
			}
			addq(&head, &tail, input);
		}
	}
	
	return 0;
}
