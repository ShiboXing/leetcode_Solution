class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nlen=len(nums)
        dp=[[0] * (nlen+2) for x in range(nlen+2)]
        nums=[1]+nums+[1]
        
        def memo(left,right):
            
            if dp[left][right]:
                return dp[left][right]
            if left +1== right:
                return 0
            ans=0
            
            for i in range(left+1,right):
                tmp=nums[left]*nums[i]*nums[right]
                ans=max(ans,memo(left,i)+memo(i,right)+tmp)
            dp[left][right]=ans
            #print(left,right)
            #print(dp)
            return ans
        
        return memo(0,nlen+1)