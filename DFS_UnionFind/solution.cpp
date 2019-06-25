class Solution {
public:
    int rlen,clen;
    vector<vector<int>> grid;
    map<pair<int,int>,pair<int,int>> uf;
    map<pair<int,int>,int> degrees;
    int largestIsland(vector<vector<int>>& grid) {
       
        int ans=0;
        Solution::grid=grid;
        if(grid.empty())
            return 1;
        rlen=grid.size();
        clen=grid[0].size(); 
        
        for(int i=0;i<rlen;i++)
            for(int j=0;j<clen;j++)
                degrees[{i,j}]=dfs(i,j);
        //for(auto x :degrees)
          //  cout<<x.second<<endl;
        
        for(int i=0;i<rlen;i++)
            for(int j=0;j<clen;j++)
                if(grid[i][j]==0)
                {
                    map<pair<int,int>,int> tmp;
                    int tmpans=0;
                    if(degrees.count(f({i-1,j})))
                        tmp[f({i-1,j})]=degrees[f({i-1,j})];
                    if(degrees.count(f({i+1,j})))            
                        tmp[f({i+1,j})]=degrees[f({i+1,j})];   
                    if(degrees.count(f({i,j-1})))       
                        tmp[f({i,j-1})]=degrees[f({i,j-1})];   
                    if(degrees.count(f({i,j+1})))   
                        tmp[f({i,j+1})]=degrees[f({i,j+1})];                
                    for(auto x :tmp)
                        tmpans+=x.second;
                    ans=max(tmpans,ans);
                }
        int ExistingBiggestIsland=0;
        for(auto x:degrees)
            ExistingBiggestIsland=max(ExistingBiggestIsland,x.second);
        if(ExistingBiggestIsland==rlen*clen)
            return ExistingBiggestIsland;
        return max(ExistingBiggestIsland+1,ans+1);
    }
    
    int dfs(int r, int c)
    {
        pair<int,int> tmp={r,c};
       
        if( grid[r][c]==0 || grid[r][c]==-1)
        {
            return 0;
        }
        int ans=1;
        grid[r][c]=-1;
        if(r+1<rlen && grid[r+1][c]==1) {
            u(make_pair(r+1,c),tmp);
            ans+=dfs(r+1,c);
        }
        if(r-1>=0 && grid[r-1][c]==1){
            u(make_pair(r-1,c),tmp);
            ans+=dfs(r-1,c);
        }
        if(c+1<clen && grid[r][c+1]==1) {
            u(make_pair(r,c+1),tmp);
            ans+=dfs(r,c+1);
        }
        if(c-1>=0 && grid[r][c-1]==1) {
            u(make_pair(r,c-1),tmp);
            ans+=dfs(r,c-1);
        }
        return ans;
    }
    
    int u(pair<int,int> a, pair<int,int> b)
    {
        uf[f(a)]=f(b);
        return 0;
    }
    pair<int,int> f(pair<int,int> a)
    {
        if(!uf.count(a) || uf[a]==a)
            return a;
        uf[a]=f(uf[a]);
        return uf[a];
    }
};
