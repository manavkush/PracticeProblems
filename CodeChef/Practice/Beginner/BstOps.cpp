#include<iostream>
#include<vector>

using namespace std;
struct node
{
      long long int data;
      node *left,*right;
};
//long long int count=1;
//============================================INSERT=====================================
node* insert(node*root, long long int x,long long int count)
{
      if(root==NULL)
      {
            root=new node;
            root->data=x;
            root->left=root->right=NULL;
            cout<<count<<"\n";
      }
      else if(x<root->data)
      {
            count=2*count;
            insert(root->left,x,count);
      }
      else
      {
            count=2*count+1;
            insert(root->right,x,count);
      }
      return root;
}
//====================================================================================

node *delete()







int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      long long int n,temp;
      cin>>n;
      node *root=NULL;
      while(n--)
      {
            char c;
            cin>>c;
            cin>>temp;
            if(c=='i')
            {
                  insert(root,temp,1);
            }
      }

}
