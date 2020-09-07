def majority(max, array):
    output = {}
    for val in array:
        if val in output:
            output[val] += 1
        else:
            output[val] = 1
    return output

max = int(input())
array = [int(x) for x in input().split(' ')]
out = majority(max, array)
currentmax = 0
output= None

for key, val in out.items():
    if val > max/2 and val > currentmax:
        output = key
        currentmax = val
if output == None:
    print('NO')
else:
    print(output)