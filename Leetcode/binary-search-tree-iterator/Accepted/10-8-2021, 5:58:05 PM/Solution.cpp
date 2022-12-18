// https://leetcode.com/problems/binary-search-tree-iterator

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
class BSTIterator {
private: 
    vector<int> inorder = {-1};
    int iter = 0;
public:
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while((!st.empty()) || curr) {
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        
    }
    
    int next() {
        iter++;
        return inorder[iter];
    }
    
    bool hasNext() {
        return iter!=inorder.size()-1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */