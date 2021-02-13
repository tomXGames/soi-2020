# Gassupply
## Subtask 1

There have to be at maximum three queries to be sure where the leak is. This is how to do it:

1 ) Check in the middle (edge 2-3)

2 ) If it flows to the right, check at the bottom right (edge 3-5) and proceed to step 3 right, else check on the bottom left (edge 1-2) and proceed to step 3 left.

3 right) if it flows to the right, you know the leak is at 5, else check on edge 3-4 and proceed to step 4 right.

3 left) if it flows to the left, you know the leak is at 1, else check edge 0-2 and proceed to step 4 left.

4 right) if it flows to the right the edge is on node 4, else its on node 3.

4 left) if it flows to the left the edge is on node 0, else its on node 2.

## Subtask 2
Apply binary search:
```python
left = 0
right = n-1
flows = [None for i in range(n-1)] #this list saves all the flows
while left>= right:
    mid = left + (left+right)//2
    flow = probe(mid, mid+1) #probe is a function that takes in two nodes and returns the probe at the edge between those nodes (0 = left, 1 = right)
    flows[mid] = flow
    if(flow == 0) right == mid-1
    else left = mid +1
    if(flows[mid+1] != None and flows[mid+1] != flows[mid]) return mid #found leaky node
```
With this implementation, our algorithm has a running time of O(log2(n)), because it always decreases its search space space by a factor of 2 until its 1.

## Subtask 3
I don't have the time to implement it in pseudocode, so heres a general explaination:

Start in the absolute middle of the graph. Probe and move accordingly to the left or right, like in the 2D implementation. if there is a branch and it points in either of that direction, check the first edge of the lower one and then, if necessary check the first edge of the other branch to decide which branch to follow.

I believe the running time stays the same (O(log2(n))), but I am not sure.