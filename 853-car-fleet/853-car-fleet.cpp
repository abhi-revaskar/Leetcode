class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> postime;
        for(int i=0;i<position.size();i++)
        {
            double time = (target-position[i])/double(speed[i]);
            postime.push_back({position[i],time});
        }
        sort(postime.begin(),postime.end());
        stack<double> st;
        for(int i=0;i<postime.size();i++)
        {
            while(!st.empty() && st.top()<=postime[i].second)
                st.pop();
            st.push(postime[i].second);
        }
        return st.size();
    }
};