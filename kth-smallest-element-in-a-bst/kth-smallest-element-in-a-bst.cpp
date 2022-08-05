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
    void smll(set<int>& sm, TreeNode* root, int k) {
        if(!root) return;
        if(sm.size() == k) {
            if(root->val < *(--sm.end())) {
                sm.erase(*(--sm.end()));
                sm.insert(root->val);
            }
        } else {
            sm.insert(root->val);
        }
        smll(sm, root->left, k);
        smll(sm, root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        set<int>sm;
        smll(sm, root, k);
        return (*(--sm.end()));
    }
};