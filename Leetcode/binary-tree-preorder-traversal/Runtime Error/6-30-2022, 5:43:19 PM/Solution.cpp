// https://leetcode.com/problems/binary-tree-preorder-traversal

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        st.push(root);
        ans.push_back(root->val);
        root=root->left;
        while(1) {
            if(root) {
                ans.push_back(root->val);
                st.push(root);
                root = root->left;
            } else {
                if(st.empty()) {
                    break;
                }
                TreeNode * top = st.top();
                st.pop();
                root=top->right;
            }
        }
        return ans;
    }
};