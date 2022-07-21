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
    void in(vector<int>& list, TreeNode* root) {
        if(!root) return;
        
        in(list, root->left);
        list.push_back(root->val);
        in(list, root->right);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>list;
        in(list, root);
        
        for(int i=0; i<list.size()-1; i++) {
            if(list[i]>=list[i+1])
                return false;
        }
        
        return true;
    }
};