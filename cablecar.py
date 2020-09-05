def cablecar(array):
    difference = 0
    for i, val in enumerate(array):
        if i == 0:
            difference = array[1] - val
        elif val - array[i-1] != difference:
            return False
    return True

input()
array = [int(x) for x in input().split(' ')]
if cablecar(array):
    print('yes')
else:
    print('no')