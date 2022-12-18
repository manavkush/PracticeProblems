// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
    int maxDepth(TreeNode* root) {
        int lev = 0;
        if(!root)   return lev;
        queue<TreeNode*> q;
        q.push(root);
        
        int curr = 0;
        int tot = 1;
        while(!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            if(top->left)   q.push(top->left);
            if(top->right)  q.push(top->right);
            curr++;
            if(curr==tot) {
                lev++;
                curr = 0;
                tot = q.size();
            }
        }
        return lev;
    }
};