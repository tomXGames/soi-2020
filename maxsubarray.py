def maxsubarray(array):
    length = len(array)
    max =0
    for i in range(length):
        index = length - i
        for j in range(index):
            if max< sum(array[i:i+j]):
                max = sum(array[i:i+j])
    return max

input()
array = input().split(' ')
array = [int(x) for x in array]
print(str(maxsubarray(array)))