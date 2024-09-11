#include <stdio.h>
#include <stdlib.h>

typedef struct ll
{
	int data;
	struct ll *next;
} ll_t;

ll_t *createNode(int data)
{
	ll_t *node = malloc(sizeof(ll_t));
	node -> data = data;
	node -> next = NULL;

	return node;
}

ll_t *initLinkedList(int data)
{
	return createNode(data); 
}

ll_t *pushNode(int data, ll_t *head)
{
	ll_t *node = createNode(data);
	node -> next = head;

	return node;
}

ll_t *popNode(ll_t *head)
{
	ll_t *newHead = head -> next;

	head -> data = 0;
	head -> next = NULL;

	free (head);
	return (newHead);
}

ll_t *appendNode(int data, ll_t *head)
{
	ll_t *lastNode = head;
	while (lastNode -> next != NULL) lastNode = lastNode -> next;

	ll_t *node = createNode(data);
	lastNode -> next = node;

	return head;
}

ll_t *insertNode(int data, ll_t *head, int position)
{
	if (position == 0) return pushNode(data, head);
	
	ll_t *previousNode = head;
	ll_t *nodeToSwap = NULL;

	for (int i = 0; i < position-1; ++i) previousNode = previousNode -> next;
	nodeToSwap = previousNode -> next;
	
	ll_t *newNode = createNode(data);
	
	previousNode -> next = newNode;
	newNode -> next = nodeToSwap; 	

	return head;
}

ll_t *deleteNodeByValue(int value, ll_t *head)
{
	ll_t *previousNode = head;
	while (previousNode -> next -> data != value) previousNode = previousNode -> next;
	
	ll_t *nodeToRemove = previousNode -> next;

	previousNode -> next = nodeToRemove -> next;
	
	nodeToRemove -> data = 0;
	nodeToRemove -> next = NULL;

	free(nodeToRemove);
	  
	return head;
}

ll_t *deleteNodeByPosition(ll_t *head, int position)
{
	if (position == 0) return popNode(head);

	ll_t *previousNode = head;
	ll_t *nodeToRemove = NULL;
	ll_t *nextNode = NULL;
	
	for (int i = 0; i < position-1; ++i) previousNode = previousNode -> next;
	nodeToRemove = previousNode -> next; 
	nextNode = nodeToRemove -> next;

	nodeToRemove -> data = 0;
	nodeToRemove -> next = NULL;
	free(nodeToRemove);

	previousNode -> next = nextNode;

	return head;
}

void printLinkedList(ll_t *head)
{
	ll_t *currentNode = head;

	while (currentNode != NULL)
	{
		printf("%d -> ", currentNode -> data);
		currentNode = currentNode -> next;
	}	
	printf("NULL\n");
}

int main()
{
	ll_t *list1 = initLinkedList(20);
	for (int i = 0; i < 5; ++i) list1 = pushNode(15*i, list1);

	printLinkedList(list1);	
	list1 = popNode(list1);
	printLinkedList(list1);

	list1 = appendNode(1000, list1);
	printLinkedList(list1);

	list1 = insertNode(123, list1, 3);
	printLinkedList(list1);

	list1 = deleteNodeByValue(20, list1);
	printLinkedList(list1);

	list1 = deleteNodeByPosition(list1, 3);	
	printLinkedList(list1);
}