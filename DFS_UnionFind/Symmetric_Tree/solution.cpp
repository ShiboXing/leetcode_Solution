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
    bool isSymmetric(TreeNode* root) {
        vector<int> lseq;
        if(root==NULL)
            return true;
        lseq=dfs(root->left,lseq,true);
        vector<int> rseq;
        rseq=dfs(root->right,rseq,false);
        if(lseq.size()!=rseq.size())
            return false;
        
        for(int i=0;i<lseq.size();i++)
            if (rseq[i]!=lseq[i])
                return false;
        
        return true;
    }
    
    vector<int> dfs(TreeNode* n, vector<int> seq,bool isLeft){
        if(n==NULL)
        {
            seq.push_back(-1);
            return seq;
        }
        seq.push_back(n->val);
        //cout<<"isLeft: "<<isLeft<<"  val: "<<n->val<<endl;
        if(isLeft)
        {
            seq=dfs(n->left,seq,isLeft);
            seq=dfs(n->right,seq,isLeft);
        }
        else
        {
            seq=dfs(n->right,seq,isLeft);
            seq=dfs(n->left,seq,isLeft);
                
        }
            
        return seq;
    }
};

