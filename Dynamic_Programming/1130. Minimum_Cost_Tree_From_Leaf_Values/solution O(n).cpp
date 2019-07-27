class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> st;
        st.push_back(INT_MAX);
        int res=0;
        for(auto x :arr)
        {
            while (x>=st.back())
            {
                int last=st.back();
                st.pop_back();
                res+=last*min(st.back(),x);
            }
            st.push_back(x);
               
        }
        
        while(st.size()>2)
        {
            int last=st.back();
            st.pop_back();
            res+=st.back()*last;
        }
        return res;
    }
};