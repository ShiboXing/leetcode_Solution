class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int alen=arr.size();
        int dp[alen][alen];
        int hi[alen][alen];
        for(int i=0;i<alen;i++)
        {
            int maxVal=arr[i];
            for(int j =i;j<alen;j++)
            {
                dp[i][j]=0;
                hi[i][j]=max(maxVal,arr[j]);
                maxVal=hi[i][j];
                
            }
        }       
    
        for( int i=1;i<alen;i++)
        {
            for(int j=0;j+i<alen;j++)
            {
                int bound=i+j;
                if(i==1)
                {
                    dp[j][bound]=arr[j]*arr[bound];
                    //cout<<"i==1: j： "<<j<<" bound: "<<bound<<" dp[j][bound]: "<<dp[j][bound]<<endl;
                }
                else
                {
                    dp[j][bound]=INT_MAX;
                    for(int k=j;k<bound;k++)
                    {
                        int base=dp[j][k]+dp[k+1][bound];
                        int l= hi[j][k];
                        int r= hi[k+1][bound];
                        
                        //cout<<"j： "<<j<<" bound: "<<bound<<" k: "<<k<<" dp[j][bound]: "<<dp[j][bound]<<endl;
                        //cout<<"l: "<<l<<" r: "<<r<<" base: "<<base<<endl;
                        dp[j][bound]=min(dp[j][bound],base+l*r);
                        //cout<<"k: "<<k<<" dp[j][bound]: "<<dp[j][bound]<<endl;
                    }
                }
            }
        }
        return dp[0][alen-1];
    }
};