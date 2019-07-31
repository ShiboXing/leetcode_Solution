class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int alen=A.size();
        int slen=A[0].size();
        vector<int> dp(slen,1);
        for(int i =0;i<slen;i++)
        {
            for(int j=0;j<i;j++)
            {
                for(int a=0;a<=alen;a++)
                {
                    //cout<<i<<" "<<j<<" "<<a<<endl;
                    if(a==alen)
                        dp[i]=max(dp[i],dp[j]+1);
                    else if(A[a][j]>A[a][i])
                        break;
                }
                
            }
        }
       
        return slen- *max_element(dp.begin(),dp.end());
    }
};