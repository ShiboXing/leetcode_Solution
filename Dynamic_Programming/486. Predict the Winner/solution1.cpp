class Solution {
public:
    
    
    bool PredictTheWinner(vector<int>& nums) {
        int nlen=nums.size();
        vector<vector<int>> dp(nlen,vector<int>(nlen,0));
        for(int i=0;i<nlen;i++)
            dp[i][i]=nums[i];
        for(int i=1;i<nlen;i++)
        {
            for(int k=0;k+i<nlen;k++)
            {
                dp[k][k+i]=max(nums[k]-dp[k+1][k+i],nums[k+i]-dp[k][k+i-1]);
            }
        }
  
        return dp[0][nlen-1]>=0;
    }
};