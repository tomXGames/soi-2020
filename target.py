def generateTarget(n):
    target = [[[] for x in  range(2*n+1)] for y in range(2*n+1)]
    for i in range(2*n+1):
        for j in range(2*n+1):
            target[i][j] = max([abs(i-n),abs(j-n)])
    return target
array = generateTarget(int(input()))
for i in array:
    string = ''
    for j in i:
        string += str(j) + " "
    print(string+ '\n', end='')