* Use unordered set to store all the numbers.
* Then for each number a[i], check if a[i]-1 is present in the set or not. If it is not present, a[i] can be the starting of a sequence. Then count all the numbers in a sequence starting from a[i]. If a[i]-1 is present in the set, then this number can be counted later.