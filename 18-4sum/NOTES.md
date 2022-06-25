1. Sort
2. i=0 to n-4
3. j = i+1 to n-3
4. left=j+1 and right=n-1
5. for each pointer i,j,left and right check if nums[ptr] == nums[ptr-1], if true -> we have already searched this combo, if false-> perform search.