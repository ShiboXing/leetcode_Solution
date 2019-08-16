class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
    
        vector<vector<string>> dp(n+1,vector<string>(m+1,""));
        
        for(int i =0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                
                if(str1[i]==str2[j])
                    dp[i+1][j+1]=dp[i+1][j+1].size() > dp[i][j].size()+1 ? dp[i+1][j+1] : dp[i][j]+str1[i];
                else
                    dp[i+1][j+1]=dp[i][j+1].size() > dp[i+1][j].size() ? dp[i][j+1] : dp[i+1][j];
            }
        
            int i=0;int j=0;string ans="";
            for(auto x:dp[n][m])
            {
                while(str1[i]!=x && i<n)
                    ans+=str1[i++];
                while(str2[j]!=x && j<m)
                    ans+=str2[j++];
                ans+=x;
                i++;j++;
            }
            while(i<n)
                ans+=str1[i++];
        
            while(j<m)
                ans+=str2[j++];
        
        
        return ans;
    }
};
