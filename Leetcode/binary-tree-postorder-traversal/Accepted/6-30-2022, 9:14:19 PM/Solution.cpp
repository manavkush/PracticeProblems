// https://leetcode.com/problems/binary-tree-postorder-traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(root!=NULL || (!st.empty())) {
            if(root!=NULL) {
                st.push(root);
                root = root->left;
            } else {
                TreeNode* temp = st.top();
                if(temp->right) {
                    root = temp->right;
                } else {
                    // got to go back up the tree
                    ans.push_back(temp->val);
                    st.pop();
                    while(!st.empty() and (st.top()->right == temp)) {
                        temp = st.top();
                        ans.push_back(temp->val);
                        st.pop();
                    }
                }
            }
        }
        return ans;
    }
};