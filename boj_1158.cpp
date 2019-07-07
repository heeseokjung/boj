#include <stdio.h>
#include <stdlib.h>

int n, k;
typedef struct Node
{
	int number;
	struct Node* prev;
	struct Node* next;
}Node;
Node* head = NULL;

void input()
{
	scanf("%d %d", &n, &k);
}

void init_list()
{
	head = (Node*)malloc(sizeof(Node));
	Node* last = NULL;
	for(int i = n; i >= 1; --i) {
		Node* p = (Node*)malloc(sizeof(Node));
		p->number = i;
		if(i == n) {
			head->next = p;
			p->prev = head;
			last = p;
		}
		else {
			p->next = head->next;
			p->next->prev = p;
			p->prev = head;
			head->next = p;
		}
	}
	last->next = head->next;
	head->next->prev = last;
}

Node* remove_node(Node* p)
{
	Node* q = p->prev;
	q->next = p->next;
	p->next->prev = q;
	q = p->next;
	free(p);
	return q;
}

void run()
{
	init_list();
	if(head == NULL)
		printf("hi\n");
	Node* p = head->next;
	
	printf("<");
	while(n--) {
		int count = 1;
		while(count < k) {
			p = p->next;
			count++;
		}
		printf("%d", p->number);
		p = remove_node(p);
		if(n == 0)
			printf(">\n");
		else
			printf(", ");
	}
}

int main()
{
	input();
	run();
	
	return 0;
}