#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};
//=============================================
void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
//==============================================
void printList(Node *node,int temp,int n)
{
    int i=1;

    while(i<n-temp+1)
    {
        node=node->next;
        i++;
    }
    cout<<node->data;
}
//===========================================
int main()
{

	Node* head = NULL;
	int n,temp;
	cin>>n;
	int n2=n;
	while(n2--)
	{
	    cin>>temp;
	    push(&head,temp);
	}
    cin>>temp;
    if(temp>n)
    {
        cout<<-1;
        return 0;
    }
	printList(head,temp,n);

	return 0;
}


