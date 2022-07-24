class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0,high = matrix.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(matrix[mid][0]==target)
                return true;
            if(matrix[mid][0]<target)
                low=mid+1;
            else
                high = mid-1;
        }
        if(high<0)
            return false;
        int arr = high;
        low=0,high = matrix[0].size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(matrix[arr][mid]==target)
                return true;
            if(matrix[arr][mid]<target)
                low=mid+1;
            else
                high = mid-1;
        }
        return false;
    }
};