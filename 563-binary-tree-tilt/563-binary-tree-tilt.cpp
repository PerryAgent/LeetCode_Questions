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
    int sum = 0;
    int find(TreeNode* root) {
        if(!root) return 0;
        int l = find(root->left);
        int r = find(root->right);

        this->sum += abs(l-r);
        // cout << root->val <<  " " << l << " " << r <<" ";
        
        // cout << sum << " ";
        // cout << root->val+l+r <<endl;
        return (root->val+l+r);
    }
    int findTilt(TreeNode* root) {
        this->sum = 0;
        int w = find(root);
        return sum;
    }
};