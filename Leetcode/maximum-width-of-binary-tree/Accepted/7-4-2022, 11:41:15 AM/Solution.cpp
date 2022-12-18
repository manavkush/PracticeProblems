// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        if(root)
        q.push({root, 0});
        long long ans = 0;
        int size = q.size();
        long long first;
        while(!q.empty()) {
            int size = q.size();
            long long first = q.front().second;
            long long left_val, right_val;
            for(int i=0;i<size;i++) {
                TreeNode* node = q.front().first;
                long long val = q.front().second - first;
                q.pop();
                if(i==0) {
                    left_val=val;
                }
                if(i==size-1) {
                    right_val=val;
                }
                if(node->left) q.push({node->left, 2*(val)+1});
                if(node->right) q.push({node->right, 2*(val)+2});
            }
            ans = max(ans, right_val-left_val+1);
            
        }
        return ans;
    }
};