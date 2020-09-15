def missingnum(array):
    array.sort()
    for i, j in enumerate(array):
        if j+1 != array[i+1]:
            return j+1

input()
array = [int(x) for x in input().split(' ')]
print(str(missingnum(array)))