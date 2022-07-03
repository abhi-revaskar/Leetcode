* If a[left] <= a[right] , then the water that can be stored at a[left] depends on the leftmax value. If a[left] >= leftmax, no water can be stored, hence update the leftmax and left++.Else
water=leftmax-a[left].
* Similarly for other condition, i.e. when a[left]>a[right].