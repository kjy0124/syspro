#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node **top, int data){
	struct node *newNode = (struct node *) malloc(sizeof(struct node));
	if(newNode==NULL){
		perror("malloc");
		return;
	}
	newNode->data = data;
	newNode->next = *top;
	*top = newNode;
}

int pop(struct node **top){
	if(*top==NULL){
		printf("err");
		return -1;
	}
	struct node *temp = *top;
	int poppedData = temp -> data;
	*top = temp -> next;
	free(temp);
	return(poppedData);
}
void printStack(struct node **top){
	if(*top==NULL){
		printf("err");
		return;
	}
	struct node *current= *top;
	while(current!=NULL){
		printf("%d\n ",current->data);
		current = current->next;
	}
	printf("\n");
}

int main()
{
	struct node *top = NULL;
	
	int input;
	while(1){
		if(scanf("%d", &input)!= 1){
			printStack(&top);
			while(getchar() != '\n');
		}else {
			if (input == -1){
				break;
			}
			push(&top,input);
		}
	}
	return 0;
}
