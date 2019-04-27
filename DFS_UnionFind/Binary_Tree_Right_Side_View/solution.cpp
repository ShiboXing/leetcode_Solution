/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//todo: can modify use pre-order traversal and traverse the right child first

class Solution {
public:
    vector<int> res{};
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return res;
        dfs(0,root);
        return res;
    }
    
    int dfs(int l,TreeNode* n)
    {
       
        if(res.size()<=l)
            res.push_back(n->val);
        else
            res[l]=n->val;
       
        if(n->left)
            dfs(l+1,n->left);
        if(n->right)
            dfs(l+1,n->right);
        return 0;
    }
};

