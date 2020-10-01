#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef stack<int> si;
typedef stack<long long int> slli;
#define FASTIO     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"
#define pb push_back
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)

struct node
{
	int data;
	node*next;
};
node* create(int data)
{
        node*ptr=new node;
        ptr->data=data;
        ptr->next=NULL;
        return ptr;
}

int main()
{
        FASTIO;
        int k,n,temp;
        cin>>n;
        node*front,*rear,*ptr;
        node*prev,*agl;
        front=rear=NULL;
        cin>>temp;
        front=rear=create(temp);
        re1(i,2,n)
        {
                cin>>temp;
                ptr=create(temp);
                rear->next=ptr;
                rear=ptr;
        }
        cin>>k;
        if(k==0)
        {
                ptr=front;
        while(ptr)
        {
                cout<<ptr->data<<" ";
                ptr=ptr->next;
        }
        return 0;
        }
        prev=NULL;
        ptr=front;

        re(i,k)
        {
                agl=ptr->next;
                ptr->next=prev;
                prev=ptr;
                ptr=agl;
        }
        front->next=ptr;
        front=prev;

        //=========printing the queue============
        ptr=front;
        while(ptr)
        {
                cout<<ptr->data<<" ";
                ptr=ptr->next;
        }
}
