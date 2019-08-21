class Solution {
public:
    
    struct Node{
        int steps;
        int state;
        int num;
        
        Node(int a, int b,int c)
        {
            steps=a;
            state=b;
            num=c;
        }
    };
    
    struct hash_func{
        size_t operator()(const pair<int,int>& n) const
        {
            return n.first^n.second;
        }
    };
    
    struct Comparator{
        bool operator()(Node const &n1,Node const &n2)
        {
            return n1.steps<n2.steps;
        }
    };
    
    int shortestPathLength(vector<vector<int>>& graph) {
        if(!graph[0].size())
            return 0;
    
        priority_queue<Node,vector<Node>,Comparator> pq;
        unordered_map<pair<int,int>,int,hash_func> s;
        int mask=1;
        for(int i=0;i<graph.size();i++)
        {
            mask|=mask<<1;
            Node n(0,1<<i,i);
            pq.push(n);
            s[{i,1<<i}]=0;
        }
        mask=mask>>1;
        int ans=INT_MAX;
        while(!pq.empty())
        {
            Node n=pq.top();
            
            pq.pop();
            for(auto x : graph[n.num])
            {
                pair tmp={x,n.state|1<<x};
                if(tmp.second==mask){
                    ans=min(ans,n.steps+1);
                    break;
                }
                if(s.find(tmp)!=s.end() && s[tmp]>n.steps+1 || s.find(tmp)==s.end())
                {
                    s[tmp]=n.steps+1;
                    Node next(n.steps+1,n.state|1<<x,x);
                    pq.push(next);
                }
            }
        }
        
        
        return ans;
    }
};