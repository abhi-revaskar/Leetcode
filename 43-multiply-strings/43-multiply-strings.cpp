class Solution {
public:
    void add(string &s,string &t)
    {
        string ans="";
        int carry=0;
        for(int i=0;i<t.length();i++)
        {
            int n1=s[i]-'0',n2=t[i]-'0';
            int sum = n1+n2+carry;
            carry = sum/10;
            ans+=char(sum%10 +'0');
        }
        s=ans;
    }
    string multiply(string num1, string num2) {
        int n = num1.length(),m=num2.length();
        string ans(n+m+1,'0');
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<n;i++)
        {
            string temp(m+n,'0');
            int carry = 0,m1=num1[i]-'0';
            for(int j=0;j<m;j++)
            {
                int m2=num2[j]-'0';
                int multi=m1*m2+carry;
                carry=multi/10;
                temp[i+j]=char((multi%10)+'0');
            }
            temp[i+m]=char(carry+'0');
            add(ans,temp);
        }
        reverse(ans.begin(),ans.end());
        while(ans!="" && ans[0]=='0')
            ans = ans.substr(1);
        if(ans=="")
            return "0";
        return ans;
    }
};