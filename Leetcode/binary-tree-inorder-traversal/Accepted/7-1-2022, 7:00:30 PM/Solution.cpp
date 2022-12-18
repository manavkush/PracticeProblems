// https://leetcode.com/problems/binary-tree-inorder-traversal

// 

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root) {
            if(root->left) {
                TreeNode* temp = root->left;
                while(temp->right and temp->right!=root) {
                    temp = temp->right;
                }
                if(temp->right==root) {
                    temp->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;
                } else {
                    temp->right = root;
                    root = root->left;
                }
            } else {
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};