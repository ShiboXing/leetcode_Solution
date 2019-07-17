/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> in;
        auto curr=head;
        while (curr)
        {
            in.push_back(curr->val);
            curr=curr->next;
        }
        if(!in.size())
            return NULL;
        return generate(in,0,in.size()-1);
    }
    
    TreeNode* generate(vector<int> &in,int start, int end)
    {
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode* root=new TreeNode(in[mid]);
        root->left=generate(in,start,mid-1);
        root->right=generate(in,mid+1,end);
        
        return root;
    }
};
