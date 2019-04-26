class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        sLen=len(s)
        if not s or sLen==1:
            return 0
        
        def reduce(stack,i):
            tLen=len(stack)
            while i>0:
                if type(stack[i-1])==int:
                    i-=1
                else:
                    break
            while True:
                if type(stack[i+1])==int:
                    stack[i]+=stack[i+1]
                    del stack[i+1]
                else:
                    break
            return len(stack)

        stack=[]
        index=-1
        for x in s:
            stack.append(x)
            index+=1
            if x==')':
                for back in range(index-1,-1,-1):
                    if type(stack[back])==int:
                        continue
                    if stack[back]=='(':
                        stack[back]=2
                        index=reduce(stack,back)-1
                        del stack[index]
                        index-=1
                        break
                    else:
                        break
            
        ans=0
        for x in stack:
            if type(x)==int:
                ans=max(ans,x)
        return ans
                
            
        
