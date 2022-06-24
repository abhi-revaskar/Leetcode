class Solution {
public:
    bool isPossible(vector<int>& t) {
        priority_queue<int> q;
        long long sum = 0;
        for(auto x:t)
        {
            sum+=x;
            q.push(x);
        }
        while(true)
        {
            int x = q.top();
            q.pop();
            sum=sum-x;
            if(x==1 || sum==1)
                return true;
            if(x<sum || sum == 0 || x%sum==0)
                return false;
            x=x%sum;
            q.push(x);
            sum=sum+x;
        }
        return true;
    }
};