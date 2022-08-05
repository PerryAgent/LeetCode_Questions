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
    void nodes(vector<vector<int>>& ans, TreeNode* root, int level) {
        if(!root) return;
        if(ans.size() > level)
            ans[level].push_back(root->val);
        else{
            ans.push_back(vector<int>());
            ans[level].push_back(root->val);
        }
                          
        nodes(ans, root->left, level+1);
        nodes(ans, root->right, level+1);                
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        nodes(ans, root, 0);
        
        for(int i=0; i<ans.size(); i++) {
            if(i%2)
                reverse(ans[i].begin(), ans[i].end());
        }
        
        return ans;
        
    }
};