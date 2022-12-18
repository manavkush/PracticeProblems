// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> kth;
        stack<TreeNode* > st;
        TreeNode * curr = root;
        while(curr || (!st.empty())) {
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            kth.push_back(curr->val);
            curr = curr->right;
        }
        return kth[k-1];
        
    }
};