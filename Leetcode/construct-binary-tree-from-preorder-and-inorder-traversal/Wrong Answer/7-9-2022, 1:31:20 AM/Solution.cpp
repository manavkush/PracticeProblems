// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    TreeNode* util(vector<int> &preorder, vector<int> &inorder, int ii, int ff) {
        if(ii>ff) return NULL;
        if(ii==ff) {
            return new TreeNode(inorder[ii]);
        } 
        TreeNode* curr = new TreeNode(preorder[ii]);
        for(int i=ii;i<=ff;i++) {
            if(inorder[i]==preorder[ii]) {
                curr->left = util(preorder, inorder, ii, i-1);
                curr->right = util(preorder, inorder, i+1, ff);
                break;
            }
        }
        return curr;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return util(preorder, inorder, 0,n-1);
    }
};