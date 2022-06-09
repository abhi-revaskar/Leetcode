class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int l=0,h=numbers.size()-1;
        while(numbers[l]+numbers[h]!=target)
        {
            if(numbers[l]+numbers[h]>target)
                h--;
            else l++;
        }
        ans.push_back(l+1);
        ans.push_back(h+1);
        return ans;
    }
};