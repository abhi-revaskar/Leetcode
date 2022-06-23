class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& c) {
        priority_queue<int> q;
        sort(c.begin(),c.end(),comp);
        int ans=0,day=0;
        for(int i=0;i<c.size();i++)
        {
            int dur = c[i][0],ddl = c[i][1];
            // cout<<dur<<" "<<ddl<<" ";
            if(dur > ddl)
                continue;
            if(day+dur<=ddl)
            {
                // cout<<"a"<<endl;
                q.push(dur);
                ans++;
                day+=dur;
            }
            else
            {
                if(q.top()<=dur)
                {
                    // cout<<"b"<<endl;
                    continue;
                }
                else
                {
                    // cout<<"c"<<endl;
                    int t = q.top();
                    q.pop();
                    q.push(dur);
                    day = day - t+dur;
                }
            }
        }
        return ans;
    }
};