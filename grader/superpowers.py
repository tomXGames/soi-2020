def superpowers(n, array):
    array.sort()
    for i in range(n):
        array[0] *= -1
        array.sort()
    return sum(array)

n = int(input().split(' ')[0])
array = [int(x) for x in input().split(' ')]
print(superpowers(n, array))