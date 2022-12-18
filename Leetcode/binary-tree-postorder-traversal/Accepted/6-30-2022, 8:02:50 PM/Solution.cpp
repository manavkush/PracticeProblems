// https://leetcode.com/problems/binary-tree-postorder-traversal

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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> temp;
        stack<int> base;
        if(root)
            temp.push(root);
        while(!temp.empty()) {
            TreeNode* top = temp.top(); 
            temp.pop();
            base.push(top->val);
            if(top->left) temp.push(top->left);
            if(top->right) temp.push(top->right);
        }
        while(!base.empty()) {
            ans.push_back(base.top());
            base.pop();
        }
        return ans;
    }
};