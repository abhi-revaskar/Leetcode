// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	void solve(int i,string &s,string ans,vector<string> &res)
	{
	    if(i==s.length())
	    {
	        if(ans!="")
	        res.push_back(ans);
	        return;
	    }
	    solve(i+1,s,ans+s[i],res);
	    solve(i+1,s,ans,res);
	    return;
	}
		vector<string> AllPossibleStrings(string s){
		    vector<string> res;
		    string ans="";
		    solve(0,s,ans,res);
		    sort(res.begin(),res.end());
		    return res;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends