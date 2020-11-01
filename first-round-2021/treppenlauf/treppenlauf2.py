f = open('test4.txt', 'r').readlines()
t = int(f[0])
cases = {}
for i in range(t):
    cases[i] = []
    n = [int(f[i*3+1])]
    cases[i].append(n)
    cases[i].append([int(x) for i, x in enumerate(f[(i*3)+2].split(' '))])
    cases[i].append([int(x) for i, x in enumerate(f[(i*3)+3].split(' '))])

solutions = {}
for i, items in cases.items():
    right = items[1]
    left = items[2]
    out = 0
    for indx, j in enumerate(right):
        for inx, k in enumerate(left):
            if j+ k + abs(indx- inx) > out:
                out = j+ k + abs(indx- inx)
print (solutions[0])
outf = open('out3.txt', 'w')
for i, val in solutions.items():
    outf.write(f'Case #{i}: {val}\n')