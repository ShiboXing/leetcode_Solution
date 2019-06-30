class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
    
        r1=1
        r2=1
        
        if int(s[0])==0 or int(s)==0:
            return 0
        
        for i in range(1,len(s)):
        
            if (s[i-1]=='1' or (s[i-1]=='2' and int(s[i])<=6)) and s[i]!='0':
                r1=r1+r2
                r2=r1-r2
            elif s[i]=='0':
                if s[i-1]=='1' or s[i-1]=='2':
                    r1=r2
                else:
                    return 0
            else:
                r2=r1
            
        
        
        return r1
            
        
