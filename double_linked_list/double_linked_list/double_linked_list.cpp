#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}*first = NULL;
void Display(struct Node* p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
void create(int A[], int n)
{
	int i;
	struct Node* t, * last;
	first = (struct Node*)malloc(sizeof(struct Node));
	first->data = A[0];
	first->prev = first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = last->next;
		t->prev = last;
		last->next = t;
		last = t;
	}
}
int Length(struct Node* p) {
	int len = 0;
	while (p) {
		len++;
		p = p->next;
	}
	return len;
}
void Insert(struct Node* p, int index, int x)
{
	struct Node* t;
	int i;
	if (index < 0 || index > Length(p)) {
		return;
	}
	if (index == 0)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = x;
		t->next = first;
		first->prev = t;
		t->prev = NULL;
		first = t;
	}
	else
	{
		for (i = 0; i < index - 1; i++) {
			p = p->next;
		}
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = x;
		t->next = p->next;
		t->prev = p;
		if (p->next){
			p->next->prev = t;
		}
		p->next = t;
	}
}
int deletenode(struct Node* p, int index) {
	p = first;
	int x = -1, i;
	if (index < 1 || index > Length(p)) {
		return x;
	}
	if (index == 1) {
		p = first;
		first = first->next;
		x = p->data;
		free(p);
		if (first)
			first->prev = NULL;
	}
	else {
		p = first;
		for (i = 0; i < index - 1; i++) {
			p = p->next;
		}
		p->prev->next = p->next;
		if (p->next) {
			p->next->prev = p->prev;
		}
		x = p->data;
		free(p);
	}
	return x;
}
void Reverse(struct Node* p) {
	p = first;
	struct Node* temp;
	while (p) {
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;
		if (p && p->next == NULL) {
			first = p;
		}
	}
}
int main() {
	int A[] = { 1,2,3,4,5 };
	create(A, 5);
	Insert(first, 0, 10);
	//deletenode(first, 7);
	Reverse(first);
	Display(first);
	return 0;
}
