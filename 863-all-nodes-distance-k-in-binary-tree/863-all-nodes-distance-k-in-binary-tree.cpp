/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int nodes = -1;
    void calcNodes(TreeNode* root) {
        if(!root) return;
        if(root->val > nodes)
            nodes = root->val;
        calcNodes(root->left);
        calcNodes(root->right);
    }
    
    void calcEdges(vector<vector<int>>& edges, TreeNode* root){
        if(!root) return;
        if(root->left!=NULL) {
            edges[root->val].push_back(root->left->val);
            edges[root->left->val].push_back(root->val);
            calcEdges(edges, root->left);
        }
        if(root->right!=NULL) {
            edges[root->val].push_back(root->right->val);
            edges[root->right->val].push_back(root->val);
            calcEdges(edges, root->right);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        nodes=-1;
        calcNodes(root);
        vector<vector<int>>edges(nodes+1, vector<int>());
        calcEdges(edges, root);
       
        
        vector<int> nb;
        vector<int> visited(nodes+1, 0);
        nb.push_back(target->val);
        while(k>0) {
            vector<int>nnb;
            for(auto i: nb) {
                visited[i] = 1;
                for(auto j: edges[i]){
                    if(!visited[j])
                        nnb.push_back(j);}
            }
            nb = nnb;
            k--;
        }
        
        return nb;
        
    }
};