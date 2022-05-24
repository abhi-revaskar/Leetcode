class Solution {
public:
    void part(int idx,vector<string> &ds,vector<vector<string>> &ans,string s)
    {
        int n=s.length();
        if(!ds.empty())
        {
          string t=ds.back();
          for (int i = 0; i < t.length()/2; i++)
          {
            if(t[i]!=t[t.length()-1-i])
            {
              //cout<<"not pal:"<<idx<<" "<<t<<" char miss:"<<t[i]<<t[n-1-i]<<endl;
              return;
            }
          }
        }
        if(idx==n)
        {
          ans.push_back(ds);
          //cout<<ds.back()<<endl;
          return;
        }
        string t="";
        for (int i = idx; i < n; i++)
        {
          t+=s[i];
          //cout<<idx<<" "<<i<<" "<<t<<endl;
          ds.push_back(t);//push {a}, {aa},{aaa},... etc.
          part(i+1,ds,ans,s);
          ds.pop_back();
        }
   }

vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        part(0,ds,ans,s);
        return ans;
    }
};