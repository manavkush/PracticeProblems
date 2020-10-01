#include <bits/stdc++.h>
using namespace std;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define re(i,n)        for(int i=0;i<(n);i++)

class Node {
public:
    int data;
    Node* next;
};
//=====================        =========================       ======================
void push(Node** head_ref, int data)
{
    Node* ptr1 = new Node();
    ptr1->data = data;
    ptr1->next = *head_ref;

    if (*head_ref != NULL) {

        Node* temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;
    *head_ref = ptr1;
}
//===============================   ==============      ==================
void printList(Node* head)
{

    if(head==NULL)
        return;
    Node* ptr=head;
    do
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    while(ptr!=head);
}
//  ================    ====================    =====================   ===============
void deleteNode(Node** headptr, int key,int n)
{

    Node * head=*headptr;
    Node *ptr=head->next,*prev=head,*temp;
    for(int i=1;i<n;i++)
    {
        if(ptr->data==key)
        {
            temp=ptr;
            prev->next=ptr->next;
            ptr=ptr->next;
            delete temp;
        }
        else
        {
            ptr=ptr->next;
            prev=prev->next;
        }
    }
    if(head->data==key)
    {
        temp=head;
        ptr->next=head->next;
        head=head->next;
        delete temp;
    }
}
//      ========================        ========================        =======================
int main()
{
    FASTIO;
    Node* head = NULL;
    int n,temp;
    cin>>n;
    int n2=n;
    while(n2--)
    {
        cin>>temp;
        push(&head, temp);
    }
    Node *ptr=head;
    cin>>temp;

    printList(head);

    cout<<endl;
    deleteNode(&head,temp,n);
    if(head==NULL)
    {
        cout<<-1;
        return 0;
    }
    printList(head);

    return 0;
}

