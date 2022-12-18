// https://leetcode.com/problems/average-of-levels-in-binary-tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        
        while(!q.empty()) {
            int sz = q.size();
            double curr = 0;
            for(int i=0;i<sz;i++) {
                TreeNode* top = q.front();       
                curr += top->val;
                q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            curr = curr/sz;
            ans.push_back(curr);
        }
        return ans;
    }
};