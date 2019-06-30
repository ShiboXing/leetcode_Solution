class Solution:
    def minHeightShelves(self, books: List[List[int]], shelf_width: int) -> int:
        width=len(books)
        dp=[0]*width
        
        ans=0
        dp[0]=books[0][1]
        for x in range(0,width):
            res1=dp[x-1]+books[x][1]
            ind,tmp,maxH=1,books[x][0],books[x][1]
            while x-ind>=0 and tmp<=shelf_width:
                maxH=max(maxH,books[x-ind][1])
                tmp+=books[x-ind][0]
                ind+=1
                #print(maxH,tmp,ind)
            res2=maxH
            dp[x]=min(res1,res2)+dp[x-ind]
            #print(dp)
        return dp[width-1]
                
                
                
                    
