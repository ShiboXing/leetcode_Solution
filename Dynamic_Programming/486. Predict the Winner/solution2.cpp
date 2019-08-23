class Solution {
public:
    
    int dnc(vector<int>& nums,int l, int r, vector<vector<int>>& dp)
    {
        if(l==r)
            return nums[l];
        if(dp[l][r])
            return dp[l][r];
        int ans1=nums[l]-dnc(nums,l+1,r,dp);
        int ans2=nums[r]-dnc(nums,l,r-1,dp);
        dp[l][r]=max(ans1,ans2);
        return dp[l][r];
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int nlen=nums.size();
        vector<vector<int>> dp(nlen,vector<int>(nlen,0));
        return dnc(nums,0,nlen-1,dp)>=0;
  
    }
};