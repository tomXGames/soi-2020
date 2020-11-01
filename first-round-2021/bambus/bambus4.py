f = open('test8.txt', 'r').readlines()
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
    for index, i in enumerate(m):
        if not opened.__contains__(i):
            opened.append(i)
        for j in opened:
            if j<i:
                opened.remove(j)
                count += 1
    count += len(opened)
    solution.append(count)

outf = open('out8.txt', 'w')
print(solution)
for i, sol in enumerate(solution):
    outf.write(f'Case #{i}: {sol} \n ')
