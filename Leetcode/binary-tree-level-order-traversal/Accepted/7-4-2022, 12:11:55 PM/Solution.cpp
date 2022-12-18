// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()) {
            int sz = q.size();
            vector<int> lev;
            for(int i=0;i<sz;i++) {
                TreeNode* top = q.front();
                q.pop();
                lev.push_back(top->val);
                if(top->left)  q.push(top->left);
                if(top->right) q.push(top->right);
            }
            ans.push_back(lev);
        }
        return ans;
    }
};