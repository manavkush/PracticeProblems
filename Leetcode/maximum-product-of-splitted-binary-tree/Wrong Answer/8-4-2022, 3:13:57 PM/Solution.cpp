// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

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
    const int mod = 1e9+7;
    long long ans = 1;
    long long total = 0;
    long long dfs(TreeNode* root) {
        if(!root)
            return 0;
        long long left = dfs(root->left);
        long long right = dfs(root->right);
        
        ans = max(ans, (left*(total-left))%mod);
        ans = max(ans, (right*(total-right))%mod);
        
        return left+right+root->val;
    }
public:
    int maxProduct(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* top = q.front(); q.pop();
            total += top->val;
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        dfs(root);
        return ans;
    }
};