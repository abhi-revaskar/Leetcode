class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums; //nums from 1 to n in order
        int fact = 1; //contains (n)!
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
            fact*=i; 
        }
        k--; // for 0 based indexing
        string ans = ""; //ans string
        while(nums.size()!=1) // until there is only one element left
        {
            int grpsize = fact/n;
            int grpno = k/grpsize; // grpno == element idx in nums
            ans +=to_string(nums[grpno]);
            nums.erase(nums.begin()+grpno); //delete this no from the nums
            k = k% grpsize; // index of the permutation within the grp
            fact = fact/n;
            n--;
        }
        ans +=to_string(nums.back()); //last remaining element
        return ans;
    }
};