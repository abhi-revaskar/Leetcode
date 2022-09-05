class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry = 1;
        vector<int> ans;
        for(auto x:digits)
        {
            int sum = x+carry;
            ans.push_back(sum%10);
            carry = sum/10;
        }
        if(carry)
            ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};