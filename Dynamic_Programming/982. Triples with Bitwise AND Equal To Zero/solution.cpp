class Solution {
public:
    int countTriplets(vector<int>& A) {
        int N=1<<16;
        auto dp(vector<vector<int>>(3,vector<int>(N,0)));
        
        for (auto x:A)
            dp[0][x]+=1;
        
        for(int i=1;i<3;i++)
        {
            for(int j=0;j<N;j++)
            {
                for(auto x:A)
                    dp[i][x & j]+=dp[i-1][j];
            }
        }
        return dp[2][0];
        
    }
};