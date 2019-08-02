class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.size();
        int len2=text2.size();
        vector<vector<int>> dp(vector(len1,vector<int>(len2,0)));   
        
        
        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                int tmp= text1[i]==text2[j] ? 1 : 0;
                if(i && j) dp[i][j]=max(dp[i-1][j-1]+tmp,max(dp[i-1][j],dp[i][j-1]));
                else if(i) dp[i][j]=max(dp[i-1][j],tmp);
                else if(j) dp[i][j]=max(dp[i][j-1],tmp);
                else dp[i][j]=tmp;
                
                //cout<<"i:"<<i<<" j:"<<j<<" dp:"<<dp[i][j]<<"  ";//<<" "<<text1[i]<<" "<<text2[j]<<" ";
            }
            //cout<<endl;
        }
        int ans=0;
        for(int i=0;i<len1;i++)
            ans=max(dp[i][len2-1],ans);
        
        return ans;
    }
};