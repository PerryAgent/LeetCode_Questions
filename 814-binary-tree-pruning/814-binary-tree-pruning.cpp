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
    bool subtreeHas(TreeNode* root) {
        if(!root) return false;
        
        bool l = subtreeHas(root->left);
        bool r = subtreeHas(root->right);
        
        if(!l) root->left = NULL;
        if(!r) root->right = NULL;
        
        return (root->val || l || r)?true:false;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool ans = subtreeHas(root);
        if(!ans) return NULL;
        else return root;
    }
};