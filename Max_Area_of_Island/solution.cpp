using namespace std;

class Solution {
public:
    int rlen;
    int clen;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rlen=grid.size();
        clen=grid[0].size();
        int maxRes=0;
        for(int i=0;i<rlen;i++)
            for(int j=0;j<clen;j++)
                maxRes=max(maxRes,dfs(i,j,grid));
        
        return maxRes;
    }
    
    int dfs(int r,int c,vector<vector<int>>& grid)
    {
        if (r<0 || r==rlen || c<0 || c==clen || grid[r][c]==0)
            return 0;
        
        grid[r][c]=0;
        int res=1;
        res+=dfs(r+1,c,grid)+dfs(r,c+1,grid)+dfs(r-1,c,grid)+dfs(r,c-1,grid);
        return res;
    }
};
