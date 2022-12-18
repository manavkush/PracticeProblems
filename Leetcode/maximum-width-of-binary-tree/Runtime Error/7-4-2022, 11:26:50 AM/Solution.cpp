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
        int curr = q.size();
        int size = q.size();
        int first;
        while(!q.empty()) {
            pair<TreeNode*, int> top = q.front();
            q.pop();
            int val = top.second;
            TreeNode* node = top.first;
            
            // first node
            if(curr==size) {
                first = val;
            }
            curr--;
            
            if(node->left) q.push({node->left, 2*(val-first)+1});
            if(node->right) q.push({node->right, 2*(val-first)+2});
            
            if(curr==0) {
                ans = max(ans, val-first+1);
                curr = size = q.size();
            }
        }
        return ans;
    }
};