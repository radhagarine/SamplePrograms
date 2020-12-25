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
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* r = root;
        while(r){
            st.push(r);
            r=r->left;
        };
    }
    
    int next() {
        TreeNode* t = NULL;
        if(!st.empty()){
            t = st.top();
            st.pop();
            TreeNode* temp = t->right;
            while(temp){
                st.push(temp);
                temp = temp->left;
            };
        }
        return t?t->val:-1;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
