class Solution {
public:
    
    int memo(int ind, int m,vector<int>& sums,vector<vector<int>>& dp)
    {
        if(ind+2*m>=dp.size())
        {
            dp[ind][m]=sums[ind];
            return sums[ind];
        }
        if(dp[ind][m]!=-1)
            return dp[ind][m];
        
        int mini=INT_MAX;   
        for(int i =1;i<=2*m;i++)
        {
            mini=min(mini,memo(ind+i,max(m,i),sums,dp));
        }
        //cout<<"ind: "<<ind<<" m: "<<m<<endl;
        //cout<<"mini: "<<mini<<" sums[ind]: "<<sums[ind]<<endl;
        dp[ind][m]=sums[ind]-mini;
        //cout<<"dp: "<<endl;
        /*for(auto x :dp)
        {
            for(auto y :x)
                cout<<" "<<y;
            cout<<endl;
        }*/
        return dp[ind][m];
    }
    
    int stoneGameII(vector<int>& piles) {
        int plen=piles.size();
        
        vector<int> sums(plen,0);
        vector<vector<int>> dp(plen,vector<int>(plen,-1));
        sums[plen-1]=piles[plen-1];
        for(int i=plen-2;i>-1;i--)
            sums[i]=piles[i]+sums[i+1];
        
        return memo(0,1,sums,dp);
    }
};