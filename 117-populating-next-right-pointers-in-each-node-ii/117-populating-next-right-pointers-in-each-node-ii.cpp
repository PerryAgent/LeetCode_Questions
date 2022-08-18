/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void inorder(vector<vector<Node*>>& nodes, int l, Node* root) {
        if(!root) return;
        if(nodes.size() > l) nodes[l].push_back(root);
        else {
            nodes.push_back(vector<Node*>());
            nodes[l].push_back(root);
        }
        inorder(nodes, l+1, root->left);
        inorder(nodes, l+1, root->right);
    }
    void mapping(map<Node*, Node*>& m, Node* root) {
        if(!root) return;
        root->next = m[root];
        mapping(m, root->left);
        mapping(m, root->right);
    }
    Node* connect(Node* root) {
        map<Node*, Node*>m;
        vector<vector<Node*>>nodes;
        inorder(nodes, 0, root);
        for(int i=0; i<nodes.size(); i++) {
            for(int j=0; j<nodes[i].size()-1; j++) {
                nodes[i][j]->next = nodes[i][j+1];
            }
        }
        
        // mapping(m, root);
        
        return root;
    }
};