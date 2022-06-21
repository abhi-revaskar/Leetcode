class Solution {
public:
    int furthestBuilding(vector<int> &h, int b, int l) {
        priority_queue<int,vector<int>,greater<int>> q2;
        int sum=0;
        for(int i=1;i<h.size();i++)
        {
            int jump = h[i]-h[i-1];
            if(jump>0)
            {
                if(q2.size()<l)
                {
                    q2.push(jump);
                }
                else if(!q2.empty() && q2.top()<jump)
                {
                    if(sum+q2.top()>b)
                        return i-1;
                    sum+=q2.top();
                    q2.pop();
                    q2.push(jump);
                }
                else
                {
                    if(sum+jump>b)
                        return i-1;
                    sum+=jump;
                }
            }
            
        }
        return h.size()-1;
        
    }
};