// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    bool findTarget(TreeNode* root, int k) {
       vector<int> inor;
       stack<TreeNode*> st;
       TreeNode * curr = root;
       while((!st.empty()) or (curr)) {
           while(curr) {
               st.push(curr);
               curr=curr->left;
           }
           curr = st.top();
           st.pop();
           inor.push_back(curr->val);
           curr = curr->right;
       }
       int ff = 0;
       int ll = inor.size()-1;
       while(ff<ll) {
           int sum = inor[ff]+inor[ll];
           if(sum == k) return 1;
           else if(sum < k) {
               ff++;
           } else {
               ll--;
           }
       } 
        return false;
    }
};