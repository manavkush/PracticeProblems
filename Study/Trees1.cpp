#include<bits/stdc++.h>
using namespace std;
#define max_val 1e7
#define min_val -1e7
int prv=min_val;
struct bstnode
{
      int data;
      bstnode *left;
      bstnode *right;
};

bstnode*  getnewnode(int x)
{
      bstnode *newnode= new bstnode;
      newnode->data=x;
      newnode->left=newnode->right=NULL;
      return newnode;
}
/*
// ===================================== (INSERTION) METHOD 1 =========================================
void inset (bstnode **root,int x)
{
      if(*root==NULL)
            *root=getnewnode(int x);
}
int main()
{
      bstnode *root=NULL;
      insert(&root,15);
      insert(&root,10);
      insert (&root,20);
}
//==========================================================================================
*/
//=====================================(INSERTION) METHOD 2 =========================================
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
//====================================== SEARCH FUNCTION===========================
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
//===================================== FIND HEIGHT=================================
int findheight(bstnode *root)
{
      if(root==NULL)
            return -1;
      else
            return max(findheight(root->left) ,findheight(root->right))+1;
}
//===================================== LEVEL ORDER TRAVERSAL(    BFS   )=========================
void LevelOrder(bstnode*root)
{
      if(root==NULL)    return;
      queue<bstnode*> q;
      q.push(root);
      while(!q.empty())
      {
            bstnode *current=q.front();
            cout<<current->data<<" ";
            if(current->left)      q.push(current->left);
            if(current->right)    q.push(current->right);
            q.pop();
      }
}
//====================================PREORDER TRAVERSAL (  DFS  )  ============================
void preorder(bstnode *root)
{
      if(root==NULL)    return;
      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
}//====================================INORDER TRAVERSAL (  DFS  )  ============================
void inorder(bstnode *root)
{
      if(root==NULL)    return;

      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
}
//=====================================POSTORDER TRAVERSAL  (  DFS  ) ============================
void postorder(bstnode *root)
{
      if(root==NULL)    return;
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
}
//====================================    Check if binary search tree (Method 1)===============================
bool binutility(bstnode* root, int maxval, int minval)
{
      if(root==NULL)     return true;
      if((root->data>minval)  &&  (root->data<maxval)  &&  binutility(root->left,root->data,minval)  &&  binutility(root->right,maxval,root->data))
            return true;
      else return false;
}
bool isbinarysearchtree(bstnode* root)
{
      return binutility(root,max_val,min_val);
}
//=====================================   Check if binary search tree (Method 2)===============================
bool checkbst(bstnode* root)
{
      if(root==NULL)
            return true;
      checkbst(root->left);
      if(root->data<=prv)
            return false;
      else prv=root->data;
      checkbst(root->right);
}
//=====================================         Finding the minimum  and maximum ==========================================
bstnode* Findmin(bstnode*root)
{
      if(root==NULL)
            return NULL;
      while(root->left)
            root=root->left;
      return root;
}
bstnode* Findmax(bstnode*root)
{
      if(root==NULL)
            return NULL;
      while(root->right)
            root=root->right;
      return root;
}
//=====================================         Deleting a Node ==========================================
bstnode* Delete(bstnode* root, int x)
{
      if(root==NULL)    return NULL;
      else if(x<root->data)         root->left=Delete(root->left,x);
      else if(x>root->data)         root->right=Delete(root->right,x);
      else  //you are found. Begone data!!
      {
            if(root->left==NULL&&root->right==NULL)
            {
                  delete root;
                  root=NULL;
            }

            else if(root->left==NULL)
            {
                  bstnode*temp=root;
                  root=root->right;
                  delete temp;
            }
            else if(root->right==NULL)
            {
                  bstnode * temp=root;
                  root=root->left;
                  delete temp;
            }
            else
            {
                  bstnode* temp=Findmin(root->right);
                  root->data=temp->data;
                  root->right = Delete(root->right,temp->data);
            }

      }
      return root;
}
//================================= INORDER SUCCESSOR =======================================
bstnode* getsuccessor(bstnode* root, int x)
{
      // Search the node for the element
      bstnode* curr=searchbst(root, x);

      if(curr==NULL)          // if the element is not found
            return NULL;

      if(curr->right!=NULL)   // if the element has right subtree
      {
            return Findmin(curr->right);
      }
      else // If the element does not have a right subtree
      {
            bstnode* successor=NULL;
            bstnode* traverse=root;
            while(traverse!=curr)
            {
                  if(traverse->data>curr->data)
                  {
                        successor=traverse;
                        traverse=traverse->left;
                  }
                  else
                  {
                        traverse=traverse->right;
                  }
            }
            return successor;
      }
}
//====================================== INORDER PREDECESSOR==========================
bstnode* getpredecessor(bstnode* root, int x)
{
      bstnode* curr=searchbst(root,x);
      if(curr==NULL)    return NULL;
      else if(curr->left)
      {
            return Findmax(curr->left);
      }
      else
      {
            bstnode* temp=root;
            bstnode* successor=NULL;
            while(temp!=curr)
            {
                  if(curr->data>temp->data)
                  {
                        successor=temp;
                        temp=temp->right;
                  }
                  else temp=temp->left;
            }
            return successor;
      }
}
int main()
{
      int a;
      bstnode *root=NULL;
      root=insert(root,15);
      root=insert(root,10);
      root=insert (root,20);
      root=insert(root,25);
      root=insert(root,8);
      root=insert(root,12);
      root=insert(root, 9);
      root=insert(root, 7);
      root=insert(root, 17);
      root=insert(root, 16);
      cout<<"Enter a number to be searched: ";
      cin>>a;
      if(searchbst(root,a)!=NULL)
            cout<<"Found"<<endl;
      else cout<<"Not Found"<<endl;
      cout<<"Height of the tree is "<<findheight(root)<<endl;

      cout<<"Level Order ";
            LevelOrder(root);
      cout<<endl<<isbinarysearchtree(root)<<endl;
      cout<<checkbst(root)<<endl;
      inorder(root);
      cout<<endl;
      root=Delete(root,10);
      inorder(root);
      cout<<endl;

      cout<< getsuccessor(root,8)->data;
      cout<<endl<<getpredecessor(root,16)->data;
}
