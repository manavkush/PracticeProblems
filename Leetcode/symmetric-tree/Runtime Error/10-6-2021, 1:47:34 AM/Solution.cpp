// https://leetcode.com/problems/symmetric-tree

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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty()) {
            TreeNode* top1 = q1.front();
            TreeNode* top2 = q2.front();
            q1.pop();
            q2.pop();
            if((!top1) and (!top2)) {
                continue;
            }
            else if((top1 and (!top2))) {
                return false;
            }
            if(top1->val!=top2->val) {
                return false;
            }
            q1.push(top1->left);
            q1.push(top1->right);
            q2.push(top2->right);
            q2.push(top2->left);
        }
        return true;
    }
};