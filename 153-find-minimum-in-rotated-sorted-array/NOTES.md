If the array contains only one element then return that element.
If the array is not rotated then return the first element.
low=0 high =n-1 mid=low+high/2
if the first element of the array is lesser than the mid element then the search the right half of the array.(low=mid+1)
if the first element of the array is larger than the mid element then search the left half of the array (high=mid-1)
If any of the following condition is met, then return
​
​