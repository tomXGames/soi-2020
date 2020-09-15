input()
array = [int(x) for x in input().split(' ')]
array.sort()
for i in array:
    print(i, end=' ')