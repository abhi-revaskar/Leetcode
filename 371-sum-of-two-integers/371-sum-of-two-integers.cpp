class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0,c = 0;
        for(int i=0;i<32;i++)
        {
            int b1= (a>>i)&1,b2 = (b>>i)&1;
            int sum = b1^b2^c;
            c = b1&b2 | b2&c | b1&c;
            ans = ans|(sum<<i);
            // cout<<b1<<" "<<b2<<" "<<sum<<" "<<c<<"ans: ";
            // cout<<ans<<endl;
        }
        return ans;
    }
};