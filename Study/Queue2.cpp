#include <iostream>

using namespace std;

struct node
{
      int data;
      int *next;
};
//=======================================
class Queue
{
      node *head;
public:
      Queue()
      {
            head=NULL;
      }

      void insertx(int x);
      void deletex();
};
//========================================

void Queue::insertx(int x)
{
      node *temp=new node;
      temp->data=x;


      if(head!=NULL)
      {
            temp->next=head
      }
      else
      {
           head=temp;
           head->next=head;
      }
}
//========================================
void Queue::deletex()
{
       if(front==NULL)
       {
             cout<<"Queue Empty";
       }
      else
      {
            cout<<front->data;
            node *temp=front;
            front=front->next;
            delete temp;
            if(front==NULL)
                  rear==NULL;
      }

}
//========================================

