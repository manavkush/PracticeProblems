// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "# ";
        return (to_string(root->val) + " " +serialize(root->left) + serialize(root->right));
    }

    TreeNode* deserialize_util(queue<string> &q) {
        if(q.empty()) {
            return NULL;
        }
        string s = q.front();
        q.pop();
        if(s=="#")
            return NULL;
        TreeNode* curr = new TreeNode(stoi(s));
        curr->left = deserialize_util(q);
        curr->right = deserialize_util(q);
        
        return curr;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s;
        for(int i=0;i<data.length();i++) {
            if(data[i]==' ') {
                q.push(s);
                s = "";
            } else {
                s += data[i];
            }
        }
        return deserialize_util(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));