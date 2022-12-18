// https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int dist = 0;
        if(!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int nodes = 1;
        int curr = 0;
        while(!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            curr++;
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
            if(curr==nodes) {
                ans.push_back(temp->val);
                nodes = q.size();
                curr = 0;
            }
        }
        return ans;
    }
};