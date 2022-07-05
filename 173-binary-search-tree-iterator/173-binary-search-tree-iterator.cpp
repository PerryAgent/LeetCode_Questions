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
public:
    vector<int> num;
    int current = -1;
    
    void inorder(TreeNode* root){
        if (root==NULL) return;
        inorder(root->left);
        num.push_back(root->val);
        inorder(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        return num[++current];
    }
    
    bool hasNext() {
        return (current +1 < num.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */