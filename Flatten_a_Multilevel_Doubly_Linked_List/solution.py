"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        
        def dfs(node):
            if not node.next and not node.child:
                return node
            if node.child and not node.next:
            
                node.next=node.child
                node.child.prev=node
                node.child=None
                return dfs(node.next)
            
            curr=node
            end=node
            
            while curr:
                if curr.prev and curr.prev.child:
                    curr.prev.next=curr.prev.child
                    curr.prev.child.prev=curr.prev
                    curr.prev.child=None
                    tmp=dfs(curr.prev.next)
                    tmp.next=curr
                    curr.prev=tmp
                
                end=curr
                curr=curr.next
                
            return end
        if not head:
            return None
        dfs(head)
        return head
