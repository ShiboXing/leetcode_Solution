#include <unordered_set>

using namespace std;

class Solution {
public:
    
    unordered_map<int,int> dict;
    int NumOfUnion=0;
    int removeStones(vector<vector<int>>& stones) {
        for(auto x : stones)
        {
            u(x[0],-x[1]-1);
        }
        return stones.size()-NumOfUnion;
    }
    
    int u(int a,int b){
        a=f(a);
        b=f(b);
        if(a!=b)
        {
            dict[a]=dict[b];
            NumOfUnion--;
        }
        return 0;        
    }
    
    int f(int n){
        if(!dict.count(n))
        {
            dict[n]=n;
            NumOfUnion++;
            return n;
        }
        int res=dict[n];
        if (res==n)
            return res;
        dict[n]=f(dict[n]);
        return dict[n];
    } 
};
