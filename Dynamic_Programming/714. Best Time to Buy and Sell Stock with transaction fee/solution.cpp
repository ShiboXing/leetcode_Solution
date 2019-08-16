class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int s1=0; //state1: can buy, can keep
        int s2=0; //state2: can sell, can keep
        int ans=0;
        for(auto x : prices)
        {
            int tmp=s1;
            s1=max(s2+x-2,s1);
            s2=max(tmp-x-2,s2);
                
        }
    }
};