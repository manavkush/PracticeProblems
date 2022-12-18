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
        q.push({root, 1});
        int ans = 0;
        int curr = 1;
        int tot = 1;
        int first;
        while(!q.empty()) {
            pair<TreeNode*, int> top = q.front();
            int val = top.second;
            TreeNode* node = top.first;
            
            if(curr==tot) {
                first = val;
            }
            q.pop();
            
            curr--;
            if(node->left) q.push({node->left, 2*(val)});
            if(node->right) q.push({node->right, 2*(val)+1});
            if(curr==0) {
                ans = max(ans, val-first+1);
                curr = tot = q.size();
            }
        }
        return ans;
    }
};