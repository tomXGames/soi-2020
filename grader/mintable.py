def generateTarget(n):
    target = [[[] for x in  range(n)] for y in range(n)]
    for i in range(n):
        for j in range(n):
            target[i][j] = min([abs(i),abs(j)])
    return target
    
array = generateTarget(int(input()))
for i in array:
    string = ''
    for j in i:
        string += str(j) + " "
    print(string+ '\n', end='')