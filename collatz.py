num = int(input())
steps = 0
while not num==1:
    steps +=1
    if num % 2 == 0:
        num = num/2
    else:
        num = 3*num+1
print(steps)