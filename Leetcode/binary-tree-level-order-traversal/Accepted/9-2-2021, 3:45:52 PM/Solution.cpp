// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root!=NULL) {
            q.push(root);
        }
        vector<vector<int>> ans;
        while(!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            for(int i=0; i<sz;i++) {
                TreeNode* front = q.front();
                q.pop();
                temp.push_back(front->val);
                if(front->left!=NULL) q.push(front->left);
                if(front->right!=NULL) q.push(front->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};