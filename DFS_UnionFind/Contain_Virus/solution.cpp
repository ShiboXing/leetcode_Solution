class Solution {
public:
    
    vector<int> dirs={0,-1,0,1,0};
    int rlen;
    int clen;
    unordered_map<int,int> wallToRegion;
    int walls=0;
    struct by_count{
        bool operator()(pair<vector<pair<int,int>>,int> const &a, pair<vector<pair<int,int>>,int> const &b) const
        {
            
            return a.second > b.second;
        }
    };
    
    void dfs(vector<vector<int>>& grid,int r,int c,vector<pair<int,int>>& doomed,set<pair<int,int>>& visited)
    {
        
        //cout << "visited check: " << visited.count({r,c})<<endl;
        if(r<0 || c<0 || r==rlen || c==clen || visited.count({r,c}))
            return;
        
        if(grid[r][c]==0)
        {
            doomed.push_back({r,c});
            return;
        }
        else if(grid[r][c]==1)
        {   
            visited.insert({r,c});
        }
        else if(grid[r][c]<0) 
            return;
        
        bool exposed=false;
        
        for(int i =0;i<dirs.size()-1;i++)
        {
            int newr=r+dirs[i];
            int newc=c+dirs[i+1];
            dfs(grid,newr,newc,doomed,visited);
        }
    }
  
    void quarantine(vector<vector<int>>& grid,int r,int c)
    {
        if(r<0 || c<0 || r==rlen || c==clen || grid[r][c]!=1)
               return;
        grid[r][c]=-1;
        for(int i =0;i<dirs.size()-1;i++)
        {  
           quarantine(grid,r+dirs[i],c+dirs[i+1]);
        }
    }
    
    void infect(vector<vector<int>>& grid,vector<pair<int,int>>& doomed)
    {
        for(auto x:doomed)
            grid[x.first][x.second]=1;
        
    }
    int containVirus(vector<vector<int>>& grid) 
    {
        
        rlen=grid.size();
        if(rlen==0)
           return 0;
        clen=grid[0].size();
        
        int count=0;
        
        do{
            vector<pair<vector<pair<int,int>>,int>> doomeds;
            set<pair<int,int>> visited;
            
            for(int i=0;i<rlen;i++)
                for(int j=0;j<clen;j++)
                {
                    if (grid[i][j]==1 && !visited.count({i,j}))
                    {
                        pair<vector<pair<int,int>>,int> doomed;
                        dfs(grid,i,j,doomed.first,visited);
                        set<pair<int,int>> tmp(doomed.first.begin(),doomed.first.end());
                        doomed.second=tmp.size();
                        wallToRegion[doomed.second]=i*clen+j;
                        doomeds.push_back(doomed);
                        
                    }
                    
                }
            //rank doomeds and build walls
            if (doomeds.size()==0)
                return walls;
            sort(doomeds.begin(),doomeds.end(),by_count());
            walls+=doomeds[0].first.size();
            auto coord=wallToRegion[doomeds[0].second];
            quarantine(grid,coord/clen,coord%clen);
            //infect the doomeds
            for (int i =1;i<doomeds.size();i++)
                infect(grid,doomeds[i].first);
            
        }
        while (true);
        
        return 0;
    }
    
};
