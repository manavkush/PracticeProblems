// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another

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
private:
    bool dfs(TreeNode* root, string &curr, int val) {
        if(!root)
            return false;
        if(root->val==val) {
            return true;
        }
        curr += 'L';
        if(dfs(root->left, curr, val))
            return true;
        curr.pop_back();
        
        curr+='R';
        if (dfs(root->right, curr, val)) 
            return true;
        curr.pop_back();
        
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode*, TreeNode*> parent;
        string s1,s2;
        dfs(root, s1, startValue);
        dfs(root, s2, destValue);
        
        int i = 0;
        for(i=0;i<min(s1.length(), s2.length()); i++) {
            if(s1[i]!=s2[i])
                break;
        }
        string l1 = string(s1.length()-i, 'U');
        string l2 = s2.substr(i);
        
        return l1+l2;
    }
};