class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int alen=A.size();
        int ma=*max_element(A.begin(),A.end());
        vector<vector<int>> dp(alen,vector<int>((ma+1)*2,1));
        int ans=0;
        /*
        cout<<"gap: "<<gap<<endl;
        cout<<"dp: ";
        for(auto x :dp)
        {
            for(auto y :x)
                cout<<y<<" ";
            
            cout<<endl;
        }*/
        for(int i=1;i<alen;i++)
        {
            for(int j =0;j<i;j++)
            {
               
                
                int tmp=A[i]-A[j]+ma;
                
                dp[i][tmp]=dp[j][tmp]+1;
                //cout<<"i: "<<i<<" j: "<<j<<" ans: "<<ans<<endl;
                ans=max(ans,dp[i][tmp]);
                /*cout<<"dp: ";
                for(auto x :dp)
                    cout<<x<<" ";
                cout<<endl;*/
            }
        }
        return ans;
    }
};
