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
    
    void order(vector<vector<int>>& list, TreeNode* root, int level) {
        if(!root) return;
        if(list.size() <= level)
            list.push_back(vector<int>());
        list[level].push_back(root->val);
        
        order(list, root->left, level+1);
        order(list, root->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> list;
        order(list, root, 0);
        
        return list;
    }
};