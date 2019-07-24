class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        rlen=len(matrix)
        if not rlen:
            return 0
        clen=len(matrix[0])
        ans=0
        for x in range(0,rlen):
            for y in range(1,clen):
                matrix[x][y]+=matrix[x][y-1]
                
        for i in range(-1,clen-1):
            for j in range(i+1,clen):
                sum1=0
                dp=collections.defaultdict(int)
                dp[0]=1
                for x in range(0,rlen): 
                    sum1+=matrix[x][j]
                    if i >=0:
                        sum1-=matrix[x][i]
                    ans+=dp[sum1-target]
                    dp[sum1]+=1

        return ans