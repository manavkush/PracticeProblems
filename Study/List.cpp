#include<bits/bits/stdc++.h>

using namespace std;

struct node
{
      int data;
      int next;
};

void insert(node **headptr,int x);
{
      node *ptr=new node;
      node->data=x;
      node->next=*headptr;
      *headptr=node;
}

void swapnodes(node** headptr,int k1, int k2)
{
      node *ptr1,*ptr2,*temp1,*temp2;
      node*prev1,*prev2;
      ptr1=ptr2=*headptr;
      while(ptr1!=NULL)
      {
            //=============================================
            if(ptr->data==k1)
                  break;
            prev=ptr;
            ptr=ptr->next;
      }
      if(ptr1==NULL){
            cout<<"Element not found";
            return;
      }

      while(ptr2!=NULL)
      {
            if(ptr->data==k1)
                  break;
            prev=ptr;
            ptr=ptr->next;
      }
      if(ptr==NULL){
            cout<<"Element not found";
            return;
      }
      //=================================================
      if(ptr1==*headptr)
      {

      }
}
