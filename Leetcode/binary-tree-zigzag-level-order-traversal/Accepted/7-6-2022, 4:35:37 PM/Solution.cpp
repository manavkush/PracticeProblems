// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        int lev = 0;
        if(root)
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            for(int i=0;i<sz;i++) {
                TreeNode* top = q.front();
                q.pop();
                temp.push_back(top->val);
                if(top->left)   q.push(top->left);
                if(top->right)  q.push(top->right);
            }
            if(lev) {
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
            lev ^= 1;
        }
        return ans;
    }
};