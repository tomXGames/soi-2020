hissed = '''....o 
####|
####|
####|
....|
....|
....|
....|
....|
....|'''

low = '''....o
....|
....|
....|
....|
....|
####|
####|
####|
....|'''

n = int(input())
state = False
for i in range(1,n+1):
    if n%i == 0:
        state = not state
if state:
    print(hissed)
else:
    print(low)