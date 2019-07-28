class Solution {
public:
    
    int minimumDeleteSum(string s1, string s2) {
        int s1len=s1.size();
        int s2len=s2.size();
        vector<vector<int>> dp(s1len+1,vector<int>(s2len+1,0));
        for(int i=1;i<=s2len;i++)
        {
            dp[0][i]+=dp[0][i-1]+((int)s2[i-1]);
        }
        for(int i=1;i<=s1len;i++)
            dp[i][0]+=dp[i-1][0]+((int)s1[i-1]);
        for(int i=1;i<=s1len;i++)
        {
            for(int j=1;j<=s2len;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j]+((int)s1[i-1]),dp[i][j-1]+((int)s2[j-1]));   
                }
            }
        }
        return dp[s1len][s2len];
                
    }
};