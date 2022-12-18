// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* util(vector<int> &inorder,vector<int> &postorder, int ini, int inf, int posf) {
        if(ini > inf)   return NULL;
        if(ini == inf)  return new TreeNode(inorder[ini]);
        TreeNode * curr = new TreeNode(postorder[posf]);
        for(int i=ini; i<=inf;i++) {
            if(inorder[i] == postorder[posf]) {
                int len = i - ini; 
                curr->left = util(inorder, postorder, ini, i-1, posf-len-1);
                curr->right = util(inorder, postorder, i+1, inf, posf-1);
                break;
            }
        }
        return curr;
        
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        return util(inorder, postorder, 0, n-1, n-1 );
    }
};