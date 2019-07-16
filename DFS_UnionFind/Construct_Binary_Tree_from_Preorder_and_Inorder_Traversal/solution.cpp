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
    TreeNode* dfs(int pstart,int istart, int end,vector<int>& pre,vector<int>& in)
    {
        if(pstart>=pre.size())
            return NULL;
        TreeNode root<int>(pre[pstart]);
        int newEnd=0;
        for(int i=istart;i<end;i++)
        {
            if(in[i]==root.val)
            {
                newEnd=i;
                break;
            }    
        }
                  
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    }
};
