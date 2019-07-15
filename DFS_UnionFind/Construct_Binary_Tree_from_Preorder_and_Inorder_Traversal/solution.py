# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder:
            return None
        root= TreeNode(preorder[0])
        start=0
        
        while True:
            if inorder[start]==root.val:
                break
            start+=1 
        lefti,righti=inorder[:start],inorder[start+1:]
        leftcollect=set(lefti)
        start=1
        while leftcollect:
            leftcollect.remove(preorder[start])
            start+=1
        root.left=self.buildTree(preorder[1:start],lefti)
        root.right=self.buildTree(preorder[start:],righti)
        return root
