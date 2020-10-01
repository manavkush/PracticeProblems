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
#define mp make_pair
#define re(i,n)        for(int i=0;i<(n);i++)
#define re1(i,a,b)       for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)     for(int i=(a);i>=(b);i--)
struct bstnode
{
      int data;
      bstnode *left;
      bstnode *right;
};
bstnode* searchbst(bstnode *root, int x)
{
      if(root==NULL)
            return NULL;
            else if(root->data==x)
                  return root;
            else if(root->data>x)
                  return searchbst(root->left,x);
            else
                 return searchbst(root->right,x);
}
bstnode*  getnewnode(int x)
{
      bstnode *newnode= new bstnode;
      newnode->data=x;
      newnode->left=newnode->right=NULL;
      return newnode;
}

bstnode* insert(bstnode *root, int x)
{
      if(root==NULL)
            root=getnewnode(x);
      else{
                  if(root->data >x)
                        root->left=insert(root->left,x);
                  else
                        root->right=insert(root->right,x);
            }
      return root;
}

int main()
{
        FASTIO;
        int n,temp;
        cin>>n;
        bstnode* root=NULL;
        re(i,n)
        {
                cin>>temp;
                root=insert(root,temp);
        }
        int v1,v2;
        cin>>v1>>v2;
        bstnode* ptr=root;
        //bstnode*ptr1=searchbst(root,v1);
        //bstnode*ptr2=searchbst(root,v2);

        int flag=0;
        int max=0;
        while(ptr->data!=v1&&ptr->data!=v2)
        {
                if(   ptr->data>v1&&ptr->data<v2  )
                {
                        flag=2;
                        break;
                }
                else if((ptr->data<v1&&ptr->data>v2))
                {
                        flag=1;
                        break;
                }
                else if(ptr->data>v1)
                        ptr=ptr->left;
                else if(ptr->data<v2)
                        ptr=ptr->right;
        }
        if(flag==1||ptr->data==v2)
        {
                max=ptr->data;
                while(ptr->data!=v1)
                {
                        if(ptr->data<v1)
                        {
                                ptr=ptr->right;
                                max=ptr->data;
                        }
                        else if(ptr->data>v1)
                        {
                                break;
                        }
                }
        }
        else if(flag==2||ptr->data==v1)
        {
                max=ptr->data;
                while(ptr->data!=v2)
                {
                        if(ptr->data<v2)
                        {
                                ptr=ptr->right;
                                max=ptr->data;
                        }
                        else if(ptr->data>v2)
                        {
                                break;
                        }
                }
        }
        /*else if(ptr->data=v2)
        {
                max=ptr->data;
                while(ptr->data!=v1)
                {
                        if(ptr->data<v1)
                        {
                                ptr=ptr->right;
                                max=ptr->data;
                        }
                        else if(ptr->data>v1)
                        {
                                break;
                        }
                }
        }*/
        cout<<max;

}
