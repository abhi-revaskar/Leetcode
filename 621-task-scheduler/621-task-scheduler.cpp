class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto x:tasks)
        {
            mp[x]++;
        }
        priority_queue<int> ready;
        queue<pair<int,int>> waiting;
        for(auto x: mp)
        {
            ready.push(x.second);
        }
        int time = 0;
        while(!ready.empty() || !waiting.empty())
        {
            if(ready.empty())
            {
                ready.push(waiting.front().first);
                time = waiting.front().second;
                waiting.pop();
            }
            int task = ready.top();
            time++;
            ready.pop();
            if(task!=1)
                waiting.push({task-1,time+n});
            if(waiting.size() && waiting.front().second==time)
            {
                ready.push(waiting.front().first);
                waiting.pop();
            }
        }
        return time;
    }
};