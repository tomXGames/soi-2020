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
for i in range(1,int(n**0.5)):
    if n%i == 0:
        state = not state
if n == 1:
    state = True
if state:
    print(hissed)
else:
    print(low)