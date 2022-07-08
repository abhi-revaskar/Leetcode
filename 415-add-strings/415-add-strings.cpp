class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.length()>num2.length())
            return addStrings(num2,num1);
        string ans = "";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        int carry = 0;
        for(int i=0;i<num1.length();i++)
        {
            int sum = num1[i]-'0'+num2[i]-'0'+carry;
            if(sum>=10)
                carry=1;
            else
                carry=0;
            ans+=char(sum%10+'0');
        }
        for(int i=num1.length();i<num2.length();i++)
        {
            int sum = num2[i]-'0'+carry;
            carry = (sum>=10)?1:0;
            ans+=char(sum%10 +'0');
        }
        if(carry)
        ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};