# Warmup 22.02.2021

Observation: The index of the median increases by 1 each time we increase the length of the prefix by 2.

This means, that for every call we have a range. 

Pseudo-Code:
```python
medians=[]
for i in range(n):
    medians.append(sort(nums[i:n-1])[i:i+((int)(n-i-1)/2)])
```
Proof: The median is always the middle element. IDK

Runtime depends on how fast the used language handles slicings and sorting... if slicing is O(1) and sorting is O(n*log(n)) its O(n*log(n)). 
This is not correct. The array is not sorted, so its n^2.