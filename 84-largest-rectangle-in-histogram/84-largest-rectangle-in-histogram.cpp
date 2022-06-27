class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int rse[h.size()],lse[h.size()];
        stack<int> st1,st2;
        rse[h.size()-1]=h.size();
        lse[0]=-1;
        st1.push(h.size()-1);
        st2.push(0);
        for(int i=0;i<h.size();i++)
        {
            while(!st1.empty() && h[st1.top()]>=h[h.size()-i-1])
                    st1.pop();
            if(st1.empty())
                    rse[h.size()-i-1]=h.size();
            else 
                rse[h.size()-i-1] = st1.top();
            st1.push(h.size()-i-1);
            while(!st2.empty() && h[st2.top()]>=h[i])
                    st2.pop();
            if(st2.empty())
                    lse[i]=-1;
            else 
                lse[i] = st2.top();
            st2.push(i);
        }
        int ans = 0;
        for(int i=0;i<h.size();i++)
        {
            // cout<<lse[i]<<" "<<rse[i]<<endl;
        }
        for(int i=0;i<h.size();i++)
        {
            ans = max(ans,h[i]*(rse[i]-lse[i]-1));
        }
        return ans;
    }
};