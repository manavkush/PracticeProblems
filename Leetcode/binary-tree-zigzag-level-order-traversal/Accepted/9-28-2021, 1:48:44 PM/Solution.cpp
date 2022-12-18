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
        vector<vector<int>>ans;
        if(!root)   return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int curr = 0;
        int tot = 1;
        vector<int> ind;
        while(!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            ind.push_back(top->val);
            {
                if(top->left) 
                q.push(top->left);
                if(top->right)
                q.push(top->right);
            }
            curr++;
            if(curr==tot) {
                ans.push_back(ind);
                ind.clear();
                level ^=1;
                curr = 0;
                tot = q.size();
            }
        }
        for(int i=0;i<ans.size();i++) {
            if(i&1) reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};