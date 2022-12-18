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
        queue<pair<TreeNode*, int>> q;
        if(root)
        q.push({root, 0});
        int ans = 0;
        int size = q.size();
        int first;
        while(!q.empty()) {
            int size = q.size();
            int first = q.front().second;
            int left_val, right_val;
            for(int i=0;i<size;i++) {
                TreeNode* node = q.front().first;
                int val = q.front().second;
                q.pop();
                if(i==0) {
                    left_val=val;
                }
                if(i==size-1) {
                    right_val=val;
                }
                if(node->left) q.push({node->left, 2*(val-first)+1});
                if(node->right) q.push({node->right, 2*(val-first)+2});
            }
            ans = max(ans, right_val-left_val+1);
            
        }
        return ans;
    }
};