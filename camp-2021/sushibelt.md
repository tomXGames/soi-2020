# Sushibelts

## Subtask 1:
There have to be w=17 waiters to serve all th guests with b=10 belts, as I assume, that the meal can't just be pased from waiter to waiter, it has to be laid onto the conveyer belt.
The arrangement is in the image in the text channel (diagram 1).

## Subtask 2:
The formula is:
w = (b-1)*2-1

```python
waiters = [[-1 for i in range(b-1)] for i in range(b-1)] #there is a waiter wherever there is a number, not a -1
for i in range(b-1):
    waiter[i][i] = i
for i from b-1:
    waiter[i][b-1-i] = i + b-1 #The waiter in the middle is being set again, but that doesn't count, only the matrix at the end counts
print(waiters)
```
The algorithm described above produces a matrix with all waiters at necessary at each position, if the meal can't be handed fromw waiter to waiter, it is correct.

Proof:
Lets look at a situation based on the diagram in the text channel (diagram 2). Assume that a meal has to travel from b_0 to b_2. This could be done with b-1 (in our case b= 3 so 2) waiters in a diagonal line. But with only one diagonal line, a meal at b_k cannot travel to b_k-2 (in our example from b_2 to b_0), as explained by the red path on the diagram. There should be another waiter (on the diagram in blue).

This means that (b-1)*2-1 is the minimum possible amount of waiters.

## Subtask 3
This problem looks like a DP problem to me, where the DP-State is as follows:

```
DP[b_k][b_k+n] = earliest point at which a meal arrives at b_k+n = waiters[k][[DP[b_k][b_k+n-1]:end].at(0)
DP[b_k][b_k-n] = earliest point at which a meal arrives at b_k-n = waiters[k][[DP[b_k][b_k+n+1]:end].at(0)
```
And the basecases as follows:
```
DP[i][i] = 0
```
Using a double nested for loop, starting i at 0 and j at 0 DP[i][j] can be computed with the set basecases.

This works because it checks every possibility.
Do I have to write out the algorithm next time?

