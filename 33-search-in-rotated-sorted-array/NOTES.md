low=0 and high =n-1
mid = (low+high)/2
if target is at mid, return it.
either of the left half or the right half will be sorted always. check which half is sorted,
if the left half is sorted, check if the target lies in left half or not. if lies then make h=mid-1
if not then make l=mid+1
similarly for the right half.