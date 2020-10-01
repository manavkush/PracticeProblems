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
      node *front, *rear;
public:
      Queue()
      {
            front=NULL;
            rear=NULL;
      }

      void insertx(int x);
      void deletex();
};
//========================================

void Queue::insertx(int x)
{
      node *temp=new node;
      temp->data=x;
      temp->next=NULL;

      if(rear!=NULL)
      {
            rear->next=temp;
            rear=temp;
      }
      else
      {
            rear=temp;
            front=temp;
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

