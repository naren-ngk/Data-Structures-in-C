#include <stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
}* first = NULL,* second = NULL,* third = NULL;
void create(int A[], int n) {
	struct Node* t, * last;
	int i;
	first = (struct Node*)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;
	for (i = 1; i < n; i++) {
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}
void create2(int A[], int n) {
	struct Node* t, * last;
	int i;
	second = (struct Node*)malloc(sizeof(struct Node));
	second->data = A[0];
	second->next = NULL;
	last = second;
	for (i = 1; i < n; i++) {
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}
void displaylist(struct Node* p) {
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}
int countnodes(struct Node* p) {
	int count = 0;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}
void sumnodes(struct Node* p) {
	int sum = 0;
	while (p != NULL) {
		sum+=p->data;
		p = p->next;
	}
	printf("The sum of nodes is %d", sum);
}
void maximum(struct Node* p) {
	int max = -32768;
	while (p != NULL) {
		if (p->data > max) {
			max = p->data;
		}
		p = p->next;
	}
	printf("The maximum is %d", max);
}
struct Node* searching(struct Node* p, int x) {
	while (p != NULL) {
		if (x == p->data)
			return p;
		p = p->next;
	}
	return NULL;
}
void insert(struct Node* p, int x, int pos) {
	if (pos < 0 || pos > countnodes(p)) {
		return;
	}
	struct Node* t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;
	if (pos == 0) {
		t->next = first;
		first = t;
	}
	else {
		p = first;
		for (int i = 0; i < pos - 1; i++) {
			p = p->next;
		}
		t->next = p->next;
		p->next = t;
	}
}
void sortedinsert(struct Node* p, int x) {
	struct Node* q, * t;
	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;
	q = NULL;
	if (first == NULL) {
		first = t;
	}
	else {
		while (p && p->data < x) {
			q = p;
			p = p->next;
		}
		if (p == first) {
			t->next = first;
			first = t;
		}
		else {
			t->next = q->next;
			q->next = t;
		}
	}
}
int deletenode(struct Node* p, int index) {
	int x = -1, i;
	struct Node* q;
	if (index < 1 || index > countnodes(p)) {
		return -1;
	}
	if (index == 1) {
		q = first;
		x = first->data;
		first = first->next;
		free(q);
		return x;
	}
	else {
		p = first;
		q = NULL;
		for (i = 0; i < index - 1; i++) {
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		free(p);
		return x;
	}
}
int issorted(struct Node* p) {
	int x = -32768;
	p = first;
	while (p != NULL) {
		if (p->data < x) {
			return 0;
		}
		x = p->data;
		p = p->next;
	}
	return 1;
}
void removeduplicates(struct Node* p) {
	p = first;
	struct Node* q = first->next;
	while (q != NULL) {
		if (p->data != q->data) {
			p = q;
			q = q->next;
		}
		else {
			p->next = q->next;
			free(q);
			q = p->next;
		}
	}
}
/*void reverselist(struct Node* p) {
	struct Node* q, * r;
	p = first;
	q = r = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	first = q;
}*/
int isPalindrome(struct Node* head) {
	struct Node* p, * q, * r, * mid;
	p = q = head;
	while (p) {
		p = p->next;
		if (p == NULL)
			break;
		p = p->next;
		q = q->next;
	}
	mid = p = q;
	r = q = NULL;
	p = p->next;
	while (p) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	mid->next = q;
	p = head;
	q = mid->next;
	while (p != mid) {
		if (q->data != p->data)
			return 0;
		p = p->next;
		q = q->next;
	}
	return 1;
}
void mergelists(struct Node* first, struct Node* second) {
	struct Node* last;
	if (first->data < second->data) {
		third = last = first;
		first = first->next;
		last->next = NULL;
	}
	else {
		third = last = second;
		second = second->next;
		last->next = NULL;
	}
	while (first != NULL && second != NULL) {
		if (first->data < second->data) {
			last->next = first;
			last = first;
			first = first->next;
			last->next = NULL;
		}
		else {
			last->next = second;
			last = second;
			second = second->next;
			last->next = NULL;
		}
	}
	if (first != NULL) {
		last->next = first;
	}
	else {
		last->next = second;
	}
}
int main()
{
	int A[] = {1,2,3,4,3,2,1};
	create(A, 7);
	/*int B[] = {1,2,13,14,15};
	create2(B, 5);
	mergelists(first, second);
	displaylist(third);*/
	printf("%d", isPalindrome(first));
}

