#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(Node *node)
{
    int count=0;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	cout<<count;
}
int main()
{

	Node* head = NULL;
	int temp;
	cin>>temp;
	while(temp!=-1)
	{
	    push(&head,temp);
	    cin>>temp;
	}

	printList(head);

	return 0;
}


