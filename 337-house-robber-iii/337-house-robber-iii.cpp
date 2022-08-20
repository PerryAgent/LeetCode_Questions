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
    map<pair<TreeNode*, int>, int>dp;
//     void inorder(vector<int>& sum, TreeNode* root, int l) {
//         if(!root) return;
//         while(sum.size()<=l) sum.push_back(0);
//         sum[l] += root->val;
//         inorder(sum, root->left, l+1);
//         inorder(sum, root->right, l+1);
        
//     }
    // int maxSum(vector<int>& sum, int i) {
    //     if(i>=sum.size()) return 0;
    //     if(dp.find(i)!=dp.end()) return dp[i];
    //     return dp[i] = max(sum[i]+maxSum(sum, i+2), maxSum(sum, i+1));
    // }
    int dpFn(TreeNode* root, int f) {
        if(!root) return 0;
        if(dp.find({root, f})!=dp.end()) return dp[{root, f}];
        if(f) {
            return dp[{root, f}] = max(root->val+dpFn(root->left, 1-f)+dpFn(root->right, 1-f), dpFn(root->left, f) + dpFn(root->right, f));
        }
        return dp[{root, f}] = dpFn(root->left, 1-f) + dpFn(root->right, 1-f);
    }
    
    int rob(TreeNode* root) {
        
        return dpFn(root, 1);
        vector<int>sum;
        
//         inorder(sum, root, 0);
        
//         return maxSum(sum, 0);
    }
};