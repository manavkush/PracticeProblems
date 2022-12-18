// https://leetcode.com/problems/diameter-of-binary-tree

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
    int util(TreeNode* root, map<TreeNode*, int> &heights) {
        if(!root)   return -1;
        else {
            return heights[root] = 1+max(util(root->left, heights), util(root->right, heights));
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        map<TreeNode*, int> heights;
        heights[NULL] = -1;
        util(root, heights);
        int diameter = 0;
        for(auto x: heights) {
            if(x.first) {
                cout<<(x.first)->val<<" "<<x.second<<endl;
                diameter = max(diameter, heights[x.first->left]+heights[x.first->right]+2);
            }
        }
        return diameter;
    }
};