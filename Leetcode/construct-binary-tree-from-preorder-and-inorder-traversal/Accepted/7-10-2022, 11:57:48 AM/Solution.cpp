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
    TreeNode* util(vector<int> &preorder, vector<int> &inorder, int prei, int pref, int ini, int inf) {
        // cout<<ini<<" "<<inf<<" "<<prei<<" "<<pref<<endl;
        if(prei>pref) return NULL;
        if(prei==pref) {
            return new TreeNode(preorder[prei]);
        } 
        TreeNode* curr = new TreeNode(preorder[prei]);
        for(int i=ini;i<=inf;i++) {
            if(inorder[i]==preorder[prei]) {
                int len = i-ini;
                curr->left = util(preorder, inorder, prei+1, prei+len , ini, i-1);
                curr->right = util(preorder, inorder, prei+len+1, pref, i+1, inf);
                break;
            }
        }
        return curr;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return util(preorder, inorder, 0, n-1, 0,n-1);
    }
};