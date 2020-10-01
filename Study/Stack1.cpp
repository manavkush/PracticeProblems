#include<iostream>

using namespace std;

struct node
{
      int data;
      node *next;
};

class   Stack
{
      node *top;
public:
      Stack()
      {
            top=NULL;
      }
      void push(int x);
      void pop();

      ~Stack()
      {
            while(top!=NULL)
            {
                  node *temp=top;
                  top=top->next;
                  delete temp;
            }
      }
};

void Stack::push(int x)
{
      node *temp = new node;
      temp->data=x;
      temp->next=top;
      top=temp;
}

void Stack::pop()
{
      node *temp=top;
      top=top->next;
      cout<<temp->data;
      delete temp;
}

int main()
{
      cout<<"hello world";
}









