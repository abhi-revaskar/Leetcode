The question boils down to finding the largest palindrome substring from the beginning.
We can use the concept of longest prefix suffix to find this.
Edge case : when the suffix and prefix overlap.
Solution : use delimiter.
OR
Computer Z function for t = s + "#" + s
find index i in z, such that i+z[i] = len(t),then s.substr(z[i]) should be added to front(in reverse)