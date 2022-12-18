// https://leetcode.com/problems/binary-tree-inorder-traversal

// single stack inorder

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(1) {
            if(root) {
                st.push(root);
                root=root->left;
            } else {
                if(st.empty()) {
                    return ans;
                }
                ans.push_back(st.top()->val);
                root = st.top()->right;
                st.pop();
            }
        }
    }
};