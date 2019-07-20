class Solution {
public:
    

    bool divisorGame(int N, bool isAlice=true) {
        if(N==1)
            return false;
        vector<bool> dp(N+1,false); 
        dp[1]=false;
        for(int i=2;i<=N;i++)
            for(int j=1;j<=i/2;j++)
                if(i%j==0 && dp[i-j]==false)
                {
                    dp[i]=true;
                    break;
                }
        return dp[N];
    }
};
