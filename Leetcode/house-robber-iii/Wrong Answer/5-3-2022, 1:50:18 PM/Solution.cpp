// https://leetcode.com/problems/house-robber-iii

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
    void util(TreeNode* root, int color, int &red, int &black) {
        if(root==NULL)
            return;
        if(color&1) {
            black+= root->val;
            util(root->left, color^1, red, black);
            util(root->right, color^1, red, black);
        } else {
            red+= root->val;
            util(root->left, color^1, red, black);
            util(root->right, color^1, red, black);
        }
    }
public:
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        int red=0, black=0;
        util(root, 0, red, black);
        return max(red, black);
    }
};