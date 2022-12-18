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
class BSTIterator {
    private:
        stack<TreeNode*> st;
        bool reverse;
    public:
        BSTIterator(TreeNode* root, bool IsReverse) {
            reverse = IsReverse;
            push_all(root);
        }
        void push_all(TreeNode* root) {
            for(;root!=NULL;) {
                st.push(root);
                if(reverse) root = root->right;
                else root = root->left;
            }
        }
        int next() {
            TreeNode* top = st.top();
            st.pop();
            if(reverse) push_all(top->left);    // (right, node) done
            else push_all(top->right);          // (left, node)  done
            return top->val;
        }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l = BSTIterator(root, 0);
        BSTIterator r = BSTIterator(root, 1);
        
        int i = l.next();
        int f = r.next();
        while(i<f) {
            if(i+f==k)
                return true;
            if(i+f<k)
                i = l.next();
            else 
                f = r.next();
        }
        return false;
    }
};