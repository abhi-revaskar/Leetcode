class Solution {
public:
    int ans;
    void find(int i,string &s,vector<string> &arr)
    {
        // cout<<s<<" ";
        if(i==arr.size())
        {
            ans = max(ans,int(s.length()));
            return;
        }
        find(i+1,s,arr);
        for(char x:arr[i])
        {
            // cout<<x<<" "<<s.find(x)<<endl;
            if(s.find(x)< s.length())
                return;
        }
        s+=arr[i];
        find(i+1,s,arr);
        s.erase(s.length()-arr[i].length());
    }
    int maxLength(vector<string>& arr) {
        vector<string> arr2;
        string s ="";
        for(auto x:arr)
        {
            int f = 0;
            for(int i=0;i<x.length();i++)
            {
                string t = x;
                t.erase(i,1);
                if(t.find(x[i])<t.length())
                {
                    f=1;
                    break;
                }
            }
            if(!f)
                arr2.push_back(x);
        }
        find(0,s,arr2);
        return ans;
    }
};