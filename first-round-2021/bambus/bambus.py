f = open('test11.txt', 'r').readlines()
t = int(f[0])
cases = []
for i in range(t):
    case = []
    l = int(f[i*2+1].strip('\n'))
    case.append(l)
    m = [int(x) for x in f[i*2+2].split(' ')]
    case.append(m)
    cases.append(case)
solution = []
# cases = [[8,[8, 2, 5, 2, 1, 5, 5, 8]]]
for case in cases:
    m = case[1]
    count = 0
    opened = []
    previous = -1
    for index, i in enumerate(m):
        if not opened.__contains__(i):
            opened.append(i)
        toberemoved =[]
        if previous < i:
            for j in opened:
                if j<i:
                    toberemoved.append(j)
                    count += 1
            for j in toberemoved:
                opened.remove(j)
        previous = i
    count += len(opened)
    print(count)
    solution.append(count)

outf = open('out10.txt', 'w')
print(solution)
for i, sol in enumerate(solution):
    outf.write(f'Case #{i}: {sol} \n ')