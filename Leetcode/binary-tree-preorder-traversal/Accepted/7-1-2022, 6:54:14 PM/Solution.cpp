// https://leetcode.com/problems/binary-tree-preorder-traversal


// Morris Traversal Preorder

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root) {
            if(root->left) {
                TreeNode* temp = root->left;
                while(temp->right and temp->right!=root) {
                    temp = temp->right;
                }
                if(temp->right==root) {
                    temp ->right = NULL;
                    root = root->right;
                } else {
                    temp->right = root;
                    ans.push_back(root->val);
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